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

	char name1[16], name2[16], name3[16];
	char type1, type2, type3;
	double price1, price2, price3;
	int count1, count2, count3;
	/* Введення фактичних даних */
	printf("1. Введіть: назву, вид, ціну, мінімальну кількість>");
	scanf("%s %c %lf %d", name1, &type1, &price1, &count1);
	printf("2. Введіть: назву, вид, ціну, мінімальну кількість>");
	scanf("%s %c %lf %d", name2, &type2, &price2, &count2);
	printf("3. Введіть: назву, вид, ціну, мінімальну кількість>");
	scanf("%s %c %lf %d", name3, &type3, &price3, &count3);
	/* Виведення таблиці */ /* Виведення заголовків */

	printf("\n-------------------------------------------------------------------\n");
	printf("|                           Прайс-лист                            |\n");
	printf("|-----------------------------------------------------------------|\n");
	printf("|      Назва    |  Тип  |Ціна за 1шт|Мінімальна кількість в партії|\n");
	printf("|               | товару|  (грн)    |                             |\n");
	printf("|---------------|-------|-----------|-----------------------------|\n");
	/* виведення рядків фактичних даних */
	printf("| %14s|%7c|%11.3f|%-29d|\n", name1, type1, price1, count1);
	printf("| %14s|%7c|%11.3f|%-29d|\n", name2, type2, price2, count2);
	printf("| %14s|%7c|%11.3f|%-29d|\n", name3, type3, price3, count3);
	/* виведення приміток */
	printf("|-----------------------------------------------------------------|\n");
	printf("|            Примітка: К - Канцтовари; О - Оргтехніка;            |\n");
	printf("-------------------------------------------------------------------\n");
	
	return 0;
}
