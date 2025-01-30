#include "PlayingCard.h"

PlayingCard::PlayingCard(int suit, int face) // Defines a card
{
	m_suit = suit;
	m_faceValue = face;
}

// Converts the cards integer value to a string
std::string PlayingCard::GetSuitName() const
{
    switch (m_suit)
    {
    case 1: return "Clubs   ";
    case 2: return "Diamonds";
    case 3: return "Hearts  ";
    case 4: return "Spades  ";
    }
}

// Converts the cards integer value to a string
std::string PlayingCard::GetFaceName() const
{
    switch (m_faceValue)
    {
    case 11: return "Jack";
    case 12: return "Queen";
    case 13: return "King";
    case 14: return "Ace";
    default: return std::to_string(m_faceValue);
    }
}