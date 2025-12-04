use std::fs;

fn parse_grid(content: &str) -> Vec<Vec<char>> {
    let mut grid: Vec<Vec<char>> = Vec::new();
    for line in content.lines() {
        let row: Vec<char> = line.chars().collect();
        grid.push(row);
    }
    grid
}

fn adjacent_rolls(r: usize, c: usize, G: &Vec<Vec<char>>) -> usize {
    let directions = vec![
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 1),
        (1, -1),
        (1, 0),
        (1, 1),
    ];
    let rows = G.len() as isize;
    let cols = G[0].len() as isize;
    let mut count = 0;

    for (dr, dc) in directions {
        let nr = r as isize + dr;
        let nc = c as isize + dc;
        if nr >= 0 && nr < rows && nc >= 0 && nc < cols {
            if G[nr as usize][nc as usize] == '@' {
                count += 1;
            }
        }
    }

    count
}

fn main() {
    let content = fs::read_to_string("in.txt").unwrap();
    let G = parse_grid(&content);

    let rows = G.len();
    let cols = G[0].len();

    let mut count = 0;
    for r in 0..rows {
        for c in 0..cols {
            if G[r][c] == '@' && adjacent_rolls(r, c, &G) < 4 {
                count += 1;
            } }
        }
    }

    println!("Total: {}", count);
}
