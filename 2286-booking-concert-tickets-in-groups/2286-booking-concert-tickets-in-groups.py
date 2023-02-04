class SegmentTree():
    #construct a segment tree
    #l,r denote the range [l,r], both inclusive
    def __init__(self, l, r):
        mid = (l + r) // 2
        self.l = l
        self.r = r
        self.left, self.right = None, None
        self.max = 0
        self.sums = 0
        if l != r:
            self.left = SegmentTree(l, mid)
            self.right = SegmentTree(mid + 1, r)
    
    #update the value(the number of unreserved seats) at index(row) i to val
    def update(self, i, val):
        if self.l == i == self.r:
            self.max = val
            self.sums = val
            return val, val
        mid = (self.l + self.r)//2
        if self.l <= i <= mid:
            left_max, left_sums = self.left.update(i, val)
            self.max, self.sums = max(left_max, self.right.max), left_sums + self.right.sums
        else:
            right_max, right_sums = self.right.update(i, val)
            self.max, self.sums = max(self.left.max, right_max), self.left.sums + right_sums
        return self.max, self.sums

    #return the max and sum of unreserved seats in rows in range [l,r]
    def query(self, l, r):
        if r < self.l or self.r < l:
            return 0, 0
        elif l <= self.l and self.r <= r:
            return self.max, self.sums
        else:
            left_max, left_sums = self.left.query(l,r)
            right_max, right_sums = self.right.query(l,r)
            return max(left_max, right_max), left_sums + right_sums

    #return the smallest row index that has unreserved seats greater than or equal to k
    def queryLowestGreaterEqual(self, k):
        if self.max < k:
            return -1
        if self.l == self.r:
            return -1 if self.max < k else self.l
        if self.left.max >= k:
            return self.left.queryLowestGreaterEqual(k)
        return self.right.queryLowestGreaterEqual(k)


class BookMyShow:

    def __init__(self, n: int, m: int):
        self.st = SegmentTree(0,n-1)
        for i in range(n):
            self.st.update(i, m)
        self.m = m
        #beginning row to check scatter reservation, that is, the rows with index less than self.scatter_row already become full
        self.scatter_row = 0 
        self.n = n


    def gather(self, k: int, maxRow: int):
        i = self.st.queryLowestGreaterEqual(k)
        if i < 0 or i > maxRow:
            return []
        v, _ = self.st.query(i,i)
        self.st.update(i, v-k)
        return [i,self.m-v]

    def scatter(self, k: int, maxRow: int):
        if self.st.query(0, maxRow)[1] >= k:
            while self.scatter_row <self.n and k>0:
                v, _ = self.st.query(self.scatter_row, self.scatter_row)
                self.st.update(self.scatter_row, v-min(v,k))
                if v > k:
                    #k = 0
                    break
                else:
                    k -= v
                    self.scatter_row += 1
            return True
        return False
# Your BookMyShow object will be instantiated and called as such:
# obj = BookMyShow(n, m)
# param_1 = obj.gather(k,maxRow)
# param_2 = obj.scatter(k,maxRow)