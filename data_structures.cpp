#include "data_structures.h"
#include "linked_list.h"
#include <iostream>
template <typename T>
void print(T arg) {
	std::cout << arg
		<< std::endl;
};

template <typename T>
struct fraction {
	T numerator;
	T denominator;
	void print() {
		std::cout
			<< numerator
			<< '/'
			<< denominator;
	}
	T get_numerator() {
		return numerator;
	}
	void set_numerator(T n) {
		numerator = n;
	}
};

void data_structures() {
	std::cout << "Data structur " << std::endl;
	LinkedList<int>* intList = new LinkedList<int>();
	intList->add(10);
	intList->add(20);
	intList->add(30);
	intList->print();
	intList->insertBefore(5, 0);
	intList->print();
	std::cout << "remove" << std::endl;
	intList->insertBefore(15, 2);
	intList->print();


}

	void data_structures_t() {
		std::cout << "Data structures and tempelates" << std::endl;
		print("Temprlate function demo");
		print(42);
		print(true);
		print('A');
		print<short>(42);

		fraction<int>f1{ 1,2 };
		fraction<float>f2{ 1.5,2.5 };
		fraction<short>f3{ 2 ,3 };
		f1.print(); std::cout << std::endl;
		f2.print(); std::cout << std::endl;
		f3.print(); std::cout << std::endl;
	};