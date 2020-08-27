

#include "../../VLVector.hpp"
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

