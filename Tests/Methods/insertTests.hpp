#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <forward_list>


template<typename T>
void printV(VLVector<T, 3> &vector)
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


bool edge_case_1()
{
	VLVector<int, 3> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	std::cout << "before insertion at begin(): " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	VLVector<int, 3>::iterator it = v.insert(v.begin(), 100);
	std::cout << "after insertion at begin(): " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return (*it == 100);
}

bool edge_case_2()
{
	VLVector<int, 3> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	std::cout << "before insertion at end(): " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	VLVector<int, 3>::iterator it = v.insert(v.end(), 100);
	std::cout << "after insertion at end(): " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return (*it == 100);
}

bool edge_case_3()
{
	VLVector<int, 3> v;
	for (int i = 0; i < 3; ++i)
	{
		v.push_back(i);
	}
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int *stack_ptr = v.data();
	VLVector<int, 3>::iterator it = v.insert(v.begin() + 1, 100);
	int *heap_ptr = v.data();
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return ((*it == 100) && (stack_ptr != heap_ptr));
}

bool edge_case_4()
{
	VLVector<int, 3> v;
	for (int i = 0; i < 6; ++i)
	{
		v.push_back(i);
	}
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int *prev_heap_ptr = v.data();
	VLVector<int, 3>::iterator it = v.insert(v.begin() + 3, 100);
	int *new_heap_ptr = v.data();
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return ((*it == 100) && (prev_heap_ptr != new_heap_ptr));
}

bool edge_case_5()
{
	VLVector<int, 3> v;
	v.push_back(100);
	std::forward_list<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	VLVector<int, 3>::iterator it = v.insert(v.begin(), a.begin(), a.end());
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return (*it == 0);
}

bool edge_case_6()
{
	VLVector<int, 3> v;
	v.push_back(100);
	std::forward_list<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	VLVector<int, 3>::iterator it = v.insert(v.begin(), a.begin(), a.begin());
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return (*it == 100);
}

bool edge_case_7()
{
	VLVector<int, 3> v;
	std::forward_list<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	VLVector<int, 3>::iterator it = v.insert(v.begin(), a.begin(), a.end());
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return (*it == 0);
}

bool edge_case_8()
{
	VLVector<int, 3> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	int *stack_ptr = v.data();
	std::forward_list<int> a = {3};
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	v.insert(v.begin(), a.begin(), a.end());
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int *heap_ptr = v.data();
	return (stack_ptr != heap_ptr);
}

bool edge_case_9()
{
	VLVector<int, 3> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	int *old_heap_ptr = v.data();
	std::forward_list<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	v.insert(v.begin(), a.begin(), a.end());
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	int *new_heap_ptr = v.data();
	return (old_heap_ptr != new_heap_ptr);
}

bool edge_case_10()
{
	VLVector<int, 3> v;
	v.push_back(100);
	const std::forward_list<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "before insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	VLVector<int, 3>::iterator it = v.insert(v.begin(), a.begin(), a.begin());
	std::cout << "after insertion: " << std::endl;
	std::cout << "VLV is: " << std::endl;
	printV(v);
	return (*it == 100);
}

int insertTestsPractic()
{
	auto start = std::chrono::steady_clock::now();
	// test std::count


	std::cout << "______________CASE 1______________" << std::endl;
	std::cout << "______________testing insert (1):______________" << std::endl;
	std::cout << "______________edge case: insertion at begin()______________" << std::endl;

	assert(edge_case_1());

	std::cout << std::endl;
	std::cout << "______________CASE 2______________" << std::endl;
	std::cout << "______________testing insert (1):______________" << std::endl;
	std::cout << "______________edge case: insertion at end()______________" << std::endl;

	assert(edge_case_2());

	std::cout << std::endl;
	std::cout << "______________CASE 3______________" << std::endl;
	std::cout << "______________testing insert (1):______________" << std::endl;
	std::cout << "______________edge case: insertion from heap to stack______________" << std::endl;

	assert(edge_case_3());

	std::cout << std::endl;
	std::cout << "______________CASE 4______________" << std::endl;
	std::cout << "______________testing insert (1):______________" << std::endl;
	std::cout << "______________edge case: insertion from heap to new heap alloc______________" <<
			  std::endl;

	assert(edge_case_4());

	std::cout << std::endl;
	std::cout << "______________Test insert(2)______________" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "______________CASE 5______________" << std::endl;
	std::cout << "______________testing insert (2):______________" << std::endl;
	std::cout << "______________edge case: insert from most basic iterator_________" << std::endl;

	assert(edge_case_5());

	std::cout << std::endl;
	std::cout << "______________CASE 6______________" << std::endl;
	std::cout << "______________testing insert (2):______________" << std::endl;
	std::cout << "______________edge case: first == last_________" << std::endl;

	assert(edge_case_6());

	std::cout << std::endl;
	std::cout << "______________CASE 7______________" << std::endl;
	std::cout << "______________testing insert (2):______________" << std::endl;
	std::cout << "______________edge case: insert on empty_________" << std::endl;

	assert(edge_case_7());

	std::cout << std::endl;
	std::cout << "______________CASE 8______________" << std::endl;
	std::cout << "______________testing insert (2):______________" << std::endl;
	std::cout << "______________edge case: insert from stack to heap_________" << std::endl;

	assert(edge_case_8());


	std::cout << std::endl;
	std::cout << "______________CASE 9______________" << std::endl;
	std::cout << "______________testing insert (2):______________" << std::endl;
	std::cout << "______________edge case: insert from heap to heap_________" << std::endl;

	assert(edge_case_9());

	std::cout << std::endl;
	std::cout << "______________CASE 10______________" << std::endl;
	std::cout << "______________testing insert (2):______________" << std::endl;
	std::cout << "______________edge case: insert from const forward iterator_______" << std::endl;

	assert(edge_case_10());


	std::cout << std::endl;
	std::cout << "______________all tests passed!______________" << std::endl;
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return 1;
}


int insertTests()
{


	std::vector<int> a = {1, 2};
	a.erase(a.begin() + 1);
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("InsertOut.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	std::string word;
	std::cin >> word;           //input from the file in.txt
	std::cout << word << "  ";  //output to the file out.txt

	insertTestsPractic(); //call function

	std::cin.rdbuf(cinbuf);   //reset to standard input again
	std::cout.rdbuf(coutbuf); //reset to standard output again
	return 0;
}