#include "libhangman/libhangman.h"
#include <iostream>
#include <list>
#include <string.h>

using namespace std;

int main()
{
    int dific;
    bool correctDific = false;
    cout << "\n\n\n\t\t"
         << "!!! Welcome to the HAAAAANGMAAAAN (hangman :D) !!!\n\n"
         << endl;
    cout << "\t\tSelect "
            "difficulty:\n\t\t1-Easy\n\t\t2-Medium\n\t\t3-Hard\n\t\t4-"
            "Impossible\n\t\tEnter the number of difficulty: "
         << endl;
    while (correctDific == false) {
        cout << "\t\t";
        cin >> dific;
        if (dific < 1 || dific > 4) {
            cout << "\t\tIncorrect difficulty!" << endl;
            dific = 0;
        } else
            correctDific = true;
    }
    string word;
    switch (dific) {
    case 1:
        Alphabet();
        cout << "\t\t" << GameDeck(1) << endl;
        word = GameDeck(1);
        if (Game(&word).second == true) {
            cout << "\t\t" << Game(&word).first;
        } else
            cout << "\t\tWrong button!" << endl;
        break;
    case 2:
        Alphabet();
        cout << "\t\t" << GameDeck(2) << endl;
        word = GameDeck(2);
        if (Game(&word).second == true) {
            cout << "\t\t" << Game(&word).first;
        } else
            cout << "\t\tWrong button!" << endl;
        break;
    case 3:
        Alphabet();
        cout << "\t\t" << GameDeck(3) << endl;
        word = GameDeck(3);
        if (Game(&word).second == true) {
            cout << "\t\t" << Game(&word).first;
        } else
            cout << "\t\tWrong button!" << endl;
        break;
    case 4:
        Alphabet();
        cout << "\t\t" << GameDeck(4) << endl;
        word = GameDeck(4);
        if (Game(&word).second == true) {
            cout << "\t\t" << Game(&word).first;
        } else
            cout << "\t\tWrong button" << endl;
        break;
    }
}
