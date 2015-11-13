#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder {
public:

    MedianFinder():count(0) {
    }

    // Adds a number into the data structure.
    void addNum(int num) {
       if(count % 2 == 0) {
           if(count == 0) {
               minHeapAtMiddleRight.push(num);
           } else if(num >= maxHeapAtMiddleLeft.top()) {
               minHeapAtMiddleRight.push(num);
           } else {
               minHeapAtMiddleRight.push(maxHeapAtMiddleLeft.top());
               maxHeapAtMiddleLeft.pop();
               maxHeapAtMiddleLeft.push(num);
           }
       } else {
           if(num <= minHeapAtMiddleRight.top()) {
               maxHeapAtMiddleLeft.push(num);
           } else {
               maxHeapAtMiddleLeft.push(minHeapAtMiddleRight.top());
               minHeapAtMiddleRight.pop();
               minHeapAtMiddleRight.push(num);
           }
       }
        count++;
    }

    // Returns the median of current data stream
    double findMedian() {
        if(count == 0)
            return -1;
        if(count % 2 == 0) {
            return (double)minHeapAtMiddleRight.top() / 2 + (double)maxHeapAtMiddleLeft.top() / 2;
        } else {
            return (double)minHeapAtMiddleRight.top();
        }
    }
private:
    priority_queue<int> maxHeapAtMiddleLeft;
    priority_queue<int, vector<int>, greater<int>> minHeapAtMiddleRight;
    int count;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
    MedianFinder testUnit;
    testUnit.addNum(1);
    cout << testUnit.findMedian() << endl;
    testUnit.addNum(2);
    cout << testUnit.findMedian() << endl;
    testUnit.addNum(3);
    cout << testUnit.findMedian() << endl;
    return 0;
}