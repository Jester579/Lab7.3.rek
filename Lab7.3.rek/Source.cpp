#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h> 
using namespace std;

void PrintRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo) {
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < colCount - 1)
        InputRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo) {
    InputRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        InputRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

int SUM(int** a, const int rowCount, const int colCount, int col) {
    if (col >= colCount) {
        return 0; 
    }

    bool hasNegative = false;
    int sum = 0;

    for (int row = 0; row < rowCount; ++row) {
        if (a[row][col] < 0) {
            hasNegative = true;
            break; 
        }
        sum += a[row][col];
    }

    if (hasNegative) {
        sum = 0; 
    }

    return sum + SUM(a, rowCount, colCount, col + 1);
}

void MinDiagonalSum(int** a, const int rowCount, const int colCount) {
    int minSum = INT_MAX;

    for (int first = 1; first < colCount; ++first) {
        int sum = 0;
        for (int i = 0; i < min(rowCount, colCount - first); ++i) {
            sum += abs(a[i][first + i]);
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }

    for (int first = 1; first < rowCount; ++first) {
        int sum = 0;
        for (int i = 0; i < min(rowCount - first, colCount); ++i) {
            sum += abs(a[first + i][i]);
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }

    cout << "Мінімум серед сум модулів елементів діагоналей, паралельних до побічної діагоналі матриці "<< minSum << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    InputRows(a, rowCount, colCount, 0); 
    PrintRows(a, rowCount, colCount, 0); 

    int sum = SUM(a, rowCount, colCount, 0);
    cout << "Сума елементів у тих стовпцях, які не містять від'ємних елементів " << sum << endl;

    MinDiagonalSum(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
