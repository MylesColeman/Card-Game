#include <vector>
#include "PlayingCard.h"
#pragma once
class Hand
{
private:
	std::vector<PlayingCard> m_cards;
public:
	void Add(PlayingCard card);
	int Value();

	void Display();
};