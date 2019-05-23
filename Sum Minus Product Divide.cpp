#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double num1, num2, sum, dif, pro, quo;

    cout << "Enter num1 : ";
    cin >> num1;
    cout << "Enter num2 : ";
    cin >> num2;

    sum = num1 + num2;
    dif = num1 - num2;
    pro = num1 * num2;
    quo = num1 / num2;

    cout << "Sum=" << sum << endl;
    cout << "Difference=" << dif << endl;
    cout << "Product=" << pro << endl;
    cout << "Quotient=" << quo << endl;

    return 0;
}
