#include "Game.h"
#include <iostream>

void Game::Play()
{
    // Builds the deck
    m_deck.Build();
    std::cout << "Deck Built <----------------------------------------" << std::endl;
    std::cout << m_deck << std::endl;

    // Shuffles the deck
    m_deck.Shuffle(); 
    std::cout << "Deck Shuffled <----------------------------------------" << std::endl;
    std::cout << m_deck << std::endl;

    // Checks for the number of players
    bool numPlayersError = true;
    int numHands = 1;
    while (numPlayersError)
    {
        std::cout << "How many people are playing? 2 - 5" << std::endl;
        std::cin >> numHands;

        if (numHands < 2 || numHands > 5)
        {
            numPlayersError = true;
            std::cout << "ERROR - Player count must be between 2 and 5!" << std::endl;
        }
        else
        {
            numPlayersError = false;
        }
    }
    
    // Creates the specified number of players
    for (int player = 1; player < numHands + 1; player++)
    {
        Hand newHand; 
        m_hands.push_back(newHand);
        for (int i = 0; i < 5; i++)
        {
            PlayingCard dealtCard = m_deck.Deal();
            newHand.Add(dealtCard);
        }
        std::cout << std::endl;
        std::cout << "Player " << player << "s " << "Dealt Cards:" << std::endl;
        std::cout << newHand << std::endl;
        std::cout << "Total Hand Value: " << newHand.Value() << std::endl;
    }

    // Checks for a winner (or draw)
    int highestPlayerValue = m_hands[0].Value();
    std::cout << m_hands[0] << std::endl;
    int winningPlayer = 1;
    for (int player = 1; player < numHands; player++)
    {
       
    }
    std::cout << "Player " << winningPlayer << " Wins!" << std::endl;
}