use std::fs;

fn main() {
    let content = fs::read_to_string("in.txt").unwrap();
    let mut total = 0;
    for line in content.lines() {
        println!("{}", line);
        let integers: Vec<i64> = line
            .chars()
            .filter_map(|c| c.to_digit(10))
            .map(|d| d as i64)
            .collect();
        println!("{:?}", integers);

        let mut maximum = 0;
        for i in 0..integers.len() {
            for j in (i + 1)..integers.len() {
                maximum = maximum.max(integers[i] * 10 + integers[j]);
            }
        }
        println!("Maximum: {}", maximum);
        total += maximum;
    }
    println!("Total: {}", total);
}
