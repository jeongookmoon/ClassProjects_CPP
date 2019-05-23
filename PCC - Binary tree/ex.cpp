#include <iostream>
using std::cin;
using std::cout;

#include "Foo.h"

int main()
{
    Foo f;

    double input;
    char choice;


    do
    {
        // menu
        cout << "(I)nsert\n(P)rint\n(Q)uit\n";

        // prompt for a choice
        cout << "[IPQ]: ";

        // get the choice
        cin >> choice;


        // process the choice
        switch ( choice )
        {
            case 'I': case 'i':
                cout << "Gimme a value: ";
                cin >> input;
                f.insert( input );
            break;
            case 'P': case 'p':
                f.print();
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
