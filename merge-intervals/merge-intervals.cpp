class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {   
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <=  intervals[i - 1][1]){
                intervals[i][0] = intervals[i - 1][0];
                
                if(intervals[i - 1][1] > intervals[i][1])
                    intervals[i][1] = intervals[i - 1][1];
                    
                vector<vector<int>>::iterator it = intervals.begin() + i - 1;
                intervals.erase(it);
                i--;
            }
        }
        
        return intervals;
    }
};
