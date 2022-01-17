#include "CppUnitTest.h"
#include "..\ConsoleApplication1\Deck.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task02Tests
{
	TEST_CLASS(Task02Tests)
	{
	public:

		TEST_METHOD(constructor_valid_data_succeed)
		{
			Deck a;
			Assert::IsTrue(a.getSize() == 0);
		}
		TEST_METHOD(pushL_valid_data_succeed)
		{
			Deck a;
			for (int i = 0; i++; i < 9) {
				for (int l = 0; l++; l < i) {
					int k = -49 + rand() % 50;
					a.pushL(k);
					Assert::IsTrue(a.getL() == k);
				}
			}
		}
		TEST_METHOD(pushR_valid_data_succeed)
		{
			Deck a;
			for (int i = 0; i++; i < 9) {
				for (int l = 0; l++; l < i) {
					int k = -49 + rand() % 50;
					a.pushR(k);
					Assert::IsTrue(a.getR() == k);
				}
			}
		}
		TEST_METHOD(popL_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushL(k);
			Assert::IsTrue(k == a.popL());
		}
		TEST_METHOD(popR_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushR(k);
			Assert::IsTrue(k == a.popR());
		}
		TEST_METHOD(getSize_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushR(k);
			Assert::IsTrue(a.getSize() == 1);
		}
		TEST_METHOD(getL_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushL(k);
			Assert::IsTrue(k == a.getL());
		}
		TEST_METHOD(getR_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushR(k);
			Assert::IsTrue(k == a.getR());
		}
		TEST_METHOD(editL_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushL(k);
			k = -49 + rand() % 50;
			a.editL(k);
			Assert::IsTrue(k == a.getL());
		}
		TEST_METHOD(editR_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushR(k);
			k = -49 + rand() % 50;
			a.editR(k);
			Assert::IsTrue(k == a.getR());
		}
		TEST_METHOD(operator_valid_data_succeed)
		{
			Deck a;
			int k = -49 + rand() % 50;
			a.pushL(k);
			std::stringstream temp;
			temp << k << " ";
			std::string tempStr = temp.str();
			std::stringstream out;
			out << a;
			Assert::IsTrue(tempStr == out.str());
		}
	};
}