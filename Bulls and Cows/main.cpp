#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int numOfBulls = 0;
        int numOfCows = 0;
        unordered_map<char,int> cowCandidates;
        string cowCandidatesGuess;
        for(int idx = 0; idx < secret.size(); ++idx) {
            if(secret[idx] == guess[idx]) {
                ++numOfBulls;
            } else {
                cowCandidatesGuess.push_back(guess[idx]);
                if(cowCandidates.find(secret[idx]) != cowCandidates.end()) {
                    ++cowCandidates[secret[idx]];
                } else {
                    cowCandidates[secret[idx]] = 1;
                }
            }
        }
        for(auto iter = cowCandidatesGuess.begin(); iter != cowCandidatesGuess.end(); ++iter) {
            if((cowCandidates.find(*iter) != cowCandidates.end()) && (cowCandidates[*iter] > 0)) {
                ++numOfCows;
                --cowCandidates[*iter];
            }
        }
        ostringstream osBulls;
        osBulls << numOfBulls;
        ostringstream osCows;
        osCows << numOfCows;
        string result;
        result.append(osBulls.str()).append("A").append(osCows.str()).append("B");
        return result;
    }
};

int main() {
    string testCase1Secret("1122");
    string testCase1Guess("2211");
    Solution testUnit;
    cout << testUnit.getHint(testCase1Secret, testCase1Guess) << endl;
    return 0;
}