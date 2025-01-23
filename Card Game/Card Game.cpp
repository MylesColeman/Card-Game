#include <iostream>

#include "Deck.h"
#include "PlayingCard.h"
#include "Hand.h"

using namespace std;
int main()
{
    srand(time(NULL));

    Deck newDeck; // Creates the deck
    newDeck.Build(); 
    cout << newDeck << endl;

    newDeck.Shuffle(); // Shuffles the deck
    cout << "Deck Shuffled" << endl;
    cout << newDeck << endl;

    Hand newHand; // Creates the hand
    for (int i = 0; i < 5; i++)
    {
        PlayingCard dealtCard = newDeck.Deal();
        newHand.Add(dealtCard);
    }
    cout << "Dealt Cards:" << endl;

    cout << "Total Hand Value: " << newHand.Value() << endl; 
}