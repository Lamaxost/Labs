#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <random>
using namespace std;
enum class MenuOptions { ClearConsole = -1, Exit = 0, Task1, Task2 };
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
    SetConsoleTextAttribute(h, 15);
    printf("\n\nВиберіть потрібне завдання:");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task1);
    SetConsoleTextAttribute(h, 15);
    printf(" - робота з динамічним масивом");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task2);
    SetConsoleTextAttribute(h, 15);
    printf(" - переписати в динамічний масив значення за правилом");
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
void Task1();
void Task2();

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


int FillArray(int* arr, int size) {
    
    for (int i = 0; i < size; i++) {
        int item;
        cout << "Введіть елемент масиву>";
        cin >> item;
        *(arr + i) = item;
    }
    return size;
}

int ProcessArray(int* arr, int size) {

    int min = *arr;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }
    for (int i = 0; i < size; i++) {
        if (*(arr + i) < 0) {
            *(arr + i) = min;
        }
    }
    return min;
}

void RearangeArray(int* arr, int size) {
    int negativeCount = 0;
    int positiveCount = 0;
    int nullCount = 0;
    for (int i = 0; i < size; i++) {
        int item = *(arr + i);
        if(item > 0)
        {
            positiveCount++;
        }
        else if (item == 0) {
            nullCount++;
        }
        else if (item < 0) {
            negativeCount++;
        }
    }
    int* negativeArray =(int*) malloc(negativeCount * sizeof(int));
    int* positiveArray =(int*) malloc(positiveCount* sizeof(int));
    int* nullArray =(int*) malloc(nullCount* sizeof(int));

    for (int i = 0, positiveIndex = 0, negativeIndex = 0, nullIndex = 0; i < size; i++) {
        int item = *(arr + i);
        if (item > 0)
        {
            *(positiveArray + positiveIndex++) = item ;
        }
        else if (item == 0) {
            *(nullArray+ nullIndex++) = item ;
        }
        else if (item < 0) {
          
            *(negativeArray+ negativeIndex++) =item;
        }
    }

    for (int i = 0; i < size; i++) {
        int item = 0;
        if (i < nullCount) {
            item = *(nullArray + i);
        }
        else if (i - nullCount < negativeCount) {
            item = *(negativeArray + i - nullCount);
        }
        else if (i - negativeCount - nullCount < positiveCount) {
            item = *(positiveArray + i - negativeCount - nullCount);
        }
        *(arr + i) = item;
    }
    free(negativeArray);
    free(positiveArray);
    free(nullArray);
}

void Task1() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int size;
    cout << "Введіть розмір масиву>";
    cin >> size;
    int* arr = (int*)malloc(size*sizeof(int));
    FillArray(arr,size);
    ProcessArray(arr, size);
    
    for (int i = 0; i < size; i++) {
        int item = *(arr + i);
        if (item >= 0) {
            SetConsoleTextAttribute(h, 2);
        }
        else {
            SetConsoleTextAttribute(h, 4);
        }
        cout << item << " ";
    }
    SetConsoleTextAttribute(h, 15);
    free(arr);
}

void Task2() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int size;
    cout << "Введіть розмір масиву>";
    cin >> size;
    int* arr = (int*)malloc(size * sizeof(int));
    FillArray(arr, size);
    RearangeArray(arr, size);
    for (int i = 0; i < size; i++) {
        int item = *(arr + i);
        if (item > 0) {
            SetConsoleTextAttribute(h, 2);
        }
        else if (item > 0) {
            SetConsoleTextAttribute(h, 6);
        }
        else {
            SetConsoleTextAttribute(h, 4);
        }
        cout << item << " ";
    }
}