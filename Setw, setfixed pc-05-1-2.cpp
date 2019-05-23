/*
When an object is falling because of gravity, the following formula can be used to determine the distance the object falls in a specific time period:
funcion
d = 1/2 * gt2

variables d, g =9.8, t
The variables in the formula are as follows: d is the distance in meters, g is 9.8, and t is the amount of time, in seconds, that the object has been falling.

function name fallingDistance(int t)
d = 1/2 * gt2
Write a function named fallingDistance that accepts an object's falling time (in seconds) as an argument. The function should return the distance, in meters, that the object has fallen during that time interval.

using std::setprecision;
using std::fixed;
using std::setw;

setprecision(3) << fixed

for (int i, i<10, i++>
    cout << setw(4) << i << setw(7) << fallingDistance(i) << endl;

Write a program that demonstrates the function by calling it in a loop that passes the values 1 through 10 as arguments, and displays the return value, formatted in fixed point notation to 3 decimal places of precision.

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using std::setprecision;
using std::cout;
using std::endl;
using std::fixed;
using std::setw;


double fallingDistance(int);

int main()
{
    cout << "--------------" << endl;
    cout << setw(4) << "Secs" << setw(10) << "Dist" << endl;
    cout << "--------------" << endl;

    for (int i=0; i<10; i++)
    {
        cout << setw(4) << i << setw(10) << setprecision(3) << fixed << fallingDistance(i) << endl;
    }
    cout << "--------------" << endl;
    return 0;
}
double fallingDistance (int t)
{
    double d, g;
    g = 9.8;
    d = g * pow(t, 2)/2;
    return d;
}
