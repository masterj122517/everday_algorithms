package main

import (
	"fmt"
)

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head *Node
}

func createLinkedList() *LinkedList {
	return &LinkedList{head: nil}
}

func push_front(list *LinkedList, val int) {
	new_Node := &Node{value: val}
	new_Node.next = list.head
	list.head = new_Node
}
func push_backward(list *LinkedList, val int) {
	new_Node := &Node{value: val}
	new_Node.next = nil
	if list.head == nil {
		list.head = new_Node
	} else {
		current := list.head
		for current.next != nil {
			current = current.next
		}
		current.next = new_Node
	}
}
func peak(list *LinkedList) int {
	if list.head == nil {
		fmt.Println("The list is empty\n")
		return -1
	}
	return list.head.value
}
func pop_front(list *LinkedList) int {
	if list.head == nil {
		fmt.Println("The list is empty")
		return -1
	} else {
		temp := list.head
		val := temp.value
		list.head = temp.next // go 不需要你手动释放内存，但是记得把“头”传下去
		return val
	}
}

func pop_backward(list *LinkedList) int {
	if list.head == nil {
		fmt.Println("this list is empty")
		return -1
	}
	if list.head.next == nil {
		val := list.head.value
		list.head = nil
		return val
	}
	prev := list.head
	current := list.head.next
	for current.next != nil {
		prev = current
		current = current.next
	}
	val := current.value
	prev.next = nil
	return val
}

func main() {
	var list *LinkedList
	list = createLinkedList()
	push_front(list, 30)
	push_front(list, 20)
	push_front(list, 10)
	fmt.Println("peak: ", peak(list))
	fmt.Println("pop front ", pop_front(list))
	fmt.Println("pop front ", pop_front(list))
	fmt.Println("pop front ", pop_front(list))
}
