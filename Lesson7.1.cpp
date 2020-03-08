#include "pch.h"
#include <iostream>
#include <functional>

// typedef bool (*Comp) (int, int);

using Comp = std::function<bool(int, int)>;

void sort(int* begin, const int* const end, std::function<bool(int, int)> cmp) {
	if (begin == nullptr || end == nullptr || begin == end) {
		return;
	}
	for (int* it_level1 = begin; it_level1 != end; ++it_level1) {
		for (int* it_level2 = it_level1 + 1; it_level2 != end; ++it_level2) {
			if (cmp(*it_level1, *it_level2)) {
				int tmp = *it_level1;
				*it_level1 = *it_level2;
				*it_level2 = tmp;
			}
		}
	}
}

void sort(double* begin, const double* const end, std::function<bool(double, double)> cmp) {
	if (begin == nullptr || end == nullptr || begin == end) {
		return;
	}
	for (double* it_level1 = begin; it_level1 != end; ++it_level1) {
		for (double* it_level2 = it_level1 + 1; it_level2 != end; ++it_level2) {
			if (cmp(*it_level1, *it_level2)) {
				double tmp = *it_level1;
				*it_level1 = *it_level2;
				*it_level2 = tmp;
			}
		}
	}
}

bool Equal_45(int current) {
	return current == 45;
}

bool is_even(int current) {
	return current % 2 == 0;
}

using Comp_Find = std::function<bool(int)>;

bool find_fist_of(int* begin, const int* const end, Comp_Find cmp) {
	if (begin == nullptr || end == nullptr || begin == end) {
		return false;
	}
	for (int* it_level1 = begin; it_level1 != end; ++it_level1) {
		if (cmp(*it_level1)) {
			return true;
		}
	}
	return false;
}


int main(int argc, char const *argv[]) {
	const int kSize{ 6 };
	int array[kSize]{ 3, 2, 9, 3, 5, 7 };
	auto more = [](int a, int b) {
		return a < b;
	};

	sort(array, array + kSize, more);

	std::cout << more(10, 11) << std::endl;
	for (auto var : array) {
		std::cout << var << " ";
	}
	std::cout << std::endl;

	std::cout << std::boolalpha;

	// std::cout << find_fist_of(array, array + kSize, [](int a){return a % 2 == 0;});

	int find_value{};

	std::cin >> find_value;
																								// захват по значение (онли рид онли) и захват по ссылке
	std::cout << find_fist_of(array, array + kSize, [&find_value](int a) {							// [&find_value] - момент обьявления лямбда, (int a) - момент вызова функция
		find_value++;																				// дописали mutable ибо далее find_value была конст в теле функции			
		return a == find_value;
	});
	std::cout << std::endl;
	std::cout << find_value << std::endl;

	sort(array, array + kSize, more);

	double arraey_d[kSize]{ 3,2,9,3,5,7 };
	sort(arraey_d, arraey_d + kSize, more);   // статический полиморфизм

	return 0;
}