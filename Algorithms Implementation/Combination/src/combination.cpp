
void makeCombination(int elementsSize){
    vector<int> elements;

    for(int i=0; i < elementsSize; i++){
        elements.push_back(i + 1);
    }

    vector<int> combination;

    int k = 2;

    for(int i=0; i<k; i++){
        combination.push_back(1);
    }

    for(int i=0; i < elements.size() - k; i++){
        combination.push_back(0);
    }

    sort(combination.begin(), combination.end());
    int ans = {MAX};
    do{
        vector<int> colorRows;
        for(int i=0; i < combination.size(); i++){
            if(combination[i] == 1){
                colorRows.push_back(i);
            }
        }
        int ret = changeCount(colorRows[0],colorRows[1]);
        ans = min(ans, ret);
    }while(next_permutation(combination.begin(), combination.end()));

    cout << ans;
}
