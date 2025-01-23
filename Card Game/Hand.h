#pragma once
#include <vector>
#include <ostream>
#include "PlayingCard.h"

class Hand
{
private:
	std::vector<PlayingCard> m_cards; // Vector containing the hand

	friend inline std::ostream& operator<<(std::ostream& os, const Hand& deck);
public:
	void Add(PlayingCard card); // Adds a dealt card to the hand
	int Value(); // Takes the sum of all cards in the hand and returns it
};

inline std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
	for (const PlayingCard& card : hand.m_cards)
	{
		os << card;
	}
	return os;
}