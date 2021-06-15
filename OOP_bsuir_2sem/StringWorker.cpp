#include <iostream>

using namespace std;
class BaseString
{
public:
	BaseString()
	{
		str = "initial value";
		len = str.length();
	};
	BaseString(string newstr)
	{
		str = newstr;
		len = str.length();
	};
	BaseString(BaseString& st)
	{
		str = st.str;
		len = str.length();
	};
	string get_str()
	{
		return str;
	};

	void set_str(string newstr)
	{
		str = newstr;
		len = str.length();
	};
	char get_symbol(int index)
	{
		return str[index];
	};
	void set_symbol(char newSymbol, int index)
	{
		str[index] = newSymbol;
	};
	int get_len()
	{
		return len;
	};

private:
	string str;
	int len;
};
class StringWorker: public BaseString
{
public:
	StringWorker(string newstr): BaseString(newstr)	{};

	void swap()
	{
		char temp = get_symbol(0);
		int lastIndex = get_len()-1;

		//устанавливаем нулевой элемент
		set_symbol(get_symbol(lastIndex), 0);

		//устанавливаем последний элемент
		set_symbol(temp, lastIndex);
	};
};

