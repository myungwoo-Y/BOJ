#include <bits/stdc++.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

using namespace std;

int rowSize, colSize;
vector<vector<char>> arr;
int changeCount(int firstLine, int secondLine){
    // 구할수 없는 경우
    if(secondLine - firstLine < 2)
        return MAX;

    int cnt {};
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            if(i <= firstLine){
                if(arr[i][j] != 'W') cnt++;
            }else if(firstLine < i && i < secondLine){
                if(arr[i][j] != 'B') cnt++;
            }else{
                if(arr[i][j] != 'R') cnt++;
            }
        }
    }
    return cnt;
}

void makeCombination(int elementsSize){
    vector<int> elements;

    for(int i=0; i < elementsSize; i++){
        elements.push_back(i + 1);
    }

    vector<int> combination;

    int k = 2;

    for(int i=0; i<k; i++){
        combination.push_back(1);
    }

    for(int i=0; i < elements.size() - k; i++){
        combination.push_back(0);
    }

    sort(combination.begin(), combination.end());
    int ans = {MAX};
    do{
        vector<int> colorRows;
        for(int i=0; i < combination.size(); i++){
            if(combination[i] == 1){
                colorRows.push_back(i);
            }
        }
        int ret = changeCount(colorRows[0],colorRows[1]);
        ans = min(ans, ret);
    }while(next_permutation(combination.begin(), combination.end()));

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> rowSize >> colSize;
    arr.resize(rowSize, vector<char>(colSize));

    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            cin >> arr[i][j];
        }
    }
    makeCombination(rowSize);
    return 0;
}