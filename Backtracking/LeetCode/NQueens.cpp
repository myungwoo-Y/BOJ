// Title : N-Queens

// TimeComplexity : O(N!)

// start from row 0
// when place a queen, add col and diagonal info to sets 
// then move onto the next row with parameter row+1, col set and diagonal set

class Solution {
public:

    vector<vector<string>> ans;
    int N;

    void search(int r, int cnt, unordered_set<int>& colSet, unordered_set<int>& diaRightSet, unordered_set<int>& diaLeftSet, vector<string>& subAns){
        
        if(cnt == N){
            ans.push_back(subAns);
            return;
        }else if(r >= N){
            return;
        }
        
        for(int c = 0; c < N; c++){
            int diaDiffVal = r-c;
            int diaAddVal = r+c;
            if(colSet.find(c) == colSet.end()
               && diaRightSet.find(diaDiffVal) == diaRightSet.end()
               && diaLeftSet.find(diaAddVal) == diaLeftSet.end()){
                subAns.push_back(string(N, '.').replace(c, 1, "Q"));
                colSet.insert(c);
                diaRightSet.insert(diaDiffVal);
                diaLeftSet.insert(diaAddVal);
                search(r+1, cnt+1, colSet, diaRightSet, diaLeftSet, subAns);
                colSet.erase(c);
                diaRightSet.erase(diaDiffVal);
                diaLeftSet.erase(diaAddVal);
                subAns.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        unordered_set<int> colSet;
        unordered_set<int> diaRightSet;
        unordered_set<int> diaLeftSet;
        vector<string> subAns;
        N = n;
        
        search(0, 0, colSet, diaRightSet, diaLeftSet, subAns);

        return ans;
    }
};