#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        int minNum = INT_MAX;
        int secMinNum = INT_MAX;
        bool minNumHasBeenSet = false;
        bool secMinNumHasBeenSet = false;
        for(int idx = 0; idx < nums.size(); ++idx) {
            if((!minNumHasBeenSet) || (nums[idx] <= minNum)) {
                minNum = nums[idx];
                minNumHasBeenSet = true;
                continue;
            } else if((!secMinNumHasBeenSet) || (nums[idx] <= secMinNum)) {
                secMinNum = nums[idx];
                secMinNumHasBeenSet = true;
                continue;
            } else {
                return true;
            }
        }
        return false;
    }
};


int main() {
    int testCase[6] = {1, 2, 3, 1, 2, 1};
    vector<int> testData(testCase, testCase + 6);
    Solution sl;
    cout << sl.increasingTriplet(testData) << endl;
    return 0;
}