#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        string path;
        removeInvalidParenthesesInternal(s, 0, 0, 0, path, result);
        return result;
    }

private:
    void removeInvalidParenthesesInternal(const string& s, int leftCount, int rightCount, int position, string& path, vector<string>& result) {
        // Final case handlement.
        if(position == s.size()) {
            if(leftCount == rightCount) {
                if(result.empty()) {
                    result.push_back(path);
                } else if(result[0].size() == path.size()) {
                    result.push_back(path);
                }
            }
            return;
        }
        // Give up the illegal path.
        if(leftCount < rightCount) {
            return;
        }
        // Main handlement
        if((s[position] != '(') && (s[position] != ')')) {
            // Always accept the non-parenttheses character
            path.push_back(s[position]);
            removeInvalidParenthesesInternal(s, leftCount, rightCount, position + 1, path, result);
            path.pop_back();
        } else if(s[position] == '(') {
            // Accept
            path.push_back(s[position]);
            removeInvalidParenthesesInternal(s, leftCount + 1, rightCount, position + 1, path, result);
            path.pop_back();

            // Reject
            int offset = 1;
            while(((position + offset) < s.size()) && (s[position + offset] == s[position])) {
                ++offset;
            }
            removeInvalidParenthesesInternal(s, leftCount, rightCount, position + offset, path, result);
        } else {
            // Accept
            if(leftCount > rightCount) {
                path.push_back(s[position]);
                removeInvalidParenthesesInternal(s, leftCount, rightCount + 1, position + 1, path, result);
                path.pop_back();
            }
            // Reject
            int offset = 1;
            while(((position + offset) < s.size()) && (s[position + offset] == s[position])) {
                ++offset;
            }
            removeInvalidParenthesesInternal(s, leftCount, rightCount, position + offset, path, result);
        }
        return;
    }
};

int main(){
    string testCase("(f");
    Solution testUnit;
    vector<string> result = testUnit.removeInvalidParentheses(testCase);
    for(auto iter = result.begin(); iter != result.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}