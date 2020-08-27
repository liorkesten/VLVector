//
// Created by Lior Kesten on 06/08/2020.
//



//#include "../VLVector.hpp"
//#include "../helpers/Helpers.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Classes/Car.hpp"
#include <cassert>

#ifndef __DISABLE_PRESUBMISSION_TESTS
#define PRESUBMISSION_ASSERT(testCase) \
__ASSERT_TEST("Noam's Tests\t\t\t\t\t\t\t\t\t\t\t\t\t", testCase)
#else
#include <string>
#define PRESUBMISSION_ASSERT(testCase)
#endif



//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define CAP_STAT = 90

void printV(VLVector<std::string, 0> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' '
			  << "memory id: " << vector.data() << ' ';
	for (size_t i = 0; i < vector.size(); ++i)
	{
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}

void printV(VLVector<std::vector<int>, 0> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' '
			  << "memory id: " << vector.data() << ' ';
//	for (size_t i = 0; i < vector.size(); ++i)
//	{
//		std::cout << ' ' << vector[i];
//	}
	std::cout << std::endl;
}

void printV(VLVector<int, 8> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' '
			  << "memory id: " << vector.data() << ' ';
	for (size_t i = 0; i < vector.size(); ++i)
	{
//		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}

void printV(VLVector<int, 0> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' '
			  << "memory id: " << vector.data() << ' ';
	for (size_t i = 0; i < vector.size(); ++i)
	{
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}

//
//void printV(VLVector<Car, 3> &vector)
//{
//	std::cout << "size: " << vector.size() << ' '
//			  << "Cap: " << vector.capacity() << ' '
//			  << "memory id: " << vector.data() << ' ';
//	for (size_t i = 0; i < vector.size(); ++i)
//	{
//		std::cout << ' ' << vector[i];
//	}
//	std::cout << std::endl;
//}


int zeroCtorStr(VLVector<std::string, 0> str0)
{
	printV(str0);
	assert(str0.size() == 0 && str0.capacity() == 0);
	std::string *memory_zero = str0.data();
	std::string tt = "hello";
	str0.push_back(tt);
	assert(str0.size() == 1 && str0.capacity() == 1 && memory_zero != str0.data());
	str0.pop_back();
	assert(str0.size() == 0 && str0.capacity() == 0 && memory_zero == str0.data());
	printV(str0);
}

int zeroCtorVec(VLVector<std::vector<int>, 0> &vec)
{
	assert(vec.size() == 0 && vec.capacity() == 0);
	std::vector<int> *memory_zero = vec.data();;
	std::vector<int> vec1 = {1, 2, 3, 4};
	vec.push_back(vec1);
//	printV(vec);
	assert(vec.size() == 1 && vec.capacity() == 1 && memory_zero != vec.data());
	std::vector<int> vec2 = {3, 2, 3, 4};
	vec.push_back(vec2);
	assert(vec.size() == 2 && vec.capacity() == 3 && memory_zero != vec.data());
	vec.erase(vec.begin());
	assert(vec.size() == 1 && vec.capacity() == 3 && memory_zero != vec.data());
	vec.erase(vec.begin());
	assert(vec.size() == 0 && vec.capacity() == 0 && memory_zero == vec.data());
//	printV(vec);
}

int testDefaultCtorStringsInts()
{
	VLVector<std::string, 1> str1;
	assert(str1.size() == 0 && str1.capacity() == 1);
	VLVector<std::string, 0> str0;
	zeroCtorStr(str0);

	VLVector<int, 10000> int10000;
	assert(int10000.size() == 0 && int10000.capacity() == 10000);

	VLVector<int, 1> int1;
	assert(int1.size() == 0 && int1.capacity() == 1);

}

int testDefaultCtorCars()
{
	VLVector<Car, 3> car3;
	assert(car3.size() == 0 && car3.capacity() == 3);

	VLVector<std::vector<int>, 0> vec;
	zeroCtorVec(vec);
}


void testComparison(VLVector<int, 8> a, VLVector<int, 8> b)
{

	assert(b == a);
	assert(a == b);
	assert(!(b != a));
	assert(!(a != b));
}

void testNotComparsion(VLVector<int, 8> a, VLVector<int, 8> b)
{

	assert(b != a);
	assert(a != b);
	assert(b != a);
	assert(a != b);
}

void testComparison(VLVector<Car, 3> a, VLVector<Car, 3> b)
{

	assert(b == a);
	assert(a == b);
	assert(!(b != a));
	assert(!(a != b));
}

void testNotComparsion(VLVector<Car, 3> a, VLVector<Car, 3> b)
{

	assert(b != a);
	assert(a != b);
	assert(b != a);
	assert(a != b);
}


int testCopyCtorCars()
{
	VLVector<Car, 3> car;

	for (int i = 0; i < 30; ++i)
	{
		const Car x(i % 2);
		car.push_back(x);
	}

	VLVector<Car, 3> carB(car);
	testComparison(carB, car);
	Car temp = Car(1);
	carB[4] = temp;
	testNotComparsion(carB, car);
}


int testCopyCtorInts()
{
	//int
	VLVector<int, 8> vec;

	for (int i = 0; i < 30; ++i)
	{
		const int x = i;
		vec.push_back(x);
	}

	VLVector<int, 8> b(vec);
	testComparison(vec, b);
	b[4] = 5;
	testNotComparsion(vec, b);
	b[4] = vec[4];
	testComparison(vec, b);


}

int testCtorOneInt()
{


	//check empty construct int
	VLVector<int, 8> vec;
	VLVector<int, 8> vec2(vec.begin(), vec.end());
	testComparison(vec, vec2);
	VLVector<int, 8> vec3(vec.begin(), vec.begin());
	testComparison(vec, vec3);

	//check full ctor 1 ints
	for (int i = 0; i < 30; ++i)
	{
		const int x = i;
		vec.push_back(x);
	}
	VLVector<int, 8> vec4(vec.begin() + 1, vec.begin() + 3);
	assert(vec4.size() == 2 && vec4.capacity() == 8 && vec4[0] == vec[1] && vec4[1] == vec[2]
		   && vec4[5] != vec[5]);
	testNotComparsion(vec4, vec);
	VLVector<int, 8> vec5(vec.begin() + 8, vec.begin() + 9);
	assert(vec5.size() == 1 && vec5.capacity() == 8 && vec5[0] == vec[8]);
	testNotComparsion(vec5, vec);
	testNotComparsion(vec5, vec4);

	//until end-1
	VLVector<int, 8> vec6(vec.begin(), vec.end() - 1);
	assert(vec6.size() == 29);
	testNotComparsion(vec6, vec);

	//until end
	VLVector<int, 8> vec7(vec.begin(), vec.end());
	assert(vec7.size() == 30);
	testComparison(vec, vec7);
}

int testCtorOneCar()
{
	//check empty construct cars
	//check empty construct
	VLVector<Car, 3> car;
	VLVector<Car, 3> car2(car.begin(), car.end());
	testComparison(car, car2);
	VLVector<Car, 3> car3(car.begin(), car.begin());
	testComparison(car, car3);

	//check full ctor 1 Cars
	VLVector<Car, 3> vec;
	for (int i = 0; i < 30; ++i)
	{
		const int x = i;
		vec.push_back(x);
	}
	VLVector<Car, 3> vec4(vec.begin() + 1, vec.begin() + 3);
	assert(vec4.size() == 2 && vec4.capacity() == 3);
	testNotComparsion(vec4, vec);
	VLVector<Car, 3> vec5(vec.begin() + 8, vec.begin() + 9);
	assert(vec5.size() == 1 && vec5.capacity() == 3);
	testNotComparsion(vec5, vec);
	testNotComparsion(vec5, vec4);

	//until end-1
	VLVector<Car, 3> vec6(vec.begin(), vec.end() - 1);
	assert(vec6.size() == 29);
	testNotComparsion(vec6, vec);

	//until end
	VLVector<Car, 3> vec7(vec.begin(), vec.end());
	assert(vec7.size() == 30);
	testComparison(vec, vec7);


}


int testAssignmentInt()
{

	VLVector<int, 8> vec;
	for (int i = 0; i < 10; ++i)
	{
		const int x = i;
		vec.push_back(x);
	}

	VLVector<int, 8> vec2;
	for (int i = 0; i < 12; ++i)
	{
		const int x = i + 3;
		vec2.push_back(x);
	}

	auto ptr = vec2.data();
	vec2 = vec;
	assert(vec.data() != ptr);
	*ptr;
	testComparison(vec, vec2);
	auto ptr_vec2 = vec.data();
	vec = vec2;
	assert(vec.data() == ptr_vec2);
	auto ptr_vec = vec.data();
	vec = vec;
	assert(vec.data() == ptr_vec);

}


int testAssignmentCars()
{

	VLVector<Car, 3> vec;
	for (int i = 0; i < 10; ++i)
	{
		const int x = i;
		vec.push_back(x);
	}

	VLVector<Car, 3> vec2;
	for (int i = 0; i < 12; ++i)
	{
		const int x = i + 3;
		vec2.push_back(x);
	}

	auto ptr = vec2.data();
	vec2 = vec;
	assert(vec.data() != ptr);
	*ptr;
	testComparison(vec, vec2);
	auto ptr_vec2 = vec.data();
	vec = vec2;
	auto a = vec.data();
	auto b = ptr_vec2;
	assert(vec.data() != ptr_vec2);
	auto ptr_vec = vec.data();
	vec = vec;
	assert(vec.data() == ptr_vec);

}

//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int constactorTests()
{
	PRESUBMISSION_ASSERT(testDefaultCtorStringsInts)
	PRESUBMISSION_ASSERT(testCopyCtorInts)
	PRESUBMISSION_ASSERT(testCtorOneInt)
//	PRESUBMISSION_ASSERT(testAssignmentInt)
	std::cout << "ALL TESTS PASSED- Ints And Strings" << std::endl;
	PRESUBMISSION_ASSERT(testDefaultCtorCars)
	PRESUBMISSION_ASSERT(testCopyCtorCars)
	PRESUBMISSION_ASSERT(testCtorOneCar)
//	PRESUBMISSION_ASSERT(testAssignmentCars)
	std::cout << "ALL TESTS PASSED- Car" << std::endl;

	return 1;
}
