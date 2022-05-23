#include "pch.h"
#include "framework.h"
#include <iostream>
using namespace std;
// TODO: This is an example of a library function
class MyString
{
private:
	// Указатель на массив char, хранит символы, которые мы передали в наш объект.
	char* str;
	int length;
public:
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{

		length = strlen(str);// функция strlen получает количество символов в строке которую мы передаём в объект

		// выделяем память для динамического массива где будет храниться наша строка
		// +1 символ так как нужно место в массиве под терминирующий 0
		this->str = new char[length + 1];
		
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		//закрываем строку терминирующим нулём
		this->str[length] = '\0';

	}
	MyString(MyString&& other)
	{
		this->length = std::move(other.length);
		this->str = std::move(other.str);
		other.str = nullptr;
	}
	MyString(char* ptr) {
		str = ptr;
		length = strlen(ptr);
	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}
	friend ostream& operator<<(ostream& os, const MyString& dt);
	friend istream& operator>> (istream& is, MyString& dt);
	friend istream& Getline(istream& stream, MyString& str);
	// перегруженый оператор присваивания, вызывается когда необходимо присвоить значение одного объекта другому
	MyString& operator =(const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}
	MyString& operator=(char*& str) {
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] =str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString operator+(const MyString& other)
	{
		
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		// возвращаем результат конкатенации
		return newStr;
	}
	void push_back(char symb) {
		char* newstr = new char[length + 2];
		for (int i = 0; i < length; i++) {
			newstr[i] = str[i];
		}
		newstr[length] = symb;
		newstr[length + 1] = '\0';
		length++;
		delete[]str;
		str = newstr;
	}
	MyString& replace(size_t pos, size_t len, MyString s) {
		if ((pos < 0) || (pos >= length)) {
			return *this;
		}
		size_t ssize = s.size();
		size_t newlength = length + ssize - len;
		char* newstr = new char[newlength+1];
		int i = 0;
		for (; i < pos; ++i) {
			newstr[i] = str[i];
		}

		for (int j = 0; j < ssize; ++j) {
			newstr[pos + j] = s[j];
		}
		i = pos;
		for (; i < length; ++i) {
			newstr[i + ssize] = str[i + len];
		}
		newstr[newlength] = '\0';
		delete str;
		str = newstr;
		length = newlength;
		return *this;

	}
	MyString substr(size_t start, size_t len) {
		char* newstr = new char[len+1];
		for (size_t i = 0; i < len; ++i) {
			newstr[i] = str[start + i];
		}
		newstr[len] = '\0';
		return MyString(newstr);

	}
	char* c_str() {
		return str;
	}
	int find(MyString s,size_t pos=0) const {
		size_t ssize = s.size();
		bool f;
		if (this->length < ssize)
		{
			return -1;
		}
		for (int i = pos; i < length; ++i) {
			if (str[i] == s[0]) {
				f = true;
				for (int j = 1; j < ssize; ++j) {
					if (str[i + j] != s[j]) {
						f = false;
						break;
					}

				}
				if (f) {
					return i;
				}
			}
		}
		return -1;
	}
	void Print()
	{
		std::cout << str;
	}

	int size()
	{
		return length;
	}

	bool operator ==(const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));
	}

	char& operator [](int index)
	{
		return this->str[index];
	}
	void clear()
	{
		delete str;
		str = nullptr;
		length = 0;
	}
};
ostream& operator<<(ostream& os, const MyString& dt) {
	if (dt.str!= nullptr) {
		os << dt.str;
	}
	return os;
}
istream& operator>> (istream& is, MyString& dt)
{
 char* str=new char[1024];
	is >> str;
	dt = str;
	delete str;
	return is;
}
//ifstream& Getline(ifstream& stream, MyString& str)
//{
//	char ch;
//	//str.clear();
//	while () {
//		str.push_back(ch);
//	}
//	return stream;
//}
istream& Getline(istream& stream, MyString& str)
{
	char ch;
	//str.clear();
	while (stream.get(ch) && ch != '\n') {
		str.push_back(ch);
	}
	return stream;
}
void Memcpy(char*& s1,const char* s2, size_t n) {
	char* newstr = new char[n + 1];
	for (int i = 0; i < n; i++) {
		newstr[i] = s2[i];
	}
	newstr[n] = '\0';
	delete s1;
	s1 = newstr;
}