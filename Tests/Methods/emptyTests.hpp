
#include "../../VLVector.hpp"
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

