// Find the Largest Number in a Rotated List

int solve(vector<int>& arr) {
    int l = 0, r = arr.size()-1;
    
    int ans = arr[r];
    
    while(l < r){
        ans = max(arr[l], arr[r]);
        int p = (l+r)/2;
        
        if(arr[l] < arr[r]){
            ans = arr[r];
            break;
        }else if(arr[l] > arr[r] && arr[l] >= arr[p]){
            r = p;
        }else if(arr[l] > arr[r] && arr[l] < arr[p]){
            ans = arr[p];
            l = p;
        }
    }
    
    return ans;
}