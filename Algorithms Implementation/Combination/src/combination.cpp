
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
