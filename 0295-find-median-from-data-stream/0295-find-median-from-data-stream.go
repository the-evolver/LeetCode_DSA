type Heap []int32

func (h Heap) Len() int            { return len(h) }
func (h Heap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *Heap) Push(x interface{}) { *h = append(*h, x.(int32)) }
func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MinHeap struct{ Heap }

func (h MinHeap) Less(i, j int) bool { return h.Heap[i] < h.Heap[j] }

type MaxHeap struct{ Heap }

func (h MaxHeap) Less(i, j int) bool { return h.Heap[i] > h.Heap[j] }

type MedianFinder struct {
	maxHeap   MaxHeap
	minHeap   MinHeap
	median    int32
	hasMedian bool
}

func Constructor() MedianFinder {
	return MedianFinder{
		maxHeap: MaxHeap{make(Heap, 0, 25000)},
		minHeap: MinHeap{make(Heap, 0, 25000)},
	}
}

func (m *MedianFinder) AddNum(num int) {
	num32 := int32(num)
	if !m.hasMedian {
		if m.maxHeap.Len() == 0 {
			m.median = num32
		} else {
			if num32 < m.maxHeap.Heap[0] {
				m.median = heap.Pop(&m.maxHeap).(int32)
				heap.Push(&m.maxHeap, num32)
			} else if num32 > m.minHeap.Heap[0] {
				m.median = heap.Pop(&m.minHeap).(int32)
				heap.Push(&m.minHeap, num32)
			} else {
				m.median = num32
			}
		}
	} else if num32 < m.median {
		heap.Push(&m.maxHeap, num32)
		heap.Push(&m.minHeap, m.median)
	} else {
		heap.Push(&m.maxHeap, m.median)
		heap.Push(&m.minHeap, num32)
	}
	m.hasMedian = !m.hasMedian
}

func (m *MedianFinder) FindMedian() float64 {
	if m.hasMedian {
		return float64(m.median)
	}
	return float64(m.maxHeap.Heap[0]+m.minHeap.Heap[0]) / 2
}