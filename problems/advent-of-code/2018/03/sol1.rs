use regex::Regex;
use std::fs;

struct Pos {
    x: u32,
    y: u32,
}

struct Rect {
    width: u32,
    height: u32,
}

struct Claim {
    id: u32,
    root: Pos,
    rect: Rect,
}

impl Claim {
    fn from_str(s: &str, re: &Regex) -> Self {
        let caps = re.captures(s).expect("Invalid claim format");
        let id: u32 = caps[1].parse().expect("Invalid claim ID");
        let x: u32 = caps[2].parse().expect("Invalid x coordinate");
        let y: u32 = caps[3].parse().expect("Invalid y coordinate");
        let width: u32 = caps[4].parse().expect("Invalid width");
        let height: u32 = caps[5].parse().expect("Invalid height");

        Claim {
            id,
            root: Pos { x, y },
            rect: Rect { width, height },
        }
    }
}

fn read_input() -> Vec<String> {
    fs::read_to_string("in.txt")
        .expect("Failed to read input file")
        .lines()
        .map(String::from)
        .collect()
}

fn main() {
    const GRID_SIZE: usize = 1000;
    let mut grid: [[u32; GRID_SIZE]; GRID_SIZE] = [[0; GRID_SIZE]; GRID_SIZE];
    let content = read_input();
    let re: Regex = Regex::new(r"#(\d+) @ (\d+),(\d+): (\d+)x(\d+)").unwrap();

    for line in &content {
        let claim = Claim::from_str(line, &re);
        for i in claim.root.x..(claim.root.x + claim.rect.width) {
            for j in claim.root.y..(claim.root.y + claim.rect.height) {
                grid[i as usize][j as usize] += 1;
            }
        }
    }

    let mut count = 0;
    for row in 0..GRID_SIZE {
        for col in 0..GRID_SIZE {
            if grid[row][col] > 1 {
                count += 1;
            }
        }
    }
    println!("Overlapping square inches: {}", count);
}
