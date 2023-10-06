//Qs-> https://leetcode.com/problems/sum-of-beauty-in-the-array/description/

#include<bits/stdc++.h>
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        int score=0;
        vector<int> l(n);
        vector<int> r(n);
        int mini=INT_MIN;
        for(int i=0;i<n;i++){   //max element prefix
            mini=max(mini,nums[i]);
            l[i]=mini;
        }
        int maxi=INT_MAX;
        for(int i=n-1;i>=0;i--){     //min element suffix
           maxi=min(maxi,nums[i]);
           r[i]=maxi;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>l[i-1] && nums[i]<r[i+1]){
                score+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                score+=1;
            }
        }
        return score;
    }
};