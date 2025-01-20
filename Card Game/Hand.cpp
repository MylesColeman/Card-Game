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
	}

	return totalValue;
}

void Hand::Display()
{
	for (auto& card : m_cards)
	{
		std::cout << "Suit: " << card.GetSuit() << " " << "Face Value: " << card.GetFaceValue() << std::endl;
	}
}