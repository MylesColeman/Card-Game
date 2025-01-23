#pragma once
#include <vector>
#include <ostream>
#include "PlayingCard.h"

class Deck
{
private:
	int m_nextCard { 0 };
	std::vector<PlayingCard> m_deckCards; // Vector containing the deck

	friend inline std::ostream& operator<<(std::ostream& os, const Deck& deck);
public:
	void Build(); // Places cards within the deck
	void Shuffle();
	PlayingCard Deal();
};

inline std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	for (const PlayingCard& card : deck.m_deckCards)
	{
		os << card;
	}
	return os;
}