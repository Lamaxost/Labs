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
void FillMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = random(-50, 50);
        }
    }
}
void PrintMatrix(int** matrix, int rows, int columns) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            /*if (matrix[i][j] < 5) {
                SetConsoleTextAttribute(h, 4);
            }
            else {
                SetConsoleTextAttribute(h, 2);
            }*/
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 15);
}
int ProcessArray(int* array, int rows, int columns) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = array[i * rows + j];
        }
    }
    cout << "Початкова матриця: \n";

    PrintMatrix(matrix, rows, columns);
    int sumOfMaxsOfRows = 0;
    for (int i = 0; i < rows; i++) {
        int minInRow = matrix[i][0];
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
            }
        }
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] += minInRow;
        }
        int maxInRow = matrix[i][0];
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }
        sumOfMaxsOfRows += maxInRow;
    }
    cout << endl;
    cout << "Матриця-результат: \n";
    PrintMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i * rows + j] = matrix[i][j];
        }
    }


    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return sumOfMaxsOfRows;
}
int SumPositiveElementsInRow(int* row, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (row[i] > 0) {
            sum+=row[i];
        }
    }
    return sum;
}


enum class MenuOptions { ClearConsole = -1, Exit = 0, Task1, Task2, Task3 };
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
    SetConsoleTextAttribute(h, 15);
    printf("\n\nВиберіть потрібне завдання:");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task1);
    SetConsoleTextAttribute(h, 15);
    printf(" - обробити масив");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task2);
    SetConsoleTextAttribute(h, 15);
    printf(" - взяти знак порівняння");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task3);
    SetConsoleTextAttribute(h, 15);
    printf(" - демонстрація функцій");
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

void Task1()
{
    
    const int rows = 3;
    const int columns = 3;

    int* arr = new int[rows * columns];

    cout << "Початковий масив: \n";
    for (int i = 0; i < rows * columns; i++) {
        arr[i] = i + 1;
        cout << setw(3) << i + 1;
    }
    cout << endl;
    int sum = ProcessArray(arr, rows, columns);
    cout << "Массив результат: \n";
    for (int i = 0; i < rows * columns; i++) {
        cout << setw(3) << arr[i];
    }
    cout << endl;
    cout << "Сумма найбільших елементів з рядків: " << sum << endl;

    delete[] arr;
}

char GetComparingSign(int a, int b) {

    if (a > b) {
        return '>';
    }
    if (a == b) {
        return '=';
    }
    if (a < b) {
        return '<';
    }
}

void Task2() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int a, b;
    cout << "Введіть два числа >";
    cin >> a >> b;
    char sign = GetComparingSign(a, b);
    cout << a;
    if (sign == '<') {
        SetConsoleTextAttribute(h, 4);
    }
    else if (sign == '=') {
        SetConsoleTextAttribute(h, 2);
    }
    else if (sign == '>') {
        SetConsoleTextAttribute(h, 6);
    }
    cout <<' ' << sign <<' ';
    SetConsoleTextAttribute(h, 15);
    cout << b;
}

void Task3() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int rows = 5;
    int columns = 5;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    FillMatrix(matrix, rows, columns);

    cout << "Початкова матриця: \n";
    PrintMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; i++) {
        int sum = SumPositiveElementsInRow(matrix[i], columns);
        SetConsoleTextAttribute(h, 15);
        cout << "Сумма позитивних елементів у ";
        SetConsoleTextAttribute(h, 4);
        cout << i + 1;
        SetConsoleTextAttribute(h, 15);
        cout << " рядку: ";
        SetConsoleTextAttribute(h, 2);
        cout << sum << endl;
        SetConsoleTextAttribute(h, 15);
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}