#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


#include <vector>

using namespace std;

//Constructor for a deck object
Deck::Deck() {

	vector<string> ranks = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "REVERSE", "DRAW+2", "SKIP" };
	vector<string>colors = { "R", "G", "B","Y" };
	
	int k = 0;

	while (k < 4) {
		pile.push_back(Card("0", colors.at(k)));
		pile.push_back(Card("DRAW+4", "N/A"));
		pile.push_back(Card("WILD", "N/A"));
		k++;
	}
	for (int i = 0; i < ranks.size(); i++) {
		for (int j = 0; j < colors.size(); j++) {
			pile.push_back(Card(ranks.at(i), colors.at(j)));
			pile.push_back(Card(ranks.at(i), colors.at(j)));
		}
	}
}




//This method shuffles the entire Uno deck
void Deck::shuffle() {
	srand(time(0));
	for (int i = 0; i < static_cast<int> (pile.size()); i++) {
		Card temp = pile.at(i);
		int j =	rand() % 108;
		pile[i] = pile[j];
		pile[j] = temp;
	}
	
}

//Draws a card from the Uno deck
Card Deck::draw() {
	if (pile.size()==0) {
		cout << "There are no cards remaining in the deck" << endl;
	}
	else {
		Card drawnCard = pile.front();
		pile.erase(pile.begin());
		return drawnCard;
	}
}


//Retrieves the top card from the Uno deck
Card Deck::getTop() {
	
	while (true) {
		Card aux = pile.front();
		pile.erase(pile.begin());
		//if the first drawn card is either a wild or draw+4, then 
		if (aux.getRank() == "WILD" || aux.getRank() == "DRAW+4") {
			pile.push_back(aux);
		}
		else {
			return aux;
		}
	}	
	return Card();
}

//This method displays the entire Uno deck
void Deck::displayDeck() {
	vector<Card> ::iterator myIter;
	for (myIter = pile.begin(); myIter != pile.end(); myIter++) {
		(*myIter).displayCard();
	}
}

//This method draws 7 cards from the Uno deck where these cards are given to a player at the beginning of the game
vector<Card> Deck::drawBeginningCards() {
	
	vector<Card> temp;
	for (int j = 0; j < 7; j++) {
		Card auxiliary = pile.front();
		pile.erase(pile.begin());
		temp.push_back(auxiliary);
	}
	return temp;
}

//Returns the card at the front of the Uno deck
Card Deck::showFront() {
	return pile.front();
}
