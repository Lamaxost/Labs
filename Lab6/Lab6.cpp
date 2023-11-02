#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <random>
using namespace std;


void Task1();
void Task2();
void Task3();

int random(int from, int to) {
    int result = rand() % (to - from + 1) + from;
    return result;
}
void SwapElements(int** matrix, int aRow, int aColumn, int bRow, int bColumn) {
    int temp = matrix[aRow][aColumn];
    matrix[aRow][aColumn] = matrix[bRow][bColumn];
    matrix[bRow][bColumn] = temp;
}
void FillMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = random(10, 99);
        }
    }
}
void PrintMatrix(int** matrix, int rows, int columns) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] < 55) {
                SetConsoleTextAttribute(h, 4);
            }
            else {
                SetConsoleTextAttribute(h, 2);
            }
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 15);
}
void PrintMatrixColors(int** matrix, int rows, int columns) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] < 55) {
                SetConsoleTextAttribute(h, 4);
            }
            else {
                SetConsoleTextAttribute(h, 2);
            }
            cout << setw(3) << "##";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 15);
}
void RotateMatrix(int** matrix, int rows,int columns) {
    for (int i = 0; i < (rows +1)/2; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == rows / 2 && j >= columns / 2)
            { 
                break;
            }
            SwapElements(matrix, i, j, rows - i - 1, columns - j - 1);
        }
    }
}
void SwapFirstAndMaxInEveryRow(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        int maxIndex = 0;
        for (int j = 0; j < columns; j++) {
            if (matrix[i][maxIndex] < matrix[i][j]) {
                maxIndex = j;
            }
        }
        SwapElements(matrix, i, 0, i, maxIndex);
    }
}
void SwapLastAndMinInEveryRow(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        int minIndex = 0;
        for (int j = 0; j < columns; j++) {
            if (matrix[i][minIndex] > matrix[i][j]) {
                minIndex = j;
            }
        }
        SwapElements(matrix, i, columns-1, i, minIndex);
    }
}

enum class MenuOptions { ClearConsole = -1, Exit = 0, Task1, Task2, Task3 };
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
    SetConsoleTextAttribute(h, 15);
    printf("\n\nВиберіть потрібне завдання:");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task1);
    SetConsoleTextAttribute(h, 15);
    printf(" - обробити матрицю");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task2);
    SetConsoleTextAttribute(h, 15);
    printf(" - міняти максимальний та мінімальний");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task3);
    SetConsoleTextAttribute(h, 15);
    printf(" - перевірка перемноження");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::ClearConsole);
    SetConsoleTextAttribute(h, 15);
    printf(" - очистити консоль");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Exit);
    SetConsoleTextAttribute(h, 15);
    printf(" - вийти\n> ");
    SetConsoleTextAttribute(h, 15);
    scanf("%i", &choice);
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    MenuOptions choice;

    while (true) {
        PrintMenuAndAskChoice(h, choice);
        switch (choice)
        {
        case MenuOptions::Task1:
            Task1();
            break;
        case MenuOptions::Task2:
            Task2();
            break;
        case MenuOptions::Task3:
            Task3();
            break;
        case MenuOptions::Exit:
            return 0;
        case MenuOptions::ClearConsole:
            system("cls");
            break;
        default:
            SetConsoleTextAttribute(h, 4);
            printf("Невідома команда - %i", (int)choice);
            SetConsoleTextAttribute(h, 4);

            break;
        }
    }
}


void Task3() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int rows1, columns1;
    cout << "Введіть розміри першої матриці > ";
    cin >> rows1 >> columns1;
    int rows2, columns2;
    cout << "Введіть розміри другої матриці > ";
    cin >> rows2 >> columns2;
    if (rows1 == columns2 ) {
        cout << "Матриці";
        SetConsoleTextAttribute(h, 2);
        cout << " можна ";
        SetConsoleTextAttribute(h, 15);
        cout << "перемножувати";
    }
    else {
        cout << "Матриці";
        SetConsoleTextAttribute(h, 4);
        cout << " не можна ";
        SetConsoleTextAttribute(h, 15);
        cout << "перемножувати";
    }
}

void Task2() {
    int rows = 9;
    int columns = 9;

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    FillMatrix(matrix, rows, columns);
    cout << "Матриця до:\n";
    PrintMatrix(matrix, rows, columns);
    SwapFirstAndMaxInEveryRow(matrix, rows, columns);
    cout << "Матриця де в кожному рядку помінялись місцями перший елемент, та найбільший:\n";
    PrintMatrix(matrix, rows, columns);
    SwapLastAndMinInEveryRow(matrix, rows, columns);
    cout << "Матриця де в кожному рядку помінялись місцями останній елемент, та найменший:\n";
    PrintMatrix(matrix, rows, columns);
    cout << endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Task1()
{
    int rows = 9;
    int columns = 9;

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    FillMatrix(matrix, rows, columns);
    cout << "Матриця до:\n";
    PrintMatrix(matrix, rows, columns);
    cout << endl;
    PrintMatrixColors(matrix, rows, columns);
    RotateMatrix(matrix, rows, columns);
    cout << endl;
    cout << "Матриця після:\n";
    PrintMatrix(matrix, rows, columns);
    cout << endl;
    PrintMatrixColors(matrix, rows, columns);
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
