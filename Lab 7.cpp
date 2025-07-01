/*course: CS215 - 001
*Project: Lab 7
*Purpose: to practice creating an array to organize a sequence of items and to get familiar with the Visual Studio debugger
*Author: Jayden McBride
*/
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

using namespace std;

const int NUM_JUDGES = 6; // Total number of judges

// Function to remove the lowest and highest scores while preserving order
void dropTWO(double scores[], int& size) 
{
    double minScore = scores[0], maxScore = scores[0];
    int minIndex = 0, maxIndex = 0;

    // Find the indices of the lowest and highest scores
    for (int i = 1; i < size; i++) 
    {
        if (scores[i] < minScore)
        {
            minScore = scores[i];
            minIndex = i;
        }
        if (scores[i] > maxScore) 
        {
            maxScore = scores[i];
            maxIndex = i;
        }
    }

    // Create a new array to hold the scores after removal
    double tempScores[NUM_JUDGES - 2];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (i != minIndex && i != maxIndex) 
        {
            tempScores[j++] = scores[i];
        }
    }

    // order all the scores and present them
    for (int i = 0; i < j; i++) 
    {
        scores[i] = tempScores[i];
    }
    size = j;
}

// Function to do the final judges score
double final_score(double scores[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }
    return sum / size;
}

int main()
{
    double scores[NUM_JUDGES];
    int size = NUM_JUDGES;

    cout << "Please enter your scores for the gymnast (between 0.0 and 10.0):" << endl;

    for (int i = 0; i < NUM_JUDGES; i++)
    {
        while (true) 
        {
            cout << "Score " << (i + 1) << ": ";
            string input;
            getline(cin, input);
            stringstream ss(input);
            double score;

            if (ss >> score && score >= 0.0 && score <= 10.0)
            {
                scores[i] = score;
                break;
            }
            else 
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
        }
    }

    // Display original scores
    cout << "The scores from the judges are: " << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < NUM_JUDGES; i++) 
    {
        cout << scores[i] << " ";
    }
    cout << endl;

    // Drop the lowest and highest scores while preserving order
    dropTWO(scores, size);

    // Display scores after dropping lowest and highest
    cout << "The scores after dropping the highest and lowest scores: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;

    // Compute and display final execution score
    double executionScore = final_score(scores, size);
    cout << "Final Execution Score is: " << executionScore << endl;

    return 0;
}
