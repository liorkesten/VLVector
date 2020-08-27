#include "../../VLVector.hpp"
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
