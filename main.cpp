
#include "VLVector.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("At method Tests", testCase)
#define PRESUBMISSION_ASSERT(testCase)


//-------------------------------------------------------
// Tests
//-------------------------------------------------------

#define CAPC(X) (((3*(X+1))/2))

// ________________ Cap tests ________________________________________________________
int testsAtEmpty()
{
	VLVector<int, STATIC_CAP> v;
	bool flag = false;

	try
	{ v.at(0); }
	catch (std::out_of_range)
	{ flag = true; }

	RETURN_ASSERT_TRUE(flag == true);
}

int testsAtSize1()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(1);
	bool flag = true;

	try
	{ v.at(0); }
	catch (std::out_of_range)
	{ flag = false; }
	RETURN_ASSERT_TRUE(flag == true);
}

int testsAtAfterIndexOutOfErrorThereIsAccess()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(411);
	bool flag = true;

	try
	{ v.at(1); }
	catch (std::out_of_range)
	{ flag = false; }

	RETURN_ASSERT_TRUE(v[0] == 411);
}


int testAtNonConst()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(10);
	v.at(0) += 12;

	RETURN_ASSERT_TRUE(v[0] == 22);
}

int testAtConst()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(10);
	const auto w(v);
	auto d = w.at(0);

	RETURN_ASSERT_TRUE((d == v[0]));
}

#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("At method Tests", testCase)
#define PRESUBMISSION_ASSERT(testCase)


//-------------------------------------------------------
// Tests
//-------------------------------------------------------

#define CAPC(X) (((3*(X+1))/2))

// ________________ Cap tests ________________________________________________________


int testsBracketsSize1()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(523);

	RETURN_ASSERT_TRUE(v[0] == 523);
}


int testBracketsNonConst()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(10);
	v[0] += 12;

	RETURN_ASSERT_TRUE(v[0] == 22);
}

int testBracketsConst()
{
	VLVector<int, STATIC_CAP> v;
	v.push_back(10);
	const auto w(v);
	RETURN_ASSERT_TRUE(w[0] == 10);
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("Cap method", testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------

#define CAPC(X) (((3*(X+1))/2))

// ________________ Cap tests ________________________________________________________
int testCapEmptyList()
{
	VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.capacity() == STATIC_CAP)
}

int testCapLimitStack()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP; ++i)
	{
		vec.push_back(i);
	}
	RETURN_ASSERT_TRUE(vec.capacity() == STATIC_CAP)
}

int testCapFirstHeap()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{
		vec.push_back(i);
	}
	auto a = CAPC(STATIC_CAP);
	RETURN_ASSERT_TRUE(vec.capacity() == CAPC(STATIC_CAP));
}

int testCapReturnFromHeapToStack()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 3; ++i)
	{
		vec.push_back(i);
	}
	vec.clear();
	RETURN_ASSERT_TRUE(vec.capacity() == STATIC_CAP)
}

int testCapReturnFromHeapToHeap()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{
		vec.push_back(i);
	}
	auto cap = vec.capacity();
	for (auto i = 0; i < STATIC_CAP * 90; ++i)
	{
		vec.pop_back();
	}
	RETURN_ASSERT_TRUE(vec.capacity() == cap)
}

int testsCapConst()
{
	const VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.capacity());
}


int testCapCopyConstructor()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{
		vec.push_back(i);
	}
	for (auto i = 0; i < STATIC_CAP * 90; ++i)
	{
		vec.pop_back();
	}
	auto u(vec);
	RETURN_ASSERT_TRUE(vec.capacity() == u.capacity())
}

int testCapOperatorEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{
		vec.push_back(i);
	}
	for (auto i = 0; i < STATIC_CAP * 90; ++i)
	{
		vec.pop_back();
	}
	auto u(vec);
	RETURN_ASSERT_TRUE(vec.capacity() == u.capacity())
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("Clear method", testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define SPACE "--------------------"
#define SUCCESS_INTRO "The test "
#define SUCCESS_END " Successfully done"

// ______________________ Size tests ________________________________________________________
int testsClearEmpty()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.clear();
	RETURN_ASSERT_TRUE(vec.empty())
}

int testsClearOnStack()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP; ++i)
	{
		vec.push_back(i);
	}
	vec.clear();
	RETURN_ASSERT_TRUE(vec.empty())
}

int testsClearOnHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 1000; ++i)
	{
		vec.push_back(i);
	}
	vec.clear();
	RETURN_ASSERT_TRUE(vec.empty())
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("Data method", testCase)
#define PRESUBMISSION_ASSERT(testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define SPACE "--------------------"
#define SUCCESS_INTRO "The test "
#define SUCCESS_END " Successfully done"


// ______________________ Size tests ________________________________________________________
int dataOnStack()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(1);
	auto p = &(vec[0]);
	RETURN_ASSERT_TRUE(p == vec.data() && p[0] == *(vec.data()));
}


int dataOnFirstHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(1); }
	auto p = &(vec[0]);
	RETURN_ASSERT_TRUE(p == vec.data() && p[0] == *(vec.data()));
}

int dataOnHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{ vec.push_back(1); }
	auto p = &(vec[0]);
	RETURN_ASSERT_TRUE(p == vec.data() && p[0] == *(vec.data()));
}

int dataOnStackConst()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(1);
	auto w(vec);
	auto p = &(w[0]);

	RETURN_ASSERT_TRUE(p == w.data() && p[0] == *(vec.data()));
}


int dataOnFirstHeapConst()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(1); }
	const auto w(vec);
	auto p = &(w[0]);

	RETURN_ASSERT_TRUE(p == w.data() && p[0] == *(vec.data()));
}

int dataOnHeapConst()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{ vec.push_back(1); }
	const auto w(vec);
	auto p = &(w[0]);

	RETURN_ASSERT_TRUE(p == w.data() && p[0] == *(vec.data()));
}

int dataChangeValue()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(411);
	++(*vec.data());
	RETURN_ASSERT_TRUE(412 == *vec.data());
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("Data method", testCase)
#define PRESUBMISSION_ASSERT(testCase)



// ______________________ Size tests ________________________________________________________
int dataOnStack()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(1);
	auto p = &(vec[0]);
	RETURN_ASSERT_TRUE(p == vec.data() && p[0] == *(vec.data()));
}


int dataOnFirstHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(1); }
	auto p = &(vec[0]);
	RETURN_ASSERT_TRUE(p == vec.data() && p[0] == *(vec.data()));
}

int dataOnHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{ vec.push_back(1); }
	auto p = &(vec[0]);
	RETURN_ASSERT_TRUE(p == vec.data() && p[0] == *(vec.data()));
}

int dataOnStackConst()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(1);
	auto w(vec);
	auto p = &(w[0]);

	RETURN_ASSERT_TRUE(p == w.data() && p[0] == *(vec.data()));
}


#include <iostream>
#include <sstream>
#include <map>
#include <array>
#include <vector>
#include <assert.h>

#define STATIC_CAPACITY 10

void print(VLVector<int, STATIC_CAPACITY> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector.at(i) << std::endl;
	}
}

void assetNumberIn(VLVector<int, STATIC_CAPACITY> vector, int num)
{
	assert(vector.size() == num);
	for (int i = 0; i < num; i++)
	{
		assert(vector.at(i) == i);
	}
}

void assertVectorEquals(std::vector<int> vec1, VLVector<int, STATIC_CAPACITY> vec2)
{
	//std::cout << vec1.size() << " size " << vec2.size() << std::endl;
	assert(vec1.size() == vec2.size());
	for (int i = 0; i < vec1.size(); i++)
	{
		//std::cout << vec1.at(i) << " " << vec2[i] << std::endl;
		assert(vec1.at(i) == vec2[i]);
	}
}

void testPushPop()
{
	VLVector<int, STATIC_CAPACITY> vector;

	for (int i = 0; i < 50; i++)
	{
		vector.push_back(i);
	}
	assetNumberIn(vector, 50);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 40);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 30);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 20);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 10);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 0);
	printf("Push/Pop test has passed \n");
}

void testInsert1Stack()
{
	// Test on the stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 2; i++)
	{
		vector.push_back(i);
	}
	VLVector<int, STATIC_CAPACITY>::iterator it = vector.begin();
	for (int i = 0; i < STATIC_CAPACITY - 4; i++)
	{
		it++;
	}
	auto itTemp = vector.insert(it, 50);
	std::vector<int> compare = {0, 1, 2, 3, 4, 5, 50, 6, 7};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 50);
	printf("testInsert1Stack succeeded \n");
}

void testInsert1StackToHeap()
{
	// Test on the stack to heap
	VLVector<int, STATIC_CAPACITY> vector2;
	for (int i = 0; i < STATIC_CAPACITY; i++)
	{
		vector2.push_back(i);
	}
	auto it2 = vector2.begin();
	for (int i = 0; i < STATIC_CAPACITY - 4; i++)
	{
		it2++;
	}
	auto itTemp = vector2.insert(it2, 50);
	std::vector<int> compare2 = {0, 1, 2, 3, 4, 5, 50, 6, 7, 8, 9};
	VLVector<int, STATIC_CAPACITY> vector3(vector2);
	assertVectorEquals(compare2, vector3);
	assert(*itTemp == 50);
	printf("testInsert1StackToHeap succeeded \n");
}

void testInsert1Heap()
{
	VLVector<int, STATIC_CAPACITY> vector4;
	auto it2 = vector4.begin();
	for (int i = 0; i < STATIC_CAPACITY + 1; i++)
	{
		vector4.push_back(i);
	}
	it2 = vector4.begin();
	for (int i = 0; i < STATIC_CAPACITY - 4; i++)
	{
		it2++;
	}
	auto itTemp = vector4.insert(it2, 50);
	std::vector<int> compare3 = {0, 1, 2, 3, 4, 5, 50, 6, 7, 8, 9, 10};
	assertVectorEquals(compare3, vector4);
	assert(*itTemp == 50);
	printf("testInsert1Heap succeeded \n");
}

void testInsert2Stack()
{
	//stay in stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 5; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 1, 2, 3, 4};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2Stack succeeded \n");
}

void testInsert2StackToHeap()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 1; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 8};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2StackToHeap succeeded \n");
}

void testInsert2Heap()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 2; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2Heap succeeded \n");
}

void testInsert2HeapAddLots()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 2; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
								  20};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
								19, 20, 1, 2, 3, 4, 5,
								6, 7, 8, 9, 10, 11};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2HeapAddLots succeeded \n");
}

void testErase1Stack()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 1; i++)
	{
		vector.push_back(i);
	}
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.erase(vecIt);
	std::vector<int> compare = {0, 2, 3, 4, 5, 6, 7, 8};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 2);
	printf("testErase1Stack succeeded \n");
}

void testErase1HeapToStack()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 1; i++)
	{
		vector.push_back(i);
	}
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.erase(vecIt);
	std::vector<int> compare = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 2);
	printf("testErase1HeapToStack succeeded \n");
}

void testErase1Heap()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 2; i++)
	{
		vector.push_back(i);
	}
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.erase(vecIt);
	std::vector<int> compare = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 2);
	printf("testErase1Heap succeeded \n");
}

void testErase2Stack()
{
	//stay in stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 5; i++)
	{
		vector.push_back(i);
	}
	auto itStart = vector.begin();
	itStart++;
	auto itEnd = vector.end();
	itEnd--;
	auto itTemp = vector.erase(itStart, itEnd);
	std::vector<int> compare = {0, 4};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 4);
	printf("testErase2Stack succeeded \n");
}

void testErase2StackToHeap()
{
	//stay in stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 1; i++)
	{
		vector.push_back(i);
	}
	auto itStart = vector.begin();
	itStart++;
	auto itEnd = vector.end();
	itEnd--;
	auto itTemp = vector.erase(itStart, itEnd);
	std::vector<int> compare = {0, 10};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 10);
	printf("testErase2StackToHeap succeeded \n");
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("Empty test", testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------

#define CAPC(X) (((3*(X+1))/2))

// ________________ Cap tests ________________________________________________________
int testsEmptyEmptyList()
{
	VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.empty() == true);
}


int testsEmptyStack()
{
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(1);
	RETURN_ASSERT_TRUE(vec.empty() != true);
}

int testsEmptyHeap()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(i); }

	RETURN_ASSERT_TRUE(vec.empty() != true);
}


int testsEmptyClearFromStack()
{
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(1);
	vec.clear();
	RETURN_ASSERT_TRUE(vec.empty() == true);
}

int testsEmptyClearFromHeap()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(i); }
	vec.clear();
	RETURN_ASSERT_TRUE(vec.empty() == true);
}


int testsEmptyAfterDefaultConstructor()
{
	VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.empty() == true);
}

int testsEmptyAfterCopyConstructorEmpty()
{
	VLVector<int, STATIC_CAP> vec;
	auto w(vec);
	RETURN_ASSERT_TRUE(w.empty() == true);
}

int testsEmptyAfterCopyConstructorNotEmpty()
{
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(i); }
	auto w(vec);
	RETURN_ASSERT_TRUE(w.empty() != true);
}

int testsEmptyConst()
{
	const VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.empty());
}

//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int emptyTests()
{
	MY_ASSERT(testsEmptyEmptyList)
	MY_ASSERT(testsEmptyStack)
	MY_ASSERT(testsEmptyHeap)
	MY_ASSERT(testsEmptyClearFromStack)
	MY_ASSERT(testsEmptyClearFromHeap)
	MY_ASSERT(testsEmptyAfterDefaultConstructor)
	MY_ASSERT(testsEmptyAfterCopyConstructorEmpty)
	MY_ASSERT(testsEmptyAfterCopyConstructorNotEmpty)
	MY_ASSERT(testsEmptyConst)


	return 1;
}


int dataOnFirstHeapConst()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(1); }
	const auto w(vec);
	auto p = &(w[0]);

	RETURN_ASSERT_TRUE(p == w.data() && p[0] == *(vec.data()));
}

int dataOnHeapConst()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP * 100; ++i)
	{ vec.push_back(1); }
	const auto w(vec);
	auto p = &(w[0]);

	RETURN_ASSERT_TRUE(p == w.data() && p[0] == *(vec.data()));
}

int dataChangeValue()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(411);
	++(*vec.data());
	RETURN_ASSERT_TRUE(412 == *vec.data());
}

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

#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("PopBack method", testCase)
#define PRESUBMISSION_ASSERT(testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define SPACE "--------------------"
#define SUCCESS_INTRO "The test "
#define SUCCESS_END " Successfully done"
#define POW(X) ((X)*(X))

// ______________________ Size tests ________________________________________________________
int iteratorPlusEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.begin();
	it += 3;
	RETURN_ASSERT_TRUE(*it == 3);
}

int iteratorPlusPlusFromRight()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.begin();
	auto it2 = it++;
	RETURN_ASSERT_TRUE(*it == 1 && *it2 == 0);
}

int iteratorPlusPlusFromLeft()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.begin();
	auto it2 = ++it;
	RETURN_ASSERT_TRUE(*it == 1 && *it2 == 1);
}

int iteratorMinusMinusFromRight()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.begin() + 1;
	auto it2 = it--;
	RETURN_ASSERT_TRUE(*it2 == 1 && *it == 0);
}

int iteratorMinusMinusFromLeft()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.begin() + 1;
	auto it2 = --it;
	RETURN_ASSERT_TRUE(*it2 == 0 && *it == 0);
}


int constiteratorPlusPlusFromRight()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.cbegin();
	auto it2 = it++;
	RETURN_ASSERT_TRUE(*it == 1 && *it2 == 0);
}

int constiteratorPlusPlusFromLeft()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.cbegin();
	auto it2 = ++it;
	RETURN_ASSERT_TRUE(*it == 1 && *it2 == 1);
}

int constiteratorMinusMinusFromRight()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.cbegin() + 1;
	auto it2 = it--;
	RETURN_ASSERT_TRUE(*it2 == 1 && *it == 0);
}

int constiteratorMinusMinusFromLeft()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.cbegin() + 1;
	auto it2 = --it;
	RETURN_ASSERT_TRUE(*it2 == 0 && *it == 0);
}


//int constIteratorPlusEqual()
//{
//	VLVector<int, STATIC_CAP> vec;
//	for (int i = 0; i < 10; ++i)
//	{ vec.push_back(i); }
//	const auto w(vec);
//	RETURN_ASSERT_TRUE(*(w.begin() += 3) == 3);
//}

int iteratorPlusFromRight()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = vec.begin();
	auto it2 = it + 3;
	RETURN_ASSERT_TRUE(*it2 == 3 && *it == 0);
}

int constIteratorPlusFromRight()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	const auto w(vec);

	auto it = w.cbegin() + 3;
	RETURN_ASSERT_TRUE(*it == 3);
}

int iteratorPlusFromLeft()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto w(vec);
	auto it = vec.begin();
	auto it2 = 3 + it;
	RETURN_ASSERT_TRUE(*it2 == 3 && *it == 0);
}

int iteratorMinusEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }

	auto it = (vec.begin() + 2);
	it -= 1;
	RETURN_ASSERT_TRUE(*it == 1);
}

int iteratorMinusIterator()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin();
	auto it2 = (vec.begin() + 2);
	RETURN_ASSERT_TRUE(it2 - it1 == 2);
}

int constIteratorMinusConstIterator()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin();
	auto it2 = (vec.cbegin() + 2);
	RETURN_ASSERT_TRUE(it2 - it1 == 2);
}

int iteratorBoolean()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin();
	auto it2 = vec.begin();
	RETURN_ASSERT_TRUE(it1 == it2 && !(it1 != it2));
}

int constIteratorBoolean()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin();
	auto it2 = vec.cbegin();
	RETURN_ASSERT_TRUE(it1 == it2 && !(it1 != it2));
}

int iteratorMinusConstIterator()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin() + 2;
	auto it2 = vec.cbegin();
	RETURN_ASSERT_TRUE(it1 - it2 == 2 && it2 - it1 == -2);
}

int constiteratorMinusIterator()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin() + 2;
	auto it2 = vec.begin();
	RETURN_ASSERT_TRUE(it1 - it2 == 2 && it2 - it1 == -2);
}

int constiteratorGreaterEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin() + 2;
	auto it2 = vec.cbegin();
	auto it3 = vec.cbegin();
	RETURN_ASSERT_TRUE(it1 >= it2 && it2 >= it3);
}

int iteratorGreaterEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin() + 2;
	auto it2 = vec.begin();
	auto it3 = vec.begin();
	RETURN_ASSERT_TRUE(it1 >= it2 && it2 >= it3);
}

int constiteratorLesserEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin() + 2;
	auto it2 = vec.cbegin();
	auto it3 = vec.cbegin();
	RETURN_ASSERT_TRUE(it2 <= it1 && it2 <= it3);
}

int iteratorLesserEqual()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin() + 2;
	auto it2 = vec.begin();
	auto it3 = vec.begin();
	RETURN_ASSERT_TRUE(it2 <= it1 && it2 <= it3);
}

int iteratorGreater()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin() + 2;
	auto it2 = vec.begin();
	auto it3 = vec.begin();
	RETURN_ASSERT_TRUE(it1 > it2 && !(it2 > it3));
}

int constIteratorGreater()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin() + 2;
	auto it2 = vec.cbegin();
	auto it3 = vec.cbegin();
	RETURN_ASSERT_TRUE(it1 > it2 && !(it2 > it3));
}

int iteratorLesser()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.begin() + 2;
	auto it2 = vec.begin();
	auto it3 = vec.begin();
	RETURN_ASSERT_TRUE(it2 < it1 && !(it2 < it3));
}

int constIteratorLesser()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	auto it1 = vec.cbegin() + 2;
	auto it2 = vec.cbegin();
	auto it3 = vec.cbegin();
	RETURN_ASSERT_TRUE(it2 < it1 && !(it2 < it3));
}

int iteratorInsert()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.insert(vec.begin(), 4);
	return 1;
}

int iteratorInsert2()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.insert(vec.begin(), vec.begin(), vec.begin());
	return 1;
}

int constiteratorInsert()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.insert(vec.cbegin(), 4);
	return 1;
}

int constiteratorInsert2()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.insert(vec.cbegin(), vec.cbegin(), vec.cbegin());
	return 1;
}


int iteratorErase()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.erase(vec.begin());
	return 1;
}

int iteratorErase2()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.erase(vec.begin(), vec.begin());
	return 1;
}

int constiteratorErase()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.erase(vec.cbegin());
	return 1;
}

int constiteratorErase2()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < 10; ++i)
	{ vec.push_back(i); }
	vec.erase(vec.cbegin(), vec.cbegin());
	return 1;
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("PopBack method", testCase)
#define PRESUBMISSION_ASSERT(testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define SPACE "--------------------"
#define SUCCESS_INTRO "The test "
#define SUCCESS_END " Successfully done"
#define POW(X) ((X)*(X))

// ______________________ Size tests ________________________________________________________
int popBackEmpty()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.pop_back();
	RETURN_ASSERT_TRUE(vec.size() == 0);
}


int popBackFromHeapToStack()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{
		vec.push_back(i);
	}
	auto p = vec.data();
	vec.pop_back();
	RETURN_ASSERT_TRUE(vec.size() == STATIC_CAP && p != vec.data());
}

int popBackFromHeapToHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < POW(STATIC_CAP); ++i)
	{ vec.push_back(i); }

	auto p = vec.data();
	while (vec.size() > (STATIC_CAP + 1))
	{ vec.pop_back(); }

	RETURN_ASSERT_TRUE(p == vec.data());
}


//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int popBackTests()
{
	MY_ASSERT(popBackEmpty)
	MY_ASSERT(popBackFromHeapToStack)
	MY_ASSERT(popBackFromHeapToHeap)


	return 1;
}


#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("PushBack method", testCase)
#define PRESUBMISSION_ASSERT(testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define SPACE "--------------------"
#define SUCCESS_INTRO "The test "
#define SUCCESS_END " Successfully done"


// ______________________ Size tests ________________________________________________________
int pushBackToEmpty()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	vec.push_back(411);
	RETURN_ASSERT_TRUE(vec[0] == 411 && vec.size() == 1);
}


int pushBackFromStackToHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	auto p = vec.data();
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{
		vec.push_back(i);
	}
	RETURN_ASSERT_TRUE(vec[STATIC_CAP] == STATIC_CAP && vec.data() != p);
}

int pushBackFromHeapToHeap()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (auto i = 0; i < STATIC_CAP + 1; ++i)
	{ vec.push_back(i); }
	auto p = vec.data();
	auto cap = vec.capacity();
	for (auto i = 0; i < cap; ++i)
	{ vec.push_back(i * 10000); }
	RETURN_ASSERT_TRUE(vec[vec.size() - 1] == (cap - 1) * 10000 && vec.data() != p);
}

#include <iostream>
#include <vector>
#include <algorithm>

#define MY_ASSERT(testCase) __ASSERT_TEST("size method", testCase)
#define PRESUBMISSION_ASSERT(testCase)

//-------------------------------------------------------
// Tests
//-------------------------------------------------------
#define SPACE "--------------------"
#define SUCCESS_INTRO "The test "
#define SUCCESS_END " Successfully done"


// ______________________ Size tests ________________________________________________________
int testsSizeEmptyList()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.size() == 0)
}

int testsSizeListOnStack()
{
	// Test 1 : Empty list
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < STATIC_CAP - 1; ++i)
	{
		vec.push_back(i);
	}
	RETURN_ASSERT_TRUE(vec.size() == STATIC_CAP - 1)
}

int testsSizeListOnHeap()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < STATIC_CAP + 4; ++i)
	{
		vec.push_back(i);
	}
	RETURN_ASSERT_TRUE(vec.size() == STATIC_CAP + 4)
}


int testsSizeListOnHeapAfterFewAllocations()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < (STATIC_CAP * 5); ++i)
	{
		vec.push_back(i);
	}
	RETURN_ASSERT_TRUE(vec.size() == STATIC_CAP * 5)
}

int testsSizeAfterClearFromStack()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < STATIC_CAP - 1; ++i)
	{
		vec.push_back(i);
	}
	vec.clear();
	RETURN_ASSERT_TRUE(vec.size() == 0)
}

int testsSizeAfterClearFromHeap()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < STATIC_CAP + 5; ++i)
	{
		vec.push_back(i);
	}
	vec.clear();
	RETURN_ASSERT_TRUE(vec.size() == 0)
}


int testsSizeAfterPopBackToEmptyList()
{
	VLVector<int, STATIC_CAP> vec;
	vec.pop_back();
	RETURN_ASSERT_TRUE(vec.size() == 0)
}

int testsSizeAfterEraseToEmptyList()
{
	VLVector<int, STATIC_CAP> vec;
	vec.erase(vec.begin());
	RETURN_ASSERT_TRUE(vec.size() == 0)
}

int testsSizeAfterErase2ToEmptyList()
{
	VLVector<int, STATIC_CAP> vec;
	vec.erase(vec.begin(), vec.end());
	RETURN_ASSERT_TRUE(vec.size() == 0)
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEF_SIZE 4

void printVLV(const VLVector<int, DEF_SIZE> &a)
{
	for (int i = 0; i < (int) a.size(); i++)
	{
		std::cout << "a[" << i << "]=" << a[i] << std::endl;
	}
}

void checkEqualOP1() // b is static, a is dynm
{
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 2; i++)
	{
		b.push_back(i);
	}
	assert(b != a);
	b = a;
	assert(b == a);
}

void checkEqualOP2() // b is dynm, a is dynm
{
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
	}
	assert(b != a);
	b = a;
	assert(b == a);

}

void checkEqualOP3() // b is dynm, a is stat
{
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
	}
	assert(b != a);
	b = a;
	assert(b == a);
}

void checkEqualOP4() // b is stat, a is stat
{
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 2; i++)
	{
		b.push_back(i);
	}
	assert(b != a);
	b = a;
	assert(b == a);
}

void checkEqOp()
{
	checkEqualOP1();
	checkEqualOP2();
	checkEqualOP3();
	checkEqualOP4();
}

void checkCompOp()
{
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 3; i++)
	{
		b.push_back(i);
	}
	assert(a == b);
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		b.push_back(i);
	}
	assert(a == b);
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 5; i++)
	{
		b.push_back(i);
	}
	assert(!(a == b));
	a.clear();
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		b.push_back(i);
	}
	assert(!(a == b));
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		if (i == 5)
		{
			b.push_back(20);
		}
		else
		{
			b.push_back(i);
		}
	}
	assert(!(a == b));
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
	}
	assert(!(a == b));
	a.clear();
	for (int i = 0; i < 2; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		b.push_back(i);
	}
	assert(!(a == b));
}

void checkNonCompOp()
{
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 3; i++)
	{
		b.push_back(i);
	}
	assert(!(a != b));
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		b.push_back(i);
	}
	assert(!(a != b));
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 5; i++)
	{
		b.push_back(i);
	}
	assert((a != b));
	a.clear();
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		b.push_back(i);
	}
	assert((a != b));
	a.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		if (i == 5)
		{
			b.push_back(20);
		}
		else
		{
			b.push_back(i);
		}
	}
	assert((a != b));
}

void checkItr()
{
	VLVector<int, DEF_SIZE> a;
	std::vector<int> b;
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	int j = 0;
	for (auto &cur:a)
	{
		assert(cur == b[j]);
		j++;
	}
	j = 0;
	a.clear();
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (auto &cur:a)
	{
		assert(cur == b[j]);
		j++;
	}
	j = 0;
	a.clear();
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (const auto &cur:a)
	{
		assert(cur == b[j]);
		j++;
	}
	j = 0;
	a.clear();
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (const auto &cur:a)
	{
		assert(cur == b[j]);
		j++;
	}
	j = 0;
	a.clear();
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto cura = a.begin();
	auto curb = b.begin();
	curb++;
	cura++;
	assert(*cura == *curb);
	curb += 5;
	cura += 5;
	assert(*cura == *curb);
	auto curb2 = curb + 10;
	auto cura2 = cura + 10;
	assert(*cura2 == *curb2);
	a.clear();
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	const VLVector<int, DEF_SIZE> f(a);
	auto ita = f.begin();
	auto itb = b.begin();
	assert(*ita == *itb);
	a.clear();
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	const VLVector<int, DEF_SIZE> r(a);
	ita = r.begin();
	itb = b.begin();
	assert(*ita == *itb);
	a.clear();
	b.clear();
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto it2a = a.begin();
	auto it2b = b.begin();
	it2a = it2a + 5;
	it2b = it2b + 5;
	assert(*it2a == *it2b);
	it2a = -3 + it2a;
	it2b = -3 + it2b;
	assert(*it2a == *it2b);
	const VLVector<int, DEF_SIZE> vlv(a);
	auto it3a = vlv.begin();
	auto it3b = b.begin();
	it3a = it3a + 5;
	it3b = it3b + 5;
	assert(*it3a == *it3b);
	it3a = -3 + it3a;
	it3b = -3 + it3b;
	assert(*it3a == *it3b);


}

void insert1()
{
	VLVector<int, DEF_SIZE> a;
	std::vector<int> b;
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto ita = a.begin();
	auto itb = b.begin();
	ita += 6;
	itb += 6;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 20; i++)
	{ assert(a[i] == b[i]); }
	b.clear();
	a.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita = a.begin();
	itb = b.begin();
	ita += 2;
	itb += 2;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 3; i++)
	{ assert(a[i] == b[i]); }
	b.clear();
	a.clear();
	for (int i = 0; i < 4; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita = a.begin();
	itb = b.begin();
	ita += 3;
	itb += 3;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 4; i++)
	{ assert(a[i] == b[i]); }
	b.clear();
	a.clear();
	for (int i = 0; i < 7; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita = a.begin();
	itb = b.begin();
	ita += 3;
	itb += 3;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 7; i++)
	{ assert(a[i] == b[i]); }

}

void insert1Const()
{
	std::vector<int> b;
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto ita = a.cbegin();
	auto itb = b.cbegin();
	ita += 6;
	itb += 6;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 20; i++)
	{ assert(a[i] == b[i]); }
	a.clear();
	b.clear();
	for (int i = 0; i < 2; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita = a.cbegin();
	itb = b.cbegin();
	ita += 2;
	itb += 2;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 2; i++)
	{ assert(a[i] == b[i]); }
	a.clear();
	b.clear();
	for (int i = 0; i < 4; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita = a.cbegin();
	ita += 3;
	itb = b.cbegin();
	itb += 3;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 4; i++)
	{ assert(a[i] == b[i]); }
	a.clear();
	b.clear();
	for (int i = 0; i < 7; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita = a.cbegin();
	ita += 3;
	itb = b.cbegin();
	itb += 3;
	assert(*a.insert(ita, 300) == *b.insert(itb, 300));
	for (unsigned long i = 0; i < 7; i++)
	{ assert(a[i] == b[i]); }

}

void checkBuilder()
{
	std::vector<int> a;
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b(a.begin(), a.end());
	for (unsigned long i = 0; i < 3; i++)
	{ assert(a[i] == b[i]); }
	a.clear();
	for (int i = 0; i < 15; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> c(a.begin(), a.end());
	for (unsigned long i = 0; i < 15; i++)
	{ assert(a[i] == c[i]); }
}

void insert2()
{
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	std::vector<int> ref;
	for (int i = 11; i < 20; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb = b.begin();
	auto iteref = ref.begin();
	iterb += 5;
	iteref += 5;
	assert(*b.insert(iterb, a.begin(), a.end()) == *ref.insert(iteref, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }

	a.clear();
	b.clear();
	ref.clear();
	for (int i = 1; i < 3; i++)
	{
		a.push_back(i * 30);
	}
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	iterb = b.begin();
	iterb += 2;
	iteref = ref.begin();
	iteref += 2;
	assert(*b.insert(iterb, a.begin(), a.end()) == *ref.insert(iteref, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	a.clear();
	b.clear();
	ref.clear();
	for (int i = 1; i < 10; i++)
	{
		a.push_back(i * 30);
	}
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	iterb = b.begin();
	iterb += 2;
	iteref = ref.begin();
	iteref += 2;
	assert(*b.insert(iterb, a.begin(), a.end()) == *ref.insert(iteref, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	a.clear();
	b.clear();
	for (int i = 1; i < 2; i++)
	{
		a.push_back(i * 30);
	}
	for (int i = 0; i < 10; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	iterb = b.begin();
	iterb += 2;
	iteref = ref.begin();
	iteref += 2;
	assert(*b.insert(iterb, a.begin(), a.end()) == *ref.insert(iteref, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }


}

void constInsert2()
{
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	VLVector<int, DEF_SIZE> b;
	std::vector<int> ref;
	for (int i = 11; i < 20; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb = b.cbegin();
	iterb += 5;
	auto iteref = ref.cbegin();
	iteref += 5;
	assert(*b.insert(iterb, a.begin(), a.end()) == *ref.insert(iteref, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	a.clear();
	b.clear();
	for (int i = 1; i < 3; i++)
	{
		a.push_back(i * 30);
	}
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb2 = b.cbegin();
	(iterb2) += 2;
	auto iteref2 = ref.cbegin();
	(iteref2) += 2;
	assert(*b.insert(iterb2, a.begin(), a.end()) == *ref.insert(iteref2, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	a.clear();
	b.clear();
	for (int i = 1; i < 10; i++)
	{
		a.push_back(i * 30);
	}
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb3 = b.cbegin();
	(iterb3) += 2;
	auto iteref3 = ref.cbegin();
	(iteref3) += 2;
	assert(*b.insert(iterb3, a.begin(), a.end()) == *ref.insert(iteref3, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	a.clear();
	b.clear();
	for (int i = 1; i < 2; i++)
	{
		a.push_back(i * 30);
	}
	for (int i = 0; i < 10; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb4 = b.cbegin();
	(iterb4) += 2;
	auto iteref4 = ref.cbegin();
	(iteref4) += 2;
	assert(*b.insert(iterb4, a.begin(), a.end()) == *ref.insert(iteref4, a.begin(), a.end()));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }


}

void erase()
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

void constErase()
{
	std::vector<int> ref;
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb = b.cbegin() + 5;
	auto lastb = b.cbegin() + 10;
	auto firstref = ref.cbegin() + 5;
	auto lastref = ref.cbegin() + 10;
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
	auto first2b = b.cbegin() + 1;
	auto last2b = b.cbegin() + 13;
	auto first2ref = ref.cbegin() + 1;
	auto last2ref = ref.cbegin() + 13;
	assert(*b.erase(first2b, last2b) == *ref.erase(first2ref, last2ref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first3b = b.cbegin() + 1;
	auto last3b = b.cbegin() + 3;
	auto first3ref = ref.cbegin() + 1;
	auto last3ref = ref.cbegin() + 3;
	assert(*b.erase(first3b, last3b) == *ref.erase(first3ref, last3ref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }


}

void eraseSingle()
{
	std::vector<int> ref;
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb = b.begin() + 5;
	auto firstref = ref.begin() + 5;
	assert(*b.erase(firstb) == *ref.erase(firstref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 5; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb = b.begin() + 2;
	firstref = ref.begin() + 2;
	assert(*b.erase(firstb) == *ref.erase(firstref));
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
	firstref = ref.begin() + 1;
	assert(*b.erase(firstb) == *ref.erase(firstref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb = b.end() - 1;
	firstref = ref.end() - 1;
	assert(*b.erase(firstb) == *ref.erase(firstref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }


}

void constEraseSingle()
{
	std::vector<int> ref;
	VLVector<int, DEF_SIZE> b;
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb = b.cbegin() + 5;
	auto firstref = ref.cbegin() + 5;
	assert(*b.erase(firstb) == *ref.erase(firstref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 15; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first2b = b.cbegin() + 1;
	auto first2ref = ref.cbegin() + 1;
	assert(*b.erase(first2b) == *ref.erase(first2ref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }
	ref.clear();
	b.clear();
	for (int i = 0; i < 4; i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first3b = b.cbegin() + 1;
	auto first3ref = ref.cbegin() + 1;
	assert(*b.erase(first3b) == *ref.erase(first3ref));
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(ref[i] == b[i]); }

}

void sort()
{
	std::vector<int> a = {5, 8, 3, 7, 5, 9, 543, 321, 765, 21, 6};
	VLVector<int, DEF_SIZE> b(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	std::sort(a.begin(), a.end());
	for (unsigned long i = 0; i < (unsigned long) b.size(); i++)
	{ assert(a[i] == b[i]); }

}

void forEach()
{
	std::vector<int> a = {5, 8, 3, 7, 5, 9, 543, 321, 765, 21, 6};
	VLVector<int, DEF_SIZE> b(a.begin(), a.end());
	int sumB = 0, sumA = 0;
	std::for_each(b.begin(), b.end(), [&sumB](int x) -> int { return sumB += x; });
	std::for_each(a.begin(), a.end(), [&sumA](int x) -> int { return sumA += x; });
	assert(sumA == sumB);
}

void checkAt()
{
	std::vector<int> a = {5, 8, 3, 7, 5, 9, 543, 321, 765, 21, 6};
	VLVector<int, DEF_SIZE> b(a.begin(), a.end());
	try
	{ std::cout << b.at(-5) << std::endl; }
	catch (...)
	{}
	try
	{ std::cout << b.at(500) << std::endl; }
	catch (...)
	{}
	for (unsigned long i = 0; i < (unsigned long) a.size(); i++)
	{ assert(a.at(i) == b.at(i)); }

}

void checkConstructors()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	VLVector<int, DEF_SIZE> b(a.begin(), a.end());
	for (unsigned long i = 0; i < (unsigned long) a.size(); i++)
	{ assert(a[i] == b[i]); }
	VLVector<int, DEF_SIZE> c(b);
	for (unsigned long i = 0; i < (unsigned long) a.size(); i++)
	{ assert(c[i] == a[i]); }
	std::vector<int> a2 = {1, 2, 3};
	VLVector<int, DEF_SIZE> b2(a2.begin(), a2.end());
	for (unsigned long i = 0; i < (unsigned long) a2.size(); i++)
	{ assert(a2[i] == b2[i]); }
	VLVector<int, DEF_SIZE> c2(b);
	for (unsigned long i = 0; i < (unsigned long) a2.size(); i++)
	{ assert(a2[i] == c2[i]); }
}

void checkCap()
{
	//--------------------- constructor --------------------
	std::vector<int> b;
	for (int i = 0; i < 2; i++)
	{ b.push_back(i); }
	VLVector<int, DEF_SIZE> a1(b.begin(), b.end());
	assert(a1.capacity() == DEF_SIZE);
	for (int i = 0; i < 3; i++)
	{ b.push_back(i); }
	VLVector<int, DEF_SIZE> a2(b.begin(), b.end());
	assert(a2.capacity() == 7);
	for (int i = 0; i < 4; i++)
	{ b.push_back(i); }
	VLVector<int, DEF_SIZE> a3(b.begin(), b.end());
	assert(a3.capacity() == 12);
	//---------- push back-------------------
	VLVector<int, DEF_SIZE> a;
	for (int i = 0; i < 2; i++)
	{ a.push_back(i); }
	assert(a.capacity() == DEF_SIZE);
	for (int i = 0; i < 2; i++)
	{ a.push_back(i); }
	assert(a.capacity() == DEF_SIZE);
	for (int i = 0; i < 2; i++)
	{ a.push_back(i); }
	assert(a.capacity() == 7);
	a.push_back(1);
	assert(a.capacity() == 7);
	a.push_back(1);
	assert(a.capacity() == 12);
	//--------------------- insert --------------------
	a.clear();
	for (int i = 0; i < 6; i++)
	{ a.push_back(i); }
	b.clear();
	for (int i = 0; i < 10; i++)
	{ b.push_back(i); }
	auto it = a.begin() + 2;
	a.insert(it, b.begin(), b.end());
	assert(a.capacity() == 19);
	//----------------- erase -----------------------
	it = a.begin() + 2;
	auto it2 = a.begin() + 10;
	a.erase(it, it2);
	assert(a.capacity() == 19);
	it = a.begin();
	it2 = a.begin() + 5;
	a.erase(it, it2);
	assert(a.capacity() == DEF_SIZE);


}


int testsSizeAfterCopyConstructor()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < STATIC_CAP + 5; ++i)
	{
		vec.push_back(i);
	}
	auto w(vec);
	RETURN_ASSERT_TRUE(vec.size() == w.size())
}

int testsSizeAfterAssignmentOperator()
{
	VLVector<int, STATIC_CAP> vec;
	for (int i = 0; i < STATIC_CAP + 5; ++i)
	{
		vec.push_back(i);
	}
	auto w = vec;
	RETURN_ASSERT_TRUE(vec.size() == w.size())
}

int testsSizeConst()
{
	const VLVector<int, STATIC_CAP> vec;
	RETURN_ASSERT_TRUE(vec.size() == 0)
}

//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int sizeTests()
{
	MY_ASSERT(testsSizeEmptyList)
	MY_ASSERT(testsSizeListOnStack)
	MY_ASSERT(testsSizeListOnHeap)
	MY_ASSERT(testsSizeListOnHeapAfterFewAllocations)
	MY_ASSERT(testsSizeAfterClearFromStack)
	MY_ASSERT(testsSizeAfterClearFromHeap)
	MY_ASSERT(testsSizeAfterPopBackToEmptyList)
	MY_ASSERT(testsSizeAfterEraseToEmptyList)
	MY_ASSERT(testsSizeAfterErase2ToEmptyList)
	MY_ASSERT(testsSizeAfterCopyConstructor)
	MY_ASSERT(testsSizeAfterAssignmentOperator)
	MY_ASSERT(testsSizeConst)

	return 1;
}


//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int pushBackTests()
{
	MY_ASSERT(pushBackToEmpty)
	MY_ASSERT(pushBackFromStackToHeap)
	MY_ASSERT(pushBackFromHeapToHeap)


	return 1;
}

//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int iteratorsTests()
{
	MY_ASSERT(iteratorPlusEqual)
	MY_ASSERT(iteratorPlusPlusFromRight)
	MY_ASSERT(iteratorPlusPlusFromLeft)
	MY_ASSERT(iteratorMinusMinusFromRight)
//	MY_ASSERT(constIteratorPlusEqual)
	MY_ASSERT(iteratorMinusMinusFromLeft)
	MY_ASSERT(iteratorPlusFromRight)
	MY_ASSERT(constiteratorPlusPlusFromLeft)
	MY_ASSERT(constiteratorMinusMinusFromRight)
	MY_ASSERT(constiteratorMinusMinusFromLeft)
	MY_ASSERT(constiteratorPlusPlusFromRight)
	MY_ASSERT(constIteratorPlusFromRight)
	MY_ASSERT(iteratorPlusFromLeft)
	MY_ASSERT(iteratorMinusEqual)
	MY_ASSERT(iteratorMinusIterator)
	MY_ASSERT(iteratorMinusConstIterator)
	MY_ASSERT(constiteratorMinusIterator)
	MY_ASSERT(constIteratorMinusConstIterator)
	MY_ASSERT(iteratorBoolean)
	MY_ASSERT(constIteratorBoolean)
	MY_ASSERT(iteratorGreaterEqual)
	MY_ASSERT(constiteratorGreaterEqual)
	MY_ASSERT(constiteratorLesserEqual)
	MY_ASSERT(iteratorLesserEqual)
	MY_ASSERT(iteratorGreater)
	MY_ASSERT(constIteratorGreater)
	MY_ASSERT(iteratorLesser)
	MY_ASSERT(constIteratorLesser)
	MY_ASSERT(iteratorInsert)
	MY_ASSERT(iteratorInsert2)
	MY_ASSERT(constiteratorInsert)
	MY_ASSERT(constiteratorInsert2)
	MY_ASSERT(iteratorErase)
	MY_ASSERT(iteratorErase2)
	MY_ASSERT(constiteratorErase)
	MY_ASSERT(constiteratorErase2)


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

//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int dataTests()
{
	MY_ASSERT(dataOnStack)
	MY_ASSERT(dataOnFirstHeap)
	MY_ASSERT(dataOnHeap)
	MY_ASSERT(dataOnStackConst)
	MY_ASSERT(dataOnFirstHeapConst)
	MY_ASSERT(dataOnHeapConst)
	MY_ASSERT(dataChangeValue)

	return 1;
}


//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int dataTests()
{
	MY_ASSERT(dataOnStack)
	MY_ASSERT(dataOnFirstHeap)
	MY_ASSERT(dataOnHeap)
	MY_ASSERT(dataOnStackConst)
	MY_ASSERT(dataOnFirstHeapConst)
	MY_ASSERT(dataOnHeapConst)
	MY_ASSERT(dataChangeValue)

	return 1;
}


//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int clearTests()
{
	MY_ASSERT(testsClearEmpty)
	MY_ASSERT(testsClearOnStack)
	MY_ASSERT(testsClearOnHeap)

	return 1;
}

//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int capTests()
{
	MY_ASSERT(testCapEmptyList)
	MY_ASSERT(testCapLimitStack)
	MY_ASSERT(testCapFirstHeap)
	MY_ASSERT(testCapReturnFromHeapToStack)
	MY_ASSERT(testCapReturnFromHeapToHeap)
	MY_ASSERT(testsCapConst)
	MY_ASSERT(testCapCopyConstructor)
	MY_ASSERT(testCapOperatorEqual)


	return 1;
}


//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int bracketsTests()
{
	MY_ASSERT(testsBracketsSize1)
	MY_ASSERT(testBracketsNonConst)
	MY_ASSERT(testBracketsConst)


	return 1;
}


//-------------------------------------------------------
//  The main entry point
//-------------------------------------------------------
int atTests()
{
	MY_ASSERT(testsAtEmpty)
	MY_ASSERT(testsAtSize1)
	MY_ASSERT(testsAtAfterIndexOutOfErrorThereIsAccess)
	MY_ASSERT(testAtNonConst)
	MY_ASSERT(testAtConst)


	return 1;
}

int mineTests()
{
	checkConstructors();
	checkNonCompOp();
	checkCompOp();
	checkEqOp();
	checkItr();
	insert1();
	insert1Const();
	checkBuilder();
	insert2();
	constInsert2();
	erase();
	constErase();
	eraseSingle();
	constEraseSingle();
	sort();
	forEach();
	checkAt();
	checkCap();


}

int generalTests()
{
	testPushPop();
	testInsert1Heap();
	testInsert1Stack();
	testInsert1StackToHeap();
	testInsert2Stack();
	testInsert2StackToHeap();
	testInsert2Heap();
	testInsert2HeapAddLots();
	testErase1Stack();
	testErase1HeapToStack();
	testErase1Heap();
	testErase2Stack();
	testErase2StackToHeap();
}

int main()
{
	atTests();
	bracketsTests();
	capTests();
	clearTests();
	dataTests();
	emptyTests();
	insertTests();
	iteratorsTests();
	popBackTests();
	pushBackTests();
	sizeTests();
	mineTests();


	std::vector<int> v(100, 101);
	VLVector<int, 3> w;
	w.insert(w.begin(), v.begin(), v.begin() + 50);
	w.insert(w.begin(), v.begin(), v.begin() + 50);
	w.insert(w.begin(), v.begin(), v.begin() + 50);
	w.erase(v.end());
	w.erase(w.begin()
	_20, w.end());

}