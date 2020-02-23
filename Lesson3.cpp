#include "pch.h"
#include <iostream>
#include <bitset>

int main()
{
	
	int value{ 10 };
	int value2{ 20 };
	std::cout << std::boolalpha;
	bool is_state = (value == value2);
	std::cout << is_state << std::endl;
	is_state = (value != value2);
	std::cout << is_state << std::endl;
	is_state = (value >= value2);
	std::cout << is_state << std::endl;
	std::cout << "//////////////////////////////////////" << std::endl;
	int a = 41;
	// проверка диапазона (20, 40] 
	bool is_access = a > 20 && a <= 40;
	std::cout << is_access << std::endl;

	is_access = a == 20 || a == 41;
	std::cout << is_access << std::endl;

	is_access = !(a == 20 || a == 41);
	std::cout << is_access << std::endl;
	std::cout << "//////////////////////////////////////" << std::endl;
	std::bitset<8> bit{ 126 }; // 8 - сколько бит всего
	std::cout << bit.to_string('X') << std::endl;
	bit.set(2, false); // 2 - это 3-тий бит который сбрасываем (3 ибо отсчёт от 0)
	std::cout << bit.to_string('X') << std::endl;
	std::cout << bit.count() << std::endl;
	std::cout << "//////////////////////////////////////" << std::endl;
	std::cout << (value & 1) << std::endl;
	auto value1{ 123456 };
	std::cout << value1 % 10 << std::endl; // при 100 то ласт 2 цифры
	std::cout << "//////////////////////////////////////" << std::endl;

	const long long kMax = std::numeric_limits<int>::max();
	int k;
	std::cin >> k;
	/*if (a <= max)
	{											// но так не надо делать  (точка 1 входа (так называется))
		int b;
		std::cin >> b;
		if (b <= max)
		{
			int c;
			std::cin >> c;
			if (c <= max)
			{
				auto D = a * b*c;
				std::cout << D << std::endl;
			}
			else {
				std::cout << "Error c";
			}
		}
		else {
			std::cout << "Error b";
		}
	}
	else {
		std::cout << "Error a";
	}
	*/
	if (k > kMax) {
		std::cout << "Error k" << std::endl;
		return 0;
	}
	int b;
	std::cin >> b;
	if (b > kMax) {
		std::cout << "Error b" << std::endl;
		return 0;
	}
	auto D = k * b;
	std::cout << D << std::endl;
	std::cout << "//////////////////////////////////////" << std::endl;
	
	enum {
		FIRST=1, // по умолчанию =0 (даже не пишут чему равно)
		SECOND,
		UNDEFINED  // вместо default в свитче
	};
	/*
	enum {
		A = 'A',
		B,
		C
	};
	enum {
		FIRST_BIT = 1LL << 0;
		SECOND_BIT = 1LL << 1;       // 0001  -->  0010   , сдвиг влево 
	};
	*/
	//case 1 .. 10     // так тоже можно
	

	int v_1;
	std::cin >> v_1;

	switch (v_1)
	{
	case FIRST:
		std::cout << "1" << std::endl;
		break;   // если break не будет то произойдёт провал, т.е. пойдёт дальше пока не найдёт некст break (вместо break можно юзать return)
	case SECOND:
		std::cout << "2" << std::endl;
		break;
	case UNDEFINED:
		std::cout << "UNDEFINED" << std::endl;
		break;
	default:
		std::cout << "not match" << std::endl;
	}
	std::cout << "//////////////////////////////////////" << std::endl;

	int bro;
	std::cin >> bro;
	for (size_t i = 0; i < bro; i++)  // size_t максимальный размер на любой платформе (для предотвращения переполнения)
	{
		std::cout << "before check\n";
	}
	std::cout << "//////////////////////////////////////" << std::endl;

	int rab{ 123456 };
	for (auto rab_copy{ rab }; rab_copy >0 ; rab_copy/=10)
	{
		if (((rab_copy % 10) % 2) == 0)
		{
			std::cout << "even" << std::endl;
		}
		else {
			std::cout << "odd" << std::endl;
		}
	}
	std::cout << "//////////////////////////////////////" << std::endl;



	return 0;
}
