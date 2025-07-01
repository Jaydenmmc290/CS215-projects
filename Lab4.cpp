/* course:cs215-001
* project: lab 4
* Purpose: The purpose of this lab assignment is to continue practicing conditional statements and to practice loop 
statements by Writing a program that performs Credit Card Number Check
 Date:2/5/2025
aruthor: jayden mcbride
*/
#include <iostream>
using namespace std;
int main() 
{
    int cardNumber; // Variable to store the user's input

    
    cout << "Enter an 8-digit credit card number (-1 to quit): ";// user to enter an 8-digit credit card number

    
    while (cin >> cardNumber && cardNumber != -1)// Loop to continuously accept user input until -1 is entered
    {
        int sum1 = 0, sum2 = 0, temp = cardNumber; // start sum variables counts and a tempirary variable to manipulate the number

        
        for (int i = 0; i < 8; i++) // Process each digit of the number
        {
            int digit = temp % 10; // take the last digit

            if (i % 2 == 0) // Check if the position is even (starting from rightmost)
            { 
                sum1 += digit; // Add digit to sum1
            }
            else 
            {
                int doubled = digit * 2; // Double the digit
                sum2 += (doubled / 10) + (doubled % 10); // Add sum of doubled value
            }

            temp /= 10; // Remove the last digit from the number
        }

        int totalSum = sum1 + sum2; //  total sum of both sums

       
        if (totalSum % 10 == 0) // Check if the last digit of the sum is 0, making a valid number
        {
            cout << "Valid number." << endl; 
        }
        else 
        {
            
            cout << "Invalid number. Check digit should be " << (10 - (totalSum % 10)) % 10 << endl;// Compute the correct check digit to make the number valid
        }

        
    
    }

   
    return 0;
}


