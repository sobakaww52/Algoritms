#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"
#include <iostream>
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SORTEDTEST
{
	TEST_CLASS(Sorted)
	{
	public:
		
		
		TEST_METHOD(quik_sort)
		{
			std::vector<int> arr = { 4, 3, 1, 13, 5, 0 };
			std::vector<int> sort_arr = { 0, 1, 3, 4, 5, 13 };
			std::vector<int> result_quik = arr;
			quikSort(result_quik, 0 , 5);
			const int size_t = 6;
			for (int i = 0; i < size_t; ++i) {
				Assert::AreEqual(sort_arr[i], result_quik[i], L"Element == arr");
			}
			
		}

		TEST_METHOD(sort_shell)
		{
			std::vector<int> arr = { 4, 3, 1, 13, 5, 0 };
			std::vector<int> sort_arr = { 0, 1, 3, 4, 5, 13 };
			std::vector<int> result_quik = arr;
			sortShell(result_quik);
			const int size_t = 6;
			for (int i = 0; i < size_t; ++i) {
				Assert::AreEqual(sort_arr[i], result_quik[i], L"Element == arr");
			}

		}

		TEST_METHOD(radix_sort)
		{
			std::vector<int> arr = { 4, 3, 1, 13, 5, 0 };
			std::vector<int> sort_arr = { 0, 1, 3, 4, 5, 13 };
			std::vector<int> result_quik = arr;
			radixSort(result_quik);
			const int size_t = 6;
			for (int i = 0; i < size_t; ++i) {
				Assert::AreEqual(sort_arr[i], result_quik[i], L"Element == arr");
			}

		}
	};
}
