#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\New_String\New_String.cpp>
#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\My_Vec\My_Vec.cpp>
#include <iostream>
#include <string>
using namespace std;
template <typename T>
std::remove_reference_t<T>&& Move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}

template<typename T,typename U>
struct my_pair {
public:
    T first;
    U second;
    my_pair(T first, U second):first(first),second(second){}
    void swap(my_pair<T, U>& other) {
        auto temp1=Move(this->first);
        auto temp2 = Move(this->second);
        this->first = Move(other.first);
        this->second = Move(other.second);
        other.first = Move(temp1);
        other.second = Move(temp2);
    }
    void operator=(const my_pair<T, U>& other) {
        this->first = Move(other.first);
        this->second = Move(other.second);
    }
};
int main()
{
    my_vec<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i + 100);
    }
    for (auto now : vec) {
        cout << now << " ";
    }
    cout << '\n';
    vec.assign(2, 7);
    for (auto now = vec.rbegin(); now != vec.rend(); now++) {
        cout << *now<<" ";
    }
    cout << '\n';
    cout << vec.front()<<" "<<vec.data();
    cout << endl;
    my_vec<my_vec<size_t>> big_vec(10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            big_vec[i].push_back(j+200);
        }
    }
    for (auto &now : big_vec) {
        for (auto &sec : now) {
            cout << sec << " ";
        }
        cout << '\n';
    }
  
    /*MyString str;
    Getline(cin, str);
    cout <<str<<" "<< str.Length();
    pair<int, MyString> test(77, "abs");
    my_pair<int, pair<int,MyString>> error(25, test);
    cout << error.first << " " << error.second.first<<" "<<error.second.second << '\n';*/
    return 0;
}
