#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <random>

using namespace std;
int random(int from, int to);
void Task1();
void Task2();
void Task3();
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Task1();
    //Task2();
    Task3();
       
}
void Task3() {
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
        cout << "�� �� ������� ��������� �������� ��������";
    }
    if (insertPosition + insertCount > sizeof(arr) / sizeof(int) - 1) {
        cout << "�� �� ������� ��������� �������� ������ ��������";
    }
    for (int i = insertPosition; i - insertPosition < insertCount; i++) {
        arr[i] = 0;
    }
    cout << "����� ������: ";
    for (int i = 0; i < sizeof(arr) / sizeof(int); cout << arr[i++] << " ");
    cout << endl;
}
void Task2() {
    int smokingSeatsIndex = 0;
    int nonSmokingSeatsIndex = 5;
    int seats[10] = {0,};
    while (smokingSeatsIndex + nonSmokingSeatsIndex < 15) {
        cout << "̳���: ";
        for (int i = 0; i < 10; i++) {
            cout << seats[i] << " ";
        }
        cout << endl;
        char answer[4];
        cout << "������?(���, Ͳ)\n";
        cin >> answer;
        if (strcmp(answer, "���")==0) {
            if (smokingSeatsIndex >= 5) {
                cout << "�� ���� ��� ������� ������\n";
                continue;
            }
            else {
                seats[smokingSeatsIndex] = 1;
                smokingSeatsIndex++;
                cout << "���� ���� ����� " << smokingSeatsIndex << endl;
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
                cout << "���� ���� ����� " << nonSmokingSeatsIndex << endl;
            }
        }
        else {
            cout << "���������� �������";
        }
    }
    
}
void Task1() {
    int Ar[200];   /* �����, ���� ������������ */
    int i, j;    /* ������� � ����� */
    int av;      /* ������ �������� */
    int nn; /* ������� �������� � ����������� */
    int ib;      /* ������ ������� ����������� */
    srand(time(0));
    /* ���������� ������ ����������� ������� */
    for (i = 0; i < sizeof(Ar) / sizeof(int); Ar[i++] = random(-50,50));
    /* ��������� ����������� ������ */
    printf("���������� ������:\n");
    for (i = 0; i < sizeof(Ar) / sizeof(int); printf("%3d  ", Ar[i++]));
    putchar('\n');  putchar('\n');

    bool isInSequence = false;
    int lastNumber = Ar[0];
    for (i = 1; i < sizeof(Ar) / sizeof(int); i++) {
        bool sequenceFound = false;
        if (Ar[i] <= lastNumber) {
            sequenceFound = true;
        }
        else {
            isInSequence = false;
        }
        if (!isInSequence && sequenceFound) {
            cout << i-1 << " ";
        }
        isInSequence = sequenceFound;
    }

    printf("������-���������:\n");/* ��������� ���������� */
    for (i = 0; i < sizeof(Ar) / sizeof(int); printf("%3d  ", Ar[i++]));  putchar('\n');

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