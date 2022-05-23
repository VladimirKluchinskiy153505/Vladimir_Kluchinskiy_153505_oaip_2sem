#ifndef MYSTRING_H
#define MYSTRING_H
#include<stdlib.h>
using namespace std;
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
        this->length = (other.length);
        this->str = (other.str);
        other.str = nullptr;
    }
    ~MyString()
    {
        delete[] this->str;
    }

    MyString(const MyString& other)
    {
        length = Strlen(other.str);
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
    char* c_str() {
        return str;
    }
    int find(MyString s) const {
        size_t ssize = s.size();
        bool f;
        if (this->length < ssize)
        {
            return -1;
        }
        for (int i = 0; i < length; ++i) {
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
    while (stream.get(ch) && ch != '\r') {
        str.push_back(ch);
    }
    return stream;
}
#endif // MYSTRING_H
