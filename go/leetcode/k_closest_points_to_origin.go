package leetcode

type HeapNodeClosestPoint struct {
	Pair     []int
	Distance int
}

type HeapClosestPoint struct {
	arr      []HeapNodeClosestPoint
	maxSize  int
	heapSize int
}

func NewHeapNodeClosestPoint(pair []int) *HeapNodeClosestPoint {
	distance := calculateDistanceToOrigin(pair)
	return &HeapNodeClosestPoint{Pair: pair, Distance: distance}
}

func calculateDistanceToOrigin(pair []int) int {
	x := pair[0] * pair[0]
	y := pair[1] * pair[1]
	return x + y //do not need square root, this is enought to say if this point is more or less distant from origin
}

func NewHeapClosestPoint(maxSize int) *HeapClosestPoint {
	return &HeapClosestPoint{arr: make([]HeapNodeClosestPoint, maxSize), maxSize: maxSize, heapSize: 0}
}

func (h *HeapClosestPoint) getParent(i int) int {
	return i / 2
}

func (h *HeapClosestPoint) getLeftChild(i int) int {
	return 2 * i
}

func (h *HeapClosestPoint) getRightChild(i int) int {
	return 2*i + 1
}

func (h *HeapClosestPoint) Insert(pair []int) {
	node := NewHeapNodeClosestPoint(pair)

	if h.heapSize >= h.maxSize && node.Distance < h.arr[0].Distance {
		h.heapSize--
		h.Pop()
	} else if h.heapSize >= h.maxSize {
		return
	}

	i := h.heapSize
	h.arr[i] = *node
	h.heapSize++

	for i != 0 {
		parent := h.getParent(i)
		if h.arr[i].Distance > h.arr[parent].Distance {
			h.arr[i], h.arr[parent] = h.arr[parent], h.arr[i]
		}
		i = parent
	}
}

func (h *HeapClosestPoint) Heapfy(i int) {
	left := h.getLeftChild(i)
	right := h.getRightChild(i)
	largest := i

	if left < h.heapSize && h.arr[i].Distance < h.arr[left].Distance {
		largest = left
	}
	if right < h.heapSize && h.arr[largest].Distance < h.arr[right].Distance {
		largest = right
	}
	if largest != i {
		h.arr[i], h.arr[largest] = h.arr[largest], h.arr[i]
		h.Heapfy(largest)
	}
}

func (h *HeapClosestPoint) Pop() []int {
	root := h.arr[0]
	h.arr[0] = h.arr[h.heapSize]
	h.Heapfy(0)
	return root.Pair
}

func (h *HeapClosestPoint) GetAllPoints() [][]int {
	var points [][]int

	for _, node := range h.arr {
		points = append(points, node.Pair)
	}

	return points
}

func kClosest(points [][]int, k int) [][]int {
	if k == len(points) {
		return points
	}

	heap := NewHeapClosestPoint(k)

	for _, point := range points {
		heap.Insert(point)
	}

	return heap.GetAllPoints()
}
