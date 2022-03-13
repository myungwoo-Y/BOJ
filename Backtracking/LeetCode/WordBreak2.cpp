// 140. Word Break II

class Solution {
public:
    unordered_set<string> wordSet;
    vector<string> ansList;

    void findWord(int i, string& s, string subStr, vector<string>& ans) {
        if (i >= s.length()) {
            if (subStr == "" && i != 0) {
                string a = "";
                for (int i = 0; i < ans.size(); i++) {
                    a += ans[i];
                    if (i+1 < ans.size()) {
                        a += " ";
                    }
                }
                ansList.push_back(a);
            }
            return;
        }

        subStr += string(1, s[i]);

        if (wordSet.find(subStr) != wordSet.end()) {
            ans.push_back(subStr);
            findWord(i+1, s, "", ans);    
            ans.pop_back();
        }
        findWord(i+1, s, subStr, ans);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            wordSet.insert(word);
        }
        vector<string> ans;

        findWord(0, s, "", ans);

        return ansList;
    }
};
