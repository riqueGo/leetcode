package leetcode

type MyQueue struct {
	Stack1 Stack
	Stack2 Stack
}

func Constructor() MyQueue {
	return MyQueue{}
}

func (this *MyQueue) Push(x int) {
	this.Stack1.Push(x)
}

func (this *MyQueue) Pop() int {
	if this.Stack2.IsEmpty() {
		this.fillStack2()
	}
	return this.Stack2.Pop()
}

func (this *MyQueue) Peek() int {
	if this.Stack2.IsEmpty() {
		this.fillStack2()
	}
	return this.Stack2.Top()
}

func (this *MyQueue) Empty() bool {
	return this.Stack1.IsEmpty() && this.Stack2.IsEmpty()
}

func (this *MyQueue) fillStack2() {
	for !this.Stack1.IsEmpty() {
		this.Stack2.Push(this.Stack1.Pop())
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
