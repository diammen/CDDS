#pragma once
#include "HighScoreEntry.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	//bool pruneBottomNNScores(int bottomRows);
	std::vector<std::string> split(std::string &line);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();
};