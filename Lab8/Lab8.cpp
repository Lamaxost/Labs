#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <random>
using namespace std;
enum class MenuOptions { ClearConsole = -1, Exit = 0, Task1, Task2};
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
    SetConsoleTextAttribute(h, 15);
    printf("\n\nВиберіть потрібне завдання:");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task1);
    SetConsoleTextAttribute(h, 15);
    printf(" - рекурсивно перевести число з вісімкової у десяткову");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task2);
    SetConsoleTextAttribute(h, 15);
    printf(" - визначити, скільки віднімань буде виконано в алгоритмі");
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

int Convert8SystemTo10System(string input) {
    int power = input.length();
    int firstDigit = (input[0] - '0');
    int digitValue = firstDigit * pow(8, power - 1);
    if (power == 1) {
        return digitValue;
    }
    else {
        int otherDigitsValue = digitValue + Convert8SystemTo10System(input.substr(1, input.length() - 1));
        return otherDigitsValue;
    }
}


void Task1() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string numIn8;
    SetConsoleTextAttribute(h, 15);
    cout << "Введіть число у вісімковій системі> ";
    cin >> numIn8;
    for (int i = 0; i < numIn8.length(); i++) {
        char ch = numIn8[i];
        if (ch < '0' || ch > '8') {
            SetConsoleTextAttribute(h, 4);
            cout << "Неправильно записане число!";
            return;
        }
    }
    SetConsoleTextAttribute(h, 15);
    cout << "Ви ввели число у вісімковій системі: ";
    SetConsoleTextAttribute(h, 4);
    cout << numIn8 << endl;
    int decimalValue = Convert8SystemTo10System(numIn8);
    SetConsoleTextAttribute(h, 15);
    cout << "Це число у десятковій системі: ";
    SetConsoleTextAttribute(h, 2);
    cout << decimalValue;
}
void Task2() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int number;
    cout << "Введіть число для алгоритму >";
    cin >> number;
    int numberForWork = number;
    int subtractingCount = 0;
    cout << "Початкове число: " << number << endl;
    while (numberForWork > 0)
    {
        int digitsSum = 0;
        int numberForWorkCopy = numberForWork;
        SetConsoleTextAttribute(h, 2);
        cout << numberForWorkCopy;
        SetConsoleTextAttribute(h, 15);
        cout << "-" << "(";
        SetConsoleTextAttribute(h, 4);
        for (int digit = numberForWorkCopy % 10; numberForWorkCopy > 0; numberForWorkCopy= (numberForWorkCopy - digit)/10){
            digit = numberForWorkCopy % 10;
            digitsSum += digit;
            cout << digit;
            if (numberForWorkCopy > 10) {
                cout << "+";
            }
        }
        SetConsoleTextAttribute(h, 15);
        cout << ")=";
        numberForWork -= digitsSum;
        SetConsoleTextAttribute(h, 6);
        cout << numberForWork << endl;
        subtractingCount++;
    }
    SetConsoleTextAttribute(h, 15);
    cout << "Необхідно ";
    SetConsoleTextAttribute(h, 2);
    cout << subtractingCount;
    SetConsoleTextAttribute(h, 15);
    cout << " віднімань";
    SetConsoleTextAttribute(h, 15);
}