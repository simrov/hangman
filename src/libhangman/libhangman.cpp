#include "libhangman/libhangman.h"

string GameDeck(int difficult)
{
    int this_dific = difficult;
    string deckLength;
    if (this_dific == 1) {
        cout << "\n\t\t" << endl;
        deckLength = "_ _ _ _";
    }
    if (this_dific == 2) {
        cout << "\n\t\t" << endl;
        deckLength = "_ _ _ _ _";
    }
    if (this_dific == 3) {
        cout << "\n\t\t" << endl;
        deckLength = "_ _ _ _ _ _";
    } else if (this_dific == 4) {
        cout << "\n\t\t" << endl;
        deckLength = "_ _ _ _ _ _ _ _ _";
    }
    return deckLength;
}

list<char> Alphabet()
{
    cout << "\n\t\tTHE GAME HAS BEGUN" << endl;
    list<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    cout << endl << endl << "\t\t";
    for (auto i = alphabet.begin(); i != alphabet.end(); i++) {
        cout << *i << " ";
    }
    return alphabet;
}

pair<string, bool> Game(string* word)
{
    bool right = true;
    // checking
    return make_pair(*word, right);
}
