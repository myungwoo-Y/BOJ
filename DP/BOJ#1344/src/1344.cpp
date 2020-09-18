#include <bits/stdc++.h>
#include <stdio.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int xssss = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}
const char endL = '\n';

using namespace std;

double dp[20][20][20];
double pa, pb;
int endPhase = 18;
vector<int> primeNumbers = {2,3,5,7,11,13,17};
double search(int aSum, int bSum, int phase){
    if(phase == 18){
        auto pointA = find(primeNumbers.begin(), primeNumbers.end(), aSum);
        auto pointB = find(primeNumbers.begin(), primeNumbers.end(), bSum);
        if(pointA != primeNumbers.end() || pointB != primeNumbers.end()){
            return 1.0;
        }else{
            return 0.0;
        }
    }
    double& ret = dp[aSum][bSum][phase];
    if(ret != -1){
        return ret;
    }

    ret = pa * (1-pb) * search(aSum+1, bSum, phase+1)
            + pb * (1-pa) * search(aSum, bSum+1, phase+1)
            + pa * pb * search(aSum+1, bSum+1, phase+1)
            + (1-pa) * (1-pb) * search(aSum, bSum, phase+1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    fill_n(&dp[0][0][0],sizeof(dp)/8, -1.f);
    int a {}, b {};
    cin >> a >> b;
    pa = a / (double)100;
    pb = b / (double)100;

    cout.precision(10);
    cout << fixed;
    cout << search(0, 0, 0);


    return 0;
}


