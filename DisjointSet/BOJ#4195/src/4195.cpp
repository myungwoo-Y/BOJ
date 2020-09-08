#include <bits/stdc++.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

using namespace std;

const char endL {'\n'};

struct DisjointSet{
    vector<int> parent;
    vector<int> counts;
    DisjointSet(int size): parent(size), counts(size, 1){
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    int merge(int a, int b){
        int parentA = find(a), parentB = find(b);
        if(parentA == parentB)
            return counts[parentA];
        else{
            if(counts[parentB] > counts[parentA]){
                counts[parentB] += counts[parentA];
                parent[parentA] = parentB;
                return counts[parentB];
            }else{
                counts[parentA] += counts[parentB];
                parent[parentB] = parentA;
                return counts[parentA];
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int testCase {};
    cin >> testCase;

    loop(testCase){
        int friendRelations {};
        cin >> friendRelations;
        int friendIdx {1};
        DisjointSet tree(friendRelations * 2 + 1);
        map<string, int> m;
        loop(friendRelations){
            string a, b;
            cin >> a >> b;

            if(m.count(a) == 0)
                m[a] = friendIdx++;
            if(m.count(b) == 0)
                m[b] = friendIdx++;
            int aIdx = m[a]-1;
            int bIdx = m[b]-1;
            cout << tree.merge(aIdx, bIdx) << endL;
        }
    }
    return 0;
}