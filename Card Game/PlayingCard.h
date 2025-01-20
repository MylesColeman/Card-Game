#pragma once
class PlayingCard
{
private:
	int m_faceValue;
	int m_suit;
public:
	PlayingCard(int suit, int face); // Defines a card
	int GetFaceValue();
	int GetSuit();
};