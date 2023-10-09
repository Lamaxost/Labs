#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include "Lab3.h"
using namespace std;


enum class MenuOptions { ClearConsole =-1, Exit=0, PointInAreaTask, SquareEquationTask, MushroomOutputTask, };
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice);
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �����, ��� ���� ������� ������
	MenuOptions choice; // �����, ��� �������� � ����
	while (true) {

		PrintMenuAndAskChoice(h, choice);
		switch (choice)
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
				printf("������� ������� - %i", (int)choice);
				SetConsoleTextAttribute(h, 4);

				break;
		}
	}
}

void MushroomOutputTask() {
	int mushroomCount; // ����� ��� ������� �����
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �����, ��� ���� ������� ������
	printf("������ ������� �����>");
	scanf("%i", &mushroomCount);

	char wordEnding[3]; // ��������� ����� ����, ��� ���� �������� �������� "", "�", "��"
	if (mushroomCount > 10 && mushroomCount < 20) // ��� ����� �� 10 � 20 ������ ���� ����(��)
	{
		wordEnding[0] = 'i';
		wordEnding[1] = '�';
		wordEnding[2] = '\0';
	}
	else if (mushroomCount % 10 == 0 || mushroomCount % 10 >= 5) // ���� ����� ��������� �� 0, 5, 6, 7, 8, 9, �� ������ ����(��)
	{
		wordEnding[0] = 'i';
		wordEnding[1] = '�';
		wordEnding[2] = '\0';
	}
	else if (mushroomCount % 10 == 1) // ���� ����� ��������� �� 1 �� ������ ����
	{
		wordEnding[0] = '\0';
	}
	else if (mushroomCount % 10 > 1 && mushroomCount % 10 < 5) // ���� ����� ��������� �� 2,3,4 �� ������ ����(�)
	{
		wordEnding[0] = 'a';
		wordEnding[1] = '\0';
	}
	printf("� ���� ");
	SetConsoleTextAttribute(h, 4);
	printf("%i", mushroomCount);
	SetConsoleTextAttribute(h, 15);
	printf(" ����");
	SetConsoleTextAttribute(h, 10);
	printf("%s", wordEnding);
}

void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
	SetConsoleTextAttribute(h, 15);
	printf("\n\n������� ������� ��������:");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::PointInAreaTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - ����������� ����� � �������");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::SquareEquationTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - �������� ����������� �������");
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::MushroomOutputTask);
	SetConsoleTextAttribute(h, 15);
	printf(" - ��������� ����� � �������", MenuOptions::PointInAreaTask, MenuOptions::SquareEquationTask, MenuOptions::MushroomOutputTask, MenuOptions::Exit);
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::ClearConsole);
	SetConsoleTextAttribute(h, 15);
	printf(" - �������� �������", MenuOptions::PointInAreaTask, MenuOptions::SquareEquationTask, MenuOptions::MushroomOutputTask, MenuOptions::Exit);
	SetConsoleTextAttribute(h, 10);
	printf("\n%i", MenuOptions::Exit);
	SetConsoleTextAttribute(h, 15);
	printf(" - �����\n> ", MenuOptions::PointInAreaTask, MenuOptions::SquareEquationTask, MenuOptions::MushroomOutputTask, MenuOptions::Exit);
	SetConsoleTextAttribute(h, 15);
	scanf("%i", &choice);
}



void PrintEquationSolution(HANDLE& h, double x)
{
	SetConsoleTextAttribute(h, 15);
	printf("����� �������: ");
	SetConsoleTextAttribute(h, 10);
	printf("%lf", x);
	SetConsoleTextAttribute(h, 15);
}

void PrintEquationSolutions(const HANDLE& h,  double x1, double x2 = -DBL_MAX)
{
	if(x2)
	SetConsoleTextAttribute(h, 15);
	printf("����� �������:");
	SetConsoleTextAttribute(h, 10);
	printf("%lf", x1);
	SetConsoleTextAttribute(h, 15);
	printf(";");
	SetConsoleTextAttribute(h, 10);
	printf("%lf", x2);
	SetConsoleTextAttribute(h, 15);
}

void PointInAreaTask()
{
	// ��'��� ������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �����, ��� ���� ������� ������
	double x, y; // ���� - ����������;

	/* �������� ��������� ����� */
	printf("������:x,y ���������� �����>");

	scanf("%lf %lf", &x, &y);

	//����� ��������� � ����
	bool isPointInSquare = y <= 1 && y >= 0 && x >= -1 && x <= 0; // ����� ��� ��������� � �������
	bool isPointInCirlce = y * y + x * x <= 1; // ����� ��� ��������� ����� � ����
	bool isPointInSector = isPointInCirlce && x >= 0 && y >= 0; // ����� ��� ��������� ����� � �������� ������ �����

	bool isPointInRequiredArea = isPointInSquare || isPointInSector; // ����� ��� ��������� ����� � ������������ �������

	if (isPointInRequiredArea) {

		SetConsoleTextAttribute(h, 15);
		printf("�����");
		SetConsoleTextAttribute(h, 12);
		printf(" (%.2lf; %.2lf)", x, y);
		SetConsoleTextAttribute(h, 10);
		printf(" ���������");
		SetConsoleTextAttribute(h, 15);
		printf(" � ������������ �������");
	}
	else {
		SetConsoleTextAttribute(h, 15);
		printf("�����");
		SetConsoleTextAttribute(h, 12);
		printf(" (%.2lf; %.2lf)", x, y);
		SetConsoleTextAttribute(h, 4);
		printf(" �� ���������");
		SetConsoleTextAttribute(h, 15);
		printf(" � ������������ �������");
	}



	SetConsoleTextAttribute(h, 7);
}

void SquareEquationCheckTask() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �����, ��� ���� ������� ������
	double a, b, c; // ���� �� ������������� ����������� � ����������� ������ ���� ax^2 + bx + c = 0
	printf("������ ���� a, b, c �� ������������� ����������� � ����������� ������ ���� ax^2 + bx + c = 0> ");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("������� ������� %lf*x^2 %+lfx %+lf = 0\n", a, b, c);
	if (a == 0) {
		SetConsoleTextAttribute(h, 4);
		printf("г������ �� � ���������� !\n");
		if (b == 0) {
			printf("г������ �� �� ������ ������!");
			return;
		}
		double x = -c / b;
		PrintEquationSolution(h, x);
	}
	else if (b == 0) {
		SetConsoleTextAttribute(h, 4);
		printf("г������ � �������� ���������� ��������!\n");
		if (c > 0) {
			printf("г������ �� �� ������ ������");
			SetConsoleTextAttribute(h, 15);
		}
		else {
			double x1 = sqrt(-c);
			double x2 = -sqrt(-c);
			PrintEquationSolutions(h, x1, x2);
		}

		SetConsoleTextAttribute(h, 15);
	}
	else if (c == 0)
	{
		SetConsoleTextAttribute(h, 4);
		printf("г������ � �������� ���������� ��������!\n");
		if (b == 0) {
			double x1 = 0;
			double x2 = 0;
			PrintEquationSolutions(h, x1, x2);
		}
		else {
			double x = -b / a;
			PrintEquationSolution(h, x);
		}
		return;
	}
	double D; // ����������� ����� ����������� �������;
	D = b * b - 4 * a * c;
	if (D < 0) {
		SetConsoleTextAttribute(h, 4);
		printf("����������� ������� ����� 0. г������ �� �� ����'����, D = %.3lf", D);
		SetConsoleTextAttribute(h, 15);

	}
	else if (D == 0) {
		double x = b / (2 * a);
		SetConsoleTextAttribute(h, 15);
		printf("����������� ������� ������� ����\n");
		PrintEquationSolution(h, x);
	}
	else {
		double x1 = (-b - sqrt(D)) / (2 * a);
		double x2 = (-b + sqrt(D)) / (2 * a);
		PrintEquationSolutions(h, x1, x2);
	}
}

