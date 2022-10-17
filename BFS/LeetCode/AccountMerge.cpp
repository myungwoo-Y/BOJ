// 721. Accounts Merge

class Solution {
public:
    bool isConnected(unordered_set<string>& emailSet, vector<string>& emails) {
        for (int i = 1; i < emails.size(); i++) {
            if (emailSet.find(emails[i]) != emailSet.end()) {
                return true;
            }
        }
        
        return false;
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ret;
        
        vector<vector<int>> graph(accounts.size());
        vector<unordered_set<string>> emailSets;
        vector<bool> visited(accounts.size());
        
        for (auto& account : accounts) {
            unordered_set<string> emailSet(account.begin()+1, account.end());
            emailSets.push_back(emailSet);
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = i+1; j < accounts.size(); j++) {
                if (isConnected(emailSets[i], accounts[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            if (visited[i]) continue;
            queue<int> q;
            unordered_set<string> emailSet;
            string name = accounts[i][0];
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                
                for (int next : graph[cur]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
                
                for (int j = 1; j < accounts[cur].size(); j++) {
                    emailSet.insert(accounts[cur][j]);
                }
                
            }
            
            vector<string> newAccount(emailSet.begin(), emailSet.end());
            sort(newAccount.begin(), newAccount.end());
            newAccount.insert(newAccount.begin(), name);
            ret.push_back(newAccount);
        }
        
        return ret;
    }
};