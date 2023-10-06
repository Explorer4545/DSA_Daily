//Qs-> https://leetcode.com/problems/majority-element-ii/description/?envType=daily-question&envId=2023-10-05

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int me;
        int me1;
        int c=0,c1=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
               if(nums[i]==me){
                c++;
            }
              else if(nums[i]==me1){
                c1++;
            }
            else if(c==0){
                me=nums[i];
                c=1;
            }
            else if(c1==0){
                me1=nums[i];
                c1=1;
            }
            else{
                c--;
                c1--;
            }
        }
            int life=0,life1=0;
            for(auto i:nums){
                if(i==me) life++;
                if(i==me1) life1++;
            }
            if(life>n/3)
            ans.push_back(me);
            if(life1>n/3)
            ans.push_back(me1);
        return ans;
    }
};