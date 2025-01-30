#include "Game.h"
#include <iostream>
#include <vector>
#include <string>

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
        std::cout << "How many people are playing? 1 - 7" << std::endl;
        std::cin >> numHands;

        if (numHands < 1 || numHands > 7)
        {
            numPlayersError = true;
            std::cout << "ERROR - Player count must be between 1 and 7!" << std::endl;
        }
        else
        {
            numPlayersError = false;
        }
    }
    
    // Creates the specified number of players
    PlayingCard dealtCard = m_deck.Deal();
    for (int player = 1; player < numHands + 1; player++)
    {
        Hand newHand; 
        m_hands.push_back(newHand);

        dealtCard = m_deck.Deal();
        newHand.Add(dealtCard);

        std::cout << std::endl;
        std::cout << "Player " << player << "s " << "Dealt Cards:" << std::endl;
        std::cout << newHand << std::endl;
    }

    Hand dealersHand;
    m_hands.push_back(dealersHand);

    dealtCard = m_deck.Deal();
    dealersHand.Add(dealtCard);

    std::cout << std::endl;
    std::cout << "Dealer's First Card:" << std::endl;
    std::cout << dealersHand << std::endl;

    for (int player = 1; player < numHands + 1; player++)
    {
        dealtCard = m_deck.Deal();
        m_hands[player - 1].Add(dealtCard);

        std::cout << std::endl;
        std::cout << "Player " << player << "s " << "Dealt Cards:" << std::endl;
        std::cout << m_hands[player - 1] << std::endl;

        std::string playerAction = " ";
        while (playerAction != "Stick")
        {
            std::cout << "Do you want to: Twist or Stick?" << std::endl;
            std::cin >> playerAction;

            if (playerAction == "Twist")
            {
                PlayingCard dealtCard = m_deck.Deal();
                m_hands[player - 1].Add(dealtCard);

                std::cout << m_hands[player - 1] << std::endl;
            }
            else if (playerAction == "Stick")
            {
                std::cout << m_hands[player - 1] << std::endl;
            }
            else
            {
                std::cout << "ERROR - Action not recognised!" << std::endl;
            }
        }
    }

    dealtCard = m_deck.Deal();
    dealersHand.Add(dealtCard);

    std::cout << std::endl;
    std::cout << "Dealer's First Card:" << std::endl;
    std::cout << dealersHand << std::endl;
}