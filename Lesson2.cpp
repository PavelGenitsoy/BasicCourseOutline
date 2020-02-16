#include "pch.h"
#include <iostream>

//typedef unsigned long long my_time_t   называют алиасами   
//using my_time_t = unsigned long long;
int main()
{	
	size_t start;  //всегда для задания размера последовательности
	int a; // на самом деле это signed int ~32 bit, т.е. ключевое слово signed можно опускать
	short b; // ~16 bit
	// signed short int b; это идентичная обьявление как и выше, только можно опускать ключевые слова signed и int
	long c; // ~32-64 bit
	// signed long int c; это идентичная обьявление как и выше, только можно опускать ключевые слова signed и int
	unsigned int d; // это беззнаковое целое ~32, как видно чтобы создать беззнаковое значение нужно указать unsigned
	unsigned short e; // беззнаковое короткое целое ~16
	// unsigned short int e; это идентичная обьявление как и выше, только можно опустить ключевое слово int
	unsigned long f; // беззнаковое длиное целое ~32-64, 
	// unsigned long  int f; это идентичная обьявление как и выше, только можно опустить ключевое слово int
	long long g;
	char ch;
	int32_t value;
	uint32_t value1; // беззнаковое
	float pl1;
	double pl2;
	long double pl3;
	//uint32_t v1 = std::numeric_limits<uint32_t>::max();
	//uint16_t v2 {v1}; // универсальная инициализация
	uint16_t c1{ 20 };
	//uint8_t c2 = (uint8_t)c1; //сишный каст
	uint8_t c2 = static_cast<uint8_t>(c1); // явный каст,явно преобразувем 1 тип к другому 
	std::cout << ((int)c2) << std::endl;
	std::cout << "///////////////////" << std::endl;
	double g1;
	auto g1_ = g1;
	decltype(g1_) new_; // инициализиурет новую переменную с типом таким же что и у g1_
	auto cc{ 1. }; // литерал вещественный
	std::cout << sizeof(value) << std::endl;
	std::cout << sizeof(value1) << std::endl;
	std::cout << std::numeric_limits<uint32_t>::max() << std::endl;
	std::cout << "///////////////////" << std::endl;
	std::cout << sizeof(a) << std::endl;
	std::cout << sizeof(b) << std::endl;
	std::cout << sizeof(c) << std::endl;
	std::cout << sizeof(g) << std::endl;
	std::cout << sizeof(ch) << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << (int)std::numeric_limits<char>::max() << std::endl;
	std::cout << (int)std::numeric_limits<char>::min() << std::endl;

	return 0;
}
