// https://cses.fi/problemset/task/1071 14.9.2023
use std::io;
 
fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
 
    let t: u64 = input
        .trim()
        .parse()
        .expect("Please type a number!");
 
    let results: Vec<u64> = (0..t)
        .map(|_| {
            let (y, x) = read_yx();
            find_number(y, x)
        })
        .collect();
 
    for i in &results {
        println!("{}", i);
    }
}
 
fn read_yx() -> (u64, u64) {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
 
    let both_inputs: Vec<u64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect("not an int."))
        .collect();
 
    (both_inputs[0], both_inputs[1])
}
 
fn find_number(y: u64, x: u64) -> u64 {
    if y >= x {
        if y & 1 == 1 {
            (y - 1) * (y - 1) + x
        } else {
            y * y - (x - 1)
        }
    } else {
        if x & 1 == 1 {
            x * x - (y - 1)
        } else {
            (x - 1) * (x - 1) + y
        }
    }
}
