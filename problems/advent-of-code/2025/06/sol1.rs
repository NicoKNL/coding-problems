use std::fs;

#[derive(Debug)]
enum Operation {
    Add,
    Subtract,
    Multiply,
    Divide,
}

impl Operation {
    fn from_char(c: char) -> Option<Operation> {
        match c {
            '+' => Some(Operation::Add),
            '-' => Some(Operation::Subtract),
            '*' => Some(Operation::Multiply),
            '/' => Some(Operation::Divide),
            _ => None,
        }
    }
}

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let content = fs::read_to_string(&args[1]).unwrap();

    let lines: Vec<&str> = content.lines().collect();
    let data_lines = &lines[..lines.len() - 1];
    let operations_line = lines[lines.len() - 1];

    let column_count = data_lines[0].trim().split_whitespace().count();

    let columns: Vec<Vec<u64>> = (0..column_count)
        .map(|i| {
            data_lines
                .iter()
                .map(|line| {
                    let tokens: Vec<&str> = line.trim().split_whitespace().collect();
                    tokens[i].trim().parse().unwrap()
                })
                .collect()
        })
        .collect();

    let operations: Vec<Operation> = operations_line
        .chars()
        .filter(|c| !c.is_whitespace())
        .filter_map(|c| Operation::from_char(c))
        .collect();

    let total: u128 = columns
        .iter()
        .enumerate()
        .map(|(i, col)| {
            let mut result = col[0] as u128;
            let op = &operations[i];
            for j in 1..col.len() {
                let value = col[j] as u128;
                match op {
                    Operation::Add => result += value,
                    Operation::Subtract => result -= value,
                    Operation::Multiply => result *= value,
                    Operation::Divide => result /= value,
                }
            }
            result
        })
        .sum();

    println!("Total: {}", total);
}
