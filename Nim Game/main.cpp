#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return (n & 3);
    }
};

int main() {
    Solution testUnit;
    cout << testUnit.canWinNim(5) << endl;
    return 0;
}