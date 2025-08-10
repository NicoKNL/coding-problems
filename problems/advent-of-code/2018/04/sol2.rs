use std::collections::HashMap;
use std::fs;

fn read_lines(filename: &str) -> Vec<String> {
    let contents = fs::read_to_string(filename).expect("Something went wrong reading the file");
    contents.lines().map(|s| s.to_string()).collect()
}

enum State {
    Asleep(u32, u32),
    Awake(u32, u32),
    Shift(u32),
}

impl State {
    fn from_str(s: &str) -> Self {
        let parts: Vec<&str> = s.split_whitespace().collect();
        if parts[2] == "falls" {
            let hour = parts[1][..2].parse::<u32>().unwrap();
            let minute = parts[1][3..5].parse::<u32>().unwrap();
            State::Asleep(hour, minute)
        } else if parts[2] == "wakes" {
            let hour = parts[1][..2].parse::<u32>().unwrap();
            let minute = parts[1][3..5].parse::<u32>().unwrap();
            State::Awake(hour, minute)
        } else {
            let guard_id = parts[3][1..].parse::<u32>().unwrap();
            State::Shift(guard_id)
        }
    }
}

fn parse_guards(lines: Vec<String>) -> HashMap<u32, [u32; 60]> {
    let mut guards: HashMap<u32, [u32; 60]> = HashMap::new();
    let mut current_guard = 0;
    let mut last_minute = 0;

    for line in lines {
        match State::from_str(&line) {
            State::Shift(guard_id) => {
                current_guard = guard_id;
                guards.entry(current_guard).or_insert([0; 60]);
                last_minute = 0;
            }
            State::Asleep(hour, minute) => {
                if hour == 0 {
                    last_minute = minute;
                }
            }
            State::Awake(hour, minute) => {
                if hour == 0 {
                    for m in last_minute..minute {
                        let entry = guards.entry(current_guard).or_insert([0; 60]);
                        entry[m as usize] += 1;
                    }
                    last_minute = minute;
                }
            }
        }
    }
    guards
}

fn main() {
    let mut lines = read_lines("in.txt");
    lines.sort_unstable();

    let guards = parse_guards(lines);

    let mut most_asleep_guard = 0;
    let mut most_asleep_time = 0;
    let mut most_asleep_minute = 0;

    for minute in 0..60 {
        for (&guard_id, sleep) in &guards {
            if sleep[minute] > most_asleep_time {
                most_asleep_time = sleep[minute];
                most_asleep_guard = guard_id;
                most_asleep_minute = minute;
            }
        }
    }

    println!("Result: {}", most_asleep_guard * most_asleep_minute as u32);
}
