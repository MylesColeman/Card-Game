#include "PlayingCard.h"

PlayingCard::PlayingCard(int suit, int face) // Defines a card
{
	m_suit = suit;
	m_faceValue = face;
}

int PlayingCard::GetFaceValue()
{
	return m_faceValue;
}

int PlayingCard::GetSuit()
{
	return m_suit;
}