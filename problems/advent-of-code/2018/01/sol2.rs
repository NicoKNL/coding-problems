use std::fs;
use std::collections::HashSet;

fn main() {
    let content = fs::read_to_string("in.txt").unwrap();

    let mut numbers = Vec::new();
    for line in content.lines() {
        let num = line.parse::<i64>().unwrap();
        numbers.push(num);
    }

    let mut sum: i64 = 0;
    let mut seen: HashSet<i64> = HashSet::new();

    while true {
        for &num in &numbers {
            sum += num;
            if seen.contains(&sum) {
                println!("{}", sum);
                return;
            }
            seen.insert(sum);
        }
    }
}