#ifndef BIT_SET_H
#define BIT_SET_H
#include<memory>
#include <cstdlib>
#include<string>
using namespace std;
const size_t machine_word = (8 * sizeof(unsigned int));
template<size_t n>
class Bit_Set {
private:
    size_t* array;
    size_t elements;//of array
    size_t words;//the hole words
public:
    Bit_Set();
    Bit_Set(unsigned long long int value);
    ~Bit_Set();
    void set(unsigned int);//+
    void reset(unsigned int);//+
    void flip(unsigned int);//+
    int test(unsigned int);//+
    bool all();//+
    bool any();//+
    size_t count();
    bool none();//+
    size_t size();//+
    size_t operator[](size_t index);
    std::string to_string();
    unsigned long long int to_ullong();
    unsigned long int to_ulong();
   /* void operator |(unsigned long long int value);
    void operator &(unsigned long long int value);*/
};

template<size_t n>
Bit_Set<n>::Bit_Set() {
     elements = n / machine_word;
     words = elements;
    if (n % machine_word) { ++elements; }
    array = (size_t*)calloc(elements,sizeof(size_t));
}

template<size_t n>
Bit_Set<n>::Bit_Set(unsigned long long int value)
{
    elements = n / machine_word;
    words = elements;
    if (n % machine_word) { ++elements; }
    array = (size_t*)calloc(elements, sizeof(size_t));
    for (size_t i = 0; i < elements; ++i) {//полностью прочитали слова
        array[i] = (value | static_cast<unsigned long int>(0));
        value >>= machine_word;
        //cout << value<<'\n';
    }
    if (n % machine_word) {
        array[words] &= ((static_cast<unsigned long int>(1) << (n % machine_word)) - 1);//обрубили не нужное
    }
}

template<size_t n>
Bit_Set<n>::~Bit_Set()
{
     free(array);
}

template<size_t n>
void Bit_Set<n>::set(unsigned int k) {
    array[k / machine_word] |= (1U << (k % machine_word));
}

template<size_t n>
void Bit_Set<n>::reset(unsigned int k) {
    array[k / machine_word] &= ~(1U << (k % machine_word));
}

template<size_t n>
int Bit_Set<n>::test(unsigned int k) {
    return ((array[k / machine_word] & (1U << (k % machine_word))) != 0);
}

template<size_t n>
bool Bit_Set<n>::all()
{
    constexpr bool _Zero_length = n == 0;
    if constexpr (_Zero_length) { // must test for this, otherwise would count one full word
        return true;
    }

    constexpr bool _No_padding = n % machine_word == 0;
    for (size_t pos = 0; pos < words; ++pos) {//проверили все целые слова
        if (array[pos] != ~static_cast<unsigned long int>(0)) {
            return false;
        }
    }

    return _No_padding || (array[words] == (static_cast<unsigned long int>(1) << (n % machine_word)) - 1);
}

template<size_t n>
bool Bit_Set<n>::any()
{
    for (size_t pos = 0; pos < elements; ++pos) {
        if (array[pos] != 0) {
            return true;
        }
    }
        return false;
}

template<size_t n>
size_t Bit_Set<n>::count()
{
    const char* const _Bitsperbyte = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4"
        "\1\2\2\3\2\3\3\4\2\3\3\4\3\4\4\5"
        "\1\2\2\3\2\3\3\4\2\3\3\4\3\4\4\5"
        "\2\3\3\4\3\4\4\5\3\4\4\5\4\5\5\6"
        "\1\2\2\3\2\3\3\4\2\3\3\4\3\4\4\5"
        "\2\3\3\4\3\4\4\5\3\4\4\5\4\5\5\6"
        "\2\3\3\4\3\4\4\5\3\4\4\5\4\5\5\6"
        "\3\4\4\5\4\5\5\6\4\5\5\6\5\6\6\7"
        "\1\2\2\3\2\3\3\4\2\3\3\4\3\4\4\5"
        "\2\3\3\4\3\4\4\5\3\4\4\5\4\5\5\6"
        "\2\3\3\4\3\4\4\5\3\4\4\5\4\5\5\6"
        "\3\4\4\5\4\5\5\6\4\5\5\6\5\6\6\7"
        "\2\3\3\4\3\4\4\5\3\4\4\5\4\5\5\6"
        "\3\4\4\5\4\5\5\6\4\5\5\6\5\6\6\7"
        "\3\4\4\5\4\5\5\6\4\5\5\6\5\6\6\7"
        "\4\5\5\6\5\6\6\7\5\6\6\7\6\7\7\x8";
    const unsigned char* _Ptr = reinterpret_cast<const unsigned char*>(array);
    const unsigned char* const _End = _Ptr + sizeof(size_t)*elements;
    size_t _Val = 0;
    for (; _Ptr != _End; ++_Ptr) {
        _Val += _Bitsperbyte[*_Ptr];
    }

    return _Val;
}

template<size_t n>
void Bit_Set<n>::flip(unsigned int k) {
    array[k / machine_word] ^= (1U << (k % machine_word));
}



template<size_t n>
bool Bit_Set<n>::none()
{
    return !any();
}

template<size_t n>
size_t Bit_Set<n>::size()
{
    return n;
}

template<size_t n>
size_t Bit_Set<n>::operator[](size_t index)
{
    if (index >= n) { index = n - 1; }
    size_t num_of_word = index / machine_word;
    size_t pos_in_word = index % machine_word;
    size_t word = array[num_of_word];
    size_t res = (word >> pos_in_word) & 1;
    return (bool)res;
}

template<size_t n>
std::string Bit_Set<n>::to_string()
{
    std::string str;
    for (int i = n - 1; i >= 0; --i) {
        str.push_back(this->operator[](i)+48);
    }
    return str;
}

template<size_t n>
unsigned long long int Bit_Set<n>::to_ullong()
{
    unsigned long long int res = 0;
    unsigned long long int multiplier = 1;
    for (size_t i = 0; i < n; ++i) {
        res += multiplier * this->operator[](i);
        multiplier <<= 1;
    }
    return res;
}

template<size_t n>
unsigned long int Bit_Set<n>::to_ulong()
{
    unsigned long int res = 0;
    unsigned long long int multiplier = 1;
    for (size_t i = 0; i < n; ++i) {
        res += multiplier * this->operator[](i);
        multiplier <<= 1;
    }
    return res;
}

#endif // BIT_SET_H
