use std::fs;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
struct Pos {
    x: i128,
    y: i128,
    z: i128,
}

struct Distance {
    a: usize,
    b: usize,
    dist: f64,
}

struct UnionFind {
    parent: Vec<usize>,
    rank: Vec<usize>,
    size: Vec<usize>,
    positions: Vec<Pos>,
}

impl UnionFind {
    fn new(positions: Vec<Pos>) -> Self {
        let n = positions.len();
        UnionFind {
            parent: (0..n).collect(),
            rank: vec![0; n],
            size: vec![1; n],
            positions,
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]); // path compression
        }
        self.parent[x]
    }

    fn union(&mut self, x: usize, y: usize) -> bool {
        let root_x = self.find(x);
        let root_y = self.find(y);

        if root_x == root_y {
            return false; // already in same set
        }

        // union by rank and update size
        if self.rank[root_x] < self.rank[root_y] {
            self.parent[root_x] = root_y;
            self.size[root_y] += self.size[root_x];
        } else if self.rank[root_x] > self.rank[root_y] {
            self.parent[root_y] = root_x;
            self.size[root_x] += self.size[root_y];
        } else {
            self.parent[root_y] = root_x;
            self.rank[root_x] += 1;
            self.size[root_x] += self.size[root_y];
        }
        true
    }

    fn get_size(&mut self, x: usize) -> usize {
        let root = self.find(x);
        self.size[root]
    }

    fn count_components(&mut self) -> usize {
        let n = self.parent.len();
        let mut roots = std::collections::HashSet::new();
        for i in 0..n {
            roots.insert(self.find(i));
        }
        roots.len()
    }

    fn get_roots(&mut self) -> Vec<usize> {
        let n = self.parent.len();
        let mut roots = std::collections::HashSet::new();
        for i in 0..n {
            roots.insert(self.find(i));
        }
        roots.into_iter().collect()
    }
}

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let content = fs::read_to_string(&args[1]).unwrap();

    let mut positions = Vec::new();
    for line in content.lines() {
        let tokens: Vec<&str> = line.trim().split(',').collect();
        let x: i128 = tokens[0].trim().parse().unwrap();
        let y: i128 = tokens[1].trim().parse().unwrap();
        let z: i128 = tokens[2].trim().parse().unwrap();

        let pos = Pos { x, y, z };
        positions.push(pos);
    }

    let mut uf = UnionFind::new(positions);

    let mut distances: Vec<Distance> = Vec::new();
    for i in 0..uf.positions.len() {
        for j in (i + 1)..uf.positions.len() {
            let dx = (uf.positions[i].x - uf.positions[j].x) as f64;
            let dy = (uf.positions[i].y - uf.positions[j].y) as f64;
            let dz = (uf.positions[i].z - uf.positions[j].z) as f64;
            let dist = (dx * dx + dy * dy + dz * dz).sqrt();

            distances.push(Distance { a: i, b: j, dist });
        }
    }

    distances.sort_by(|d1, d2| d1.dist.partial_cmp(&d2.dist).unwrap());
    for distance in distances.iter() {
        uf.union(distance.a, distance.b);
        if uf.get_roots().len() == 1 {
            println!(
                "{}",
                uf.positions[distance.a].x * uf.positions[distance.b].x
            );
            break;
        }
    }
}
