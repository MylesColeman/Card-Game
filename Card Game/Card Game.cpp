#include <iostream>

#include "Deck.h"
#include "PlayingCard.h"
#include "Hand.h"

using namespace std;
int main()
{
    Deck newDeck; // Creates the deck
    newDeck.Build(); 
    newDeck.Display();

    newDeck.Shuffle(); // Shuffles the deck
    cout << "Deck Shuffled" << endl;
    newDeck.Display(); 

    Hand newHand; // Creates the hand
    for (int i = 0; i < 5; i++)
    {
        PlayingCard dealtCard = newDeck.Deal();
        newHand.Add(dealtCard);
    }
    cout << "Dealt Cards:" << endl;
    newHand.Display();
    cout << "Total Hand Value: " << newHand.Value() << endl; 

}