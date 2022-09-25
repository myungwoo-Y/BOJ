class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int totalLength = 0;
        bool isAddMid = false;
        unordered_map<string, int> palins;
        
        for (string& word : words) {
            if (palins.find(word) != palins.end() && palins[word] > 0) {
                totalLength += 4;
                palins[word]--;
            } else {
                string reversedWord(word);
                reverse(reversedWord.begin(), reversedWord.end());
                palins[reversedWord]++;
            }
        }
        
        for (auto pair : palins) {
            if (pair.second > 0 && pair.first[0] == pair.first[1]) {
                totalLength += 2;
                break;
            }
        }
        
        return totalLength;
    }
};