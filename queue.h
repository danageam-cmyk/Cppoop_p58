#pragma once
#include "linked_list.h"
template<typename T>
class Queue {
private:
	LinkedList<T>* queue;
public:
	void enqueuea(T data){
		queue->add(data);
	}
	T    dequeue() {
		if (queue->getSize() > 0) {
			return queue->remove(0);
		}
		else {
			return T(0);
		}
	}
	size_t getLenght() {
		return queue->getSize();
	}

	Queue() {
		queue = new LinkedList<T>();
	}

	Queue(Queue<T>& other) {
	///////
	}

	Queue(Queue<T>&& other) {
		this->queue = other->queue;
		other->queue = NULL;
	}

	~Queue() {
		if(queue) delete queue;
	}


};