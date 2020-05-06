void combination(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> rowSize >> colSize;

    int elementsSize = rowSize;
    vector<int> elements;

    for(int i=0; i < elementsSize; i++){
        elements.push_back(i + 1);
    }

    vector<int> combination;

    int k = 3;

    for(int i=0; i<k; i++){
        combination.push_back(1);
    }

    for(int i=0; i < elements.size() - k; i++){
        combination.push_back(0);
    }

    sort(combination.begin(), combination.end());

    do{
        for(int i=0; i < combination.size(); i++){
            if(combination[i] == 1){
                printf("%d ", elements[i]);
            }
        }

    }while(next_permutation(combination.begin(), combination.end()));

    return 0;
}