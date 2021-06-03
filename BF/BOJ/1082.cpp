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

int n;

struct Data{
    int num, money;
};

vector<Data> moneyList;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int totalMoney {};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int money {};
        cin >> money;
        moneyList.push_back({i, money});
    }

    cin >> totalMoney;

    sort(moneyList.begin(), moneyList.end(), [](Data& a, Data& b) -> bool{
        return a.money < b.money;
    });

    vector<Data> ans;

    Data cur = moneyList[0];
    if(moneyList.size() > 1 && cur.num == 0){
        Data next = moneyList[1];
        if(next.money <= totalMoney){
            ans.push_back(next);
            totalMoney -= next.money;
        }
    }

    while(totalMoney >= cur.money){
        ans.push_back(cur);
        totalMoney -= cur.money;
    }

    if(ans.size() == 0 || ans[0].num == 0){
        cout << 0;
        return 0;
    }

    for (int i = moneyList.size()-1; i >= 0; --i) {
        Data cur = moneyList[i];
        for (int j = 0; j < ans.size(); ++j) {
            if(cur.num < ans[j].num) continue;
            int diff = cur.money - ans[j].money;
            if(diff <= totalMoney){
                ans[j] = cur;
                totalMoney -= diff;
            }
        }
    }

    string result = "";

    for (int i = 0; i < ans.size(); ++i) {
        result += to_string(ans[i].num);
    }
    cout << result;


    return 0;
}


