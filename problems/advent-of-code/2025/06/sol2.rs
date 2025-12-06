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

    let max_len = data_lines.iter().map(|l| l.len()).max().unwrap_or(0);
    let column_count = max_len;

    let mut columns: Vec<String> = vec![String::new(); column_count];

    for line in data_lines {
        let chars: Vec<char> = line.chars().collect();
        for col_idx in 0..column_count {
            if col_idx < chars.len() {
                let ch = chars[col_idx];
                if ch.is_numeric() {
                    columns[col_idx].push(ch);
                }
            }
        }
    }

    let mut operation_positions: Vec<(usize, Operation)> = Vec::new();
    for (idx, ch) in operations_line.chars().enumerate() {
        if let Some(op) = Operation::from_char(ch) {
            operation_positions.push((idx, op));
        }
    }

    let mut grouped_columns: Vec<Vec<u64>> = Vec::new();

    for i in 0..operation_positions.len() {
        let start_pos = operation_positions[i].0;
        let end_pos = if i + 1 < operation_positions.len() {
            operation_positions[i + 1].0
        } else {
            column_count
        };

        let mut column_numbers: Vec<u64> = Vec::new();
        for col_idx in start_pos..end_pos {
            if col_idx < columns.len() && !columns[col_idx].is_empty() {
                column_numbers.push(columns[col_idx].parse().unwrap());
            }
        }

        grouped_columns.push(column_numbers);
    }

    let operations: Vec<Operation> = operation_positions
        .iter()
        .map(|(_, op)| match op {
            Operation::Add => Operation::Add,
            Operation::Subtract => Operation::Subtract,
            Operation::Multiply => Operation::Multiply,
            Operation::Divide => Operation::Divide,
        })
        .collect();

    let total: u128 = grouped_columns
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
