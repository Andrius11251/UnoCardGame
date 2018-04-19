#ifndef DECK_H
#define DECK_H
#include<iostream>
#include<string>


#include <vector>

using namespace std;

class Deck {
	private:
		vector<Card> pile;
	public:
		Deck();
		void displayDeck();
		void shuffle();
		Card getTop();
		Card draw();
		vector<Card>drawBeginningCards();
		Card showFront();


};
#endif