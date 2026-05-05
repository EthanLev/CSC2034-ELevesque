#include "main.h"
#include <filesystem>

int main()
{
    vector<string> candidates;
    vector<vector<string>> votes;

    cout << std::filesystem::current_path() << endl;

    readCSV("data.csv", candidates, votes);

    int numCandidates = candidates.size();
    int totalVoters = votes.size();

    vector<bool> eliminated(numCandidates, false);

    ofstream outFile("results.csv");

    // Write names
    for (int i = 0; i < candidates.size(); i++)
    {
        outFile << candidates[i];

        if (i < candidates.size() - 1) // add comma after last name
        {
            outFile << ",";
        }
    }

    outFile << "\n";

    // Voting rounds
    while (true)
    {
        vector<int> counts = tallyVotes(votes, eliminated);

        // save count
        vector<int> output = counts;

        for (int i = 0; i < numCandidates; i++)
        {
            if (eliminated[i])
            {
                output[i] = 0; // show 0 if eliminated
            }
        }

        writeRound(outFile, output);

        // Check winner
        int winner = findWinner(counts, totalVoters);

        if (winner != -1)
        {
            cout << "Winner: " << candidates[winner] << endl;
            break;
        }

        // Eliminate lowest
        int lowest = findLowest(counts, eliminated);

        if (lowest == -1)
        {
            cout << "No winner\n";
            break;
        }

        eliminated[lowest] = true;
    }

    outFile.close();

    return 0;
}

void readCSV(const string& file_path, vector<string>& candidates, vector<vector<string>>& votes)
{
    ifstream file(file_path);

    if (!file.is_open())
    {
        cout << "Error opening file\n";
        return;
    }

    string line;

    // Read candidates
    getline(file, line);

    stringstream ss(line); // turn string into stream
    string field;

    while (getline(ss, field, ',')) // split by commas
    {
        candidates.push_back(field);
    }

    // Read votes
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> row;

        while (getline(ss, field, ','))
        {
            row.push_back(field);
        }

        votes.push_back(row);
    }

    file.close();
}

int getFirstChoice(const vector<string>& row, const vector<bool>& eliminated)
{
    if (row.size() != eliminated.size())
    {
        return -1;
    }

    int minRank = -1;   // no value yet
    int index = -1;

    for (int i = 0; i < row.size(); i++)
    {
        if (eliminated[i]) continue;

        int rank = stoi(row[i]); // string to int

        if (minRank == -1 || rank < minRank)
        {
            minRank = rank;
            index = i;
        }
    }

    return index;
}

vector<int> tallyVotes(const vector<vector<string>>& votes, const vector<bool>& eliminated)
{
    vector<int> counts(eliminated.size(), 0);

    for (int i = 0; i < votes.size(); i++)
    {
        int choice = getFirstChoice(votes[i], eliminated);

        if (choice != -1)
        {
            counts[choice]++;
        }
    }

    return counts;
}

int findWinner(const vector<int>& counts, int totalVoters)
{
    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] > totalVoters / 2)
        {
            return i;
        }
    }

    return -1;
}

int findLowest(const vector<int>& counts, const vector<bool>& eliminated)
{
    int minVotes = 999;
    int index = -1;

    for (int i = 0; i < counts.size(); i++)
    {
        if (!eliminated[i] && counts[i] < minVotes)
        {
            minVotes = counts[i];
            index = i;
        }
    }

    return index;
}

void writeRound(ofstream& file, const vector<int>& counts)
{
    for (int i = 0; i < counts.size(); i++)
    {
        file << counts[i];

        if (i < counts.size() - 1)
        {
            file << ",";
        }
    }

    file << "\n";
}