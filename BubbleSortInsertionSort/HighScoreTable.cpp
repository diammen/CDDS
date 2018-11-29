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
	using namespace std;
	// bubble sort
	//bool swapped = false;
	//vector<HighScoreEntry> newScore;
	//newScore = hsVector;

	//for (int i = 0; i < hsVector.size() - 1; ++i)
	//{
	//	for (int j = 0; j < hsVector.size() - i - 1; ++j)
	//	{
	//		HighScoreEntry temp;
	//		temp = newScore[j];
	//		if (newScore[j].score > newScore[j + 1].score)
	//		{
	//			newScore[j].score = newScore[j + 1].score;
	//			newScore[j + 1].score = temp.score;
	//			swapped = true;
	//		}
	//	}
	//	if (!swapped) break;
	//}
	//if (topRows > hsVector.size() - 1)
	//{
	//	topRows = hsVector.size() - 1;
	//}
	//vector<HighScoreEntry> topNumScores;
	//for (int i = topRows; i >= 0; --i)
	//{
	//	topNumScores.push_back(newScore[i]);
	//}
	//return topNumScores;

	// insertion sort
	vector<HighScoreEntry> newScore;
	newScore = hsVector;
	HighScoreEntry key;
	for (int i = 1; i < hsVector.size(); ++i)
	{
		for (int j = i; j > 0 && newScore[j - 1].score > newScore[j].score; --j)
		{
			key = newScore[j - 1];
			newScore[j - 1] = newScore[j];
			newScore[j] = key;
		}
	}
	if (topRows > hsVector.size() - 1)
	{
		topRows = hsVector.size() - 1;
	}
	vector<HighScoreEntry> topNumScores;
	for (int i = topRows; i >= 0; --i)
	{
		topNumScores.push_back(newScore[i]);
	}
	return topNumScores;
}

std::vector<HighScoreEntry> HighScoreTable::topNNScoresBubble(int topRows)
{
	using namespace std;
	bool swapped = false;
	vector<HighScoreEntry> newScore;
	newScore = hsVector;

	for (int i = 0; i < hsVector.size() - 1; ++i)
	{
		for (int j = 0; j < hsVector.size() - i - 1; ++j)
		{
			HighScoreEntry temp;
			temp = newScore[j];
			if (newScore[j].score > newScore[j + 1].score)
			{
				newScore[j].score = newScore[j + 1].score;
				newScore[j + 1].score = temp.score;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
	if (topRows > hsVector.size() - 1)
	{
		topRows = hsVector.size() - 1;
	}
	vector<HighScoreEntry> topNumScores;
	for (int i = topRows; i >= 0; --i)
	{
		topNumScores.push_back(newScore[i]);
	}
	return topNumScores;
}

void HighScoreTable::merge(std::vector<HighScoreEntry> * arr, size_t p, size_t q, size_t r)
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
		left.push_back(arr->at(p+i));
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

void HighScoreTable::mergeSort(std::vector<HighScoreEntry> * arr, size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	for (int i = 0; i < bottomRows; ++i)
	{
		hsVector.pop_back();
	}
	return true;
}

void Merge(int * arr, size_t p, size_t q, size_t r)
{
	using namespace std;
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;
	int i = 0;
	int j = 0;

	int * leftArr = new int[leftEnd];
	int * rightArr = new int[rightEnd];

	for (i = 0; i < leftEnd; ++i)
	{
		leftArr[i] = arr[p + i];
	}
	for (j = 0; j < rightEnd; ++j)
	{
		rightArr[j] = arr[q + j + 1];
	}

	i = 0;
	j = 0;

	for (int k = p; k <= r; ++k)
	{
		if ((j >= rightEnd) || (i < leftEnd && leftArr[i] <= rightArr[j]))
		{
			arr[k] = leftArr[i];
			++i;
		}
		else
		{
			arr[k] = rightArr[j];
			++j;
		}
	}

	delete[] leftArr;
	delete[] rightArr;
}

void MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}