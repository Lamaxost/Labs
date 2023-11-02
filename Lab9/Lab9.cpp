#define _CRT_SECURE_NO_WARNINGS


//#define PRINT_TYPE

#include <iostream>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <random>
#include "PriceListItem.cpp"


using namespace std;
enum class MenuOptions { ClearConsole = 5, Exit = 4, Filling=1, Sort=2, Print=3 };
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
    SetConsoleTextAttribute(h, 15);
    printf("\n\n������� �� �������:");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Filling);
    SetConsoleTextAttribute(h, 15);
    printf(" - ���������� ��������� (������� �� ��������������� �� � ������, �� ���������� �����)");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Sort);
    SetConsoleTextAttribute(h, 15);
    printf(" - ����������(�� ��������� ����)");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Print);
    SetConsoleTextAttribute(h, 15);
    printf(" - ����");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::ClearConsole);
    SetConsoleTextAttribute(h, 15);
    printf(" - �������� �������");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Exit);
    SetConsoleTextAttribute(h, 15);
    printf(" - �����\n> ");
    SetConsoleTextAttribute(h, 15);
    scanf("%i", &choice);
}

template<typename Type>
void Swap(Type* items, int aIndex, int bIndex) {
    Type t = items[aIndex];
    items[aIndex] = items[bIndex];
    items[bIndex] = t;
    
}


void Print(PriceListItem*& items, int& count) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
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
    for (int i = 0; i < count; i++) 
    {
        PriceListItem good = items[i];
        printf("| %-14s|%7c|%11.3f|%29d|\n", good.Name.c_str(), good.Type, good.Price, good.MinCountInBatch);
    }
    /* ��������� ������� */
    h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
    SetConsoleTextAttribute(h, 6);
    printf("|-----------------------------------------------------------------|\n");
    printf("|            �������: � - ����������; � - ���������;            |\n");
    printf("-------------------------------------------------------------------\n");
    h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
    SetConsoleTextAttribute(h, 7);
}


void Sort(PriceListItem*& items, int& count) {
    cout << "�� ���� ����� �����������(1 - ��'�, 2 - ���, 3 - ����, 4 - ̳������� ������� � ����)>";
    int answer;
    cin >> answer;


    if (answer == 1) {
        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++) {

                if (items[i].Name.compare(items[j].Name) > 0) {
                    Swap(items, j, i);
                }
            }
        }
    }
    else if (answer == 2) {
        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++) {

                if (items[i].Type < items[j].Type) {
                    Swap(items, j, i);
                }
            }
        }
    }
    else if (answer == 3) {
        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++) {

                if (items[i].Price < items[j].Price) {
                    Swap(items, j, i);
                }
            }
        }
    }
    else if (answer == 4) {
        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++) {

                if (items[i].MinCountInBatch < items[j].MinCountInBatch) {
                    Swap(items, j, i);
                }
            }
        }
    }
    else {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(h, 4);
        cout << "���������� �������";
        SetConsoleTextAttribute(h, 15);
        return;
    }
    Print(items, count);

}

void Fill(PriceListItem* &items,int &count) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
#ifdef PRINT_TYPE

    cout << "������ ���\n";
    while (true) {
        cout << "� ����� ";
        SetConsoleTextAttribute(h, 4);
        cout << count;
        SetConsoleTextAttribute(h, 15);
        cout << " ��������, ������ ? (+, -)";
        char input;
        cin >> input;
        if (input == '-') {
            return;
        }
        PriceListItem item = PriceListItem();
        cout << "������ ����� �������� >";
        cin >> item.Name;
        cout << "������ ��� �������� (� � ����������, � � ���������)>";
        cin >> item.Type;
        cout << "������ ���� �������� >";
        cin >> item.Price;
        cout << "������ �������� ������� � ���� >";
        cin >> item.MinCountInBatch;

        PriceListItem* newArr = new PriceListItem[count + 1];
        newArr[0] = item;
        for (int i = 1; i < count + 1; i++) {
            newArr[i] = items[i - 1];
        }
        delete[] items;
        items = newArr;
        count++;
    }

#else
    cout << "������������ ���\n";
    count = 2 + rand() % 5;
    string namesForRand[] = { "����", "����", "�����������", "������", "�����", "������" };
    char typesForRand[] = { '�', '�'};
    PriceListItem* newArr = new PriceListItem[count];
    for (int i = 0; i < count; i++) {
        PriceListItem item = PriceListItem();
        item.Name = namesForRand[rand()%6];
        item.Type = typesForRand[rand()%2];
        item.Price = (double)(rand()%1000) / 100;
        item.MinCountInBatch = rand()%100;
        newArr[i] = item;
    }
    delete[] items;
    items = newArr;
#endif // PRINT_TYPE
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
    
    int itemsCount = 0;
    PriceListItem * items = new PriceListItem[itemsCount];

    while (true) {
        PrintMenuAndAskChoice(h, choice);
        switch (choice)
        {
        case MenuOptions::Filling:
            Fill(items, itemsCount);
            break;
        case MenuOptions::Sort:
            Sort(items, itemsCount);
            break;
        case MenuOptions::Print:
            Print(items, itemsCount);
            break;
        case MenuOptions::Exit:
            delete[] items;
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
    delete[] items;
}