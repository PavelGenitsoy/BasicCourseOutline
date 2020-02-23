#include "pch.h"
#include <iostream>

enum {
	FIRST,
	SECOND,
	LAST
};

int main()
{	
	int array[2];
	int array3[2] {1,2};
	int array1[10]{ 1 };  //only 1 element is 1, another - 0
	// int mak[2]{};  all elements are 0
	// int array[] {1,2,3};  компилятор сам подберёт размер
	const int kArray[LAST]{54,55};

	std::cout << array[1] << std::endl; //если не инициализированы элемменты массива то выведит мусор (т.е. значение, той ячейки к которой обращаемся)
	std::cout << array3[1] << std::endl;
	std::cout << array1[1] << std::endl;
	std::cout << "//////////////////////////////" << std::endl;
	/*int i;
	if (i < LAST) {
		kArray[i]
	}*/

	char kArr[]{ "HELLOWORLD" }; //для массива символов размер не указуем (всегда размер = к-ство символов + 1 (скрытый 0-терминальной символ))
	// char kArr[]{'H','E'};   тут размер = к-ству символов

	// размер массива всегда задаём отдельной константой с размером size_t
	const size_t kSizeArray{ 3 };
	int Ark[kSizeArray]{ 1,2,3 };
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << Ark[i] << std::endl;
	}
	std::cout << "//////////////////////////////" << std::endl;

	int val{ 1 };
	std::cout << sizeof(val) << std::endl;
	std::cout << sizeof(Ark) << std::endl;  // размер будет 4 * 3 = 12  (количество выделяемой памяти)
	std::cout << sizeof(Ark)/sizeof(Ark[0]) << std::endl; // сам размер массива, т.е. именно сколько элементов в нём (ответ = 3)
	std::cout << "//////////////////////////////" << std::endl;

	for (auto i : Ark) {
		std::cout << i << std::endl;    // более упрощённая версия цыкла for
	}

	std::cout << kArr << std::endl; // символьные массив выводится изи
	std::cout << "//////////////////////////////" << std::endl;

	int vak{ 10 };
	int *vak_ptr; //обявляем некую переменную которая ссылается на чтото
	int *vaks_ptr = &vak; // указатель указывает на переменную интового типа (это типа помимо указателя на адресс)
	std::cout << &vak << " " << &vak_ptr << std::endl;
	std::cout << vak << " " << vak_ptr << std::endl;

	std::cout << &vak << " " << &vaks_ptr << std::endl;
	std::cout << vak << " " << vaks_ptr << std::endl;
	std::cout << "//////////////////////////////" << std::endl;

	*vaks_ptr = 100; // разименование, т.е. мы заменили значение той ячейки на адресс которой указывает указатель
	std::cout << vak << " " << *vaks_ptr << std::endl;
	/*
	// проверка валидности указателя
	int *var_ptr = nullptr;

	if (var_ptr != nullptr) {
		*var_ptr = 100;
	}
	*/
	double d{ 1.23 };
	//vaks_ptr = &d;    ошибка так как разные типы данных
	void* ptr=&d; // нетипизированный указатель, то есть он  банально хранит адресс переменной  (типа воид стирает типы данных)

	*(static_cast<double*>(ptr)) = 300; // разименование явной типизации
	std::cout << d << std::endl;
	/*
	*(static_cast<int*>(ptr)) = 100;     // здесь идёт повреждение ячейки памяти (double) ибо пытаемся представить его в виде инта
	std::cout << d << std::endl;
	*/
	return 0;
}
