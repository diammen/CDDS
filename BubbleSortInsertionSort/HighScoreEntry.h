#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string;

class HighScoreEntry
{
public:
	string name;
	int score;
	int level;

	HighScoreEntry();
	~HighScoreEntry();
};