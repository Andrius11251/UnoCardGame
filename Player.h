#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>


#include <vector>

using namespace std;

class Player {
private:
	vector<Card> hand;

public:
	Player();
	void insertStartingCards(vector<Card>);
	vector<Card> getHand();
	void displayHand();
	void addToHand(Card);
	Card selectCard(Card);
	bool validateSelection(Card,Card);


};

#endif
