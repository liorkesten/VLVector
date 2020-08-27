

#include "../../VLVector.hpp"
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
