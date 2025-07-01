/*
 * Course: CS215-001
 * Project: Lab 12
 * File: SuperString.h
 * Purpose: Declaration of the SuperString class to perform various string operations,
 *          including reversing a string using a loop, recursion, and a stack,
 *          and checking if a string is a palindrome.
 *          A palindrome is defined as a sequence of characters that reads the same backward as forward.
 *
 * Author: Jayden Mcbride
 */
#include "SuperString.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor: Initializes the SuperString object with an input string.
SuperString::SuperString(string ini_str)
{
    str = ini_str;  // Set the string value to the passed string.
}

// Getter method: Returns the current string stored in the object.
string SuperString::getString() const 
{
    return str;
}

// Setter method: Updates the current string with a new input string.
void SuperString::setString(string input_str)
{
    str = input_str;
}

// Reverses the string using a loop.
// Loop through the string from the last character to the first, adding each character to the reversed string.
string SuperString::rev_loop() const 
{
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];  // Append characters in reverse order.
    }
    return reversed;  // Return the reversed string.
}

// Reverses the string using recursion.
// Base case: If the string is empty, return an empty string.
// Recursive case: Take the last character and append the reversed substring (excluding the last character).
string SuperString::rev_recursion() const
{
    if (str.empty())
    {
        return "";
    }
    else {
        // Recursive call: reverse the substring excluding the last character and prepend the last character.
        return str[str.length() - 1] + SuperString(str.substr(0, str.length() - 1)).rev_recursion();
    }
}

// Reverses the string using a stack.
// Push all characters of the string onto the stack.
// Pop characters from the stack and append them to the reversed string.
string SuperString::rev_stack() const
{
    stack<char> s;
    for (char ch : str) 
    {
        s.push(ch);  // Push each character to the stack.
    }

    string reversed = "";
    // While the stack is not empty, pop characters and build the reversed string.
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    return reversed;  // Return the reversed string.
}

// Checks if the string is a palindrome using the loop-based reverse function.
// A palindrome is a string that reads the same backward as forward.
bool SuperString::isPalindrome() const
{
    string reversed = rev_loop(); // Reverse the string using the loop method.
    return str == reversed;  // Compare the original string to the reversed one.
}

// Checks if the string is a palindrome using recursion.
// Base case: A string of length 0 or 1 is a palindrome.
// Recursive case: Compare the first and last characters, and recursively check the middle part of the string.
bool SuperString::isPalindrome_recursion() const
{
    if (str.length() <= 1)
        return true;  // A string of length 1 or 0 is a palindrome by definition.
    else {
        bool firstPair = (str[0] == str[str.length() - 1]);  // Compare the first and last characters.
        string middle = str.substr(1, str.length() - 2);  // Remove the first and last characters.
        SuperString shorter(middle);  // Create a SuperString object for the substring.

        // Return true if the first pair matches and the middle part is a palindrome.
        return firstPair && shorter.isPalindrome_recursion();
    }
}

// Prints the current string stored in the object.
void SuperString::print() const 
{
    cout << str << endl;
}
