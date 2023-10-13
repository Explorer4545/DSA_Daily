//  Qs -> https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefl(n);      //prefixvector
        vector<int> prefr(n);       //suffixvector
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){         //prefix
           prefl[i]=max(maxi,nums[i]);
           if(nums[i]>maxi)
           maxi=nums[i];
        }
        maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){         //suffix
           prefr[i]=max(maxi,nums[i]);
           if(nums[i]>maxi)
           maxi=nums[i];
        }
        long long maxi2=0;
        for(int i=1;i<n-1;i++){
          long long temp = (long long)(prefl[i-1]-nums[i])*prefr[i+1];
          maxi2=max(maxi2,temp);
        }
        // cout<<maxi2;                    //debugger
        return maxi2;
    }
};