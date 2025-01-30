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
    std::cout << "Deck Shuffled" << std::endl;
    std::cout << std::endl;

    // Checks for the number of players
    bool numPlayersError = true;
    int numHands = 1;
    while (numPlayersError)
    {
        std::cout << "How many people are playing? 1 - 7" << std::endl;
        std::cin >> numHands;

        if (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

            numPlayersError = true;
            std::cout << "ERROR - Please enter a valid number!" << std::endl;
        }
        else if (numHands < 1 || numHands > 7)
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
        dealtCard = m_deck.Deal();
        newHand.Add(dealtCard);
        m_hands.push_back(newHand);

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
    }

    PlayingCard dealersSecondCard = m_deck.Deal();
    std::cout << "Dealing the Dealer's Second Card." << std::endl;

    std::cout << std::endl;
    std::cout << "Dealer's First Card:" << std::endl;
    std::cout << dealersHand << std::endl;

    for (int player = 1; player < numHands + 1; player++)
    {
        std::string playerAction = " ";
        bool stopAction = false;

        HandValue pontoonCheck = m_hands[player - 1].Value();
        if (pontoonCheck.maxValue == 21)
        {
            std::cout << "Player " << player << ":" << std::endl;
            std::cout << m_hands[player - 1] << std::endl;
            std::cout << "Player " << player << " has got a pontoon!" << std::endl;
            std::cout << std::endl;

            stopAction = true;
        }

        while (playerAction != "stick" && !stopAction)
        {
            std::cout << "Player " << player << ":" << std::endl;
            std::cout << m_hands[player - 1] << std::endl;

            std::cout << "Do you want to: 'twist' or 'stick'?" << std::endl;
            std::cin >> playerAction;

            if (playerAction == "twist")
            {
                PlayingCard dealtCard = m_deck.Deal();
                m_hands[player - 1].Add(dealtCard);
                std::cout << m_hands[player - 1] << std::endl;

                HandValue handValue = m_hands[player - 1].Value();
                if (handValue.minValue > 21)
                {
                    std::cout << "Player " << player << " has gone bust!" << std::endl;
                    std::cout << std::endl;
                    stopAction = true;
                }
                else if (handValue.maxValue == 21 || handValue.minValue == 21)
                {
                    std::cout << "Player " << player << " has hit 21! Wait to the end for results." << std::endl;
                    std::cout << std::endl;
                    stopAction = true;
                }  
            }
            else if (playerAction == "stick")
            {
                std::cout << m_hands[player - 1] << std::endl;
            }
            else
            {
                std::cout << "ERROR - Action not recognised!" << std::endl;
            }
        }
    }
    std::cout << "Dealer:" << std::endl;
    dealersHand.Add(dealersSecondCard);
    std::cout << dealersHand << std::endl;

    HandValue dealerHandValue = dealersHand.Value();
    while (dealerHandValue.maxValue <= 16)
    {
        std::cout << "The dealer twists." << std::endl;
        dealtCard = m_deck.Deal();
        dealersHand.Add(dealtCard);
        dealerHandValue = dealersHand.Value();

        std::cout << dealersHand << std::endl;
    }

    if (dealerHandValue.minValue > 21)
    {
        std::cout << "Dealer Bust! Everybody Still in Wins!" << std::endl;
    }
    else
    {
        for (int player = 1; player < numHands + 1; player++)
        {
            HandValue playerHandValue = m_hands[player - 1].Value();
            if (playerHandValue.minValue > 21)
            {
                std::cout << "Player " << player << " went Bust!" << std::endl;
            }
            else if (playerHandValue.maxValue > dealerHandValue.maxValue || playerHandValue.minValue > dealerHandValue.maxValue)
            {
                if (playerHandValue.maxValue == 21 && m_hands[player - 1].GetCardCount() == 2)
                {
                    std::cout << "Player " << player << " got a Pontoon!" << std::endl;
                }
                else if (m_hands[player - 1].GetCardCount() == 5 && playerHandValue.minValue <= 21 && playerHandValue.maxValue <= 21)
                {
                    std::cout << "Player " << player << " got a Five Card Trick!" << std::endl;
                }
                else
                {
                    std::cout << "Player " << player << " beat the dealer!" << std::endl;
                }
            }
            else if (playerHandValue.maxValue == dealerHandValue.maxValue || playerHandValue.minValue == dealerHandValue.maxValue)
            {
                std::cout << "Player " << player << " lost to the dealer!" << std::endl;
            }
            else
            {
                std::cout << "Player " << player << " lost to the dealer!" << std::endl;
            }
        }
    }
}