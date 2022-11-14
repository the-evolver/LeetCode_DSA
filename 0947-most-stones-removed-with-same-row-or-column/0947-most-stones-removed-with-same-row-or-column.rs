use std::collections::VecDeque;

impl Solution {
    pub fn remove_stones(mut stones: Vec<Vec<i32>>) -> i32 {
        let mut rez = 0;
        while !stones.is_empty() {
            let mut q = VecDeque::new();
            q.push_front(stones.pop().unwrap());

            while let Some(s) = q.pop_back() {
                // q.extend(stones.drain_filter(|s_| s[0] == s_[0] || s[1] == s_[1]));
                let mut i = 0;
                while i < stones.len() {
                    if s[0] == stones[i][0] || s[1] == stones[i][1] {
                        q.push_front(stones.remove(i));
                        rez += 1;
                    } else {
                        i += 1;
                    }
                }
            }
        }

        rez
    }
}