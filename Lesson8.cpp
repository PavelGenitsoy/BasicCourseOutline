#include "pch.h"
#include <iostream>

struct People
{
	int age = 10;
	const char* name = "Ekar";
	size_t id = 100;
};

struct LeadEnge
{
	People p{12,"Vooi test", 000};
	const char* depar;
};

const size_t kCountEmploy{ 100 };
struct Company
{
	LeadEnge test[kCountEmploy];
};

struct pair
{
	bool status;
	size_t res;
};

pair divide(int a, int b)
{
	if (b == 0)
	{
		return { false, 0 };
	}
	return { true,static_cast<size_t>(a) / b };
}

struct Point
{
	int x;
	int y;
	int z;
};

void move_object(Point point)
{

}

enum Error {
	kok = 1,
	ErrorRegenerate	
};

Error connect()
{
	return Error::ErrorRegenerate;
}

enum class Error1
{
	kok =0
};

void case_(Error er)
{

}


int main()
{
	People p;  // создаю обьект п, по факту как ещё 3 переменные что в пипле

	p.age = 10;
	p.id = 100;
	p.name = "Ivo Bobul";

	std::cout << p.age<< p.id<< p.name << std::endl;
	// либо так инициализируем
	People p1{ 12,"Vooi Bobul", 101 };
	std::cout << p1.age << p1.id << p1.name << std::endl;

	People p2{};
	std::cout << p2.age << p2.id << p2.name << std::endl;

	LeadEnge l;
	l.depar = "Automatic";
	l.p.age = 25;
	l.p.id = 150;

	LeadEnge l1{ {12,"Vooi Bobul", 101},"automatic" };
	std::cout << l.p.age << l.p.id << l.p.name << l.depar << std::endl;

	Company company;
	company.test[0].p.age = 100;
	///////////////////////////
	People p3;
	LeadEnge l2{ p3,"test1" };
	Company company1{ {l2} };
	///////////////////////////

	auto pr = divide(10, 5);
	if (pr.status)
	{
		std::cout << pr.res << std::endl;
	}

	Point p4{ 1,10,100 };
	move_object(p4);
	/////////////////////////
	/*
	auto [status_div, res_div] = divide(10, 10);
	if (status_div)
	{
		std::cout << res_div << std::endl;
	}
	*/
	//////////////////////////
	//if (auto[status_div, res_div] = divide(10, 10); status_div)           с 17 стандарта
	/////////////////////////

	People d{ 100,"Test",10 };
	People* ptr = &p;
	// обращение к полям структуры через указатель
	ptr->age = 100;   // analog  (*ptr).age

	LeadEnge d1;
	LeadEnge* lptr = &l;
	lptr->p.age = 5;
	//////////////////////////

	Error er{ Error::kok };
	//int i = er; // bad
	//er = Error::ErrorRegenerate;

	return 0; 
}
