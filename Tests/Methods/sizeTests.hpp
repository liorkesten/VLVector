#include "../../VLVector.hpp"
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
	MY_ASSERT(__presubmit_testCreateVLAs)
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
