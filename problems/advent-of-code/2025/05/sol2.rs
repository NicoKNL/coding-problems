use std::fs;

#[derive(PartialEq)]
enum ParseMode {
    Range,
    Values,
}

#[derive(Debug)]
struct Range {
    start: u64,
    end: u64,
}

fn merge_ranges(ranges: &mut Vec<Range>) {
    ranges.sort_by_key(|r| r.start);
    let mut merged: Vec<Range> = Vec::new();

    for range in ranges.iter() {
        if let Some(last) = merged.last_mut() {
            if range.start <= last.end {
                last.end = last.end.max(range.end);
                continue;
            }
        }
        merged.push(Range {
            start: range.start,
            end: range.end,
        });
    }

    *ranges = merged;
}

fn parse_range(s: &str) -> Range {
    let tokens: Vec<&str> = s.trim().split('-').collect();

    let start: u64 = tokens[0].trim().parse().unwrap();
    let end: u64 = tokens[1].trim().parse().unwrap();

    Range { start, end }
}

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let content = fs::read_to_string(&args[1]).unwrap();

    let mut ranges: Vec<Range> = Vec::new();
    let mut values: Vec<u64> = Vec::new();

    let mut mode = ParseMode::Range;
    for line in content.lines() {
        if line.trim().is_empty() {
            mode = ParseMode::Values;
            continue;
        }

        if mode == ParseMode::Range {
            let range = parse_range(line);
            ranges.push(range);
        } else {
            let value: u64 = line.trim().parse().unwrap();
            values.push(value);
        }
    }

    merge_ranges(&mut ranges);

    let mut count = 0;
    for range in &ranges {
        count += range.end - range.start + 1;
    }
    println!("Count: {}", count);
}
