/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        vector<Interval>::iterator it=intervals.begin();
        for(;it!=intervals.end();it++){
            if (newInterval.start<it->start){
                intervals.insert(it,newInterval);
                break;
                
            }
        }
        if(it==intervals.end()){
             intervals.insert(it,newInterval);
        }
        if(intervals.empty()){return result;}
        result.push_back(*intervals.begin());
        for(it=intervals.begin()+1;it!=intervals.end();it++){
            if(it->start>result.back().end){result.push_back(*it);}
            else{
                result.back().end=max((*it).end,result.back().end);
            }
        }
        return result;
    }
};