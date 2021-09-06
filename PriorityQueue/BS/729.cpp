// Rolling Median
class RollingMedian {
    public:

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    RollingMedian() {
        
    }

    void add(int val) {
        if(left.size() == 0){
            left.push(val);
        }else if(val > left.top()){
            right.push(val);
        }else{
            left.push(val);
        }
        
        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(right.size() > left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }

    double median() {
        if(left.size() > right.size()){
            return left.top();
        }else if(right.size() > left.size()){
            return right.top();
        }else{
            return (double)(left.top() + right.top())/2;
        }
    }
};