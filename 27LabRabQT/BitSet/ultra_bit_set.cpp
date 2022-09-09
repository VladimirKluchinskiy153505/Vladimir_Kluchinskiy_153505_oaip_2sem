#include "ultra_bit_set.h"
bit_set::bit_set(size_t N) {
    this->n = N;
     elements = n / machine_word;
     words = elements;
    if (n % machine_word) { ++elements; }
    array = (size_t*)calloc(elements,sizeof(size_t));
}

bit_set::bit_set(size_t N,unsigned long long int value)
{
    this->n = N;
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


bit_set::~bit_set()
{
     free(array);
}


void bit_set::set(unsigned int k) {
    if(k<n){
    array[k / machine_word] |= (1U << (k % machine_word));
    }
}


void bit_set::reset(unsigned int k) {
    if(k<n){
    array[k / machine_word] &= ~(1U << (k % machine_word));
    }
}


bool bit_set::test(unsigned int k) {
    if(k<n){
    return ((array[k / machine_word] & (1U << (k % machine_word))) != 0);
    }
}


bool bit_set::all()
{
     bool _Zero_length = (n == 0);
    if  (_Zero_length) { // must test for this, otherwise would count one full word
        return true;
    }

     bool _No_padding = n % machine_word == 0;
    for (size_t pos = 0; pos < words; ++pos) {//проверили все целые слова
        if (array[pos] != ~static_cast<unsigned long int>(0)) {
            return false;
        }
    }

    return _No_padding || (array[words] == (static_cast<unsigned long int>(1) << (n % machine_word)) - 1);
}


bool bit_set::any()
{
    for (size_t pos = 0; pos < elements; ++pos) {
        if (array[pos] != 0) {
            return true;
        }
    }
        return false;
}


size_t bit_set::count()
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


void bit_set::flip(unsigned int k) {
    if(k<n){
    array[k / machine_word] ^= (1U << (k % machine_word));
    }
}
bool bit_set::none()
{
    return !any();
}


size_t bit_set::size()
{
    return n;
}


size_t bit_set::operator[](size_t index)
{
    if(n==0){return 0;}
    if (index >= n) { index = n - 1; }
    size_t num_of_word = index / machine_word;
    size_t pos_in_word = index % machine_word;
    size_t word = array[num_of_word];
    size_t res = (word >> pos_in_word) & 1;
    return (bool)res;
}


std::string bit_set::to_string()
{
    std::string str;
    for (int i = n - 1; i >= 0; --i) {
        str.push_back(this->operator[](i)+48);
    }
    return str;
}


unsigned long long int bit_set::to_ullong()
{
    unsigned long long int res = 0;
    unsigned long long int multiplier = 1;
    for (size_t i = 0; i < n; ++i) {
        res += multiplier * this->operator[](i);
        multiplier <<= 1;
    }
    return res;
}


unsigned long int bit_set::to_ulong()
{
    unsigned long int res = 0;
    unsigned long long int multiplier = 1;
    for (size_t i = 0; i < n; ++i) {
        res += multiplier * this->operator[](i);
        multiplier <<= 1;
    }
    return res;
}
