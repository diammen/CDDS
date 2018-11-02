#include <iostream>
#include <vector>
#include "HighScoreEntry.h"
#include "HighScoreTable.h"
using std::vector;

int main()
{

	HighScoreTable scores("highscores.txt");
	int num[10] = { 1,9,8,3,15,54,5,2,6,7 };

	MergeSort(num, 0, 9);

	scores.mergeSort(& scores.hsVector, 0, scores.hsVector.size() - 1);
	
	vector<HighScoreEntry> topScores = scores.topNNScores(13);

	return 0;
}