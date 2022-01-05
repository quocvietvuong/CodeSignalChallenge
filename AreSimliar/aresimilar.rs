// Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

// Given two arrays a and b, check whether they are similar.

// For a = [1, 2, 3] and b = [1, 2, 3], the output should be
// solution(a, b) = true.

// For a = [1, 2, 3] and b = [2, 1, 3], the output should be
// solution(a, b) = true.
// We can obtain b from a by swapping 2 and 1 in b.

// For a = [1, 2, 2] and b = [2, 1, 1], the output should be
// solution(a, b) = false.

// Any swap of any two elements either in a or in b won't make a and b equal.

fn solution(a: Vec<i32>, b: Vec<i32>) -> bool {
    if a.len() != b.len() {
        return false;
    }
    let mut count:i32 = 0;
    let mut pos_a:Vec<i32> = [].to_vec();
    for i in 0..a.len() {
        if a[i] != b[i] {
            count = count + 1;
            pos_a.push(i as i32);
        }
    }
    if count == 0 {
        return true;
    }
    if count == 2 {
        if (a[pos_a[0] as usize] == b[pos_a[1] as usize]) && (a[pos_a[1] as usize] == b[pos_a[0] as usize]) {
            return true;
        }
        return false;
    }
    else {
        return false;
    }
}


fn main() {
    let a: Vec<i32> = [2, 3, 1].to_vec();
    let b: Vec<i32> = [1, 3, 2].to_vec();
    println!("{}", solution(a,b));
}
