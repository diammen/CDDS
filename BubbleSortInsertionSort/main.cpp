#include <iostream>
#include <vector>
#include "HighScoreEntry.h"
#include "HighScoreTable.h"
using std::vector;

int main()
{

	HighScoreTable scores("highscores.txt");
	int num[10] = { 1,9,8,3,15,54,5,2,6,7 };
	std::cout << "Merge Sort" << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "Before:" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << num[i] << std::endl;
	}

	MergeSort(num, 0, 9);

	std::cout << "After:" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << num[i] << std::endl;
	}
	
	vector<HighScoreEntry> topScores = scores.topNNScores(13);
	std::cout << "Bubble Sort" << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << "Before:" << std::endl;
	for (int i = 0; i < scores.hsVector.size(); ++i)
	{
		std::cout << scores.hsVector[i].score << std::endl;
	}
	vector<HighScoreEntry> topScoresBubble = scores.topNNScoresBubble(13);
	std::cout << "Sorted Descending Order:" << std::endl;
	for (int i = 0; i < topScoresBubble.size(); ++i)
	{
		std::cout << topScoresBubble[i].score << std::endl;
	}
	getchar();
	return 0;
}