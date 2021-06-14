// OOP_bsuir_2sem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//1.    ����������� ��� ������ � � �(�� ��������� ������������).
//� ������ � ���������� ������ a.m[5].����� � �������� : �����  poisk ����������� � �����������
//max � min �������� ��������� ������� a.m[3](������ �) � ����������� ����� swap() 
//����������� ������� �������������� �������� max � min.
//2.    ������� 2 �������  a � b, �������������� ������ � ���������� ������, ����������� 
//���������� �������� += (a += b, � ������ � ����������� ������� ������������ � b, �� �� ������������ � a).
//3.   ������� �������� ������� �������������� ������� ������������.
//������� ����� � ������ ��������(char*).����������� ����� � ������,
//���������� � ������� �������� ������.����������� � ����������� ������
//����� � ������ � ������ ������� ������� � ���������� ���� � ������ �������� ������.

#include <iostream>
const int n = 5;

int main()
{
    std::cout << "Hello World!\n";
}

class A {
    public:
        int m[n];
};

class B {
public:
	static double swap(int min,int max);
    void poisk();
private:
    int min;
    int max;
    A a;
};

double B::swap(int min, int max)
{
    return (min + max) / 2.0;
}

void B::poisk()
{
    if (n == 1)
    {
        max = a.m[0];
        min = a.m[0];
        return;
    }

    if (a.m[0] > a.m[1])
    {
        max = a.m[0];
        min = a.m[1];
    }
    else
    {
        max = a.m[1];
        min = a.m[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (a.m[i] > max)
            max = a.m[i];

        else if (a.m[i] < min)
            min = a.m[i];
    }

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
