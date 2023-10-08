//QS->https://leetcode.com/contest/weekly-contest-366/problems/minimum-processing-time/

//solution code:

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        cout<<tasks[0];
        int time=0;
        int i=3;
        int j=0;
        while(j<processorTime.size()){
            int temp=time;
            time=max((processorTime[j]+tasks[i-0]),(processorTime[j]+tasks[i-1]));
            time=max((processorTime[j]+tasks[i-2]),(processorTime[j]+tasks[i-3]));
            time=max(temp,time);
            j++;
            i+=4;
        }
        return time;
    }
};