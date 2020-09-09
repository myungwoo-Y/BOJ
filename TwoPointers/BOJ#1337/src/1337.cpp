#include <bits/stdc++.h>
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

vector<int> arr;
int n;
int maxN = 5;

int getCount(int l, int r){
    int diff = arr[r]-arr[l];
    if(l==r){
        return 4;
    }else if(diff > 4) {
        return diff;
    }else{
        return maxN - (r-l + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 0, r = 0;
    int ans = MAX;
    int sum = 0;
    while(true){
        if(r == n){
            break;
        }

        sum = getCount(l, r);
        if(sum >= maxN){
            l++;
        }else{
            r++;
        }
        ans = min(sum, ans);
    }

    cout << ans;

    return 0;
}


