// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\My_Deque\My_Deque.cpp>
#include <iostream>
using namespace std;
int main()
{
    my_deque<int> dec;
    for (int i = 0; i < 2; i++) {
        dec.push_back(10 * i + 100);
        cout << "\npush";
    }
 
    //dec.push_back(11);
    //dec.push_back(22);
    //dec.push_back(33);
    //dec.push_back(44);
  //  dec.pop_front();
    //dec.insert(777,5);
    for (int i = 0; i < dec.count_nodes(); i++) {
        cout<<dec[i]<<"\n";
    }
//    cout << dec.head.use_count()<<" "<<dec.head->core<<'\n';
  //  cout << dec.tail.use_count() << " " << dec.tail->core << '\n';
 /*   dec.eraze(5);
    dec.pop_behind();
    dec.pop_front();
    dec.push_front(888);
    cout << "\n";
    for (int i = 0; i < dec.count_nodes(); i++) {
        cout << dec[i] << "\n";
    }*/
    return 0;
}

