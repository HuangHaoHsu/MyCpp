#include <iostream>
#include <set>

using namespace std;

class MedianFinder {
public:

    MedianFinder():count(0) {
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if(count % 2 == 0) {
            if(count == 0) {
                numsAtMiddleRight.insert(num);
            } else {
                if(num >= (*numsAtMiddleLeft.begin())) {
                    numsAtMiddleRight.insert(num);
                } else {
                    numsAtMiddleRight.insert(*numsAtMiddleLeft.begin());
                    numsAtMiddleLeft.erase(numsAtMiddleLeft.begin());
                    numsAtMiddleLeft.insert(num);
                }
            }
        } else {
            if(num <= (*numsAtMiddleRight.begin())) {
                numsAtMiddleLeft.insert(num);
            } else {
                numsAtMiddleLeft.insert(*numsAtMiddleRight.begin());
                numsAtMiddleRight.erase(numsAtMiddleRight.begin());
                numsAtMiddleRight.insert(num);
            }
        }
        ++count;
    }

    // Returns the median of current data stream
    double findMedian() {
        if(count % 2 == 0) {
            return (*numsAtMiddleRight.begin()) / 2.0 + (*numsAtMiddleLeft.begin()) / 2.0;
        } else {
            return *numsAtMiddleRight.begin();
        }
    }
private:
    multiset<int, less<int>>    numsAtMiddleRight;
    multiset<int, greater<int>> numsAtMiddleLeft;
    int count;
};

int main() {
    MedianFinder testUnit;
    testUnit.addNum(1);
    cout << testUnit.findMedian() << endl;
    testUnit.addNum(3);
    cout << testUnit.findMedian() << endl;
    testUnit.addNum(2);
    cout << testUnit.findMedian() << endl;
    return 0;
}