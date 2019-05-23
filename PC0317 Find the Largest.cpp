#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
   count initiate from 0 and get increased by 1 each loop
   while loop stops when count == 4

   ask user to enter number
   compare the number with set highest value through if statement

   display the largest value when loop ends

*/

int main()
{
    double num, largest;
    largest = 0;
    int count = 0;


    while (count <= 4)
    {
        cout << "Enter number " << count+1 <<": ";
        cin >> num;

        if (num >= largest)
        {
            largest = num;
        }
        count ++;
    }

    cout << "The largest number entered is " << largest << "." << endl;



    return 0;
}
