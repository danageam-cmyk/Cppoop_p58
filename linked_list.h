#pragma once
#include <iostream>

template<typename T>
struct ListNode {
	T data;
	ListNode<T>* prev;
	ListNode<T>* next;
};

template<typename T>
class LinkedList {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last = NULL;
	size_t size = 0;
public:
	void add(T data);
	void insertBefore(T data, size_t index);
	size_t getSize() const { return size; }

	void print();
};

// #include "linked_list.cpp"
template<typename T>
void LinkedList<T>::add(T data) {
	if (last) {  //                           |попередній = last
		last->next = new ListNode<T>{ data, last, NULL };
		last = last->next;
	}
	else {
		first = new ListNode<T>{ data, NULL, NULL };
	}
	size += 1;
}

template<typename T>
void LinkedList<T>::insertBefore(T data, size_t index) {
	if (index == 0) {
		if (first) {
			first->prev = new ListNode<T>{ data, NULL, NULL };
			size += 1;
		}
		else {
			add(data);
		}
	}

	else {
		if (index < size) {
			ListNode<T>* node = first;
			for (size_t i = 0; i < index - 1; ++i) {
				first = first->next;
				if (first) {
					first->prev = NULL;
				}
				delete node;
				size -= 1;
				return data;
				if (size == 0) {
					last == NULL;
				}
			}
			else if (index == size - 1) {
			ListNode<T>* node = last;
			last = last->prev;
			last->next = NULL;
			delete node;
			size -= 1;
			return data;
			}
			else {
			// to do
			}
		}
		else {
			// error
		}
	}

}

template<typename T>
void LinkedList<T>::print() {
	ListNode<T>* node = first;
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

/*
	node
0<-[p|d|n]<->[p|d|n]->0
*/