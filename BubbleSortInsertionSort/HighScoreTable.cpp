#include "HighScoreTable.h"

HighScoreTable::HighScoreTable()
{

}

HighScoreTable::~HighScoreTable()
{

}

HighScoreTable::HighScoreTable(std::string fileName)
{
	using namespace std;

	fstream file;

	file.open(fileName, ios::in);

	if (!file.is_open())
	{
		return;
	}

	string buffer;
	getline(file, buffer);

	HighScoreEntry temp;

	vector<string> rtn;

	while (getline(file, buffer))
	{
		rtn = split(buffer);
		temp.level = stoi(rtn.back());
		rtn.pop_back();
		temp.score = stoi(rtn.back());
		rtn.pop_back();
		temp.name = rtn.back();
		hsVector.push_back(temp);
	}

	file.clear();
	file.flush();
	file.close();
}

std::vector<std::string> HighScoreTable::split(std::string &line)
{
	using namespace std;

	vector<string> result;
	stringstream lineStream(line);
	string cell;
	while (getline(lineStream, cell, ','))
		result.push_back(cell);
	if (!lineStream && cell.empty())
		result.push_back("");
	return result;
}

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	bool swapped = false;
	for (int i = 0; i < hsVector.size(); ++i)
	{
		for (int j = i; i < hsVector.size(); ++i)
		{
			HighScoreEntry temp;
			temp = hsVector[i];
			if (hsVector[i].score < hsVector[i + 1].score)
			{
				hsVector[i].score = hsVector[i = 1].score;
				hsVector[i + 1].score = temp.score;
			}
		}
	}
}