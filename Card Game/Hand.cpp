#include "Hand.h"
#include <iostream>

// Adds a dealt card to the hand
void Hand::Add(PlayingCard card)
{
	m_cards.push_back(card);
}

// Takes the sum of all cards in the hand and returns it
HandValue Hand::Value()
{
	int totalValueMinAce = 0;
	int totalValueMaxAce = 0;


	for (auto& card : m_cards)
	{
		if (card.GetFaceValue() > 10 && card.GetFaceValue() != 14)
		{
			totalValueMinAce += 10;
			totalValueMaxAce += 10;
		}
		else if (card.GetFaceValue() == 14)
		{
			totalValueMinAce += 1;
			totalValueMaxAce += 11;
		}
		else
		{
			totalValueMinAce += card.GetFaceValue();
			totalValueMaxAce += card.GetFaceValue();
		}
	}

	return { totalValueMinAce, totalValueMaxAce };
}