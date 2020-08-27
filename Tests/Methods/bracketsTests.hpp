
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

