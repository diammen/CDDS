#pragma once
#include "HighScoreEntry.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class HighScoreTable
{
private:
	std::vector<std::string> split(std::string &line);
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	std::vector<HighScoreEntry> topNNScoresBubble(int topRows);
	void merge(std::vector<HighScoreEntry> * arr, size_t p, size_t q, size_t r);
	void mergeSort(std::vector<HighScoreEntry> * arr, size_t p, size_t r);
	bool pruneBottomNNScores(int bottomRows);


	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();
};

void Merge(int * arr, size_t p, size_t q, size_t r);

void MergeSort(int * arr, size_t p, size_t r);

template<typename T>
void tMerge(int * arr, size_t p, size_t q, size_t r)
{
	using namespace std;
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;
	int i = 0;
	int j = 0;

	vector<HighScoreEntry> left;
	vector<HighScoreEntry> right;


	for (i = 0; i < leftEnd; ++i)
	{
		left.push_back(arr->at(p + i));
	}
	for (j = 0; j < rightEnd; ++j)
	{
		right.push_back(arr->at(q + j + 1));
	}

	i = 0;
	j = 0;

	for (int k = p; k <= r; ++k)
	{
		if ((j >= rightEnd) || (i < leftEnd && left[i].score <= right[j].score))
		{
			arr->at(k) = left[i];
			++i;
		}
		else
		{
			arr->at(k) = right[j];
			++j;
		}
	}
}