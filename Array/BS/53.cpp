// Create Largest Number From a List
// https://binarysearch.com/problems/Create-Largest-Number-From-a-List
string solve(vector<int>& nums) {
    
    sort(nums.begin(), nums.end(), [](int& a, int& b) -> bool{
        string x = to_string(a);
        string y = to_string(b);
        
        string s;
        string l;
        
        bool switched = x.length() > y.length();
        
        if(switched){
            l = x;
            s = y;
        }else{
            s = x;
            l = y;
        }

        if(x[0] != y[0]){
            return x[0] > y[0];
        }else{
            if(s.length() == l.length())
                return a > b;
            else{
                if(l.length() - s.length() == 1){
                    for(int i = 0; i < l.length(); i++){
                        if(i >= s.length()){
                            if(s[0] != l[i])
                                return switched ? s[0] <= l[i] : s[0] > l[i];
                            else
                                return switched ? s[0] >= l[1] : s[0] < l[1];
                        }else{
                            if(s[i] != l[i])
                                return switched ? s[i] <= l[i] : s[i] > l[i];
                        }
                    }
                    return true;
                }else{
                    for(int i = 0; i < l.length(); i++){
                        if(i >= s.length()){
                            if(s[0] != l[i])
                                return switched ? s[0] <= l[i] : s[0] > l[i];
                        }else{
                            if(s[i] != l[i])
                                return switched ? s[i] <= l[i] : s[i] > l[i];
                        }
                    }
                    return true;
                }
            }
        }
    });
    
    string ret = "";
    for(auto n : nums)
        ret += to_string(n);
    
    return ret;
}