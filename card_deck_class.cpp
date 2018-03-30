//
// Created by Mark Catugas on 3/14/2018.
//

// Creates a Card_Deck class
// Create a stack of 52 cards with 4 suits ranging from 2 to Ace.
// Shuffle the cards and print them out

# include <iostream> // Allows use of cin and cout
# include <bits/stdc++.h> // Allows use of string type

using namespace std; // So we don't need to write std::cout

class Card_Deck {                              // Define Card_Deck class
public:                                        // Create public variables
    int di;
    string card;                               // initialize deck index as integer, card as string
    string deck[52] = {};                      // initialize deck array with size of 52 cards
    string suits[4] = {"H", "C", "S", "D"};    // define the suits
    string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; // define card values

    void Gen_Deck(void);
    void Shuffle_Deck(void);
    void Print_Deck(void);
};

void Card_Deck::Gen_Deck(void){                            // Declare Generate Deck Function
    // generate the deck
    for (int k = 0; k < 4 ; k++){               // Generates the suits
        for (int i = 0; i < 13 ; i++) {         // Generates the values
            card = suits[k] + values[i];        // Concatenate the strings

            deck[di] = card;                    // Add card to deck by assigning index
            di += 1;                            // Increase index number
        }
    }
}

void Card_Deck::Shuffle_Deck(void){                                          // Declare Shuffle Deck class
    srand(time(0));                                               // initialize seed randomly

    for (int s = 0; s < 52; s++){                                 // shuffle deck - for loop
        int r = rand() % 52;                                      // generate random positions
        string temp = deck[s]; deck[s] = deck[r]; deck[r] = temp; // randomly exchange elements with each other
    }
}


void Card_Deck::Print_Deck(void){
    cout << "The Deck: " << flush;
    for (int i = 0; i < 52 ; i++) {                              // print deck - for loop
        cout << deck[i] << " " << flush;
    }
}



// --------------------------------------------------------------------------------------------------------

int main(){                 // Main Function

    Card_Deck Deck1;        // Create and Card_deck object called "Deck1"

    Deck1.Gen_Deck();       // Generate cards using function in Deck1
    Deck1.Shuffle_Deck();   // Shuffle Deck1
    Deck1.Print_Deck();     // Print the Deck1
}

