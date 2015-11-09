#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> cardsInSequence;
        int gMaxLen = 0;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if(cardsInSequence.empty() || cardsInSequence[cardsInSequence.size() - 1] < (*iter)) {
                cardsInSequence.push_back(*iter);
                gMaxLen = gMaxLen > cardsInSequence.size() ? gMaxLen : cardsInSequence.size();
            } else {
                int beginPosition = 0;
                int endPosition = cardsInSequence.size() - 1;
                // Find the lower bound
                while(beginPosition < endPosition) {
                    int middlePosition = (beginPosition + endPosition) / 2;
                    if(cardsInSequence[middlePosition] >= (*iter)) {
                        endPosition = middlePosition;
                    } else {
                        beginPosition = middlePosition + 1;
                    }
                }
                cardsInSequence[beginPosition] = *iter;
                gMaxLen = gMaxLen > (beginPosition + 1) ? gMaxLen : (beginPosition + 1);
            }
        }
        return gMaxLen;
    }
};

int main() {
    int testData[9] = {1,3,2,4,11,101,90,25,9};
    vector<int> testCase(testData, testData + 9);
    Solution testUnit;
    cout << testUnit.lengthOfLIS(testCase) << endl;
    return 0;
}