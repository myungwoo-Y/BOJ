// 465. Optimal Account Balancing

class Solution {
public:
    const int N = 21;
    int minTime = INT_MAX;
    void search(int target, int n, int t, vector<int>& debts, vector<int>& incomes) {
        if (t >= minTime) return;

        for (int i = 0; i < incomes.size(); i++) {
            int nextN = n;
            int prevDebt = debts[target], prevIncome = incomes[i];
            if (incomes[i] == 0) continue;
    
            // settle the balance
            if (debts[target] + incomes[i] >= 0) {
                incomes[i] += debts[target]; 
                debts[target] = 0;
                nextN++;
            } else {
                debts[target] += incomes[i];
                incomes[i] = 0;
            }

            if (nextN == debts.size()) {
                debts[target] = prevDebt;
                incomes[i] = prevIncome;
                minTime = min(minTime, t+1);
                return;
            } else {
                for (int j = target; j < debts.size(); j++) {
                    if (debts[j] < 0) {
                        search(j, nextN, t+1, debts, incomes);
                    }
                }
            }
            
            debts[target] = prevDebt;
            incomes[i] = prevIncome;
        }
    }

    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> debts, incomes;

        vector<int> balances(N);

        for (auto& transaction : transactions) {
            balances[transaction[0]] -= transaction[2];
            balances[transaction[1]] += transaction[2];
        }

        for (int i = 0; i < N; i++) {
            if (balances[i] > 0) {
                incomes.push_back(balances[i]);
            } else if (balances[i] < 0) {
                debts.push_back(balances[i]);
            }
        }

        if (debts.size() == 0) return 0;

        int ret = INT_MAX;

        for (int i = 0; i < debts.size(); i++) {
            search(i, 0, 0, debts, incomes);
        }

        return minTime;
    }
};