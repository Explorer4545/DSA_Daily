// Qs-> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=daily-question&envId=2023-10-09

class Solution {
public:
    int first(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size()-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) {
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
    int last(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size()-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) {
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target), last(nums,target)};
    }
};