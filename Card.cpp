#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card() {
	rank = "N/A";
	color = "N/A";
}

Card::Card(string r, string c) {
	rank = r;
	color = c;
}

void Card:: displayCardInfo() {
	cout << rank << " " << color;
}

//Displays the actual Uno card
void Card::displayCard() {
	cout << rank << " " << color << endl;

	if (rank == "1") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[     *     ]" << endl;
		cout << "[    **     ]" << endl;
		cout << "[     *     ]" << endl;
		cout << "[     *     ]" << endl;
		cout << "[   *****   ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}
		

	else if (rank == "2") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[    **     ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[    *      ]" << endl;
		cout << "[  *        ]" << endl;
		cout << "[  *****    ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	
	}
	
	else if (rank == "3") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[      *    ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[      *    ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}

	else if (rank == "4") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[      *    ]" << endl;
		cout << "[      *    ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;


	}

	else if (rank == "5") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[   *       ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[      *    ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}

	else if (rank == "6") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[    ***    ]" << endl;
		cout << "[   *       ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[    **     ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}
	else if (rank == "7") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[     *     ]" << endl;
		cout << "[    *      ]" << endl;
		cout << "[   *       ]" << endl;
		cout << "[   *       ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}


	else if (rank == "8") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[    **    ]" << endl;
		cout << "[   *  *   ]" << endl;
		cout << "[    **    ]" << endl;
		cout << "[   *  *   ]" << endl;
		cout << "[    **    ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;

	}
	else if (rank == "9") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[    ***    ]" << endl;
		cout << "[   *   *   ]" << endl;
		cout << "[   * * *   ]" << endl;
		cout << "[     *     ]" << endl;
		cout << "[   *       ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}
	else if (rank == "0") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[   ****    ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}

	else if (rank == "REVERSE") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   *  * *  ]" << endl;
		cout << "[     *  *  ]" << endl;
		cout << "[   *   *   ]" << endl;
		cout << "[   *       ]" << endl;
		cout << "[  *        ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}
	else if (rank == "SKIP") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[   ******  ]" << endl;
		cout << "[   *  * *  ]" << endl;
		cout << "[   * *  *  ]" << endl;
		cout << "[   **   *  ]" << endl;
		cout << "[   ******  ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}

	else if (rank == "WILD") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[ *       * ]" << endl;
		cout << "[ *       * ]" << endl;
		cout << "[ *   *  *  ]" << endl;
		cout << "[  * * * *  ]" << endl;
		cout << "[   *   *   ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}
	else if (rank == "DRAW+2") {
		cout << "-------------" << endl;
		cout << "[" << color << "          ]" << endl;
		cout << "[      **** ]" << endl;
		cout << "[   *     * ]" << endl;
		cout << "[  *** **** ]" << endl;
		cout << "[   *  *    ]" << endl;
		cout << "[      **** ]" << endl;
		cout << "[          " << color << "]" << endl;
		cout << "-------------" << endl;
	}

	else if (rank == "DRAW+4") {
		cout << "-------------" << endl;
		cout << "[" <<         "          ]" << endl;
		cout << "[      *  * ]" << endl;
		cout << "[   *  *  * ]" << endl;
		cout << "[  *** **** ]" << endl;
		cout << "[   *     * ]" << endl;
		cout << "[         * ]" << endl;
		cout << "[          "            "]" << endl;
		cout << "-------------" << endl;
	}
	
	

}

//This metod returns the color of the card
string Card::getColor() {
	return color;
}

//This metod returns the rank of the card
string Card::getRank() {
	return rank;
}

//This method sets the rank of the card
void Card::setColor(string c) {
	color = c;
}

