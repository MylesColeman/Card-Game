#pragma once
#include <ostream>

class PlayingCard
{
private:
	int m_faceValue;
	int m_suit;
public:
	PlayingCard(int suit, int face); // Defines a card
	int GetFaceValue(void) const { return m_faceValue; }
	int GetSuit(void) const { return m_suit; }
};

inline std::ostream& operator<<(std::ostream& os, const PlayingCard& card)
{
	os << "Suit: " << card.GetSuit() << " Value : " << card.GetFaceValue() << std::endl;

	return os;
}