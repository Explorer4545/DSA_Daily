//Qs->https://leetcode.com/contest/weekly-contest-366/problems/divisible-and-non-divisible-sums-difference/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sumnd=0;
        int sumd=0;
        for(int i=1;i<=n;i++){
            if(i%m==0) sumd+=i;
            else  sumnd+=i;
        }
        // cout<<sumd<<" "<<sumnd;          //debugger
        return sumnd-sumd;
    }
};