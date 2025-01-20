#include <vector>
#include "PlayingCard.h"
#pragma once
class Hand
{
private:
	std::vector<PlayingCard> m_cards; // Vector containing the hand
public:
	void Add(PlayingCard card); // Adds a dealt card to the hand
	int Value(); // Takes the sum of all cards in the hand and returns it

	void Display();
};