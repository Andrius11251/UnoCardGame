

#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Player::Player() {
	
}


//Inserts 7 cards to a player 
void Player::insertStartingCards(vector<Card> daCards) {
	for (int i = 0; i < daCards.size();i++) {
		hand.push_back(daCards.at(i));
	}
	
}

//Getter for the player's hand full of cards
vector<Card> Player::getHand() {
	return hand;
}

void Player::displayHand() {
	
	vector<Card> ::iterator myIter;
	for (myIter = hand.begin(); myIter != hand.end(); myIter++) {
		(*myIter).displayCardInfo();
		cout << ", ";
	}
	cout << endl;
}

//This method retrieves a card from the Uno deck and places it in the player's hand
void Player::addToHand(Card c) {
	hand.push_back(c);
}

//This method selects a card from the player's hand and also compares selected card with the card on top of the pile
Card Player::selectCard(Card top) {
	displayHand();
	bool active = false;
	int cardEntry = 0;

	do {
		//this loop validates if the card entry selection is between 0 and the size of the hand
		do {
			cout << "Enter a card selection ranging from 0 to " << hand.size() - 1 << " or " << hand.size() << " to draw a card" << endl;
			cin >> cardEntry;
			//if the user desires to draw a card from the deck, then return an empty Card as a flag
			if (cardEntry == hand.size()) {
				return Card();
			}

		}while(cardEntry<-1 || cardEntry> hand.size());

		//check if the selected card is applicable to place down
		active = validateSelection(hand.at(cardEntry),top);

		if (active) {
			cout << "Success at choosing the card" << endl;
			break;
		}
		else {
			cout << "FAILURE IN SELECTING A CARD" << endl;
		}
	}while (!active);

	//removes the drawn card and returns it
	Card toBeReturned = hand.at(cardEntry);
	hand.erase(hand.begin() + cardEntry);
	return toBeReturned;

	
}

//This method validates the selected card by efficiently comparing the top card
bool Player::validateSelection(Card c, Card top) {
	cout << c.getRank() << " " << c.getColor();
	//if the selected card is a draw 4 or a wild then choose a different color
	if (c.getRank() == "DRAW+4" || c.getRank() == "WILD") {
		string colorChoice;
		
		//do-while loop determines if chosen color is one of the Uno standard colors, and checks if the chosen color
		//is similar to the top card's color
		do {
			cout << "Which color would you like to change to?" << endl;
			cin >> colorChoice;
			if (colorChoice == top.getColor()) {
				cout << "Cannot maintain the same color that is present on the top card" << endl;
			}
		} while (colorChoice == top.getColor() && (colorChoice != "B" || colorChoice != "G" || colorChoice != "R" || colorChoice != "Y"));
		
		c.setColor(colorChoice);
		return true;
	}


	//if the selected card is either a SKIP or REVERSE
	else if(c.getRank() == "SKIP" || c.getRank() == "REVERSE" || c.getRank() == "DRAW+2"){
		//if the colors of the skip or reverse or draw2 match up or if the ranks match up regardless of color, then it is a valid selection
		if (c.getColor() == top.getColor() || c.getRank() == top.getRank()) {
			return true;
		}
		//else, it is an invalid selection
		else {
			return false;
		}
	
	}
	//if the the selected card's rank is a numerial value
	else if (c.getRank() == "1" || c.getRank() == "2" || c.getRank() == "3" || c.getRank() == "4" || c.getRank() == "5" ||
			c.getRank() == "6" || c.getRank() == "7" || c.getRank() == "8" || c.getRank() == "9" || c.getRank() == "0") {
		
		//if the top card is also a numerical value, then further compare the two card's ranks
		if (top.getRank() == "1" || top.getRank() == "2" || top.getRank() == "3" || top.getRank() == "4" || top.getRank() == "5" ||
			top.getRank() == "6" || top.getRank() == "7" || top.getRank() == "8" || top.getRank() == "9" || top.getRank() == "0") {

			cout << "ALRIGHTY FOLKS " << c.getRank() << " " << top.getRank() << endl;

			//if both cards have matching ranks or matching colors then it is validated
			if (c.getRank() == top.getRank() || c.getColor() ==top.getColor()) {
				return true;
			}
			else {
				return false;
			}
		}
		//if the top card is either a skip, reverse or draw2, then double check if their colors are the same
		else if (top.getRank() == "SKIP" || top.getRank() == "REVERSE" || top.getRank() == "DRAW+2" || top.getRank() == "DRAW+4") {
			//if colors are the same, validation is true
			if (c.getColor() == top.getColor()) {
				return true;
			}
			//otherwise false
			else {
				return false;
			}
		}
	}

	return false;
}

