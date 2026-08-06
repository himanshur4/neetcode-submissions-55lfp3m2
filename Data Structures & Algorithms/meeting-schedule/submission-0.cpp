/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int,int>mp;
        for(Interval &i:intervals){
           mp[i.start]++;
           mp[i.end]--;
           
        }
        int ct=0;
        for(auto&[k,v]:mp){
            ct+=v;
            if(ct>1|| ct<0) return false;
        }
        return true;
    }
};
