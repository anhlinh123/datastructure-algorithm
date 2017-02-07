#include "stdafx.h"
#include "CppUnitTest.h"
#include "ArrayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(ArrayListTest)
	{
	public:
		TEST_METHOD(TestConstructor1)
		{
			int array[] = { 1, 2, 3 };
			ArrayList<int> arrayList = ArrayList<int>(3, array);
			Assert::IsTrue(arrayList.CheckContent(array, 3), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestConstructor2)
		{
			int array[] = { 1 };
			ArrayList<int> arrayList = ArrayList<int>(1, array);
			Assert::IsTrue(arrayList.CheckContent(array, 1), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestConstructor3)
		{
			ArrayList<int> arrayList = ArrayList<int>(0, nullptr);
			Assert::IsTrue(arrayList.CheckContent(nullptr, 0), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestAdd1)
		{
			int array[] = { 1, 2, 3 };
			int testArray[] = { 1, 2, 3, 4 };
			ArrayList<int> arrayList = ArrayList<int>(3, array);
			arrayList.Add(4);
			Assert::IsTrue(arrayList.CheckContent(testArray, 4), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestAdd2)
		{
			int array[] = { 1, 2, 3 };
			int testArray[] = { 1, 2, 3, 4, 5 };
			ArrayList<int> arrayList = ArrayList<int>(3, array);
			arrayList.Add(4);
			arrayList.Add(5);
			Assert::IsTrue(arrayList.CheckContent(testArray, 5), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestAdd3)
		{
			int testArray[] = { 100 };
			ArrayList<int> arrayList;
			arrayList.Add(100);
			Assert::IsTrue(arrayList.CheckContent(testArray, 1), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestAdd4)
		{
			int testArray[] = { 100, 600, 5345, 3463461, 2424, 2315, 16773, 724, 135, 1737, 155, 3155, 146, 27456, 3156, 167547, 1346 };
			ArrayList<int> arrayList;
			arrayList.Add(100);
			arrayList.Add(600);
			arrayList.Add(5345);
			arrayList.Add(3463461);
			arrayList.Add(2424);
			arrayList.Add(2315);
			arrayList.Add(16773);
			arrayList.Add(724);
			arrayList.Add(135);
			arrayList.Add(1737);
			arrayList.Add(155);
			arrayList.Add(3155);
			arrayList.Add(146);
			arrayList.Add(27456);
			arrayList.Add(3156);
			arrayList.Add(167547);
			arrayList.Add(1346);

			Assert::IsTrue(arrayList.CheckContent(testArray, 17), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestInsert1)
		{
			int testArray[] = { 100 };
			ArrayList<int> arrayList;
			arrayList.Insert(100, 0);
			Assert::IsTrue(arrayList.CheckContent(testArray, 1), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestInsert2)
		{
			int array[] = { 100, 361, 614 };
			int testArray[] = { 100, 4214, 361, 1636, 614 };
			ArrayList<int> arrayList = ArrayList<int>(3, array);
			arrayList.Insert(4214, 1);
			arrayList.Insert(1636, 3);
			Assert::IsTrue(arrayList.CheckContent(testArray, 5), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestRemove1)
		{
			int array[] = { 100, 361, 614 };
			int testArray[] = { 100, 614 };
			ArrayList<int> arrayList = ArrayList<int>(3, array);
			arrayList.Remove(1);
			Assert::IsTrue(arrayList.CheckContent(testArray, 2), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestRemove2)
		{
			int array[] = { 100 };
			int testArray[] = { 1 };
			ArrayList<int> arrayList = ArrayList<int>(1, array);
			arrayList.Remove(0);
			Assert::IsTrue(arrayList.CheckContent(testArray, 0), L"failed", LINE_INFO());
		}

		TEST_METHOD(TestRemove3)
		{
			int array[] = { 100, 231, 5341, 613461, 34125, 61363 };
			int testArray[] = { 231, 5341, 61363 };
			ArrayList<int> arrayList = ArrayList<int>(6, array);
			arrayList.Remove(0);
			arrayList.Remove(3);
			arrayList.Remove(2);
			Assert::IsTrue(arrayList.CheckContent(testArray, 3), L"failed", LINE_INFO());
		}
	};
}