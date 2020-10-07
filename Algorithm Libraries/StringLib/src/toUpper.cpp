#include <bits/stdc++.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
#include <cctype>
#include <algorithm>
#include <string>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    std::string a = "abcABC.,!";

    std::transform(a.begin(), a.end(), a.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    cout << a;

    return 0;
}


