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
