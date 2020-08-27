
#include <iostream>
#include <sstream>
#include <map>
#include <array>
#include <vector>
#include "../VLVector.hpp"
#include <assert.h>

#define STATIC_CAPACITY 10

void print(VLVector<int, STATIC_CAPACITY> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector.at(i) << std::endl;
	}
}

void assetNumberIn(VLVector<int, STATIC_CAPACITY> vector, int num)
{
	assert(vector.size() == num);
	for (int i = 0; i < num; i++)
	{
		assert(vector.at(i) == i);
	}
}

void assertVectorEquals(std::vector<int> vec1, VLVector<int, STATIC_CAPACITY> vec2)
{
	//std::cout << vec1.size() << " size " << vec2.size() << std::endl;
	assert(vec1.size() == vec2.size());
	for (int i = 0; i < vec1.size(); i++)
	{
		//std::cout << vec1.at(i) << " " << vec2[i] << std::endl;
		assert(vec1.at(i) == vec2[i]);
	}
}

void testPushPop()
{
	VLVector<int, STATIC_CAPACITY> vector;

	for (int i = 0; i < 50; i++)
	{
		vector.push_back(i);
	}
	assetNumberIn(vector, 50);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 40);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 30);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 20);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 10);
	for (int i = 0; i < 10; i++)
	{
		vector.pop_back();
	}
	assetNumberIn(vector, 0);
	printf("Push/Pop test has passed \n");
}

void testInsert1Stack()
{
	// Test on the stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 2; i++)
	{
		vector.push_back(i);
	}
	VLVector<int, STATIC_CAPACITY>::iterator it = vector.begin();
	for (int i = 0; i < STATIC_CAPACITY - 4; i++)
	{
		it++;
	}
	auto itTemp = vector.insert(it, 50);
	std::vector<int> compare = {0, 1, 2, 3, 4, 5, 50, 6, 7};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 50);
	printf("testInsert1Stack succeeded \n");
}

void testInsert1StackToHeap()
{
	// Test on the stack to heap
	VLVector<int, STATIC_CAPACITY> vector2;
	for (int i = 0; i < STATIC_CAPACITY; i++)
	{
		vector2.push_back(i);
	}
	auto it2 = vector2.begin();
	for (int i = 0; i < STATIC_CAPACITY - 4; i++)
	{
		it2++;
	}
	auto itTemp = vector2.insert(it2, 50);
	std::vector<int> compare2 = {0, 1, 2, 3, 4, 5, 50, 6, 7, 8, 9};
	VLVector<int, STATIC_CAPACITY> vector3(vector2);
	assertVectorEquals(compare2, vector3);
	assert(*itTemp == 50);
	printf("testInsert1StackToHeap succeeded \n");
}

void testInsert1Heap()
{
	VLVector<int, STATIC_CAPACITY> vector4;
	auto it2 = vector4.begin();
	for (int i = 0; i < STATIC_CAPACITY + 1; i++)
	{
		vector4.push_back(i);
	}
	it2 = vector4.begin();
	for (int i = 0; i < STATIC_CAPACITY - 4; i++)
	{
		it2++;
	}
	auto itTemp = vector4.insert(it2, 50);
	std::vector<int> compare3 = {0, 1, 2, 3, 4, 5, 50, 6, 7, 8, 9, 10};
	assertVectorEquals(compare3, vector4);
	assert(*itTemp == 50);
	printf("testInsert1Heap succeeded \n");
}

void testInsert2Stack()
{
	//stay in stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 5; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 1, 2, 3, 4};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2Stack succeeded \n");
}

void testInsert2StackToHeap()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 1; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 8};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2StackToHeap succeeded \n");
}

void testInsert2Heap()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 2; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2Heap succeeded \n");
}

void testInsert2HeapAddLots()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 2; i++)
	{
		vector.push_back(i);
	}
	std::vector<int> inputIter = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
								  20};
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.insert(vecIt, inputIter.begin(), inputIter.end());
	std::vector<int> compare = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
								19, 20, 1, 2, 3, 4, 5,
								6, 7, 8, 9, 10, 11};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 1);
	printf("testInsert2HeapAddLots succeeded \n");
}

void testErase1Stack()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 1; i++)
	{
		vector.push_back(i);
	}
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.erase(vecIt);
	std::vector<int> compare = {0, 2, 3, 4, 5, 6, 7, 8};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 2);
	printf("testErase1Stack succeeded \n");
}

void testErase1HeapToStack()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 1; i++)
	{
		vector.push_back(i);
	}
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.erase(vecIt);
	std::vector<int> compare = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 2);
	printf("testErase1HeapToStack succeeded \n");
}

void testErase1Heap()
{
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 2; i++)
	{
		vector.push_back(i);
	}
	auto vecIt = vector.begin();
	vecIt++;
	auto itTemp = vector.erase(vecIt);
	std::vector<int> compare = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 2);
	printf("testErase1Heap succeeded \n");
}

void testErase2Stack()
{
	//stay in stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY - 5; i++)
	{
		vector.push_back(i);
	}
	auto itStart = vector.begin();
	itStart++;
	auto itEnd = vector.end();
	itEnd--;
	auto itTemp = vector.erase(itStart, itEnd);
	std::vector<int> compare = {0, 4};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 4);
	printf("testErase2Stack succeeded \n");
}

void testErase2StackToHeap()
{
	//stay in stack
	VLVector<int, STATIC_CAPACITY> vector;
	for (int i = 0; i < STATIC_CAPACITY + 1; i++)
	{
		vector.push_back(i);
	}
	auto itStart = vector.begin();
	itStart++;
	auto itEnd = vector.end();
	itEnd--;
	auto itTemp = vector.erase(itStart, itEnd);
	std::vector<int> compare = {0, 10};
	assertVectorEquals(compare, vector);
	assert(*itTemp == 10);
	printf("testErase2StackToHeap succeeded \n");
}



int generalTests()
{
	testPushPop();
	testInsert1Heap();
	testInsert1Stack();
	testInsert1StackToHeap();
	testInsert2Stack();
	testInsert2StackToHeap();
	testInsert2Heap();
	testInsert2HeapAddLots();
	testErase1Stack();
	testErase1HeapToStack();
	testErase1Heap();
	testErase2Stack();
	testErase2StackToHeap();
}
