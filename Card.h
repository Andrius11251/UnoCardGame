#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<string>

#include <vector>

using namespace std;

class Card {
	private:
		string rank;
		string color;

	public:
		Card();
		Card(string, string);
		void setCard();
		string getRank();
		string getColor();
		void displayCard();
		void displayCardInfo();
		void setColor(string);


};

#endif