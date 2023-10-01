use std::io::{ BufRead, BufReader };
// this module makes rust I/O faster smh
 
fn algorithm(number: u64) -> u64 {
    (!number & 1)   * number / 2 +
    (number & 1)    * (3 * number + 1)
}
 
fn main() {
    // assign stdin stream to variable input
    let mut input = BufReader::new(std::io::stdin());
 
    // faster way to make a new string object compared to String::new() appearently
    let mut line = "".to_string();
 
    // input is read into buffer string line, which is changed because & symbol
    input.read_line(&mut line).unwrap();
 
    // trim removes the endl, parse makes it int, unwrap takes the Ok value
    let mut num: u64 = line.trim().parse().unwrap();
 
    while num > 1 {
        print!("{} ", num);
        num = algorithm(num);
    }
    print!("{} ", num);
 
 
}