#include <iostream>
//#include "C:\Users\avdot\Desktop\LabWorks\LabRab25\Linked_List\Linked_List.cpp"
#include "C:\Users\avdot\Desktop\LabWorks\LabRab25\GreatDeque\GreatDeque.cpp"
using namespace std;
int main()
{
    //shared_ptr<int> ptr(new int(5)) ;
    //shared_ptr<int> r;
    //weak_ptr<int> w(ptr);
    //weak_ptr<int> ww;
    //ptr = nullptr;
    //ww.swap(w);
    //r.reset(ptr.get());
    //ww = w;
    //ptr = r;
    ////cout << *r << '\n';
    ////cout << *ww.lock();
    //Bubble_queue<int> dec;
    //
    //cout << '\n';
    //for (int i = 0; i < 5; ++i) {
    //    dec.push_front(100 + i);
    //}
    //dec.pop_behind();
    //dec.pop_front();
    //dec.push_front(99);
    //for (int i = 0; i < dec.size(); ++i) {
    //    cout << dec[i] << ' ';
    //}
    //cout << '\n';
    //dec.push_back(888);
    //dec.bubble_sort();
    //for (int i = 0; i < dec.size(); ++i) {
    //    cout << dec[i] << ' ';
    //}
  /*  int rows = 5, colls = 10;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[colls];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colls; ++j) {
            arr[i][j] = i * 100 + j;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colls; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout << '\n';
    }
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    pair<int, int> first;*/
    GreatDeque<int> dec;
    for (int i = 0; i < 9; ++i) {
        dec.push_back(i + 100);
    }
   for (auto now = dec.begin(); now != dec.end();++now) {
        cout << *now << " ";
    }
   for (int i = 0; i < 5; ++i) {
       dec.push_front(1000 - i);
   }
   dec.print();
   for (auto now = dec.begin(); now != dec.end(); ++now) {
       cout << *now << " ";
   }
   for (int i = 0; i < 10; ++i) {
       dec.push_back(i + 100);
   }
    cout << '\n';
    for (int i = 0; i < 5; ++i) {
        dec.push_front(1000 - i);
    }
    dec.pop_behind();
    dec.push_back(99999);
    dec.pop_front();
    dec.push_front(888);
    for (int i = 0; i < 5; ++i) {
        dec.push_front(1000 - i);
    }
    for (auto now = dec.begin(); now != dec.end(); ++now) {
        cout << *now << " ";
    }
    cout << '\n';
    auto now = dec.begin();
    now+= 3;
    cout << *now<<'\n';
    now -= 3;
    cout << *now << '\n';
    cout << '\n';
    cout << dec[dec.count()];
    dec.clear();
    dec.print();
    return 0;
}

