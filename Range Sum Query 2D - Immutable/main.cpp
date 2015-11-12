#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        data.resize(matrix.size());
        for(int idx = 0; idx < matrix.size(); ++idx) {
            data[idx].resize(matrix[idx].size());
            if(idx == 0) {
                data[0][0] = matrix[0][0];
            } else {
                data[idx][0] = data[idx - 1][0] + matrix[idx][0];
            }
            for(int jdx = 1; jdx < matrix[idx].size(); ++jdx) {
                if(idx == 0) {
                    data[idx][jdx] = data[idx][jdx - 1] + matrix[idx][jdx];
                } else {
                    data[idx][jdx] = data[idx][jdx - 1] + data[idx - 1][jdx] - data[idx - 1][jdx - 1] + matrix[idx][jdx];
                }
            }
        }
        return;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int leftResidual = 0;
        int upResidual = 0;
        int leftUpResidual = 0;
        if(row1 > 0) {
            upResidual = data[row1 - 1][col2];
        }
        if(col1 > 0) {
            leftResidual = data[row2][col1 - 1];
        }
        if(row1 > 0 && col1 > 0) {
            leftUpResidual = data[row1 - 1][col1 - 1];
        }
        return data[row2][col2] - leftResidual - upResidual + leftUpResidual;
    }

private:
    vector<vector<int>> data;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main() {
    int row1[] = {3, 0, 1, 4, 2};
    int row2[] = {5, 6, 3, 2, 1};
    int row3[] = {1, 2, 0, 1, 5};
    int row4[] = {4, 1, 0, 1, 7};
    int row5[] = {1, 0, 3, 0, 5};
    vector<vector<int>> testData;
    testData.push_back(vector<int>(row1, row1 + 5));
    testData.push_back(vector<int>(row2, row2 + 5));
    testData.push_back(vector<int>(row3, row3 + 5));
    testData.push_back(vector<int>(row4, row4 + 5));
    testData.push_back(vector<int>(row5, row5 + 5));
    NumMatrix testUnit(testData);
    cout << testUnit.sumRegion(2, 1, 4, 3) << endl;
    cout << testUnit.sumRegion(1, 1, 2, 2) << endl;
    cout << testUnit.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}