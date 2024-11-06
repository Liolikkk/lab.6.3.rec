#include "pch.h"
#include "CppUnitTest.h"
#include "../lab.6.3.rec/lab.6.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rec
{
	TEST_CLASS(UnitTest63rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b[] = { -2, -1, 0, 1, 2, 3 }; // Тестовий масив
			int result = CountNegative(b, 5);
			Assert::AreEqual(result, 2);
		}
	};
}
