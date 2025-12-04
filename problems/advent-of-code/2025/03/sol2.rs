use std::fs;

fn main() {
    let content = fs::read_to_string("in.txt").unwrap();
    let mut total = 0;
    for line in content.lines() {
        let mut integers: Vec<u32> = line
            .chars()
            .filter_map(|c| c.to_digit(10))
            .map(|d| d as u32)
            .collect();

        let mut count = 0;
        let mut start = 0;
        let mut answer: Vec<u32> = Vec::new();
        let MAX = integers.len();
        while count < 12 {
            let mut maximum = 0;
            let mut index = 0;
            for i in start..(MAX - (12 - count) + 1) {
                if integers[i] > maximum {
                    maximum = integers[i];
                    index = i;
                }
            }
            answer.push(maximum);
            count += 1;
            start = index + 1;
        }

        let number = answer.iter().fold(0u128, |acc, &d| acc * 10 + d as u128);
        total += number;
    }
    println!("Total: {}", total);
}
