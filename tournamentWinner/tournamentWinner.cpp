#include <vector>
#include <map>
#include <string>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
						vector<int> results)
{
	int length = results.size();
	map<string, int> score;
	map<string, int>::iterator itr;
	for (int i = 0; i < length; i++)
	{
		string key_1 = competitions[i][0];
		string key_2 = competitions[i][1];
		bool found = false;
		if (results[i] == 1)
		{
			for (itr = score.begin(); itr != score.end(); ++itr)
			{
				if (itr->first == key_1)
				{
					found = true;
					itr->second += 3;
					break;
				}
			}
			if (found == false)
			{
				score.insert(pair<string, int>(key_1, 3));
			}
			found = false;
			for (itr = score.begin(); itr != score.end(); ++itr)
			{
				if (itr->first == key_2)
				{
					found = true;
					break;
				}
			}
			if (found == false)
			{
				score.insert(pair<string, int>(key_2, 0));
			}
		}
		else
		{
			for (itr = score.begin(); itr != score.end(); ++itr)
			{
				if (itr->first == key_2)
				{
					found = true;
					itr->second += 3;
					break;
				}
			}
			if (found == false)
			{
				score.insert(pair<string, int>(key_2, 3));
			}
			found = false;
			for (itr = score.begin(); itr != score.end(); ++itr)
			{
				if (itr->first == key_1)
				{
					found = true;
					break;
				}
			}
			if (found == false)
			{
				score.insert(pair<string, int>(key_1, 0));
			}
		}
	}
	int max = score.begin()->second;
	string winner = score.begin()->first;
	for (itr = score.begin(); itr != score.end(); ++itr)
	{
		if (max < itr->second)
		{
			max = itr->second;
			winner = itr->first;
		}
	}
	return winner;
}
