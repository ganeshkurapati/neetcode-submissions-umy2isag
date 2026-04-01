class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = height[left], right_max = height[right];
        int rc = 0;
        while(left<right){
            if(left_max<right_max){
                left++;
                left_max = max(left_max, height[left]);
                rc += left_max - height[left];
            }else{
                right--;
                right_max = max(right_max, height[right]);
                rc += right_max - height[right];
            }
        }
        return rc;
    }
};
