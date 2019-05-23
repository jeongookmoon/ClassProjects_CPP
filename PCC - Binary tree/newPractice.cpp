#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Employees.h"

int main()
{
    Employees e;

    int number;
    string input;
    char choice;


    do
    {
        // menu
        cout << "\n\n(I)nsert\n(R)emove\n(P)rint\n(S)earch\n(C)ount\n(Q)uit\n";

        // prompt for a choice
        cout << "\n\n[IRPSCQ]: ";

        // get the choice
        cin >> choice;


        // process the choice
        switch ( choice )
        {
            case 'I': case 'i':
                cout << "ID: ";
                cin >> number;
                cout << "Name: ";
                cin >> input;
                e.insert( number, input );
            break;
            case 'R': case 'r':
                cout << "Which ID do you want to remove?: ";
                cin >> number;
                e.remove( number );
            break;
            case 'P': case 'p':
                e.print();
            break;
            case 'S': case 's':
                cout << "Which ID do you want to search?: ";
                cin >> number;
                e.search( number );
            break;
            case 'C': case 'c':
                e.count ();
            break;
            case 'Q':  case 'q':
                cout << "Goodbye!\n";
            break;
            default:
                cout << "Invalid selection!\n";
        }



    } while ( choice != 'Q' && choice != 'q' );

    return 0;
}
