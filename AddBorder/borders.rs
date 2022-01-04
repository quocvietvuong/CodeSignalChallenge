// Given a rectangular matrix of characters, add a border of asterisks(*) to it.
// Example
// For picture = ["abc", "ded"]
// The output should be
// solution(picture) = ["*****",
//                       "*abc*",
//                       "*ded*",
//                       "*****"]

fn solution(picture: Vec<String>) -> Vec<String> {
    let mut newvec = picture.clone();
    let len1 = picture[0].len() + 2;
    let len2 = picture[newvec.len() - 1].len() + 2;

    for i in 0..newvec.len() {
        newvec[i].insert(0, '*');
        newvec[i].push('*')
    }

    let mut v:Vec<char> = vec![];
    for _i in 0..len1 {
        v.push('*');
    }
    let s: String = v.into_iter().collect();
    newvec.insert(0, s);
    
    v = vec![];
    for _i in 0..len2 {
        v.push('*');
    }
    let s: String = v.into_iter().collect();
    newvec.push(s);
    return newvec;
}

fn main() {
    let picture: Vec<String> = vec!["some".to_string(), "long".to_string(), "list".to_string(), "of".to_string(), "strings".to_string()];
    let ret_vec: Vec<String>  = solution(picture);
    println!("in main: ");
    for x in ret_vec.iter() {
        println! ("{}", x);
    }
}