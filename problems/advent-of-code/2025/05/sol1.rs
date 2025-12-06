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

    let mut count = 0;
    for value in &values {
        let mut found = false;
        for range in &ranges {
            if *value >= range.start && *value <= range.end {
                found = true;
                break;
            }
        }
        if found {
            count += 1;
        }
    }
    println!("Count: {}", count);
}
