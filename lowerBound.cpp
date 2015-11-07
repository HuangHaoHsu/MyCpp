#include <vector>
#include <iostream>

using namespace std;

int lowerBound(const vector<int>& nums, const int pivot) {
	if(nums.size() == 0) {
		return -1;
	}
	int beginPos = 0;
	int endPos = nums.size() - 1;
	while(beginPos < endPos) {
		int middlePos = (beginPos + endPos) / 2;
		if(nums[middlePos] >= pivot) {
			endPos =  middlePos;
		} else {
			beginPos = middlePos + 1;
		}
	}
	return beginPos;
}

int main() {
	int naiveData1[6] = {1,3,5,7,8,9};
	vector<int> testCase1(naiveData1, naiveData1 + 6);
	int pivot1 = 12;
	int pivot2 = 7;
	int pivot3 = 9;
	int pivot4 = 1;
	cout << lowerBound(testCase1, pivot1) << endl;
	cout << lowerBound(testCase1, pivot2) << endl;
	cout << lowerBound(testCase1, pivot3) << endl;
	cout << lowerBound(testCase1, pivot4) << endl;
	return 0;
}