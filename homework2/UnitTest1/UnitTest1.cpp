#include "pch.h"
#include "CppUnitTest.h"
#include "../maincode/maincode.cpp"
#include <cmath>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(test_n_10_1000_100000)
		{
			int n1 = 10;
			int n2 = 1000;
			int n3 = 100000;
				
			double a = 5;
			double b = 7;
			double integral1 = 194;
			double integral2 = -(2 / 3);
			double square = 194.667;

			double result1_n1 = simpson_method(func1, a, b, n1);
			double result2_n1 = simpson_method(func2, a, b, n1);
			double test1 = result1_n1 - result2_n1;

			double result1_n2 = simpson_method(func1, a, b, n2);
			double result2_n2 = simpson_method(func2, a, b, n2);
			double test2 = result1_n2 - result2_n2;

			double result1_n3 = simpson_method(func1, a, b, n3);
			double result2_n3 = simpson_method(func2, a, b, n3);
			double test3 = result1_n3 - result2_n3;

			Assert::AreEqual(square, test1, 0.01, L"Значения совпали с точностью");
			Assert::AreEqual(square, test2, 0.01, L"Значения совпали с точностью");
			Assert::AreEqual(square, test3, 0.01, L"Значения совпали с точностью");
		}
	};
}
