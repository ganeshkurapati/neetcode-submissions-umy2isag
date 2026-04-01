class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sum_of_squares(n);
        while(slow!=fast){
            slow = sum_of_squares(slow);
            fast = sum_of_squares(sum_of_squares(fast));
        }
        return fast==1;
    }
private:
    int sum_of_squares(int n){
        int rc = 0;
        while(n!=0){
            rc += (n%10) * (n%10);
            n /= 10; 
        }
        return rc;
    }
};
