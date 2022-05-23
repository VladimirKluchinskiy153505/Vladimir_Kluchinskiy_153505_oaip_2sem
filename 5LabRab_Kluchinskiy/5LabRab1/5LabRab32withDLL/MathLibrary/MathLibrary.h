#pragma once
#define Export  extern "C" __declspec(dllexport)
Export int getNatValue();
Export void checkin(double** Arr, const int& n, const int& k);
Export void showArray2(double** Arr, int rows, int cols);
Export void transfer(double** Arr, int n, int k);
Export void PushBackTo(int x, int*& ARR, int& SIZE);