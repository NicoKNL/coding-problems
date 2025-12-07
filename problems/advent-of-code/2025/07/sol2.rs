use std::fs;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let content = fs::read_to_string(&args[1]).unwrap();

    let lines: Vec<&str> = content.lines().collect();
    let mut grid: Vec<Vec<char>> = Vec::new();
    let mut worlds: Vec<Vec<i128>> = Vec::new();
    for line in &lines {
        let row: Vec<char> = line.chars().collect();
        let world_row: Vec<i128> = vec![0; row.len()];
        worlds.push(world_row);
        grid.push(row);
    }

    for r in 0..grid.len() - 1 {
        for c in 0..grid[r].len() {
            if grid[r][c] == 'S' {
                grid[r + 1][c] = '|';
                worlds[r + 1][c] += 1;
            } else if grid[r][c] == '|' {
                if grid[r + 1][c] == '^' {
                    grid[r + 1][c - 1] = '|';
                    grid[r + 1][c + 1] = '|';

                    worlds[r + 1][c - 1] += worlds[r][c];
                    worlds[r + 1][c + 1] += worlds[r][c];
                } else {
                    grid[r + 1][c] = '|';
                    worlds[r + 1][c] += worlds[r][c];
                }
            }
        }
    }
    println!("{}", worlds[worlds.len() - 1].iter().sum::<i128>());
}
