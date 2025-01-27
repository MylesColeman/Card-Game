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
		totalValue += card.GetFaceValue();
	}

	return totalValue;
}