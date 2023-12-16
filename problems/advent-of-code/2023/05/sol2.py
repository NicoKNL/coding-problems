import sys


class SegmentMap:
    def __init__(self, source: int, target: int, length: int):
        self.source = source
        self.target = target
        self.length = length

    def __contains__(self, seed_range: tuple[int, int]) -> bool:
        return (
            self.source <= seed_range[0] < self.source + self.length
            or self.source <= seed_range[1] < self.source + self.length
        )

    def translate(self, seed_range: tuple[int, int]) -> tuple[int, int]:
        offset_start = seed_range[0] - self.source
        offset_end = seed_range[1] - self.source
        return (self.target + offset_start, self.target + offset_end)


def parseSeeds(s: str) -> list[int]:
    return list(map(int, s.split(":")[-1].strip().split(" ")))


def parseSeedRanges(s: str) -> list[tuple[int, int]]:
    seeds = parseSeeds(s)
    seed_ranges = []
    for i in range(0, len(seeds), 2):
        seed_ranges.append((seeds[i], seeds[i] + seeds[i + 1] - 1))
    return seed_ranges


def getSegmentMaps(lines: list[str], key: str) -> list[SegmentMap]:
    segment_maps = []

    data_found = False
    for line in lines:
        if data_found and line:
            target, source, length = map(int, line.split(" "))
            segment_maps.append(SegmentMap(source, target, length))
        elif data_found:
            break

        if line.startswith(key):
            data_found = True

    return segment_maps


def trimSeedRange(
    seed_range: tuple[int, int], segment_map: SegmentMap
) -> tuple[tuple[int, int], list[tuple[int, int]]]:
    outside_ranges = []

    seg_start = segment_map.source
    seg_end = seg_start + segment_map.length - 1

    if seed_range[0] < seg_start:
        outside_ranges.append((seed_range[0], seg_start - 1))
        seed_range = (seg_start, seed_range[1])

    if seed_range[1] > seg_end:
        outside_ranges.append((seg_end + 1, seed_range[1]))
        seed_range = (seed_range[0], seg_end)

    return seed_range, outside_ranges


def parseMaps(lines: list[str]) -> list[list[SegmentMap]]:
    return [
        getSegmentMaps(lines, "seed"),
        getSegmentMaps(lines, "soil"),
        getSegmentMaps(lines, "fertilizer"),
        getSegmentMaps(lines, "water"),
        getSegmentMaps(lines, "light"),
        getSegmentMaps(lines, "temperature"),
        getSegmentMaps(lines, "humidity"),
    ]


def mapSeedsToLocations(
    seed_ranges: list[tuple[int, int]], maps_per_transition: list[list[SegmentMap]]
) -> list[tuple[int, int]]:
    for segment_maps in maps_per_transition:
        next_seed_ranges = []
        i = 0
        while i < len(seed_ranges):
            current_range = seed_ranges[i]

            mapped = False
            for segment in segment_maps:
                if current_range in segment:
                    mapped = True
                    current_range, outside_ranges = trimSeedRange(
                        current_range, segment
                    )

                    next_seed_ranges.append(segment.translate(current_range))
                    seed_ranges.extend(outside_ranges)
                    break

            if not mapped:
                next_seed_ranges.append(current_range)

            i += 1
        seed_ranges = next_seed_ranges
    return seed_ranges


lines = [line.strip() for line in sys.stdin if line]

seed_ranges = parseSeedRanges(lines[0])
maps = parseMaps(lines[1:])

seed_ranges = mapSeedsToLocations(seed_ranges, maps)

seed_range_starts = [sr[0] for sr in seed_ranges]
print(min(seed_range_starts))
