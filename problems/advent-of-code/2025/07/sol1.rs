use std::fs;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let content = fs::read_to_string(&args[1]).unwrap();

    let lines: Vec<&str> = content.lines().collect();
    let mut grid: Vec<Vec<char>> = Vec::new();
    for line in &lines {
        let row: Vec<char> = line.chars().collect();
        grid.push(row);
    }

    let mut splits = 0;
    for r in 0..grid.len() - 1 {
        for c in 0..grid[r].len() {
            if grid[r][c] == 'S' || grid[r][c] == '|' {
                if grid[r + 1][c] == '^' {
                    splits += 1;

                    grid[r + 1][c - 1] = '|';
                    grid[r + 1][c + 1] = '|';
                } else {
                    grid[r + 1][c] = '|';
                }
            }
        }
    }
    println!("{}", splits);
}
