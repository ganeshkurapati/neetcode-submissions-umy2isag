class FreqStack {
    unordered_map<int,int> count;
    unordered_map<int,stack<int>> stacks;
    int maxCount;
public:
    FreqStack() {
        maxCount = 0;
    }
    
    void push(int val) {
        int cnt = ++count[val];
        if(cnt>maxCount) {
            maxCount = cnt;
            stacks[cnt] = stack<int>();
        }
        stacks[cnt].push(val);
    }
    
    int pop() {
        int rc = stacks[maxCount].top();
        stacks[maxCount].pop();
        count[rc]--;
        if(stacks[maxCount].empty()) maxCount--;
        return rc;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */