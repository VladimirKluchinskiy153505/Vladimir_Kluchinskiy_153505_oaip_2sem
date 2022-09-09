#ifndef ULTRA_BIT_SET_H
#define ULTRA_BIT_SET_H

#include<memory>
#include <cstdlib>
#include<string>
using namespace std;
const size_t machine_word = (8 * sizeof(unsigned int));
class bit_set {
private:
    size_t* array=nullptr;
    size_t n=0;
    size_t elements=0;//of array
    size_t words=0;//the hole words
public:
    bit_set(size_t N);
    bit_set(size_t N,unsigned long long int value);
    ~bit_set();
    void set(unsigned int);//+
    void reset(unsigned int);//+
    void flip(unsigned int);//+
    bool test(unsigned int);//+
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


#endif // ULTRA_BIT_SET_H
