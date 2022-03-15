// 308. Range Sum Query 2D - Mutable

class NumMatrix {
public:
    vector<vector<int>> tree;
    vector<vector<int>> m;
    int rows, cols;
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        tree = vector<vector<int>>(rows+1, vector<int>(cols+1));
        m = vector<vector<int>>(rows+1, vector<int>(cols+1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        if (!rows || !cols) return;
        
        int temp = m[row][col];
        int diff = val - temp;
        m[row][col] = val;

        for (int i = row+1; i <= rows; i += i & (-i)) {
            for (int j = col+1; j <= cols; j += j & (-j)) {
                tree[i][j] += diff;
            }
        }
    }

    int sum(int row, int col) {
        int sum = 0;

        for (int i = row+1; i > 0; i -= i & (-i)) {
            for (int j = col+1; j > 0; j -= j & (-j)) {
                sum += tree[i][j];
            }
        }

        return sum;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (!rows || !cols) return 0;
        
        return sum(row2, col2) + sum(row1-1, col1-1) - sum(row1-1, col2) - sum(row2, col1-1);
    }

};