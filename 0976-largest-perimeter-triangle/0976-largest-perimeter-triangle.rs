impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        let mut heap = std::collections::BinaryHeap::from(nums);
        let (mut b, mut c) = (-1, -1);
        while let Some(a) = heap.pop() {
            if a > 0 && b > 0 && c > 0 && c < b + a {
                return a + b + c;
            }
            c = b;
            b = a;
        }
        0
    }
}