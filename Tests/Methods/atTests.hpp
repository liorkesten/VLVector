
#include "../../VLVector.hpp"
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

