//
// Created by Mark Catugas on 3/20/2018.
//

// RPG companion creator to demonstrate struct
// File uses a while loop, functions, switch and more
// Create more than 1 companion with your choice of name and race, attack and defense are randomly generated

# include <iostream> // Allows use of cin and cout
# include <bits/stdc++.h> // Allows use of string type

using namespace std; // So we don't need to write std::cout

struct companion {          // defines the struct 'companion'
    string name, race;      // has a name and race
    int attack, defense;    // has an attack and defense
};

int char_input(int id)              // declare char_input function with argument 'id'
{                                   // *The id will help break out of while loop at appropriate time
    struct companion generic;       // creates a struct called 'generic'

    string inName, race;            // create function variables
    int choice, attack, defense;

    cout << "\nInput name:" << endl;
    cin >> inName;
    generic.name = inName;          // get input at the companion's name

    cout << "Choose race, 1 for dragonling, 2 for dire wolf, 3 for river croc." << endl;
    cin >> choice;

    switch(choice){                                     // switch block to give players choice of possible races
        case 1:                  // if n == 1,
            cout << "You picked Dragonling" << endl;
            generic.race = "Dragonling";
            break;
        case 2:                 // if n == 2
            cout << "You picked Dire Wolf" << endl;
            generic.race = "Dire Wolf";
            break;
        case 3:                 // if n == 3
            cout << "You picked River Croc" << endl;
            generic.race = "River Croc";
            break;
    } // end switch block

    srand(time(0));                    // initialize seed randomly

    generic.attack = rand() % 10;      // generate an attack stat between 0 and 10
    generic.defense =  rand() % 10;     // generate an attack state between 0 and 10


    cout << "\nThe following are your companion's stats-" << endl;  // print stats after every creation
    cout << "Name: " << generic.name << endl;
    cout << "Race: " << generic.race << endl;
    cout << "Attack: " << generic.attack << endl;
    cout << "Defense: " << generic.defense << endl;

    --id;       // decrement id for the while loop
    return id;  // returns id as 'com_num' in while loop

}

int main(void){

    int com_num;
    string companion1;

    cout << "Welcome to RPG companion creation" << endl;
    cout << "Input number of companions to create (2-3 recommended):" << endl;
    cin >> com_num;


    if (com_num < 2){           //  if user inputs 1, it will create only 1 companion
        char_input(0);
    } else {
        while (com_num != 0){   // if user inputs anything over 1, it will create the number of companions based on input
            com_num = char_input(com_num);
        }
    }
}