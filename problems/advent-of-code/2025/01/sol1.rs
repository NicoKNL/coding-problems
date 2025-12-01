use std::fs;

struct Instruction {
    direction: String,
    value: i32,
}

fn parseInstruction(s: &str) -> Instruction {
    let (direction, value) = s.split_at(1);

    Instruction {
        direction: direction.to_string(),
        value: value.parse().unwrap(),
    }
}

fn main() {
    let content = fs::read_to_string("in.txt").unwrap();

    let mut instructions = Vec::new();
    for line in content.lines() {
        instructions.push(parseInstruction(line));
    }

    let mut count: i32 = 0;
    let mut pos: i32 = 50;

    for instruction in &instructions {
        match instruction.direction.as_str() {
            "L" => pos -= instruction.value,
            "R" => pos += instruction.value,
            _ => (),
        }
        pos = (pos + 100) % 100;
        if pos == 0 {
            count += 1;
        }
    }

    println!("{:}", count);
}
