#include "Hand.h"
#include <iostream>

// Adds a dealt card to the hand
void Hand::Add(PlayingCard card)
{
	if (m_cards.size() < 5)
	{
		m_cards.push_back(card);
	}
}

// Takes the sum of all cards in the hand and returns it
int Hand::Value()
{
	int totalValue = 0;

	for (auto& card : m_cards)
	{
		totalValue += card.GetFaceValue();

		if (card.GetSuit() == 1)
		{
			totalValue += card.GetFaceValue() * 2;
		}
		else if (card.GetSuit() == 2)
		{
			totalValue += card.GetFaceValue() / 2;
		}
		else if (card.GetSuit() == 2)
		{
			totalValue += card.GetFaceValue() + 5;
		}
		else
		{
			totalValue += card.GetFaceValue();
		}
	}

	return totalValue;
}