#include "pch.h"
#include <iostream>
/*
bool swap(int *const value1, int *const value2)
{
	if (value2 == nullptr || value1 == nullptr || value1 == value2)
	{
		return false;
	}
	int tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
	return true;
}
*/
/*
bool swap(int const value1, int const value2)   // указания конст является излишним при передачи по значению
{
	int tmp = value1;
	value1 = value2;
	value2 = tmp;
	return true;
}
*/
const size_t kSize{ 5 };
void print_array(int *array, const size_t size)  // int array[] указания размерности массива компилятором игнорируется (т.е. если будем вне указывать размер и передавать его в функцию то ничего не изменится)
{
	for (size_t i{ 0 }; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
void print(const int *begin, const int *const end)
{
	if (begin == nullptr) //бегин  ибо мы его разыменовуем далее
	{
		return;
	}
	while (begin != end)
	{
		std::cout << *begin++ << " ";
	}
	std::cout << std::endl;
}

void printt(const char *begin)
{
	if (begin == nullptr) //бегин  ибо мы его разыменовуем далее
	{
		return;
	}
	while (*begin != '\0')
	{
		std::cout << *begin++ << " ";
	}
	std::cout << std::endl;
}
/*
void print_size(int array [])
{
	std::cout << sizeof(array) / sizeof(array[0]) << std::endl; // отношение размера указателя к размеру типа
}
*/
/*
void promt()
{
	char begin[13]{};
	std::cin >> begin;
	size_t size = strlen(begin);

	if (size >= 13)
	{
		return;
	}
	std::cout << begin << std::endl;
}
*/

void promtt(int *val1, int *val2)
{
	if (val1 == nullptr || val2 == nullptr)  //  напрягает постоянная проверка валидности
	{
		std::cout << "Invalid\n";
		return;
	}
	std::cout << "Enter values " << std::endl;
	std::cin >> *val1 >> *val2;  //  напрягает постоянное разыменование
}
// перепишем 

void promttt(int &val1, int &val2)
{
	std::cout << "Enter values " << std::endl;
	std::cin >> val1 >> val2;  
}

char* prom()
{
	char ar[100]{};  
	std::cin >> ar;
	return ar;
}
/*
int& f1()
{
	int v{};
	std::cin >> v;
	return v;   // висячая ссылка (т.е. мы пытаемся вернуть ссылку на переменную которой уже нету. это ub)
}
*/

/*
void f2(int(&ar)[5])
{

}*/

void f2(int (&ar) [kSize])
{
	 
}

void f3(int a, int b=10, int c = 30)  // аргументы по уммолчанию / опциональные аргументы / дефолтное значение пропускать можно если (указываем значения справа налево)
{										// с nullptr инициализируем ток указатели  (это опциональные аргументы)
	std::cout << a << " " << b << std::endl;
}
// (void) v;  подавление того что компилятор говорит что мы не используем эту переменную
// [maybe_unused];

size_t IncDecOddEven(size_t value) {
	/*if (value % 2 != 0)
	{
		return value + 1;
	}
	return value - 1;*/
	return (value & 2 != 0) ? value + 1 : value - 1; // тернарный оператор
}

int main()
{
	//int value1, value2;

	//swap(&value1, &value2);
	//std::cout << value1 << " " << value2 << std::endl;
	
	int array[kSize] { 1,2,3,4,5 };
	print_array(array, kSize);
	std::cout << "//////////////////////////////" << std::endl;
	
	print(array, array + kSize);

	std::cout << "//////////////////////////////" << std::endl;
	
	char arr[]{ "Hello" };
	printt(arr);
	std::cout << strlen(arr) << std::endl;
	char arr_copy[7]{};

	strcpy_s(arr_copy, arr);
	std::cout << arr_copy << std::endl;
	//strcmp(); сравнения 2-ух строк
	std::cout << "//////////////////////////////" << std::endl;

	int array2[kSize]{ 1,2,3,4,5 };
	int array3[kSize]{};
	memcpy(array3, array2, sizeof(int)*kSize); // теперь так проще намного и выгоднее копировать массив и вывод далее
	for (auto var: array3)
	{
		std::cout << var << " ";
	}
	std::cout << std::endl;
	std::cout << "//////////////////////////////" << std::endl;
	//promt();
	//promtt(&val1,ptr); левое закидуем
	int val1{100}, val2;
	int &ref = val1; //ссылка на вал1 , как будто мы сразу напрямую работаем с ней (ссылка это обьект на который она ссылается, а указатель указывает на этот обьект(т.е. адресс его) для работы с обьектом нужно разыменовать его для начала, а с ссылкой не надо)
	int *const ptr = &val1;

	std::cout << sizeof(ref) << " " << sizeof(ptr) << std::endl; //  выводить 4(размер  инта т.к. при ссылке мы как бы работаем сразу с переменной) и может 4 или 8 (размер указателя на неких платформах)
	std::cout <<ref << " " << ptr << std::endl;

	ref = 300;  // по сути тут одно и тоже. ссылку нельзя обьявить в начале, а инициализировать потом как с указателем. сразу инициализировать
	*ptr = 400; //

	promttt(val1, val2);
	std::cout << val1 << " " << val2 << std::endl;
	std::cout << "//////////////////////////////" << std::endl;

	int ar[5];
	f2(ar);
	//int ar1[6];
	//f2(ar1);  error при значение 5

	f3(val1);

	std::cout << IncDecOddEven(val1) << std::endl;


	return 0;
}