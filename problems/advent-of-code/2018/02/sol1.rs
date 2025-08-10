use std::fs;
use std::cmp::min;
use std::collections::HashMap;

fn main() {
    let input = fs::read_to_string("in.txt").expect("Failed to read input file");

    let mut double = 0;
    let mut triple = 0;

    for line in input.lines() {
        let mut counter = HashMap::new();

        for c in line.chars() {
            *counter.entry(c).or_insert(0) += 1;
        }

        double += min(1, counter.values().filter(|&count| *count == 2).count());
        triple += min(1, counter.values().filter(|&count| *count == 3).count());
    }

    println!("{}", double * triple);
}