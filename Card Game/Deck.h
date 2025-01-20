#include <vector>
#include "PlayingCard.h"
#pragma once

class Deck
{
private:
	int m_nextCard { 0 };
	std::vector<PlayingCard> m_deckCards; // Vector containing the deck
public:
	void Build(); // Places cards within the deck
	void Shuffle();
	PlayingCard Deal();

	void Display(); 
};