#include "data_strictures"
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