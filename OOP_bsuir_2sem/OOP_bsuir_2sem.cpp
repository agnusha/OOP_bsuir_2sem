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
const int nPoisk = 3;

class A {
    private:
         int m[n];
    public:
        A();
        A(int z[]);
        A(const A& obj);
        ~A();

        int getM(int index) { return m[index]; };
        void input();
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
A::~A() = default;

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
    int getMin() { return min; }
    int getMax() { return max; }

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
    return (min + max) / 2.03;
}

void B::poisk()
{
    if (n == 1)
    {
        max = a.getM(0);
        min = a.getM(0);
        return;
    }

    if (a.getM(0) > a.getM(1))
    {
        max = a.getM(0);
        min = a.getM(1);
    }
    else
    {
        max = a.getM(1);
        min = a.getM(0);
    }

    for (int i = 2; i < nPoisk; i++)
    {
        if (a.getM(i) > max)
            max = a.getM(i);

        else if (a.getM(i) < min)
            min = a.getM(i);
    }

}

void B::printMaxMin()
{
    cout << "\nMax: " <<max;
    cout << "\nMin: " << min;
}

class TextString {
public:
    TextString() = default;
    TextString(string currentText);

    string getText() { return text; };
    TextString& operator+=(const TextString& textString);

private:
    string text;
};

TextString::TextString(string currentText)
{
    text = currentText;
}

TextString& TextString::operator+=(const TextString& textString) {
    text += textString.text;
    return *this;
}

#pragma region General
void printAverage(double average)
{
    cout << "\nAverage: " << average;
}

void printText(string text)
{
    cout << "\Text: " << text;
}

string inputText()
{
    string result;
    cout << "\n\t Please input text" << endl;
    cout << "\t";
    cin >> result;
    return result;
}
#pragma endregion

int main()
{
    cout << "Start program!\n";

    //A a;
    //a.input();

    //B b(a);
    //b.poisk();
    //b.printMaxMin();

    //double average = B::swap(b.getMin(), b.getMax());
    //printAverage(average);

    //string text1 = inputText();
    TextString a1(inputText());
    TextString b1(inputText());

    a1 += b1;
    printText(a1.getText());
}
