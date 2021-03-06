// UnoProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main()
{
	Deck myDeck;
	myDeck.shuffle();

	cout << "Welcome to Uno" << endl;
	cout << "How many players want to play Uno?" << endl;
	int k = 0;
	cin >> k;

	int i = 0;
	vector<Player> playersList;
	while (i<k) {
		playersList.push_back(Player());
		playersList.at(i).insertStartingCards(myDeck.drawBeginningCards());
		i++;
	}



	Card topCard = myDeck.getTop();
	//the placeholder for placing cards by the players
	vector<Card> stackOfCards;
	stackOfCards.push_back(topCard);

	int o = 0;

	bool ascendingOrDescending = true; //if value is true, we are ascending, if value is false, then we are descending
	bool draw2 = false; //determines whether an attacked player needs to draw 2 cards
	bool draw4 = false; //determines whether an attacked player needs to draw 4 cards
	bool skip = false;

	//if first card is a draw+2, then set the bool variable to true
	if (topCard.getRank()=="DRAW+2") {
		draw2 = true;
	}
	//else, if it is a reverse, then set the reverse variable to true
	else if (topCard.getRank() == "REVERSE") {
		ascendingOrDescending = false;
	}


	while (true) {
		cout << "Top card is..." << endl;
		stackOfCards[0].displayCardInfo();
		cout << "" << endl;
		//determines whether the player has to draw 2 or 4 cards from the Uno deck
		if (draw2 || draw4) {
			//the player who faces a draw2 on the stack of cards is forced to draw 2 cards from deck
			if (draw2) {
				playersList.at(o).addToHand(myDeck.draw());
				playersList.at(o).addToHand(myDeck.draw());
				draw2 = false;
			}
			//the player who faces a draw4 on the stack of cards is forced to draw 4 cards from the deck
			else {
				playersList.at(o).addToHand(myDeck.draw());
				playersList.at(o).addToHand(myDeck.draw());
				playersList.at(o).addToHand(myDeck.draw());
				playersList.at(o).addToHand(myDeck.draw());
				draw4 = false;
			}
			//once the player is done drawing 2 or 4 cards, then skip his turn depending on order of play
			if (ascendingOrDescending) {
				o++;
				//if o is out of bounds, then fix it accordingly
				if (o >= k) {
					o = abs(o - k);
				}
			}
			//once the player is done drawing 2 or 4 cards, then skip his turn depending on order of play
			else {
				o--;
				//if o is out of bounds, then fix it accordingly
				if (o < 0) {
					o = abs(o + k);
				}
			}


		}
		else {
			cout << "Player " << o << "'s hand" << endl;
			Card dealtCard = playersList.at(o).selectCard(stackOfCards[0]);
			//if the returned card is empty, then it is a signal for the current player to draw a card from the deck.
			if (dealtCard.getRank() == "N/A" &&  dealtCard.getColor() == "N/A") {
				playersList.at(o).addToHand(myDeck.draw());
			}
			//else, the player has selected a card from his or her hand and is ready to be placed onto the stack of cards
			else {
				stackOfCards.insert(stackOfCards.begin() + 0, dealtCard);

				//determine if the top card is a draw2
				if (stackOfCards.front().getRank() == "DRAW+2") {
					draw2 = true;
				}
				//else, determine if teh top card is a draw4
				else if (stackOfCards.front().getRank() == "DRAW+4") {
					draw4 = true;
				}
				//if the card placed is a reverse change the order
				else if (stackOfCards.front().getRank() == "REVERSE") {
					if (ascendingOrDescending ==true) {
						ascendingOrDescending = false;
					}
					else {
						ascendingOrDescending = true;
					}
				}
				//if the card placed is a skip, change boolean value of skip to true
				else if (stackOfCards.front().getRank() == "SKIP") {
					skip = true;
				}
			}

			//if the current player's hand is empty, then he is the winner
			if (playersList.at(o).getHand().size()==0) {
				break;
			}


			//if order of playing is ascending then ascend
			if (ascendingOrDescending) {
				//if skip is true, then add 2 to o to skip to next player
				if (skip) {
					o = o + 2;
					skip = false;
				}
				//else, increment o by one since there is no skip involved
				else {
					o++;
				}
				//if o is out of bounds, then it must be redirected to the correct player
				if (o >= k) {
					o =abs(o-k);
				}
				
			}
			//else, the order of playing is descending (in reverse), then descend
			else {
				//if skip is true, then subtract 2 from o to skip to next player
				if (skip) {
					o = o - 2;
					skip = false;
				}
				else {
					o--;
				}
				//if o is out of bounds, then it must be redirected to the correct player
				if (o < 0) {
					o = abs(o + k);

				}
				
			}
		}
	}
    return 0;
}

