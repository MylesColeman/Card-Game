#pragma once
#include <ostream>
#include <string>

class PlayingCard
{
private:
	int m_faceValue;
	int m_suit;
public:
	PlayingCard(int suit, int face); // Defines a card
	int GetFaceValue(void) const { return m_faceValue; }
	int GetSuit(void) const { return m_suit; }

	std::string GetSuitName() const; // Converts the cards integer value to a string
	std::string GetFaceName() const; // Converts the cards integer value to a string
};

// Outputs each card within the deck to the console
inline std::ostream& operator<<(std::ostream& os, const PlayingCard& card)
{
	os << "Suit: " << card.GetSuitName() << "  Value : " << card.GetFaceName() << std::endl;

	return os;
}