#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3.rek/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
        TEST_METHOD(Test)
		{
            int rowCount = 3, colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i) {
                a[i] = new int[colCount];
            }

            a[0][0] = 5; a[0][1] = 8; a[0][2] = -3;
            a[1][0] = 3; a[1][1] = 6; a[1][2] = 3;
            a[2][0] = 7; a[2][1] = 2; a[2][2] = 2;

            int sum = SUM(a, rowCount, colCount, 0);
            Assert::AreEqual(sum, 31);

            for (int i = 0; i < rowCount; ++i)
                delete[] a[i];
            delete[] a;
		}
	};
}
