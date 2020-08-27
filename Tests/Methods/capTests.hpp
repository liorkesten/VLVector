
#include "../../VLVector.hpp"
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

