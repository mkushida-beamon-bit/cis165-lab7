/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    const int COLOR_SIZE = 20;
    char first_color[COLOR_SIZE];
    char second_color[COLOR_SIZE];

    cout << "Enter the first primary color (red, blue, yellow): ";
    cin >> setw(COLOR_SIZE) >> first_color;

    cout << "Enter the second primary color (red, blue, yellow): ";
    cin >> setw(COLOR_SIZE) >> second_color;

    bool first_valid =
        strcmp(first_color, "red") == 0 ||
        strcmp(first_color, "blue") == 0 ||
        strcmp(first_color, "yellow") == 0;

    bool second_valid =
        strcmp(second_color, "red") == 0 ||
        strcmp(second_color, "blue") == 0 ||
        strcmp(second_color, "yellow") == 0;

    if (!first_valid || !second_valid) {
        cout << "Error: enter red, blue, or yellow." << endl;
    } else if (strcmp(first_color, second_color) == 0) {
        cout << "Result: " << first_color << endl;
    } else if (
        (strcmp(first_color, "red") == 0 &&
         strcmp(second_color, "blue") == 0) ||
        (strcmp(first_color, "blue") == 0 &&
         strcmp(second_color, "red") == 0)
    ) {
        cout << "Result: purple" << endl;
    } else if (
        (strcmp(first_color, "red") == 0 &&
         strcmp(second_color, "yellow") == 0) ||
        (strcmp(first_color, "yellow") == 0 &&
         strcmp(second_color, "red") == 0)
    ) {
        cout << "Result: orange" << endl;
    } else {
        cout << "Result: green" << endl;
    }

    return 0;
}