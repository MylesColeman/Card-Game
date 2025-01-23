#pragma once
#include <vector>
#include "Deck.h"
#include "Hand.h"

class Game
{
private:
	std::vector<Hand> m_hands; 
	Deck m_deck; 
public:
	void Play();
};