#include <bits/stdc++.h>
#include <queue>
#include <stdio.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}
const char endL = '\n';

using namespace std;

int diceN;
int dices[10001][6];
int diceSpaceN = 6;
vector<int> route = {5, 3, 4, 1, 2, 0};

int getMaxInDice(int excludeA, int excludeB){
    int maxValue = max(excludeA, excludeB);
    int minValue = min(excludeA, excludeB);
    return maxValue == 6 ? (minValue == 5 ? 4 : 5) : 6;
}

int getIdxInDiceByValue(int value, int diceIdx){
    for (int i = 0; i < diceSpaceN; ++i) {
        if(value == dices[diceIdx][i])
            return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> diceN;

    for (int i = 0; i < diceN; ++i) {
        for (int j = 0; j < diceSpaceN; ++j) {
            cin >> dices[i][j];
        }
    }
    int ans {};
    for (int i = 0; i < diceSpaceN; ++i) {
        int sum {};
        int curValue = dices[0][i];
        int nextValue = dices[0][route[i]];
        sum += getMaxInDice(curValue, nextValue);
        for (int diceIdx = 1; diceIdx < diceN; ++diceIdx) {
            int matchValue = nextValue;
            int matchedIdx = getIdxInDiceByValue(matchValue, diceIdx);
            nextValue = dices[diceIdx][route[matchedIdx]];
            sum += getMaxInDice(matchValue, nextValue);
        }
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}


