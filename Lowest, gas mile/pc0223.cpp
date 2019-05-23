#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int highest=0;
    int lowest=0;
    int num1, num2, num3, num4, num5;

    cout << "Enter num1" << endl;
    cin >> num1;
    if(highest <= num1)
        highest = num1;
    if(highest >= num1)
        lowest = num1;

    cout << "Enter num2" << endl;
    cin >> num2;
    if(highest <= num2)
        highest = num2;
    if(highest >= num2)
        lowest = num2;

    cout << "Enter num3" << endl;
    cin >> num3;
    if(highest <= num3)
        highest = num3;
    if(highest >= num4)
        lowest = num3;

    cout << "Enter num4" << endl;
    cin >> num4;
    if(highest <= num4)
        highest = num4;
    if(highest >= num4)
        lowest = num4;

    cout << "Enter num5" << endl;
    cin >> num5;
    if(highest <= num5)
        highest = num5;
    if(highest >= num1)
        lowest = num5;

    cout << "Highest=" << highest << ", Lowest=" << lowest << endl;
    return 0;
}
