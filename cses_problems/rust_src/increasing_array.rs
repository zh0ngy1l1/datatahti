// https://cses.fi/alon/task/1068/ 22.7.2023
use std::io;

fn vec_str_to_int(vec_str: Vec<&str>) -> Vec<u64> {
    let mut vec_int: Vec<u64> = Vec::new();
    for num_str in vec_str {
        let int = num_str.parse::<u64>().unwrap();
        vec_int.push(int)
    }

    return vec_int;
}

fn main() {
    // create new mutable string "input"
    let mut input: String = String::new();
    
    // useless read_line for size
    io::stdin().read_line(&mut String::new()).expect("Failed to read line");

    // read_line modifies it to add user input to the variable.
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // create input_vector of string slices from user input split to parts
    let input_vector: Vec<&str> = input.split_whitespace().collect();

    // convert it to Vec<u64> using vec_str_to_int
    let int_vector: Vec<u64> = vec_str_to_int(input_vector);

    let mut largest: u64 = 0;
    let mut total_moves: u64 = 0;

    for num in int_vector{
        if largest <= num{
            largest = num;
        } else {
            let moves: u64 = largest - num;
            total_moves = total_moves + moves
        }
    }

    println!("{a}", a = total_moves);
}

// increasing_array.py
// size = int(input(""))
// input_array = [int(num) for num in input("").split()]
// largest = 0
// total_moves = 0
// for num in input_array:
//     if largest <= num:
//         largest = num
//     else:
//         moves = largest - num
//         total_moves += moves
// print(total_moves)
