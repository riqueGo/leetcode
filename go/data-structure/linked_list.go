package datastructure

type Node struct {
	Value interface{}
	Next  *Node
}

type LinkedList struct {
	head *Node
	tail *Node
}

func NewNode(value interface{}) *Node {
	return &Node{Value: value}
}

func NewLinkedList() *LinkedList {
	return &LinkedList{head: NewNode(nil)}
}

func (l *LinkedList) IsEmpty() bool {
	return l.head == nil
}

func (l *LinkedList) Insert(value interface{}) {
	node := NewNode(value)

	if l.IsEmpty() {
		l.head = node
	} else {
		l.tail.Next = node
	}
	l.tail = node
}
