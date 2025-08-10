use std::fs;

fn main() {
    let content = fs::read_to_string("in.txt").unwrap();

    let mut numbers = Vec::new();
    for line in content.lines() {
        let num = line.parse::<i64>().unwrap();
        numbers.push(num);
    }

    let mut sum: i64 = 0;

    for &num in &numbers {
        sum += num;
    }

    println!("{:}", sum);
}