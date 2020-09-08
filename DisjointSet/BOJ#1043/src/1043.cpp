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

int personN, partyN, smartPersonN;

vector<vector<int>> parties;
vector<vector<int>> graph;
vector<int> smartPersons;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    cin >> personN >> partyN;

    cin >> smartPersonN;
    DisjointSet disjointSet(personN+1);
    for (int i = 0; i < smartPersonN; ++i) {
        int person = 0;
        cin >> person;;
        if(!smartPersons.empty())
            disjointSet.merge(smartPersons.front(), person);
        smartPersons.push_back(person);
    }

    int ans = 0;
    parties.resize(partyN);
    for (int i = 0; i < partyN; ++i) {
        int numberOfPersonInParty = 0;
        cin >> numberOfPersonInParty;
        bool isInSmartPerson = false;
        for (int j = 0; j < numberOfPersonInParty; ++j) {
            int person = 0;
            cin >> person;
            if(!parties[i].empty())
                disjointSet.merge(person, parties[i].front());
            parties[i].push_back(person);
        }
    }

    for(auto party: parties){
        if (smartPersons.empty () || party.empty() || disjointSet.find (party.front ()) != disjointSet.find (smartPersons.front ()))
            ans++;
    }

    cout << ans;

    return 0;
}


