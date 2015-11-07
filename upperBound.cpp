
#include <iostream>
#include <vector>

using namespace std;

int upperBound(const vector<int>& nums, const int pivot) {
	if(nums.size() == 0) {
		return -1;
	}
	int beginPos = 0;
	int endPos = nums.size() - 1;
	while(beginPos < endPos) {
		int middlePos = (beginPos + endPos) / 2 + 1;
		if(nums[middlePos] <= pivot) {
			beginPos = middlePos;
		} else {
			endPos = middlePos - 1;
		}
	}
	return beginPos;
}

int main() {
	int naiveData1[6] = {1,3,4,6,7,9};
	vector<int> testCase1(naiveData1, naiveData1 + 6);
	int p1 = -3;
	int p2 = 5;
	int p3 = 6;
	int p4 = 9;
	int p5 = 15;
	cout << upperBound(testCase1, p1) << endl;
	cout << upperBound(testCase1, p2) << endl;
	cout << upperBound(testCase1, p3) << endl;
	cout << upperBound(testCase1, p4) << endl;
	cout << upperBound(testCase1, p5) << endl;
	return 0;
}