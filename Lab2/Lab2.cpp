#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char good1[16], good2[16], good3[16]; // ����� ������
	char type1, type2, type3; // ���� ������
	double price1, price2, price3; // ���� ������
	int minCountInBatch1, minCountInBatch2, minCountInBatch3; // ������� ������� � ����
	/* �������� ��������� ����� */
	printf("1. ������: ����� ������, ���, ����, �������� ������� � ����>");
	scanf("%s %c %lf %d", good1, &type1, &price1, &minCountInBatch1);
	printf("2. ������: ����� ������, ���, ����, �������� ������� � ����>");
	scanf("%s %c %lf %d", good2, &type2, &price2, &minCountInBatch2);
	printf("3. ������: ����� ������, ���, ����, �������� ������� � ����>");
	scanf("%s %c %lf %d", good3, &type3, &price3, &minCountInBatch3);
	/* ��������� ������� */ /* ��������� ��������� */
	HANDLE h; // Link on window of Console
	
	h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
	SetConsoleTextAttribute(h, 3);
	printf("\n-------------------------------------------------------------------\n");
	printf("|                           �����-����                            |\n");
	h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
	SetConsoleTextAttribute(h, 14);
	printf("|-----------------------------------------------------------------|\n");
	printf("|      �����    |  ���  |ֳ�� �� 1��|̳������� ������� � ����|\n");
	printf("|               | ������|  (���)    |                             |\n");
	printf("|---------------|-------|-----------|-----------------------------|\n");
	h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
	SetConsoleTextAttribute(h, 10);
	/* ��������� ����� ��������� ����� */
	printf("| %-14s|%7c|%11.3f|%29d|\n", good1, type1, price1, minCountInBatch1);
	printf("| %-14s|%7c|%11.3f|%29d|\n", good2, type2, price2, minCountInBatch2);
	printf("| %-14s|%7c|%11.3f|%29d|\n", good3, type3, price3, minCountInBatch3);
	/* ��������� ������� */
	h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
	SetConsoleTextAttribute(h, 6);
	printf("|-----------------------------------------------------------------|\n");
	printf("|            �������: � - ����������; � - ���������;            |\n");
	printf("-------------------------------------------------------------------\n");
	h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
	SetConsoleTextAttribute(h, 7);
	return 0;
}
