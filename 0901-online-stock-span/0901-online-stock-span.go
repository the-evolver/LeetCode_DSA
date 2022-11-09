type StockSpanner struct {
    nodes []int
}


func Constructor() StockSpanner {
    return StockSpanner{
        nodes: make([]int,0),
    }
}


func (this *StockSpanner) Next(price int) int {
    this.nodes = append(this.nodes, price)
    counter := 1
    for i:=0;i<len(this.nodes)-1;i++{
        if this.nodes[i] > price {
            counter = 1
        } else {
            counter++
        }
    }
    return counter
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */