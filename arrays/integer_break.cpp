//Qs-> https://leetcode.com/problems/integer-break/description/?envType=daily-question&envId=2023-10-06

class Solution {
public:
    int ans=1;
    int integerBreak(int n) {
        if(n==4)
        return n;
        int calc;
        if(n>4){
        if(n%3==0){
        calc=n/3;
        return pow(3,calc);
        }
        else if(n%3==1){
            calc=n/3;
            calc-=1;
            return 4*pow(3,calc);
        }
        else{
            calc=n/3;
            return 2*pow(3,calc);
        }
        }
        return n-1;
    }
};