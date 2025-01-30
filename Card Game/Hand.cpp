#include "Hand.h"
#include <iostream>

// Adds a dealt card to the hand
void Hand::Add(PlayingCard card)
{
	m_cards.push_back(card);
}

// Takes the sum of all cards in the hand and returns it
int Hand::Value()
{
	int totalValue = 0;


	for (auto& card : m_cards)
	{
		if (card.GetFaceValue() > 10 && card.GetFaceValue() != 14)
		{
			totalValue += 10;
		}
		else if (card.GetFaceValue() == 14)
		{
			totalValue += 11; // CHANGE THIS
		}
		else
		{
			totalValue += card.GetFaceValue();
		}
	}

	return totalValue;
}