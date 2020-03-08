#include "pch.h"
#include <iostream>
#include <functional>

using Comp = std::function<bool(int, int)>;  // главное чтобы функция соответсвувала сигнатуре. это некий контейнер для функции
bool More(int a, int b) { return a > b; }
bool Less(int a, int b) { return a < b; }  // бинарный предикат, т.к. передаем 2 значения
//как передать указатель на функцию??

// typedef bool(*Comp) (int, int);    //указатель на функцию который имеет такую сигнатуру typedef bool(*) (int, int)

// using Comp = bool(*) (int, int);  // comp является алиасом на указатель со следующией сигнатурой bool(*) (int, int)

void sort(int* begin, const int* end, Comp cmp)		// bool Comp (int,int) здесь написали имя которое характеризует функцию которую мы передали, 
																//	но нам надо передать указатель на функцию, либо же  bool (*Comp) (int,int) это уже указатель на функцию с некст сигнатурами bool возвращаемого предикат, int тоже ясно
																// begin we will be change
{																
	if (begin == nullptr || end == nullptr || begin == end)
	{
		return;
	}
	for (int* it_level1 = begin; it_level1 != end; ++it_level1) // банальный проход всех элементов(брутфорс)
	{
		for (int* it_level2 = it_level1 + 1; it_level2 != end; ++it_level2)
		{
			if (cmp (*it_level1,*it_level2))  // тут ииспользуется лямбда cmp
			{
				int tmp = *it_level1;
				*it_level1 = *it_level2;
				*it_level2 = tmp;
			}
		}
	}
}

bool Equal_45(int current)
{
	return current == 45;
}

bool is_even(int current)
{
	return current %2== 0;
}

using Comp_Find = bool(*)(int);
/*
bool find_first_of(int* begin, const int* end, int value, Comp_Find cmp)  // но вообще алгоритм find никогда не должен возвращать true или false
{
	if (begin == nullptr || end == nullptr || begin == end)
	{
		return false;
	}
	for (int* it_level1 = begin; it_level1 != end; ++it_level1)
	{
		if (cmp(*it_level1))
		{
			return true;
		}
		return false;
	}

}
*/
bool find_first_of(int* begin, const int* end, int value)  // но вообще алгоритм find никогда не должен возвращать true или false
{
	if (begin == nullptr || end == nullptr || begin == end)
	{
		return false;
	}
	for (int* it_level1 = begin; it_level1 != end; ++it_level1)
	{
		if (*it_level1 == 0)
		{
			return true;
		}
		return false;
	}

}

int main()
{
	const int kSize{ 6 };
	int array[kSize]{ 2,1,8,3,2,6 };
	// auto more = [](int a, int b) -> bool {return a > b; }; // auto вместо std::function<bool()>
	auto more = [](int a, int b) {return a > b; };  // так в новом стандарте (вовзврощаемый тип с лямбда автоматическии выводится)
	sort(array, array + kSize, more);   // начало обьявления лямбда [] (мы обьявляем неименованею функцию), т.е. как захват, а далее идёт сигнатура
	/*for(auto var : array)													// мы пишем обьявление в момент вызова функции (у нас нет имени этой функции). мы создаем функцию на месте
	{	
		std::cout << var << " ";
	}*/
	std::cout << more(10, 11) << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha;
	//std::cout << find_first_of(array, array + kSize, Equal_45) << std::endl;

	return 0;
}
