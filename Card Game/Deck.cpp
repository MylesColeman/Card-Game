#include "Deck.h"
#include <iostream>
#include <cstdlib>

// Places cards within the deck
void Deck::Build()
{
	m_deckCards.reserve(52);

	for (int suit = 1; suit <= 4; suit++)
	{
		for (int face = 2; face <= 14; face++)
		{
			PlayingCard newCard(suit, face);
			m_deckCards.push_back(newCard);
		}
	}
}

// Outputs the deck
void Deck::Display()
{
	for (auto& card : m_deckCards)
	{
		std::cout << "Suit: " << card.GetSuit() << " " << "Face Value: " << card.GetFaceValue() << std::endl;
	}
}

// Shuffles the deck
void Deck::Shuffle()
{
	for (int i = 0; i < 100; i++)
	{
		int cardOne = rand() % 52;
		int cardTwo = rand() % 52;


		std::swap(m_deckCards[cardOne], m_deckCards[cardTwo]);
	}
}

PlayingCard Deck::Deal()
{
	if (m_nextCard < m_deckCards.size())
	{
		PlayingCard dealtCard = m_deckCards[m_nextCard];
		m_nextCard++;

		return dealtCard;
	}
}