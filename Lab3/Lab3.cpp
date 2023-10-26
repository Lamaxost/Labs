//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include "Lab3.h"
using namespace std;

enum class MenuOptions { ClearConsole = -1, Exit, PointInAreaTask, SquareEquationTask, MushroomOutputTask, };
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Змінна, для зміни кольору консолі
	MenuOptions userChoice; // Змінна, для навігації в меню

	while (true) {

		PrintMenuAndAskChoice(h, userChoice); // Виводимо меню, та отримуємо ввід користувача
		switch (userChoice)
		{
			case MenuOptions::PointInAreaTask:
				PointInAreaTask();
				break;
			case MenuOptions::SquareEquationTask:
				SquareEquationCheckTask();
				break;
			case MenuOptions::MushroomOutputTask:
				MushroomOutputTask();
				break;
			case MenuOptions::Exit:
				return 0;
			case MenuOptions::ClearConsole:
				system("cls");
				break;
			default:
				SetConsoleTextAttribute(h, 4);
				printf("Невідома команда - %i", (int)userChoice);
				SetConsoleTextAttribute(h, 4);
				break;
		}
	}
}

//Функція, що виводить меню, та питає користувача
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
	SetConsoleTextAttribute(h, 15);
	printf("\n\nВиберіть потрібне завдання:");
	SetConsoleTextAttribute(h, 10);
	printf("\n%3i", MenuOptions::PointInAreaTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - потрапляння точки у область");
	SetConsoleTextAttribute(h, 10);
	printf("\n%3i", MenuOptions::SquareEquationTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - перевірка квадратного рівняння");
	SetConsoleTextAttribute(h, 10);
	printf("\n%3i", MenuOptions::MushroomOutputTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - форматування виводу інформації про кількість грибів", MenuOptions::PointInAreaTask, MenuOptions::SquareEquationTask, MenuOptions::MushroomOutputTask, MenuOptions::Exit);
	SetConsoleTextAttribute(h, 10);
	printf("\n%3i", MenuOptions::ClearConsole);
	SetConsoleTextAttribute(h, 15);
	printf(" - очистити консоль", MenuOptions::PointInAreaTask, MenuOptions::SquareEquationTask, MenuOptions::MushroomOutputTask, MenuOptions::Exit);
	SetConsoleTextAttribute(h, 10);
	printf("\n%3i", MenuOptions::Exit);
	SetConsoleTextAttribute(h, 15);
	printf(" - вийти\n> ", MenuOptions::PointInAreaTask, MenuOptions::SquareEquationTask, MenuOptions::MushroomOutputTask, MenuOptions::Exit);
	SetConsoleTextAttribute(h, 15);
	scanf("%i", &choice);
}

//Код для завдання 1 - Точка в області
void PointInAreaTask()
{
	// Об'ява змінних
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Змінна, для зміни кольору консолі
	double x, y; // Змінні - координати;

	/* Введення фактичних даних */
	printf("Введіть:x,y координати точки>");

	scanf("%lf %lf", &x, &y);

	//Умови попадання в зону
	bool isPointInGreenSquare = y <= 1 && y >= 0 && x >= -1 && x <= 0; // Умова для попадання у зелений квадрат
	bool isPointInGreenCirlce = y * y + x * x <= 1; // Умова для попадання точки у зелене коло
	bool isPointInRedSquare = y < 0; // Умова для попадання точки у червоний прямокутник

	bool isPointInRequiredArea = (isPointInGreenSquare || isPointInGreenCirlce) && !isPointInRedSquare; // Умова для попадання точки у заштриховану область

	if (isPointInRequiredArea) {

		SetConsoleTextAttribute(h, 15);
		printf("Точка");
		SetConsoleTextAttribute(h, 12);
		printf(" (%.2lf; %.2lf)", x, y);
		SetConsoleTextAttribute(h, 10);
		printf(" потрапляє");
		SetConsoleTextAttribute(h, 15);
		printf(" у заштриховану область");
	}
	else {
		SetConsoleTextAttribute(h, 15);
		printf("Точка");
		SetConsoleTextAttribute(h, 12);
		printf(" (%.2lf; %.2lf)", x, y);
		SetConsoleTextAttribute(h, 4);
		printf(" не потрапляє");
		SetConsoleTextAttribute(h, 15);
		printf(" у заштриховану область");
	}
}

//Код для завдання 2 - Перевірка квадратного рівняння
void SquareEquationCheckTask() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Змінна, для зміни кольору консолі
	double a, b, c; // Змінні що представляють коефіцієнти у квадратному рівнянні виду ax^2 + bx + c = 0
	double x1,x2; // Змінні для коренів рівняння
	printf("Введіть змінні a, b, c що представляють коефіцієнти у квадратному рівнянні виду ax^2 + bx + c = 0> ");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("Аналізую рівняння %lfx^2 %+lfx %+lf = 0\n", a, b, c);
	if (a == 0) {
		SetConsoleTextAttribute(h, 4);
		printf("Рівняння не є квадратним !\n");
		if (b == 0) {
			printf("Рівняння не має дійсних коренів!");
			return;
		}
		double x = -c / b;
		x1 = x;
		x2 = x;
		PrintEquationSolution(h, x);
		return;
	}
	else if (b == 0) {
		SetConsoleTextAttribute(h, 4);
		printf("Рівняння є неповним квадратним рівнянням!\n");
		if (c > 0) {
			printf("Рівняння не має дійсних коренів");
			SetConsoleTextAttribute(h, 15);
		}
		else {
			x1 = sqrt(-c/a);
			x2 = -sqrt(-c/a);
			if (x1 == x2)
			{
				PrintEquationSolution(h, x1);

			}
			else 
			{
				PrintEquationSolutions(h, x1, x2);
			}
		}

		SetConsoleTextAttribute(h, 15);
		return;
	}
	else if (c == 0)
	{
		SetConsoleTextAttribute(h, 4);
		printf("Рівняння є неповним квадратним рівнянням!\n");
		double x = -b / a;
		x1 = x;
		x2 = x;
		PrintEquationSolution(h, x);
		return;
	}
	double D; // Представляє собою дискримінант рівняння;
	D = b * b - 4 * a * c;
	if (D < 0) {
		SetConsoleTextAttribute(h, 4);
		printf("Дискримінант рівняння менше 0. Рівняння не має розв'язків, D = %.3lf", D);
		SetConsoleTextAttribute(h, 15);

	}
	else if (D == 0) {
		double x = b / (2 * a);
		x1 = x;
		x2 = x;
		SetConsoleTextAttribute(h, 15);
		printf("Дискримінант рівняння дорівнює нулю\n");
		PrintEquationSolution(h, x);
	}
	else {
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		if (x1 == x2)
		{
			PrintEquationSolution(h, x1);

		}
		else
		{
			PrintEquationSolutions(h, x1, x2);
		}
	}
}

// Ця функція виводить корінь рівняння
void PrintEquationSolution(HANDLE& h, double x)
{
	SetConsoleTextAttribute(h, 15);
	printf("Корінь рівняння: ");
	SetConsoleTextAttribute(h, 10);
	printf("%lf", x);
	SetConsoleTextAttribute(h, 15);
}

// Ця функція виводить корені рівняння
void PrintEquationSolutions(const HANDLE& h, double x1, double x2)
{
	SetConsoleTextAttribute(h, 15);
	printf("Корені рівняння:");
	SetConsoleTextAttribute(h, 10);
	printf("%lf", x1);
	SetConsoleTextAttribute(h, 15);
	printf(";");
	SetConsoleTextAttribute(h, 10);
	printf("%lf", x2);
	SetConsoleTextAttribute(h, 15);
}

// Завдання 3 - Форматування виводу інформації про кількість грибів
void MushroomOutputTask() {
	int mushroomCount; // Змінна для кількості грибів
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Змінна, для зміни кольору консолі
	printf("Введіть кількість грибів>");
	scanf("%i", &mushroomCount);

	char wordEnding[3]; // закінчення слова гриб, яке може приймати значення "", "а", "ів"
	int lastTwoDigits = mushroomCount % 100; // змінна, яка містить останні 2 цифри кількості грибів
	int lastDigit = mushroomCount % 10; // змінна, яка містить останню цифру кількості грибів

	if (lastTwoDigits > 10 && lastTwoDigits < 20) // Для чисел між 10 і 20 завжди буде гриб(ів)
	{
		wordEnding[0] = 'i';
		wordEnding[1] = 'в';
		wordEnding[2] = '\0';
	}
	else if (lastDigit == 1) // Якщо число закінчуєтся на 1 то пишемо гриб
	{
		wordEnding[0] = '\0';
	}
	else if (lastDigit > 1 && lastDigit < 5) // Якщо число закінчуєтся на 2,3,4 то пишемо гриб(а)
	{
		wordEnding[0] = 'a';
		wordEnding[1] = '\0';
	}
	else if (lastDigit == 0 || lastDigit >= 5) // Якщо число закінчуєтся на 0, 5, 6, 7, 8, 9, то пишемо гриб(ів)
	{
		wordEnding[0] = 'i';
		wordEnding[1] = 'в';
		wordEnding[2] = '\0';
	}
	printf("У мене ");
	SetConsoleTextAttribute(h, 4);
	printf("%i", mushroomCount);
	SetConsoleTextAttribute(h, 15);
	printf(" гриб");
	SetConsoleTextAttribute(h, 10);
	printf("%s", wordEnding);
}
