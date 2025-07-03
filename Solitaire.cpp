/*Class:CS215 
* Section: 001
* Author: Jayden McBride
* Purpose: Cretae a little consule app of solitare you dont need it playable just the idea 
* Date: 02/25/2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

enum Suit { Hearts, Diamonds, Clubs, Spades };
const string SUIT_NAMES[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const string RANK_NAMES[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

struct Card
{
    Suit suit;
    int rank;

    void print() const 
    {
        cout << RANK_NAMES[rank] << " of " << SUIT_NAMES[suit];
    }
};

class Deck
{
private:
    vector<Card> cards;
public:
    Deck()
    {
        for (int s = Hearts; s <= Spades; ++s) 
        {
            for (int r = 0; r < 13; ++r)
            {
                cards.push_back({ (Suit)s, r });
            }
        }
    }

    void shuffle()
    {
        srand((unsigned)time(0));
        std::shuffle(cards.begin(), cards.end(), std::default_random_engine(rand()));
    }

    Card draw() 
    {
        if (cards.empty()) throw runtime_error("Deck is empty!");
        Card top = cards.back();
        cards.pop_back();
        return top;
    }

    bool empty() const 
    {
        return cards.empty();
    }

    int size() const
    {
        return cards.size();
    }
};

class SolitaireGame {
private:
    Deck deck;
    vector<vector<Card>> piles;

public:
    SolitaireGame() {
        deck.shuffle();
        setupPiles();
    }

    void setupPiles() {
        piles.resize(7);
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j <= i; ++j) {
                piles[i].push_back(deck.draw());
            }
        }
    }

    void display() {
        cout << "\nCurrent Solitaire Board:\n";
        for (int i = 0; i < 7; ++i) {
            cout << "Pile " << i + 1 << ": ";
            for (auto& card : piles[i]) {
                card.print();
                cout << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Solitaire Game (Console Version) ===\n";
    SolitaireGame game;
    game.display();
    return 0;
}