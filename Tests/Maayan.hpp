//
// Created by Lior Kesten on 06/08/2020.
//

#ifndef C___MAAYAN_HPP
#define C___MAAYAN_HPP






//
// Created by maaya on 06/08/2020.
//

#include "../VLVector.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <forward_list>
#include <cassert>
#include "Classes/Car.hpp"


void initCars(std::forward_list<Car> &myCars, int i)
{
	for (; i > 0; --i)
	{
		myCars.push_front(Car(i));
	}
}

void printV0(VLVector<int, 0> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' ';
//			  << "memory id: " << vector.data() << ' ';
	for (unsigned i = 0; i < vector.size(); ++i)
	{
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}

void printV(VLVector<Car, 3> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' ';
	for (unsigned i = 0; i < vector.size(); ++i)
	{
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}

void printV(VLVector<int, 3> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' ';
//			  << "memory id: " << vector.data() << ' ';
	for (unsigned i = 0; i < vector.size(); ++i)
	{
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}


void case4()
{
	std::cout << "Pushing" << std::endl;
	VLVector<Car, 3> v;
	for (int i = 1; i < 30; ++i)
	{
		v.push_back(i);
		printV(v);
	}

	std::cout << "Inserting 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		const int x = i * 100;
		v.insert(v.begin() + (i * 3), x);
		printV(v);
	}

	std::cout << "Erasing 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		v.pop_back();
		printV(v);
	}
}

void case3()
{


	std::cout << "Pushing" << std::endl;
	VLVector<Car, 3> v;
	for (int i = 1; i < 30; ++i)
	{
		v.push_back(i);
		printV(v);
	}

	std::cout << "Inserting 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		const int x = i * 100;
		v.insert(v.begin() + (i * 3), x);
		printV(v);
	}

	std::cout << "Erasing 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		v.erase(v.begin() + (i * 4));
		printV(v);
	}
}

void case2()
{
	VLVector<Car, 3> v;
	std::cout << "Should be on Stack" << std::endl;
	printV(v);
	v.push_back(Car(1));
	v.push_back(Car(2));
	v.push_back(Car(3));
	v.push_back(Car(4));
	std::cout << "Should be on Heap" << std::endl;
	printV(v);
	std::cout << "Should be on Stack, 3,3, [1 3 4]" << std::endl;
	v.erase(v.begin() + 1);
	printV(v);
	std::cout << "Should be on Heap, 7,7 ,  [1 6 7 8 9 3 4]" << std::endl;
	std::vector<int> a = {5, 6, 7, 8, 9};
	v.insert(v.begin() + 1, a.begin() + 1, a.end());
	printV(v);
	std::cout << "Should be on Stack" << std::endl;
	v.erase(v.begin() + 1, v.end() - 1);
	printV(v);
	std::cout << "at last index" << v.at(1) << std::endl;
	std::cout << "Clear" << std::endl;
	v.clear();
	printV(v);
}

void case1()
{
	VLVector<Car, 3> v;
	std::cout << "Should be on Stack" << std::endl;
	printV(v);
	v.push_back(Car(1));
	v.push_back(Car(2));
	v.push_back(Car(3));
	v.push_back(Car(4));
	std::cout << "Should be on Heap" << std::endl;
	printV(v);
	std::cout << "Should be on Stack" << std::endl;
	v.erase(v.begin() + 1);
	printV(v);
}

void case5()
{
	std::cout << "_______________________case 5______________________" << std::endl;
	std::forward_list<Car> myCars;
	VLVector<Car, 3> v;
	std::cout << "Should be on Stack" << std::endl;
	printV(v);
	myCars.push_front(Car(4));
	myCars.push_front(Car(3));
	myCars.push_front(Car(2));
	myCars.push_front(Car(1));
	v.insert(v.begin(), myCars.begin(), myCars.end());
	std::cout << "Should be on Heap" << std::endl;
	printV(v);
	std::cout << "Should be on Stack" << std::endl;
	v.erase(v.begin() + 1);
	printV(v);
}

void case6()
{
	std::cout << "_______________________case 6______________________" << std::endl;
	std::forward_list<Car> myCars;
	myCars.push_front(Car(4));
	myCars.push_front(Car(3));
	myCars.push_front(Car(2));
	myCars.push_front(Car(1));
	VLVector<Car, 3> v(myCars.begin(), myCars.end());
	printV(v);
}


void printV2(VLVector<Car, 100> &vector)
{
	std::cout << "size: " << vector.size() << ' '
			  << "Cap: " << vector.capacity() << ' ';
	for (unsigned i = 0; i < vector.size(); ++i)
	{
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;
}

void case7()
{
	std::cout << "_______________________case 7______________________" << std::endl;
	std::cout << "Pushing" << std::endl;
	VLVector<Car, 100> v;
	for (int i = 1; i < 200; ++i)
	{
		v.push_back(i);
		printV2(v);
	}

	std::cout << "Inserting 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		const int x = i * 100;
		v.insert(v.begin() + (i * 3), x);
		printV2(v);
	}

	std::cout << "pop+back 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		v.pop_back();
		printV2(v);
	}
}

void case8()
{
	std::cout << "_______________________case 7______________________" << std::endl;
	std::cout << "Pushing" << std::endl;
	VLVector<Car, 100> v;
	for (int i = 1; i < 200; ++i)
	{
		v.push_back(i);
		printV2(v);
	}

	std::cout << "Inserting 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		const int x = i * 100;
		v.insert(v.begin() + (i * 3), x);
		printV2(v);
	}

	std::cout << "erasing 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		v.erase(v.begin() + i * 2);
		printV2(v);
	}
}

void case9()
{
	std::cout << "_______________________case 7______________________" << std::endl;
	std::cout << "Pushing" << std::endl;
	VLVector<Car, 100> v;
	for (int i = 1; i < 200; ++i)
	{
		v.push_back(i);
		printV2(v);
	}

	std::cout << "Inserting 1" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		const int x = i * 100;
		v.insert(v.begin() + (i * 3), x);
		printV2(v);
	}

	std::cout << "erasing many" << std::endl;
	for (int i = 1; i < 9; ++i)
	{
		v.erase(v.begin() + i * 1, v.begin() + i * 2);
		printV2(v);
	}
}

#include <iostream>
#include <fstream>
#include <string>

void edgecasesErase1_0()
{
	std::cout << "_______________________edgecasesErase1_0______________________" << std::endl;

	//from heap to stack
	std::cout << "Pushing" << std::endl;
	VLVector<int, 0> v;
	for (int i = 1; i < 5; ++i)
	{
		v.push_back((i));
		printV0(v);
	}
	auto iterator1 = v.erase(v.begin());
	assert(*iterator1 == 2);
	std::cout << "size: " << v.size() << ' '
			  << "Cap: " << v.capacity() << ' ';
//			  << "memory id: " << v.data() << ' ' << " iterator val need to be 2: "
//			  << *iterator1 << " " << "iterator address needs to be on heap" << &(*iterator1)
//			  << std::endl;
	printV0(v);
	v.push_back((10));
	v.push_back(11);
	v.push_back(12);
	auto iterator2 = v.erase(v.begin());
	assert(*iterator2 == 3);
	std::cout << "size: " << v.size() << ' '
			  << "Cap: " << v.capacity() << ' ';
//			  << "memory id: " << v.data() << ' ' << " iterator val need to be 3: " <<
//			  *iterator2 << " " << "iterator address needs to be on heap " << &(*iterator2)
//			  << std::endl;
	printV0(v);


	//erase empty vector

}

void edgecasesErase1_1()
{
	std::cout << "_______________________edgecasesErase1_1______________________" << std::endl;

	//from heap to stack
	std::cout << "Pushing" << std::endl;
	VLVector<int, 3> v;
	for (int i = 1; i < 5; ++i)
	{
		v.push_back((i));
		printV(v);
	}
	auto iterator1 = v.erase(v.begin());
	assert(*iterator1 == 2);
	std::cout << "size: " << v.size() << ' '
			  << "Cap: " << v.capacity() << ' ';
//			  << "memory id: " << v.data() << ' ' << " iterator val need to be 2: "
//			  << *iterator1 << " " << "iterator address needs to be on stack" << &(*iterator1)
//			  << std::endl;
	printV(v);
	v.push_back((10));
	v.push_back(11);
	v.push_back(12);
	auto iterator2 = v.erase(v.begin());
	assert(*iterator2 == 3); //
	std::cout << "size: " << v.size() << ' '
			  << "Cap: " << v.capacity() << ' ';
//			  << "memory id: " << v.data() << ' ' << " iterator val need to be 3: " <<
//			  *iterator2 << " " << "iterator address needs to be on heap " << &(*iterator2)
//			  << std::endl;
	printV(v);
}

void edgecasesErase1_2()
{
	std::cout << "_______________________edgecasesErase1_2______________________" << std::endl;

	std::cout << "Pushing" << std::endl;
	VLVector<int, 3> v;
	for (int i = 1; i < 5; ++i)
	{
		v.push_back((i));
		printV(v);
	}
	auto iterator1 = v.erase(v.end() - 1);
	std::cout << "size: " << v.size() << ' '
			  << "Cap: " << v.capacity() << ' ';
//			  << "memory id: " << v.data() << ' ' << " " << "iterator address needs to be on stack "
//			  << &(*iterator1)
//			  << std::endl;

	assert(iterator1 == v.end());
	v.push_back((10));
	v.push_back(11);
	v.push_back(12);
	auto iterator2 = v.erase(v.end() - 1);
	std::cout << "size: " << v.size() << ' '
			  << "Cap: " << v.capacity() << ' ' << std::endl;
//			  << "memory id: " << v.data() << ' ' << " " << "iterator address needs to be on heap "
//			  << &(*iterator2) << std::endl;
}

void edgecasesErase2_1()
{
	std::cout << "_______________________edgecasesErase2_1______________________" << std::endl;

	VLVector<int, 3> v;
	for (int i = 1; i < 5; ++i)
	{
		v.push_back((i));
		printV(v);
	}
	auto iterator1 = v.erase(v.begin() + 1, v.end());
	assert(iterator1 == v.end());
}

void edgecasesErase2_2()
{
	std::cout << "_______________________edgecasesErase2_2______________________" << std::endl;

	VLVector<int, 3> v;
	for (int i = 1; i < 5; ++i)
	{
		v.push_back((i));
		printV(v);
	}
	auto iterator0 = v.begin() + 1;
	auto iterator1 = v.erase(iterator0, iterator0);
	assert(iterator1 == iterator0);
	printV(v);
}

#define DEF_SIZE 4

void g()
{
	std::vector<int> ref;
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb = b.begin() + 5;
	auto lastb = b.begin() + 10;
	auto firstref = ref.begin() + 5;
	auto lastref = ref.begin() + 10;
	assert(*b.erase(firstb, lastb) == *ref.erase(firstref, lastref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb = b.begin() + 1;
	lastb = b.begin() + 13;
	firstref = ref.begin() + 1;
	lastref = ref.begin() + 13;
	assert(*b.erase(firstb, lastb) == *ref.erase(firstref, lastref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb = b.begin() + 1;
	lastb = b.begin() + 3;
	firstref = ref.begin() + 1;
	lastref = ref.begin() + 3;
	assert(*b.erase(firstb, lastb) == *ref.erase(firstref, lastref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 10; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb = b.begin() + 1;
	lastb = b.end();
	firstref = ref.begin() + 1;
	lastref = ref.end();
	assert(*b.erase(firstb, lastb) == *ref.erase(firstref, lastref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 10; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb = b.begin() + 1;
	firstref = ref.begin() + 1;
	assert(*b.erase(firstb, firstb) == *ref.erase(firstref, firstref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }


}


void f()
{

	case3(); //large amount of erase and pushback
	case4(); //same but uses pop_back instead of erase
	case5(); // insert by forword iterator
	case6(); //constractor1 with forword iteartor
	case7();//many pop back template capacity 100
	case8();// many erase 1
	case9();// many erase by range
	g();
	// cant do diff from here!!!!!!
	case1(); // noam tests from yesterday
	case2();// noam tests from yesterday
//	edgecasesErase1_1();
//	edgecasesErase1_2();
//	edgecasesErase1_0();
//	edgecasesErase2_1();
//	edgecasesErase2_2();
}

int saniteCheck()
{
	std::vector<int> a = {1, 2};
	a.erase(a.begin() + 1);
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("KremmerTests.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	std::string word;
	std::cin >> word;           //input from the file in.txt
	std::cout << word << "  ";  //output to the file out.txt

	f(); //call function

	std::cin.rdbuf(cinbuf);   //reset to standard input again
	std::cout.rdbuf(coutbuf); //reset to standard output again

}


#endif //C___MAAYAN_HPP
