#include "stdafx.h"
#include "CppUnitTest.h"
#include "LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(LinkedListTest)
	{
	public:
		TEST_METHOD(TestConstructor1)
		{
			int array[] = { 1, 2, 3 };
			IList<int>* list = new LinkedList<int>(3, array);
			Assert::IsTrue(list->CheckContent(array, 3), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestConstructor2)
		{
			int array[] = { 1 };
			IList<int>* list = new LinkedList<int>(1, array);
			Assert::IsTrue(list->CheckContent(array, 1), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestConstructor3)
		{
			IList<int>* list = new LinkedList<int>(0, nullptr);
			Assert::IsTrue(list->CheckContent(nullptr, 0), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestAdd1)
		{
			int array[] = { 1, 2, 3 };
			int testArray[] = { 1, 2, 3, 4 };
			IList<int>* list = new LinkedList<int>(3, array);
			list->Add(4);
			Assert::IsTrue(list->CheckContent(testArray, 4), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestAdd2)
		{
			int array[] = { 1, 2, 3 };
			int testArray[] = { 1, 2, 3, 4, 5 };
			IList<int>* list = new LinkedList<int>(3, array);
			list->Add(4);
			list->Add(5);
			Assert::IsTrue(list->CheckContent(testArray, 5), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestAdd3)
		{
			int testArray[] = { 100 };
			IList<int>* list = new LinkedList<int>();
			list->Add(100);
			Assert::IsTrue(list->CheckContent(testArray, 1), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestAdd4)
		{
			int testArray[] = { 100, 600, 5345, 3463461, 2424, 2315, 16773, 724, 135, 1737, 155, 3155, 146, 27456, 3156, 167547, 1346 };
			IList<int>* list = new LinkedList<int>();
			list->Add(100);
			list->Add(600);
			list->Add(5345);
			list->Add(3463461);
			list->Add(2424);
			list->Add(2315);
			list->Add(16773);
			list->Add(724);
			list->Add(135);
			list->Add(1737);
			list->Add(155);
			list->Add(3155);
			list->Add(146);
			list->Add(27456);
			list->Add(3156);
			list->Add(167547);
			list->Add(1346);

			Assert::IsTrue(list->CheckContent(testArray, 17), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestInsert1)
		{
			int testArray[] = { 100 };
			IList<int>* list = new LinkedList<int>();
			list->Insert(100, 0);
			Assert::IsTrue(list->CheckContent(testArray, 1), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestInsert2)
		{
			int array[] = { 100, 361, 614 };
			int testArray[] = { 4214, 100, 361, 1636, 614 };
			IList<int>* list = new LinkedList<int>(3, array);
			list->Insert(4214, 0);
			list->Insert(1636, 3);
			Assert::IsTrue(list->CheckContent(testArray, 5), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestRemove1)
		{
			int array[] = { 100, 361, 614 };
			int testArray[] = { 100, 614 };
			IList<int>* list = new LinkedList<int>(3, array);
			list->Remove(1);
			Assert::IsTrue(list->CheckContent(testArray, 2), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestRemove2)
		{
			int array[] = { 100 };
			int testArray[] = { 1 };
			IList<int>* list = new LinkedList<int>(1, array);
			list->Remove(0);
			Assert::IsTrue(list->CheckContent(testArray, 0), L"failed", LINE_INFO());
			delete list;
		}

		TEST_METHOD(TestRemove3)
		{
			int array[] = { 100, 231, 5341, 613461, 34125, 61363 };
			int testArray[] = { 231, 5341, 61363 };
			IList<int>* list = new LinkedList<int>(6, array);
			list->Remove(0);
			list->Remove(3);
			list->Remove(2);
			Assert::IsTrue(list->CheckContent(testArray, 3), L"failed", LINE_INFO());
			delete list;
		}
	};
}