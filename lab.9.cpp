/*
 * Course: CS215-00x
 * Project: Lab 9 (as the first part of Project 2)
 * Purpose: Demonstrate how to use Card class and Deck class
 *          First, it creates 52 cards on deck
 *          Second, it deals 26 cards for each of two players
 *          Then it displays cards in player1's hand and in player2's hand respectively
 *          Test running the program under two different cases:
 *          Case 1: comment out // playDeck.shuffleDeck(); at line number 29
 *          Case 2: activate statement at line number 29
 *** DO NOT CHANGE THIS FILE ***
 */
#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
 

    // Avoid magic numbers
    const int HANDS = 26;    // each player holds half cards (52 cards / 2 = 26 cards) to begin the game

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // then shuffle the cards
    Deck playDeck;
    playDeck.createDeck();
    //playDeck.shuffleDeck();

    Card yourCards[HANDS];
    Card myCards[HANDS];

    for (int i = 0; i < HANDS; i++)
    {
        yourCards[i] = playDeck.deal_a_card();
        myCards[i] = playDeck.deal_a_card();
    }

    cout << endl << "The cards in your hand are: " << endl;
    for (int i = 0; i < HANDS; i++)
    {
        yourCards[i].print();
        cout << "\t";
    }

    cout << endl << endl << "The cards in my hand are: " << endl;
    for (int i = 0; i < HANDS; i++)
    {
        myCards[i].print();
        cout << "\t";
    }

    return 0;
}
