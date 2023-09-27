#include <math.h>
#include <iostream>
using namespace std;

int main()
{


	//bytes count for types calculating
	cout << "Task 1" << endl;
	int bytesCount;

	bytesCount = sizeof(int);
	cout << "int size: " << bytesCount << " bytes" << endl;
	bytesCount = sizeof(short);
	cout << "short size: " << bytesCount << " bytes" << endl;
	bytesCount = sizeof(long);
	cout << "long size: " << bytesCount << " bytes" << endl;
	bytesCount = sizeof(char);
	cout << "char size: " << bytesCount << " bytes" << endl;
	bytesCount = sizeof(float);
	cout << "float size: " << bytesCount << " bytes" << endl;
	bytesCount = sizeof(double);
	cout << "double size: " << bytesCount << " bytes" << endl;

	system("pause");
	system("cls");

	/// Triangle area calculating
	cout << "Task 2\n";
	double aSide, bSide, cSide;
	cout << "Input first side of triangle: ";
	cin >> aSide;
	cout << "Input second side of triangle: ";
	cin >> bSide;
	cout << "Input third side of triangle: ";
	cin >> cSide;

	if (aSide + bSide <= cSide || bSide + cSide <= aSide || aSide + cSide <= bSide) 
	{
		cout << "Triangle with this sides cannot exist" << endl;
	}
	else {
		double p = (aSide + bSide + cSide) / 2;
		double area = sqrt(p * (p - aSide) * (p - bSide) * (p - cSide));
		cout << "Area of triangle equals " << area << endl;
	}

	system("pause");
	system("cls");

	/// Mira chisla....
	cout << "Task 3\n";
	int number;
	cout << "Enter number to pow: ";
	cin >> number;
	cout << number;
	number = number * number;
	number = number * number;
	number = number * number;
	cout << "^8 = " << number << endl;

	system("pause");
	system("cls");
	/// changing a and b with temporary variable
	cout << "Task 4.1" << endl;
	int a = 3;
	int b = 5;
	cout << "Enter number a and b to swap values: ";
	cin >> a >> b;
	cout << "Before swap a=" << a << " b=" << b << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "After swap a=" << a << " b=" << b << endl;

	system("pause");
	system("cls");

	/// changing a and b without temporary variable
	cout << "Task 4.2" << endl;
	cout << "Enter number a and b to swap values without additional variable: ";
	cin >> a >> b;
	cout << "Before swap a=" << a << " b=" << b << endl;

	a = a + b;
	b = a - b;
	a = a - b;

	cout << "After swap a=" << a << " b=" << b << endl;

	system("pause");
	system("cls");

	/// calculation count of seconds in years
	cout << "Enter amount of years to count seconds:";
	unsigned int yearsCount;
	cin >> yearsCount;
	long double secondCount = yearsCount * 365 * 24 * 60 * 60;
	cout << "There are " << secondCount << " seconds in " << yearsCount << " years";
	
	return 0;
}