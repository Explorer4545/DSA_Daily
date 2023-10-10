// QS-> https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

//solution
class Solution {        //using binary search
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> set1(nums.begin(),nums.end());
        // sort(nums.begin(),nums.end());
        int n1=set1.size();
        nums.clear();
        for(auto i: set1){
            nums.push_back(i);
        }
        int ans=n;
        int i=0;
        while(i<n){
        int s=i+1,e=n1-1;
        int target=nums[i]+n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
            ans=min(ans,n-(mid-i+1));
            break;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
        }
        ans = min(ans, n-(s-i+1)+1);
        i++;
        }
      return ans;  
    }
};


 
class Solution1 {            // using sliding window 
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOperations =n;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] < nums[i] + n) {
                j++;
            }

            minOperations = min(minOperations, n - (j - i));
        }

        return minOperations;        
    }
};

