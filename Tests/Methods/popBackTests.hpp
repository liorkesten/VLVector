

#include "../../VLVector.hpp"
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
