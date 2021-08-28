// Dictionary Nomad
struct Node{
    string word;
    int cnt;
};


int solve(vector<string>& dictionary, string start, string end) {

    unordered_set<string> s(dictionary.begin(), dictionary.end());
    
    queue<Node> q;
    q.push({start, 1});
    
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        
        if(node.word == end)
            return node.cnt;
        
        string word = node.word;
        for(int i = 0; i < word.length(); i++){
            for(int c = 'a'; c <= 'z'; c++){
                string nextWord = word;
                nextWord[i] = c;
                if(s.find(nextWord) != s.end()){
                    s.erase(nextWord);
                    q.push({nextWord, node.cnt+1});
                }
            }
        }
    }
    
    return -1;
}