#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void readCSV(const string& file_path, vector<string>& candidates, vector<vector<string>>& votes);
int getFirstChoice(const vector<string>& row, const vector<bool>& eliminated);
vector<int> tallyVotes(const vector<vector<string>>& votes, const vector<bool>& eliminated);
int findWinner(const vector<int>& counts, int totalVoters);
int findLowest(const vector<int>& counts, const vector<bool>& eliminated);
void writeRound(ofstream& file, const vector<int>& counts);