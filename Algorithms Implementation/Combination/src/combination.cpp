
void makeCombination(int n, int k){
    vector<int> elements;

    for(int i=0; i < n; i++){
        elements.push_back(i + 1);
    }
    vector<int> combination;

    for(int i=0; i<k; i++){
        combination.push_back(1);
    }

    for(int i=0; i < elements.size() - k; i++){
        combination.push_back(0);
    }

    sort(combination.begin(), combination.end());
    int ans = {MAX};
    do{
        // 고른원소 사용
        for(int i=0; i < combination.size(); i++){
            if(combination[i] == 1){
            }
        }

    }while(next_permutation(combination.begin(), combination.end()));

    cout << ans;
}


// 좌표에 대한 조합
vector<vector<pii>> makeCombination(){
    vector<pii> elements;
    int k = 2;

    for (int i = 1; i <= rowN; ++i) {
        for (int j = 1; j <= colN; ++j) {
            elements.push_back({i, j});
        }
    }

    vector<int> combination;

    for(int i=0; i<k; i++){
        combination.push_back(1);
    }

    for(int i=0; i < elements.size() - k; i++){
        combination.push_back(0);
    }

    vector<vector<pii>> ret;

    sort(combination.begin(), combination.end());
    do{
        vector<pii> temp;
        // 고른원소 사용
        for(int i=0; i < combination.size(); i++){
            if(combination[i] == 1){
                temp.push_back(elements[i]);
            }
        }

        ret.push_back(temp);

    }while(next_permutation(combination.begin(), combination.end()));

    return ret;
}
