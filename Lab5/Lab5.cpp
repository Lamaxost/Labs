#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <random>

using namespace std;
int random(int from, int to);
void Task1();
void Task1();
void ArrayProcessing();
void SeatsDistributor();
void ArrayInsert();
enum class MenuOptions { ClearConsole = -1, Exit = 0, Filling, SeatsDistributor, Task3};
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice);
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    MenuOptions choice; // �����, ��� �������� � ����
    while (true) {
        PrintMenuAndAskChoice(h, choice);
        switch (choice)
        {
        case MenuOptions::Filling:
            ArrayInsert();
            break;
        case MenuOptions::SeatsDistributor:
            SeatsDistributor();
            break;
        case MenuOptions::Task3:
            ArrayProcessing();
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
void ArrayInsert() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int arr[12];
    for (int i = 0; i < sizeof(arr) / sizeof(int); arr[i++] = random(-50,50));
    cout << "������: ";
    for (int i = 0; i < sizeof(arr) / sizeof(int); cout <<arr[i++]<<" ");
    cout << endl;
    int insertPosition = 0;
    int insertCount = 0;
    cout << "�� ��� ������� �������� �������� >";
    cin >> insertPosition;
    cout << "������ �������� �������� >";
    cin >> insertCount;
    if (insertPosition > sizeof(arr) / sizeof(int) - 1 || insertPosition<0) {
        SetConsoleTextAttribute(h, 4);
        cout << "�� �� ������� ��������� �������� ��������";
        return;
    }
    if (insertPosition + insertCount > sizeof(arr) / sizeof(int) - 1) {
        SetConsoleTextAttribute(h, 4);
        cout << "�� �� ������� ��������� �������� ������ ��������";
        return;
    }
    for (int i = insertPosition; i - insertPosition < insertCount; i++) {
        int insert = 0;
        cout << "��� ����� ��������>";
        cin >> insert;
        arr[i] = insert;
    }
    SetConsoleTextAttribute(h, 4);
    cout << "����� ������: ";
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        if (i >= insertPosition && i < insertPosition + insertCount) {
            SetConsoleTextAttribute(h, 2);
        }
        cout << arr[i] << " ";
        SetConsoleTextAttribute(h, 15);
    }
    cout << "\n� ��� ������� ��������>";
    cin >> insertPosition;
    cout << "������ �������� �������� >";
    cin >> insertCount;
    if (insertPosition > sizeof(arr) / sizeof(int) - 1 || insertPosition < 0) {
        SetConsoleTextAttribute(h, 4);
        cout << "��������� �������� �������� � ���� �������";
        return;
    }
    if (insertPosition + insertCount > sizeof(arr) / sizeof(int) - 1) {
        SetConsoleTextAttribute(h, 4);
        cout << "��������� �������� ������ ��������";
        return;
    }
    for (int i = insertPosition; i - insertPosition < insertCount; i++) {
        arr[i] = 0;
    }
    cout << "����� ������: ";
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        if (i >= insertPosition && i < insertPosition + insertCount) {
            SetConsoleTextAttribute(h, 4);
        }
        cout << arr[i] << " ";
        SetConsoleTextAttribute(h, 15);
    }
    cout << endl;
}
void SeatsDistributor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    int smokingSeatsIndex = 0;
    int nonSmokingSeatsIndex = 5;
    int seats[10] = {0,};
    while (smokingSeatsIndex + nonSmokingSeatsIndex < 15) {
        SetConsoleTextAttribute(h, 15);
        cout << "̳���: ";
        for (int i = 0; i < 10; i++) {
            if (seats[i]==1) {
                SetConsoleTextAttribute(h, 2);
            }
            else {
                SetConsoleTextAttribute(h, 4);
            }
            cout << seats[i] << " ";
        }
        cout << endl;
        char answer[4];
        SetConsoleTextAttribute(h, 15);
        cout << "������?(";
        SetConsoleTextAttribute(h, 4);
        cout << "���";
        SetConsoleTextAttribute(h, 15);
        cout << ",";
        SetConsoleTextAttribute(h, 2);
        cout << "Ͳ";
        SetConsoleTextAttribute(h, 15);
        cout << ")\n";
        cin >> answer;
        if (strcmp(answer, "���")==0) {
            if (smokingSeatsIndex >= 5) {
                cout << "�� ���� ��� ������� ������\n";
                continue;
            }
            else {
                seats[smokingSeatsIndex] = 1;
                smokingSeatsIndex++;
                SetConsoleTextAttribute(h, 15);
                cout << "���� ���� ����� ";
                SetConsoleTextAttribute(h, 2);
                cout << smokingSeatsIndex << endl;
            }
        }
        else if (strcmp(answer, "Ͳ") == 0) {
            if (nonSmokingSeatsIndex >= 10) {
                cout << "�� ���� ��� ��������� ������\n";
                continue;
            }
            else {
                seats[nonSmokingSeatsIndex] = 1;
                nonSmokingSeatsIndex++;
                SetConsoleTextAttribute(h, 15);
                cout << "���� ���� ����� ";
                SetConsoleTextAttribute(h, 2);
                cout << nonSmokingSeatsIndex << endl;
            }
        }
        else {
            SetConsoleTextAttribute(h, 4);
            cout << "���������� �������\n";
        }
    }
    
}
void ArrayProcessing() {
    int Ar[20];   /* �����, ���� ������������ */
    int i, j;    /* ������� � ����� */
    int av;      /* ������ �������� */
    int nn; /* ������� �������� � ����������� */
    int ib;      /* ������ ������� ����������� */
    srand(time(0));
    /* ���������� ������ ����������� ������� */
    for (i = 0; i < sizeof(Ar) / sizeof(int); Ar[i++] = random(-50,50));
    /* ��������� ����������� ������ */
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    printf("���������� ������:\n");
    SetConsoleTextAttribute(h, 15);
    for (i = 0; i < sizeof(Ar) / sizeof(int); i++) 
    {
        cout << Ar[i]<< " ";
    }
    int comparingNumber = 0;
    cout << "\n������ �����> ";
    cin >> comparingNumber;
    SetConsoleTextAttribute(h, 2);
    printf("���������:\n");/* ��������� ���������� */
    SetConsoleTextAttribute(h, 15);
    for (i = 0; i < sizeof(Ar) / sizeof(int); i++) {
        if (Ar[i] > comparingNumber) {
            Ar[i] = Ar[i] - 10;
        SetConsoleTextAttribute(h, 2);
       }
        else {
        SetConsoleTextAttribute(h, 15);
        }
        cout << Ar[i]<<" ";
    }
    SetConsoleTextAttribute(h, 15);
}
void PrintMenuAndAskChoice(const HANDLE& h, MenuOptions& choice)
{
    SetConsoleTextAttribute(h, 15);
    printf("\n\n������� ������� ��������:");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Filling);
    SetConsoleTextAttribute(h, 15);
    printf(" - �������� � �����");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::SeatsDistributor);
    SetConsoleTextAttribute(h, 15);
    printf(" - ���������� ����");
    SetConsoleTextAttribute(h, 10);
    printf("\n%i", MenuOptions::Task3);
    SetConsoleTextAttribute(h, 15);
    printf(" - �������� ��� �������");
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



int random(int from, int to) {
    if (from > 0) {
        int result = rand() % (from - to+1) + to;
        return result;
    }
    if (from < 0) {
        int result = rand() % (to - from+1) + from;
        return result;
    }
}