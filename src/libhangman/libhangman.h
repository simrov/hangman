#pragma once
#include <iostream>
#include <list>

using namespace std;

string GameDeck(int difficult);
list<char> Alphabet();
pair<string, bool> Game(string* word);
