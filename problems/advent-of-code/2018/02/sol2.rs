use std::fs;
use std::cmp::min;

fn distance_between_strings(s1: &str, s2: &str) -> usize {
    s1.chars().zip(s2.chars()).filter(|(c1, c2)| c1 != c2).count()
}

fn print_common_chars(s1: &str, s2: &str) {
    let common_chars: String = s1.chars().zip(s2.chars())
        .filter(|(c1, c2)| c1 == c2)
        .map(|(c, _)| c)
        .collect();
    println!("{}", common_chars);
}

fn main() {
    let input = fs::read_to_string("in.txt").expect("Failed to read input file");

    let lines: Vec<&str> = input.lines().collect();
    for (i, line1) in lines.iter().enumerate() {
        for line2 in &lines[i + 1..] {
            if distance_between_strings(line1, line2) == 1 {
                print_common_chars(line1, line2);
                return;
            }
        }
    }
}