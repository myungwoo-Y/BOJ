class Solution {
public:
    string add(string num1, string num2) {
        // l > r
        string l = num1.length() > num2.length() ? num1 : num2;
        string r = num1.length() > num2.length() ? num2 : num1;
        string sum = "";
        
        int p = 0;
        for (int i = 0; i < r.length(); i++) {
            int subSum = l[l.length()-i-1] - '0' + r[r.length()-i-1] - '0' + p;
            p = subSum/10;
            sum = string(1, subSum%10 + '0') + sum;
        }
        
        for (int j = l.length()-r.length()-1; j >= 0; j--) {
            int subSum = l[j] - '0' + p;
            p = subSum/10;
            sum = string(1, subSum%10 + '0') + sum;
        }
        
        if (p != 0) {
            sum = string(1, p  + '0') + sum;
        }
        
        return sum;
    }
    
    string multiply(string num1, string num2) {
        // l > r
        string l = num1.length() > num2.length() ? num1 : num2;
        string r = num1.length() > num2.length() ? num2 : num1;
        
        string sum = "0";
        
        for (int i = r.length()-1; i >= 0; i--) {
            int a = r[i] - '0';
            if (a == 0) continue;
            string subSum = "";
            int p = 0;
            for (int j = l.length()-1; j >= 0; j--) {
                int b = l[j] - '0';
                if (b == 0) {
                    subSum = string(1, p + '0') + subSum;
                    p = 0;
                } else {
                    int s = a*b + p;
                    p = s/10;
                    subSum = string(1, s%10 + '0') + subSum;         
                }
            }
            
            if (p != 0) {
                subSum = string(1, p + '0') + subSum;
            }
            
            // add zero
            for (int k = r.length()-1; k > i; k--) {
                subSum = subSum + "0";
            }

            sum = add(sum, subSum);
        }
        
        return sum;
    }
};