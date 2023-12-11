import sys


class SegmentMap:
    def __init__(self, source: int, target: int, length: int):
        self.source = source
        self.target = target
        self.length = length

    def __contains__(self, seed: int) -> bool:
        return self.source <= seed < self.source + self.length

    def translate(self, seed: int) -> int:
        offset = seed - self.source
        return self.target + offset


def parseSeeds(s: str) -> list[int]:
    return list(map(int, s.split(":")[-1].strip().split(" ")))


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


lines = [line.strip() for line in sys.stdin if line]

seeds = parseSeeds(lines[0])
maps = parseMaps(lines[1:])

location = 10e10

for seed in seeds:
    for segment_maps in maps:
        for segment in segment_maps:
            if seed in segment:
                seed = segment.translate(seed)
                break

    location = min(location, seed)

print(location)
