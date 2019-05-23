#include <iostream>

using std::cout;
using std::cin;
using std::endl;
/*
   ask user to enter value - miles, gallons used
   calculate tankful mpg = miles/gallons
   total miles = total miles + miles user entered
   total gallons = total gallons + gallons user entered
   total mpg = total miles / total gallons
*/

int main()
{
    double miles, gallons, total_miles, total_gallons, tankful_mpg, total_mpg;
    total_miles = 0;
    total_gallons = 0;

    cout << "Enter miles driven (-1 to quit): ";
    cin >> miles;

    while(miles != -1)
    {
        cout << "Enter gallons used: ";
        cin >> gallons;

        tankful_mpg = miles/gallons;
        cout << "Tankful MPG: " << tankful_mpg << endl;

        total_miles = total_miles+miles;
        total_gallons = total_gallons+gallons;
        total_mpg = total_miles/total_gallons;
        cout << "Overall MPG: " << total_mpg <<endl;

        cout << "Enter miles driven (-1 to quit): ";
        cin >> miles;

    }

    return 0;
}
