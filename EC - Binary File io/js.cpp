#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::fstream;
using std::ios;

#include <cstdlib>
using std::exit;

int main()
{
    double d[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };  // 40 bytes long
    double e[5];

    fstream f;  // create the object

    // attempt to open a file in binary mode for writing
    f.open( "file.txt", ios::binary | ios::out);

    // verify the file is opened
    if ( !f )
        exit(1);

    // process the file.
    f.write( reinterpret_cast<char*>(d) , sizeof(d) );

     // close the file
    f.close();

    f.open( "file.txt", ios::binary | ios::in);
    f.read( reinterpret_cast<char*>(e), sizeof(e));
    f.close();
    for (int i=0; i<5; i++)
    {
        cout << "what's inside : " << d[i] <<endl;
    }

    for (int i=0; i<5; i++)
    {
        cout << "what's inside : " << e[i] <<endl;
    }

    int val1 = 10, val2 = 20;
    f.open( "file2.dat", ios::out | ios::binary );

    if ( !f )
        exit(2);

    f.write( reinterpret_cast<char*>(&val1), sizeof(val1) );
    f.close();

    f.open( "file2.dat", ios::in | ios::binary );
    if (!f )
        exit(3);

    f.read( reinterpret_cast<char*>(&val2), sizeof(val2));

    f.close();

    cout << val2 << endl;

    return 0;
}
