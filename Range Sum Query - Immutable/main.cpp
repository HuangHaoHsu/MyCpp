#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        data.resize(nums.size());
        for(int idx = 0; idx < nums.size(); ++idx) {
            if(idx == 0) {
                data[idx] = nums[idx];
            } else {
                data[idx] = data[idx-1] + nums[idx];
            }
        }
    }

    int sumRange(int i, int j) {
        int sum = data[j];
        if(i > 0) {
            sum -= data[i-1];
        }
        return sum;
    }
private:
    vector<int> data;
};

int main() {
    int nativeData[6] = {-2, 0, 3, -5, 2, -1};
    vector<int> testData(nativeData, nativeData + 6);
    NumArray testUnit(testData);
    cout << testUnit.sumRange(2, 5) << endl;
    return 0;
}