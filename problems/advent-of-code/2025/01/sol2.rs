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

fn rotate(pos: &mut i32, direction: i32, value: i32) -> i32 {
    let mut count = 0;
    for _ in 0..value {
        *pos = (*pos + direction + 100) % 100;
        if *pos == 0 {
            count += 1;
        }
    }

    count
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
        count += rotate(
            &mut pos,
            if instruction.direction == "L" { -1 } else { 1 },
            instruction.value,
        );
    }

    println!("{:}", count);
}
