/*
Winning Division

Write a program that determines which of a company's four divisions
(Northeast, Southeast, Northwest, and Southwest) had the greatest sales for a quarter.
It should include the following two functions, which are called by main.
* double getSales() is passed the name of a division.
It asks the user for a division's quarterly sales figure, validates the input, then returns it. It should be called once for each division.
* void findHighest() is passed the four sales totals.
It determines which is the largest and prints the name of the high grossing division, along with its sales figure.

Input Validation: Do not accept dollar amounts less than $0.00.

*/
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

double getSales(string);
void findHighest(double, double, double, double);

int main()
{
    string namea, nameb, namec, named;
    double northeast, southeast, northwest, southwest;

    namea = "Northeast";
    nameb = "Southeast";
    namec = "Northwest";
    named = "Southwest";

    northeast = getSales(namea);
    southeast = getSales(nameb);
    northwest = getSales(namec);
    southwest = getSales(named);

    findHighest(northeast, southeast, northwest, southwest);

return 0;
}

double getSales(string rname)
{
    double data;
    cout << "Enter the sales for " << rname << " : ";
    cin >> data;
    while(data < 0 )
    {
    cout << "Enter the sales for " << rname << " : ";
    cin >> data;
    }

    return data;
}

void findHighest(double a, double b, double c, double d)
{
    double maximum = a;
    if (b > maximum)
        maximum = b;
    if (c > maximum)
        maximum = c;
    if (d > maximum)
        maximum = d;
    cout << "The highest grossing division is: " << maximum << endl;

}
