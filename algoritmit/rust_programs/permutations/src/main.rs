// https://cses.fi/alon/task/1070/ 22.7.2023
use std::io;

fn main() {
    // create new mutable string "input"
    let mut input: String = String::new();

    // read_line modifies it to add user input to the variable.
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // remove trailing newline
    input = input.trim().to_string();

    //dbg!(&input);
    //logic. same as python.
    let input_value: u64 = input.parse::<u64>().unwrap();
    if input_value == 1 {
        println!("1")
    } else if input_value < 4 {
        println!("NO SOLUTION")
    } else if input_value == 4 {
        println!("3 1 4 2")
    } else {
        for i in (1..=input_value).step_by(2) {
            print!("{} ", i);
        }
        for i in (2..=input_value).step_by(2) {
            print!("{} ", i);
        }
    }
}

// #

// n = int(input("")) # 1 makes 1
// if n == 1:
//     print(1)
// elif n < 4: #2 and 3 no solution
//     print("NO SOLUTION")
// elif n == 4: # specifically for 2
//     print("3 1 4 2")
// else: # algorithm works for n > 4
//     out_str = " ".join([str(i) for i in range(1, n+1, 2)]) + " " +  " ".join([str(i) for i in range(2, n+1, 2)])
//     print(out_str)
