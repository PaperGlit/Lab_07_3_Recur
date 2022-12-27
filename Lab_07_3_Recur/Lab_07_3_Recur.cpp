// I am going insane EDIT: my insanity is gone

#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(double** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		else
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
	}
}

void Print(double** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			cout << setw(6) << a[i][j];
			Print(a, rowCount, colCount, i, j + 1);
		}
		else
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
	}
}

int Diagonal(const int rowCount, const int colCount)
{
	if (rowCount < colCount)
		return rowCount;
	else
		return colCount;
}

int CheckRows(double** a, const int rowCount, const int colCount, int n, int i, int j)
{
	if (j < colCount)
	{
		if (i < rowCount)
		{
			if (a[i][j] != 0)
				return j;
			CheckRows(a, rowCount, colCount, n, i + 1, j);
		}
		else
			CheckRows(a, rowCount, colCount, n, 0, j + 1);
	}
}

void SwapRows(double** a, const int rowCount, const int colCount, int k, int i, int j, int n)
{
	if (j < colCount)
	{
		double temp = a[i][j];
		a[i][j] = a[k][j];
		a[k][j] = temp;
		SwapRows(a, rowCount, colCount, k, i, j + 1, n);
	}
}

void DivideRows(double** a, const int rowCount, const int colCount, double k, int n, int i)
{
	if (i < rowCount)
	{
		a[n][i] /= k;
		DivideRows(a, rowCount, colCount, k, n, i + 1);
	}
}

void SubstractRows(double** a, const int rowCount, const int colCount, int n, int i, int j)
{
	if (i < rowCount)
	{
		double n1 = a[i][n];
		if (j < colCount)
		{
			a[i][j] -= a[n][j] * n1;
			SubstractRows(a, rowCount, colCount, n, i, j + 1);
		}
		else
			SubstractRows(a, rowCount, colCount, n, i + 1, 0);
	}
}

void Triangle(double** a, const int rowCount, const int colCount, int n, int i)
{
	int n1 = Diagonal(rowCount, colCount);
	if (n < n1)
	{
		int k1 = CheckRows(a, rowCount, colCount, n, n, n);
		double k = a[n][k1];
		if (k == 0)
		{
			if (i < rowCount)
			{
				if (a[i][k1] != 0)
					SwapRows(a, rowCount, colCount, k1, i, n, n);
				Triangle(a, rowCount, colCount, n, i + 1);
			}
			for (int i = 0; i < rowCount; i++)

			k = a[n][k1];
		}
		DivideRows(a, rowCount, colCount, k, n, n);
		SubstractRows(a, rowCount, colCount, n, n + 1, n);
		Triangle(a, rowCount, colCount, n + 1, 0);
	}
}

int MinAvg(double** a, const int rowCount, const int colCount, int minavg, int k, int S, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			S += a[i][j];
			MinAvg(a, rowCount, colCount, minavg, k, S, i, j + 1);
		}
		if (S / colCount < minavg)
			k++;
		MinAvg(a, rowCount, colCount, minavg, k, 0, i + 1, 0);
	}
	else
		return k;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	cout.precision(2);
	int rowCount, colCount, minavg, Low, High;
	cout << "Кількість рядків : "; cin >> rowCount;
	cout << "Кількість стовпців : "; cin >> colCount;
	cout << "Мінімальне значення : "; cin >> Low;
	cout << "Максимальне значення : "; cin >> High;
	cout << "Мінімальне середнє арифметчне : "; cin >> minavg;
	double** a = new double* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new double[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << "Кількість рядків, середнє арифметичне елементів яких менше від заданої еличини: " << MinAvg(a, rowCount, colCount, minavg, 0, 0, 0, 0) << endl;
	Triangle(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	return 0;
}