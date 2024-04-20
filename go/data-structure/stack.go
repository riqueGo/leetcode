package datastructure

import (
	"errors"
	"fmt"
)

type StackNode struct {
	Value interface{}
	Next  *StackNode
}

type Stack struct {
	dummyNode *StackNode
	Lenght    int
}

func NewStackNode(value interface{}) *StackNode {
	return &StackNode{Value: value}
}

func NewStack() *Stack {
	return &Stack{Lenght: 0, dummyNode: NewStackNode(nil)}
}

func (s *Stack) IsEmpty() bool {
	return s.dummyNode.Next == nil
}

func (s *Stack) Peek() interface{} {
	return s.dummyNode.Next.Value
}

func (s *Stack) Push(value interface{}) {
	stackNode := NewStackNode(value)
	if s.IsEmpty() {
		s.dummyNode.Next = stackNode
	} else {
		stackNode.Next = s.dummyNode.Next
		s.dummyNode.Next = stackNode
	}
	s.Lenght++
}

func (s *Stack) Pop() interface{} {
	if s.IsEmpty() {
		errors.New("stack is Empty")
	}

	popStackNode := s.dummyNode.Next
	s.dummyNode.Next = s.dummyNode.Next.Next
	s.Lenght--
	return popStackNode.Value
}

func (s *Stack) Print() {
	current := s.dummyNode.Next
	stack := "-"

	for current != nil {
		stack += fmt.Sprintf(" %v -", current.Value)
		current = current.Next
	}
	println(stack)
}
