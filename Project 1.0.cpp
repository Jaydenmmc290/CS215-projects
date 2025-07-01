
/*course: CS215 - 001
Project: Lab 5
Purpose: rogram that repeatedly asks the user to input a year for the Super
Bowl, and displays the corresponding Super Bowl with Roman Numeral, until the user
enters either “Q” or “q” to quit the program.
Author: Jayden McBride
*/
#include <iostream>
#include <string>
#include <limits>
#include <sstream>  // For stringstream

using namespace std;

// Constants for the Super Bowl year calculations
const int START_SUPERBOWL = 1967;
const int MIN_ROMAN = 1;
const int MAX_ROMAN = 3999;
const int MAX_YEAR = START_SUPERBOWL + MAX_ROMAN - 1;

// Function prototypes
string roman_digit(int digit, string one, string five, string ten);
string roman_numeral(int n);

int main()
{
    // the introduction and background info
    cout << "***************************************************************\n";
    cout << "*     The Super Bowl is the annual Final Playoff Game         *\n";
    cout << "*         of the NFL to determine the league champion.        *\n";
    cout << "* The first Super Bowl took place on January 15, 1967.        *\n";
    cout << "*    Super Bowl I (Los Angeles memorial Coliseum) --> 1967    *\n";
    cout << "*                                                             *\n";
    cout << "* Super Bowl LIX was played on February 9, 2025               *\n";
    cout << "*                at Caesars Superdome in New Orleans.         *\n";
    cout << "*     Philadelphia Eagles 40 -- Kansas City Chiefs 22         *\n";
    cout << "*                                                             *\n";
    cout << "* This Roman Numerals Convertor is written by Jayden McBride. *\n";
    cout << "* If you had a time machine, which year of Super Bowl         *\n";
    cout << "* would you want to attend (1967 - 5965) ?                    *\n";
    cout << "***************************************************************\n";

    while (true) 
    {
        cout << "Please enter the year you want to attend (click Q or q to quit): ";
        string input;
        getline(cin, input);  // Use line to get the full input

       
        if (input == "Q" || input == "q") //  quit the loop immediately
        {
            cout << "Back to 2025, and have a great day!" << endl;
            break;
        }
       
        
        stringstream ss(input);// Convert the input to an integer if it s number
        int year;
        if (!(ss >> year))  // If not a number
        {
            cout << "Please use a four-digit number to represent a year (1967-5965)!" << endl;
            continue;  // make them put in a good answer
        }
       
        if (year < 0) // Handle negatives
        {
            cout << "The time machine will bring you to the year of " << year << ":" << endl;
            cout << "Wait!!! The year you entered is TOO LOW!" << endl;
        }
            
        if (year < 1000 || year > 9999) //check valid rage of year
        {
            cout << "Please use a four-digit number to represent a year (1967-5965)!" << endl;
        }
        else if (year < START_SUPERBOWL) // if the year is less then the start
        {
            cout << "The time machine will bring you to the year of " << input << ":" << endl;
            cout << "Wait!!! The year you entered is TOO EARLIER than the first Super Bowl!" << endl;
        }
        else if (year > MAX_YEAR) // if year is more then the max
        {
            cout << "The time machine will bring you to the year of " << input << ":" << endl;
            cout << "Hold on!!! The year you entered is TOO BIG for Roman Numerals!" << endl;
        }
        else
        {
        
            int superBowlNumber = year - START_SUPERBOWL + 1; //make into a superbowl number 
            cout << "The time machine will bring you to the year of " << year << ":" << endl;
            cout << "It is Super Bowl " << roman_numeral(superBowlNumber) << endl;
            cout << "We will help you find out the result and other interesting information...next time:)" << endl;
        }
    }

    return 0;
}



string roman_numeral(int n) //makes a number into a Roman numeral string
{
    string result;
    result += roman_digit(n / 1000, "M", "", "");
    result += roman_digit((n % 1000) / 100, "C", "D", "M");
    result += roman_digit((n % 100) / 10, "X", "L", "C");
    result += roman_digit(n % 10, "I", "V", "X");
    return result;
}
string roman_digit(int digit, string one, string five, string ten) // makes a single digit into its Roman numeral
{
    
    string roman;
    switch (digit)//using switch statement
    {
    case 1: roman = one;
        break;
    case 2: roman = one + one;
        break;
    case 3: roman = one + one + one;
        break;
    case 4: roman = one + five;
        break;
    case 5: roman = five;
        break;
    case 6: roman = five + one;
        break;
    case 7: roman = five + one + one;
        break;
    case 8: roman = five + one + one + one;
        break;
    case 9: roman = one + ten;
        break;
    default: break;
    }
    return roman;
}
