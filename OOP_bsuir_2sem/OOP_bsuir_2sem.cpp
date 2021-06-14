//1.    –азработать два класса ј и ¬(не использу€ наследовани€).
//¬ классе ј содержитс€ массив a.m[5]. ласс ¬ содержит : метод  poisk вычисл€ющий и сохран€ющий
//max и min значени€ элементов массива a.m[3](класса ј) и статический метод swap() 
//вычисл€ющее среднее арифметическое значений max и min.
//2.    —оздать 2 объекта  a и b, разработанного класса Ц символьна€ строка, реализовать 
//перегрузку операции += (a += b, в объект а добавл€ютс€ символы содержащиес€ в b, но не содержащиес€ в a).
//3.   —оздать иерархию классов представл€ющих простое наследование.
//Ѕазовый класс Ц строка символов(char*).ѕроизводный класс Ц методы,
//работающие с данными базового класса.–еализовать в производном классе
//метод Ц поиска и замены местами первого и последнего слов в строке базового класса.

#include <iostream>
using namespace std;
const int n = 5;

class A {
    public:
        A();
        A(int z[]);
        A(const A& obj);
        ~A();
        void input();
        int m[n];
};

A::A() = default;
A::A(int z[])
{
    for (int i = 0; i < n; i++)
    {
        m[i] = z[i];
    }
}
A::A(const A& obj)
{
    for (int i = 0; i < n; i++)
    {
        m[i] = obj.m[i];
    }
}
A::~A()
{
    delete[] m;
}
void A::input()
{
    cout << "\n\t Please input array values" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t a[" << i + 1 << "]=";
        cin >> m[i];
    }
}

class B {

public:
    B();
    B(A a);
    B(const B& obj);
	static double swap(int min,int max);
    void poisk();
    void printMaxMin();
private:
    A a;
    int min;
    int max;
};
B::B(A currentA) {
    a = currentA;
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

void B::printMaxMin()
{
    cout << "Max: " <<max;
    cout << "Min: " << min;
}

int main()
{
    cout << "Start program!\n";
    A a;
    a.input();

    B b(a);
    b.poisk();
    b.printMaxMin();
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
