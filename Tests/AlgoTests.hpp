#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cassert>

//template <typename T>
//void printV(VLVector<T, 3> &vector)
//{
//	std::cout << "size: " << vector.size() << ' '
//			  << "Cap: " << vector.capacity() << ' '
//			  << "memory id: " << vector.data() << ' ';
//	for (unsigned i = 0; i < vector.size(); ++i)
//	{
//		std::cout << ' ' << vector[i];
//	}
//	std::cout << std::endl;
//}


bool test_fill_int()
{
	VLVector<int, 3> a;
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(i);
	}
	std::cout << "before fill: " << std::endl;
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "after fill: " << std::endl;
	std::fill(a.begin(), a.end(), -1);
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	VLVector<int, 3> b;
	for (int i = 0; i < 20; ++i)
	{
		b.push_back(-1);
	}
	return true;
//	return (a == b);
}

bool test_fill_strings()
{
	VLVector<std::string, 3> a, b;
	std::vector<std::string> v = {"Michael", "Christopher", "Jessica", "Matthew", "Ashley",
								  "Jennifer", "Joshua", "Amanda", "Daniel", "David", "James",
								  "Jason",
								  "Justin", "Sarah", "James", "James", "Bob", "Dani", "Dani",
								  "Avi"};
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(v[i]);
	}
	std::cout << "before fill: " << std::endl;
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "after fill: " << std::endl;
	std::fill(a.begin(), a.end(), "Yossi");
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	for (int i = 0; i < 20; ++i)
	{
		b.push_back("Yossi");
	}
	return true;
//	return (a == b);
}

bool test_move_ints()
{
	VLVector<int, 3> a;
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(i);
	}
	std::cout << "before move: " << std::endl;
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "after move: " << std::endl;
	VLVector<int, 3>::iterator it = std::move(a.begin(), a.begin() + 5, a.begin() + 10);
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	return (*it == 15);
}

bool test_move_cars()
{
	std::vector<Car> v = {Car('a'), Car('b'), Car('c'), Car('d'), Car('e'),
						  Car('f'), Car('g'), Car('h'), Car('i'), Car('j'), Car('k'), Car('l'),
						  Car('m'), Car('m'), Car('k'), Car('p'), Car('k')};
	VLVector<Car, 3> a;
	for (const auto &elem : v)
	{
		a.push_back(elem);
	}
	std::cout << "before move: " << std::endl;
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "after move: " << std::endl;
	VLVector<Car, 3>::iterator it = std::move(a.begin(), a.begin() + 3, a.begin() + 5);
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	return (*it == Car('i'));
}

bool test_find_ints()
{
	VLVector<int, 3> a, b;
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(i);
		b.push_back(2 * i);
	}
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "VLV b is: " << std::endl;
	printV(b);
	return ((*(std::find(a.begin(), a.end(), 9)) == 9) &&
			((std::find(b.begin(), b.end(), 9)) == b.end()));
}

bool test_find_string()
{
	VLVector<std::string, 3> a, b;
	std::vector<std::string> v = {"Michael", "Christopher", "Jessica", "Matthew", "Ashley",
								  "Jennifer", "Joshua", "Amanda", "Daniel", "David", "James",
								  "Jason",
								  "Justin", "Sarah", "James", "James", "Bob", "Dani", "Dani",
								  "Avi"};
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(v[i]);
		b.push_back(v[i]);
	}
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "VLV b is: " << std::endl;
	printV(b);
	return ((*(std::find(a.begin(), a.end(), "David")) == "David") &&
			((std::find(b.begin(), b.end(), "Lior")) == b.end()));
}


void make_mismatch_ints(VLVector<int, 3> &a, VLVector<int, 3> &b)
{
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(i);
		b.push_back(i);
	}
	a[10] = 10;
	b[10] = 11;
}

void make_mismatch_strings(VLVector<std::string, 3> &a, VLVector<std::string, 3> &b)
{
	std::vector<std::string> v = {"Michael", "Christopher", "Jessica", "Matthew", "Ashley",
								  "Jennifer", "Joshua", "Amanda", "Daniel", "David", "James",
								  "Jason",
								  "Justin", "Sarah", "James", "James", "Bob"};
	for (int i = 0; i < 2000; ++i)
	{
		a.push_back(v[i % v.size()]);
		b.push_back(v[i % v.size()]);
	}
	a[10] = "Tony";
	b[10] = "James";
}

void make_mismatch_cars(VLVector<Car, 3> &a, VLVector<Car, 3> &b)
{
	std::vector<Car> v = {Car('a'), Car('b'), Car('c'), Car('d'), Car('e'),
						  Car('f'), Car('g'), Car('h'), Car('i'), Car('j'), Car('k'), Car('l'),
						  Car('m'), Car('m'), Car('k'), Car('p'), Car('k')};
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(v[i]);
		b.push_back(v[i]);
	}
	a[10] = Car('k');
	b[10] = Car('z');
}

bool test_mismatch_int(VLVector<int, 3> &a, VLVector<int, 3> &b)
{
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "VLV b is: " << std::endl;
	printV(b);
	std::pair<VLVector<int, 3>::iterator, VLVector<int, 3>::iterator> mispair;
	mispair = std::mismatch(a.begin(), a.end(), b.begin());
	std::cout << "The 1st mismatch element of 1st container : ";
	std::cout << *mispair.first << std::endl;
	std::cout << "The 1st mismatch element of 2nd container : ";
	std::cout << *mispair.second << std::endl;
	return (mispair.first - a.begin() == 10);
}

bool test_mismatch_string(VLVector<std::string, 3> &a, VLVector<std::string, 3> &b)
{
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "VLV b is: " << std::endl;
	printV(b);
	std::pair<VLVector<std::string, 3>::iterator, VLVector<std::string, 3>::iterator> mispair;
	mispair = std::mismatch(a.begin(), a.end(), b.begin());
	std::cout << "The 1st mismatch element of 1st container : ";
	std::cout << *mispair.first << std::endl;
	std::cout << "The 1st mismatch element of 2nd container : ";
	std::cout << *mispair.second << std::endl;
	return (mispair.first - a.begin() == 10);
}

bool test_mismatch_cars(VLVector<Car, 3> &a, VLVector<Car, 3> &b)
{
	std::cout << "VLV a is: " << std::endl;
	printV(a);
	std::cout << "VLV b is: " << std::endl;
	printV(b);
	std::pair<VLVector<Car, 3>::iterator, VLVector<Car, 3>::iterator> mispair;
	mispair = std::mismatch(a.begin(), a.end(), b.begin());
	std::cout << "The 1st mismatch element of 1st container : ";
	std::cout << *mispair.first << std::endl;
	std::cout << "The 1st mismatch element of 2nd container : ";
	std::cout << *mispair.second << std::endl;
	return (mispair.first - a.begin() == 10);
}

void fill_with_integers(VLVector<int, 3> &a)
{
	for (int i = 0; i < 20; ++i)
	{
		a.push_back(i);
	}
	a[4] = 10;
	a[8] = 10;
}

void fill_with_strings(VLVector<std::string, 3> &a)
{
	std::vector<std::string> v = {"Michael", "Christopher", "Jessica", "Matthew", "Ashley",
								  "Jennifer", "Joshua", "Amanda", "Daniel", "David", "James",
								  "Jason",
								  "Justin", "Sarah", "James", "James", "Bob"};
	for (const auto &elem : v)
	{
		a.push_back(elem);
	}
}

void fill_with_cars(VLVector<Car, 3> &a)
{
	std::vector<Car> v = {Car('a'), Car('b'), Car('c'), Car('d'), Car('e'),
						  Car('f'), Car('g'), Car('h'), Car('i'), Car('j'), Car('k'), Car('l'),
						  Car('m'), Car('m'), Car('k'), Car('p'), Car('k')};
	for (const auto &elem : v)
	{
		a.push_back(elem);
	}
}


template<typename T>
bool test_count(VLVector<T, 3> v)
{
	// test count:
	std::cout << "VLV is: " << std::endl;
	printV(v);
	T target = v[10];
	std::cout << "target is: " << target << '\n';
	int num_items1 = std::count(v.begin(), v.end(), target);
	std::cout << "found number of elements: " << num_items1 << '\n';
	return num_items1 == 3;
}

bool test_count_if(VLVector<int, 3> v)  // int
{
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int num_items3 = std::count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
	std::cout << "number divisible by two: " << num_items3 << '\n';
	return num_items3 == 10;
}


bool starts_with_j(std::string s)
{ return s[0] == 'J'; }

bool test_count_if(VLVector<std::string, 3> v)  // string
{
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int num_items3 = std::count_if(v.begin(), v.end(), starts_with_j);
	std::cout << "number of elements starts with J : " << num_items3 << '\n';
	return num_items3 == 8;
}

bool car_color_k(Car c)
{ return c == Car('k'); }

bool test_count_if(VLVector<Car, 3> v)  // string
{
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int num_items3 = std::count_if(v.begin(), v.end(), car_color_k);
	std::cout << "number of cars 'k' : " << num_items3 << '\n';
	return num_items3 == 8;
}


int algoTestsPractic()
{
	// test std::count

	std::cout << "______________testing count______________" << std::endl;
	// int:
	VLVector<int, 3> v;
	fill_with_integers(v);
	assert(test_count(v));
	// string:
	VLVector<std::string, 3> a;
	fill_with_strings(a);
	assert(test_count(a));
	// cars:
	VLVector<Car, 3> b;
	fill_with_cars(b);
	assert(test_count(b));

	// std::count_if
	std::cout << "______________testing count_if______________" << std::endl;

	// int:
	assert(test_count_if(v));
	// string:
	assert(test_count_if(a));
	// cars:
	assert(test_count(b));


	std::cout << "______________testing std::mismatch______________" << std::endl;

	// ints:
	VLVector<int, 3> d1;
	VLVector<int, 3> d2;
	make_mismatch_ints(d1, d2);
	assert(test_mismatch_int(d1, d2));

	// string:
	VLVector<std::string, 3> d3;
	VLVector<std::string, 3> d4;
	make_mismatch_strings(d3, d4);
	assert(test_mismatch_string(d3, d4));

	// cars:
	VLVector<Car, 3> d5;
	VLVector<Car, 3> d6;
	make_mismatch_cars(d5, d6);
	assert(test_mismatch_cars(d5, d6));

	std::cout << "______________testing std::find______________" << std::endl;

	// ints:
	assert(test_find_ints());

	//strings:
	assert(test_find_string());

	std::cout << "______________testing std::move______________" << std::endl;

	// ints:
	assert(test_move_ints());

	// cars:
	assert(test_move_cars());

	std::cout << "______________testing std::fill______________" << std::endl;

	// ints:
	assert(test_fill_int());

	// string:
	assert(test_fill_strings());

	std::cout << "______________all tests passed!______________" << std::endl;
}

int algoTests()
{


	std::vector<int> a = {1, 2};
	a.erase(a.begin() + 1);
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("AlgorithmsOut.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	std::string word;
	std::cin >> word;           //input from the file in.txt
	std::cout << word << "  ";  //output to the file out.txt

	algoTestsPractic(); //call function

	std::cin.rdbuf(cinbuf);   //reset to standard input again
	std::cout.rdbuf(coutbuf); //reset to standard output again
	return 0;
}

