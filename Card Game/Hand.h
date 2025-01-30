#pragma once
#include <vector>
#include <ostream>
#include "PlayingCard.h"

struct HandValue
{
	int minValue;
	int maxValue;
};

class Hand
{
private:
	std::vector<PlayingCard> m_cards; // Vector containing the hand

	friend inline std::ostream& operator<<(std::ostream& os, const Hand& deck);
public:
	void Add(PlayingCard card); // Adds a dealt card to the hand
	HandValue Value(); // Takes the sum of all cards in the hand and returns it
	int GetCardCount() const { return m_cards.size(); } // Counts the number of cards
};

// Outputs each card within the deck to the console
inline std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
	for (const PlayingCard& card : hand.m_cards)
	{
		os << card;
	}
	return os;
}