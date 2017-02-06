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
		}

		TEST_METHOD(TestAdd5)
		{
		}

		TEST_METHOD(TestInsert1)
		{
		}

		TEST_METHOD(TestInsert2)
		{
		}

		TEST_METHOD(TestInsert3)
		{
		}

		TEST_METHOD(TestInsert4)
		{
		}

		TEST_METHOD(TestInsert5)
		{
		}

	};
}