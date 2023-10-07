// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++)    //frequency array
        freq[s[i]-'a']++;
        // for(int i:freq)             //debugger for frequency array
        // cout<<i<<endl;
        string st;                        //string used as monotonic stack
        vector<bool> seen(26,false);     //track already included elements
        for(int i=0;i<s.size();++i){      
            if(seen[s[i]-'a']){            //dont process already included
                freq[s[i]-'a']--;
                continue;
            }
            while(!st.size()==0 and st.back()>s[i] and freq[st.back()-'a']>0){  //pop all possible larger elements
                seen[st.back()-'a']=false;
                st.pop_back();
            }
            st.push_back(s[i]);      //pushing elements in stack
            seen[s[i]-'a']=true;
            freq[s[i]-'a']--;
        }
        return st;
    } 
};
