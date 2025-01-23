#pragma once
#include <vector>
#include <ostream>
#include "PlayingCard.h"

class Deck
{
private:
	int m_nextCard { 0 };
	std::vector<PlayingCard> m_deckCards; // Vector containing the deck

	friend inline std::ostream& operator<<(std::ostream& os, const Deck& deck); // Allows the PlayingCard class to access the Deck class
public:
	void Build(); // Places cards within the deck
	void Shuffle();
	PlayingCard Deal();
};

// Loops through the deck so it can be outputted in the PlayingCard class
inline std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	for (const PlayingCard& card : deck.m_deckCards)
	{
		os << card;
	}
	return os;
}