#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::fstream;
using std::ios;

#include <cstdlib>
using std::exit;

void arrayToFile(const char*, int*, int);
void fileToArray(const char*, int*, int);
void print(const int*, int );

const char* loc = "data.txt";
const int length = 5;

int main()
{
    int a[length] = { 5, 4, 3, 2, 1};
    int b[length] = { 0, };

    fstream f;

    cout << "Contents of alpha array: \n";
    print(a, length);

    cout << "\nWriting alpha array to file.\n";
    arrayToFile( loc, a, length );

    cout <<"\nContents of beta array: \n";
    print(b, length);

    cout << "\nWriting file to beta array. \n";
    fileToArray( loc, b, length );

    cout <<"\nContents of beta array: \n";
    print(b, length);

    return 0;
}

void print( const int* arr, int len)
{
    for (int i=0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void arrayToFile(const char* lo, int* arr, int len)
{
    fstream a;
    a.open(lo, ios::binary | ios::out);
    if(!a) {
        cout << "Error opening file!\n";
        exit(1);
    }

    a.write(reinterpret_cast<char*>(arr), sizeof(arr)*len);
    a.close();
}

void fileToArray(const char* lo, int* arr, int len) {
    fstream a;

    a.open(lo, ios::binary | ios::in );
    if(!a) {
        cout << "Error opening file!\n";
        exit(2);
    }
    a.read(reinterpret_cast<char*>(arr), sizeof(arr)*len);
    a.close();
}


