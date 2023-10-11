// Qs-> https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/?envType=daily-question&envId=2023-10-11

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(),flowers.end());
        vector<int> ans;
        int n=flowers.size();
        vector<int> start;
        vector<int> end;
        for(auto i: flowers){
            start.push_back(i[0]);
            end.push_back(i[1]+1);
        }
        int n1=start.size();
        int n2=end.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(auto p : people){
            // int s=0,e=n1-1;
            // int mid;
            // while(s<e){
            //      mid=(s+e)/2;
            //     if(start[mid]<=i ){
            //         s=mid+1;
            //     }
            //     else 
            //     e=mid;
            // }
            // int s1=0,e1=n2-1;
            // int mid1;
            // while(s1<e1){
            //     mid1=(s1+e1)/2;
            //     if(end[mid1]<=i){
            //         s1=mid1+1;
            //     }
            //     else 
            //     e1=mid1;
            // }
            // if(start[s]==i){
            //     s=s+1;
            // }
            // if(end[s1]==i){
            //     s1=s1+1;
            // }
            // cout<<s<<" "<<e<<endl;
            // cout<<s1<<" "<<e1<<endl;
            // if(start[e]>i)
            // s=e;
            // if(end[e1]>i)
            // s1=e1;
            int s=upper_bound(start.begin(),start.end(),p)-start.begin();
            int s1=upper_bound(end.begin(), end.end(),p) - end.begin();
            ans.push_back(s-s1);
        }
        return ans;
    }
};



class Solution1 {       //bruteforce TLE
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> map1;
        cout<<flowers[0][0];
        for(int i=0;i<flowers.size();i++){
            int first=flowers[i][0];
            int second=flowers[i][1];
            for(int j=first;j<=second;j++){
                map1[j]++;
            }
        }
        vector<int> ans;
        for(auto i:people){
            int con=map1[i];
            ans.push_back(con);
        }
        return ans;
    }
};

class Solution2 {        //did not work 
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(),flowers.end());
        vector<int> ans;
        int n=flowers.size();
        int p=0;
        for(auto i :people){
            int s=0,e=n-1;
            // int tar=people[p++];
            while(s<e){
                int mid=(s+e)/2;
                if(flowers[mid][0]<=i && flowers[mid][1]>=i){
                    s=mid+1;
                }
                else if(flowers[mid][0]>i)
                e=mid-1;
                else if(flowers[mid][0]<i && flowers[mid][1]<i)
                s=mid+1;
            }
            if(flowers[s][0]<=i){
                ans.push_back(s+1);
            }
            else
            ans.push_back(s);
        }
        return ans;
    }
};

