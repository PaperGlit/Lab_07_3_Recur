#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_3_Recur/Lab_07_3_Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int TestMin(double** a, int S, int k, int i, int j)
{
	if (i < 5)
	{
		if (j < 3)
		{
			S += a[i][j];
			TestMin(a, S, k, i, j + 1);
		}
		if ((S / 3) < 4)
			k++;
		TestMin(a, 0, k, i + 1, 0);
	}
	else
		return k;
}

namespace UnitTestLab073Recur
{
	TEST_CLASS(UnitTestLab073Recur)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double** a = new double* [5];
			for (int i = 0; i < 5; i++)
				a[i] = new double[3];
			Create(a, 5, 3, 1, 7, 0, 0);
			int n = MinAvg(a, 5, 3, 4, 0, 0, 0, 0);
			int k = TestMin(a, 0, 0, 0, 0);
			Assert::AreEqual(k, n);
		}
	};
}
