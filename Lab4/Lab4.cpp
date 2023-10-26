#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include "Lab4.h"
using namespace std;

enum class MenuOptions { ClearConsole = -1, Exit = 0, PrintChartTask, GuesNumberTask, CheckMultiplyingTableTask, DigitSumTask};
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	MenuOptions choice; // Змінна, для навігації в меню
	while (true) {
		PrintMenuAndAskChoice(h, choice);
		switch (choice)
		{
		case MenuOptions::PrintChartTask:
			PrintChartTask();
			break;
		case MenuOptions::GuesNumberTask:
			GuesNumberTask();
			break;
		case MenuOptions::CheckMultiplyingTableTask:
			CheckMultiplyingTableTask();
			break;
		case MenuOptions::DigitSumTask:
			DigitSumTask();
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

void PrintChartTask() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	short n;        /* параметр зовнішнього циклу */
	double x;    /* абсциса і ордината графіка */
	short w;        /* позиція точки на екрані */
	/* зовнішній цикл - для 5 періодів */
	for (n = 0; n < 5; n++) {
		/* виведення заголовка таблиці */
		printf("|   x   |      у     |\n");
		printf("|-------|------------|\n");
		/* внутрішній цикл для одного періоду */
		for (x = 0; x <= 1; x += 0.25) {
			double y = 0;
			y = -sqrt(1 - x * x);
			/* виведення рядка таблиці */
			printf("| %5.2lf | %10.7lf |", x + n * 4, y);
			/* визначення позиції точки */
			w = (y + 1) * 10;
			if (y - 1 - w * 10 > 0.5) w++;
			/* виведення точки графіка */
			for (; w > 0; w--) printf(" ");
			printf("*\n");
		}  /* кінець внутрішнього циклу */
		for (x = -2.5; x <= 2.5; x += 0.25)
		{
			/* визначення позиції точки */
			double y = sqrt(2.5 * 2.5 - x * x);
			printf("| %5.2lf | %10.7lf |", x + n * 4, y);
			w = (y + 1) * 10;
			if (y - 1 - w * 10 > 0.5) w++;
			/* виведення точки графіка */
			for (; w > 0; w--) printf(" ");
			printf("*\n");
		}
	}  /* кінець зовнішнього циклу */
} /* кінець програми */
void CheckMultiplyingTableTask() {

	srand(time(0));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int from = 1, to = 9;
	cout << "Перевірка знання таблиці множення " << endl;
	int mark = 0;
	for (int i = 0; i < 10; i++) {

		int firstMultiplier = (rand() % (to - from + 1)) + from;
		int secondMultiplier = (rand() % (to - from + 1)) + from;
		int answer = firstMultiplier * secondMultiplier;
		int userInput = -1;
		while (userInput != answer) {
			cout << firstMultiplier << " х " << secondMultiplier << " = ";
			cin >> userInput;
			if (userInput != answer) {
				cout << "Неправильно ! Спробуйте ще раз" << endl;
				mark--;
			}
		}
		mark++;
		cout << "Правильно ! " << endl;
	}
	cout << "Оцінка " << mark << "/10";

}
void GuesNumberTask()
{
	srand(time(0));
	int from = 0, to = 100;
	int computerNumber = (rand() % (to - from + 1)) + from;
	int userNumber = -1;
	int tryCount = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);
	cout << "Комп'ютер загадав число від " << from << " до " << to << endl;
	while (userNumber != computerNumber) {
		cout << "Введіть число: ";
		cin >> userNumber;
		tryCount++;
		if (userNumber < computerNumber) {
			cout << "Ваше число менже ніж число яке загадав коп'ютер" << endl;
		}
		else if (userNumber > computerNumber) {
			cout << "Ваше число більше ніж число яке загадав коп'ютер" << endl;
		}
	}
	cout << "Ви вгадали число за " << tryCount << " спроб" << endl
		;
}
void DigitSumTask() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);
	char number[10];

	cout << "Введіть число: ";
	cin >> number;
	int digitSum = 0;
	int digitCount = 0;
	int endOfNumberIndex = -1;
	if (number[0] == '-') {
		cout << "Це від'ємне число !" << endl;
		return;
	}
	for (int i = sizeof(number) / sizeof(char) - 1; i > 0; i--) {
		if (number[i] == '\0') {
			endOfNumberIndex = i;
		}
	}
	for (int i = 0; i <=endOfNumberIndex; i++) {
		if (number[i] == '\0') {
			continue;
		}
		int digit = int(number[i] - '0');
		if (digit < 0 || digit>9) {
			cout << "Неправильно написане число !" << endl;
			return;
		}
	}
	for (int i = endOfNumberIndex; i>=0 ; i--) {
		if (number[i] == '\0') {
			continue;
		}
		int digit = int(number[i] - '0');
		digitCount++;
		digitSum += digit;
		cout << digit;
	}
	
}
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
	SetConsoleTextAttribute(h, 15);
	printf("\n\nВиберіть потрібне завдання:");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::PrintChartTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - надрукувати графік");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::GuesNumberTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - вгадати число");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::CheckMultiplyingTableTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - перевірити знання з таблиці множення");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::DigitSumTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - знайти суму цифр у введеному з екрану числі, їх кількість і надрукувати число навпаки");
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

