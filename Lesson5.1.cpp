#include "pch.h"
#include <iostream>

void calc(int val, double val1)  // каждый аргумент функции должен иметь тип (можно и auto  но это чисто расширение компилятора, стандарт не пропускает такое)
{
	std::cout << val << " " << val1 << std::endl;
}
//[[nodiscard]] // заставить человека обработать ввод. она влияет на вызываемую функцию(то что в мейне)
long long calc1(int val, double val1, bool mult) // тут(в скобах)  формальные параметры
{
	std::cout << val << " " << val1 << std::endl;
	if (mult) {
		return val + val1;   // наш return должно соответствовать или быть типом приводимым к (в данном случае) long  long . если неявное привидение типов то разрешается
	}
	return val + val1;  // фактические параметры
}
/*
auto calc1(int val, int val1, bool mult)
{
	std::cout << val << " " << val1 << std::endl;
	if (mult) {
		return val * val1; 
	}
	double val2{2.0345};
	return val + val2; // здесь инициализация происходит в return (т.е. шо получим тот тип и присвоется auto). но тут ошибка ибо в 2 разных return выводятся 2 разных типа 
}
*/

long long calc2(int val, int val1, bool mult)
{
	val = 100 ;
	std::cout << val << " " << val1 << std::endl;
	if (mult) {
		return val * val1;
	}
	return 0;
}

double promt(int *val, int *val1)
{
	if (val == nullptr || val1 == nullptr)
	{
		std::cout << "Invalid arguments\n";
		return;
	}
	std::cout << "Enter values: " << std::endl;
	std::cin >> *val >> *val1;
}

int main()
{
	int value{ 10 };
	int* ptr = &value;
	*ptr = 100;
	const int kValue{ 100 };
	const int *ptr_c = &kValue; // если ссылатся будем на константный инт то надо указать это
	// int const *ptr_c = &kValue; также можно
	const int kValue1{ 120 };
	ptr_c = &kValue1; // теперь указывает на другую константу

	//const int * const ptr_c = &kValue1;  // константный указатель на константный инт

	//int * const ptr_c = &value; // сам указатель менять не можем но через разыменование можем изменять значение ячейки куда он указывает
	//*ptr_c = 100;
	std::cout << "//////////////////////////////" << std::endl;

	int array[5];
	array[1] = 100;

	int *ptrk = array;  // произойдёт неявное преобразование массива (запишет адресс на 1 элемент этого массива)
	std::cout << ptrk << " " << &array << std::endl;

	int *ptr_4 = &array[4];
	//int *ptr_1 = &array[0];
	if (ptrk != ptr_4)
	{
		std::cout << "yes\n";
	}
	std::cout << "//////////////////////////////" << std::endl;
	/*
	int v_1;
	int v_2;

	int *ptrl_1 = &v_1;
	int *ptrl_2 = &v_1;

	if (ptrl_1 < ptrl_2)  // оператор сравнения для указателей
	{

	}*/

	int arr[5]{ 1,2,3,4,5 };
	int *ptrl_3 = arr;
	std::cout << *ptrl_3 << std::endl;
	++arr[0];
	++ptrl_3;
	std::cout << *ptrl_3 << std::endl;

	ptrl_3 += 2; //смещение на (инт (4 байта)) умножить на 2 || но для нас это просто смещение на 2 (т.е. тут указатель на ячейку со значением 4)
	std::cout << *ptrl_3 << std::endl;
	std::cout << "//////////////////////////////" << std::endl;

	int arr1[5]{ 1,2,3,4,5 };
	const int *begin = arr1; //указатель на 1 элемент (т.е. индекс нулевой)
	const int * const end = arr1 + 5; // указатель на ласт + 1 элемент || записать в ту ячейку или прочитать нельзя (это свойство называется undefined behavior) 
						 // сделаем константный энд на константный инт (т.к. он не меняется)
						 // сделаем указатель бегин на константный инт так как бегин меняет адресс (на некст ячейки)
	while (begin != end)
	{
		std::cout << *begin++ << std::endl;
		// ++begin;
	}
	std::cout << "//////////////////////////////" << std::endl;
	/*
	char arr2[]{ "Hello World" };
	const char* begin = arr2;
	while (*begin)  // нультерминальный символ рассматривается как false в цыкле
	{
		std::cout << *begin++ << std::endl;
	}*/
	std::cout << "//////////////////////////////" << std::endl;

	int arr3[] = { 1 , 2 , 3 };
	std::cout << *(arr3 + 2) << std::endl; // дай мне элемент массива arr3 смещённого на 2
	std::cout << "//////////////////////////////" << std::endl;
	int val{ 10 }, val1{ 100 };

	calc(val, val1);
	std::cout << "//////////////////////////////" << std::endl;
	std::cout << calc1(val, val1, true)<<std::endl;
	std::cout << "//////////////////////////////" << std::endl;
	std::cout << calc2(val, val1, true) << std::endl;
	std::cout << val << std::endl;
	std::cout << "//////////////////////////////" << std::endl;
	/*
	int val, val1;
	promt(&val, &val1);  // вводим и выводим
	*/
	//int *ptr = nullptr;
	//*ptr = 100;  записываем чтото не зная куда, т.е. тут UB

	//promt(nullptr, nullptr);  nullptr можем указывать тогда когда некоторые параметры не нужны
	// любая функция принимающая указатели, то нужна их проверять на валидность (т.е. сравниваем с nullptr)
	return 0;
}
