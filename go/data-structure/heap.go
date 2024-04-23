package datastructure

import "math"

type Heap struct {
	arr  []int
	size int
}

func NewHeap() *Heap {
	return &Heap{arr: []int{}, size: 0}
}

func (h *Heap) getParentIndex(i int) int {
	return i / 2
}

func (h *Heap) getLeftChildIndex(i int) int {
	return 2 * i
}

func (h *Heap) getRightChildIndex(i int) int {
	return 2*i + 1
}

func (h *Heap) Size() int {
	return h.size
}

func (h *Heap) IsEmpty() bool {
	return h.size == 0
}

func (h *Heap) Heapfy(i int) {
	left := h.getLeftChildIndex(i)
	right := h.getRightChildIndex(i)
	largest := i

	if left < h.size && h.arr[left] > h.arr[i] {
		largest = left
	}

	if right < h.size && h.arr[right] > h.arr[largest] {
		largest = right
	}

	if i != largest {
		h.arr[i], h.arr[largest] = h.arr[largest], h.arr[i]
		h.Heapfy(largest)
	}
}

func (h *Heap) increaseKey(index int, newValue int) {
	h.arr[index] = newValue
	for index != 0 && h.arr[index] > h.arr[h.getParentIndex(index)] {
		h.arr[index], h.arr[h.getParentIndex(index)] = h.arr[h.getParentIndex(index)], h.arr[index]
		index = h.getParentIndex(index)
	}
}

func (h *Heap) Insert(i int) {
	h.arr = append(h.arr, i)
	h.size++
	currIndex := h.size

	if currIndex == 1 {
		return
	}

	for currIndex != 0 && h.arr[h.getParentIndex(currIndex)] < h.arr[currIndex] {
		h.arr[currIndex], h.arr[h.getParentIndex(currIndex)] = h.arr[h.getParentIndex(currIndex)], h.arr[currIndex]
		currIndex = h.getParentIndex(currIndex)
	}
}

func (h *Heap) Pop() int {
	if h.IsEmpty() {
		println("Heap is Empty")
		return math.MinInt
	}

	h.size--
	root := h.arr[0]
	h.arr[0] = h.arr[h.size-1]

	if !h.IsEmpty() {
		h.Heapfy(0)
	}

	return root
}

func (h *Heap) RemoveIndex(index int) {
	if index > h.size || index < 0 {
		println("Index Out Of Inbound")
		return
	}

	h.increaseKey(index, math.MaxInt)
	h.Pop()
}
