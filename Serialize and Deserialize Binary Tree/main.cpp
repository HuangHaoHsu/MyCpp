#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> inputBuffer;
        inputBuffer.push(root);
        while(!inputBuffer.empty()){
            TreeNode* cur = inputBuffer.front();
            inputBuffer.pop();
            if(cur == NULL) {
                result.append("n,");
            } else {
                inputBuffer.push(cur->left);
                inputBuffer.push(cur->right);
                ostringstream convertWorker;
                convertWorker << cur -> val << ',';
                result.append(convertWorker.str());
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> result;
        unsafeSplit(result, data, ",");
        if((result.size() == 0) || (result[0] == "n"))
            return NULL;
        stringstream revertWorker(result[0]);
        int val;
        revertWorker >> val;
        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> processBuffer;
        processBuffer.push(root);
        revertWorker.clear();
        int offset = 1;
        while((!processBuffer.empty()) && (offset < result.size())) {
            TreeNode* cur = processBuffer.front();
            processBuffer.pop();
            if(result[offset] == "n") {
                cur -> left = NULL;
            } else {
                stringstream revertWorkerLeft(result[offset]);
                revertWorkerLeft >> val;
                TreeNode* tmpNode = new TreeNode(val);
                cur->left = tmpNode;
                processBuffer.push(tmpNode);
            }
            if(result[offset + 1] == "n") {
                cur -> right = NULL;
            } else {
                stringstream revertWorkerRight(result[offset + 1]);
                revertWorkerRight >> val;
                TreeNode* tmpNode = new TreeNode(val);
                cur->right = tmpNode;
                processBuffer.push(tmpNode);
            }
            offset += 2;
        }
        return root;
    }

private:
    void unsafeSplit(vector<string>& tokens, string& data, const string& delimiter) {
        string::size_type nowOffset = 0;
        while(nowOffset < data.size()) {
            string::size_type curEnd = data.find(delimiter, nowOffset);
            if(curEnd != string::npos) {
                tokens.push_back(data.substr(nowOffset, curEnd - nowOffset));
                nowOffset = curEnd + 1;
            } else {
                break;
            }
        }
        return;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec testUnit;
    TreeNode* root = new TreeNode(0);
    TreeNode* right = new TreeNode(2);
    root->right = right;
    string serializedTree = testUnit.serialize(root);
    cout << serializedTree << endl;
    TreeNode* result = testUnit.deserialize(serializedTree);
    return 0;
}