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
	top    *StackNode
	Lenght int
}

func NewStackNode(value interface{}) *StackNode {
	return &StackNode{Value: value}
}

func NewStack() *Stack {
	return &Stack{Lenght: 0, top: NewStackNode(nil)}
}

func (s *Stack) IsEmpty() bool {
	return s.top == nil
}

func (s *Stack) Peek() interface{} {
	return s.top.Value
}

func (s *Stack) Push(value interface{}) {
	stackNode := NewStackNode(value)
	if !s.IsEmpty() {
		stackNode.Next = s.top
	}
	s.top = stackNode
	s.Lenght++
}

func (s *Stack) Pop() interface{} {
	if s.IsEmpty() {
		errors.New("stack is Empty")
	}

	popStackNode := s.top
	s.top = s.top.Next
	s.Lenght--
	return popStackNode.Value
}

func (s *Stack) Print() {
	current := s.top
	stack := "-"

	for current != nil {
		stack += fmt.Sprintf(" %v -", current.Value)
		current = current.Next
	}
	println(stack)
}
