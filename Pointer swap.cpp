/// *******************************************************************************
/// Assignment 10C: Swap
/// Author : Jeong Ook Moon
/// Description : This program swaps original values through reference and pointer swap.
/// Status : Complete
/// Date : December 7, 2014
/// ********************************************************************************

#include <iostream>

using namespace std;

void referenceswap(int &n1, int&n2);
void pointerswap(int * &n1ptr, int * &n2ptr);
int main()
{
    int num1 = 5, num2 = 10;
    int *num1ptr = &num1;
    int *num2ptr = &num2;

    cout << " original values  :::  " << num1 << " " << num2 << endl;
    referenceswap(num1, num2);
    cout << " values after reference swap ::: " << num1 << " " << num2 << endl;
    pointerswap (num1ptr, num2ptr);
    cout << " values after pointer swap ::: " << num1 << " " << num2 << endl << endl;
    return 0;
}
void referenceswap(int &n1, int&n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
void pointerswap ( int *& num1, int *& num2)
{
    int  temp = *num1;

        *num1 = *num2;
        *num2 = temp;
}
