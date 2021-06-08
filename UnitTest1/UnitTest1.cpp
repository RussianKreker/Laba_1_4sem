#include "pch.h"
#include "CppUnitTest.h"
#include "G:\Программирование\Тутуева\Laba_1_4sem\Laba_1_4sem\Laba_1_4sem\BRTree.h"
#include "G:\Программирование\Тутуева\Laba_1_4sem\Laba_1_4sem\Laba_1_4sem\NodeBRTree.h"
#include "G:\Программирование\Тутуева\Laba_1_4sem\Laba_1_4sem\Laba_1_4sem\Stack.h"
#include "G:\Программирование\Тутуева\Laba_1_4sem\Laba_1_4sem\Laba_1_4sem\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test1)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			List<int>* list;
			for (int i = 0; i < 10; i++)
			{
				tree->insert(i, i * 10);
			}
			list = tree->Get_Keys();
			List<int>* list_test = new List<int>;
			list_test->Push_Back(0);
			list_test->Push_Back(2);
			list_test->Push_Back(5);
			list_test->Push_Back(4);
			list_test->Push_Back(7);
			list_test->Push_Back(6);
			list_test->Push_Back(8);
			list_test->Push_Back(9);
			for (int i = 0; i < list->Get_Size(); i++) {
				Assert::IsTrue(list->At(i) == list_test->At(i));
			}
		}
		TEST_METHOD(Test2)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			List<int>* list;
			for (int i = 0; i < 10; i++)
			{
				tree->insert(i, i * 10);
			}
			tree->remove(2);
			list = tree->Get_Keys();
			List<int>* list_test = new List<int>;
			list_test->Push_Back(5);
			list_test->Push_Back(3);
			list_test->Push_Back(1);
			list_test->Push_Back(0);
			list_test->Push_Back(4);
			list_test->Push_Back(7);
			list_test->Push_Back(6);
			list_test->Push_Back(8);
			list_test->Push_Back(9);
			for (int i = 0; i < list->Get_Size(); i++) {
				Assert::IsTrue(list->At(i) == list_test->At(i));
			}
		}
		TEST_METHOD(Test3)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			Node<int, int>* key;
			for (int i = 0; i < 10; i++)
			{
				tree->insert(i, i * 10);
			}
			key = tree->Find(3);
			Assert::IsTrue(key->key == 3);
		}
		TEST_METHOD(Test_4)
		{
			try
			{
				RBTree<int, int>* tree = new RBTree<int, int>;
				for (int i = 0; i < 10; i++)
				{
					tree->insert(i, i * 10);
				}
				tree->Find(11);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "No such element exists");
			}
		}
		TEST_METHOD(Test5)
		{
			try
			{
				RBTree<int, int>* tree = new RBTree<int, int>;
				tree->Get_Keys();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "There is no element");
			}
		}
		TEST_METHOD(Test6)
		{
			try
			{
				RBTree<int, int>* tree = new RBTree<int, int>;
				tree->Get_Values();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "There is no element");
			}
		}
		TEST_METHOD(Test7)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			for (int i = 0; i < 10; i++)
			{
				tree->insert(i, i * 10);
			}
			tree->Clear();
			Assert::IsTrue(tree->Root == nullptr);
		}
	};
}
