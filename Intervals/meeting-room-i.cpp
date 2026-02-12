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
        vector<pair<int,int>>events;
        for(auto &inter:intervals)
        {
            int st = inter.start;
            int en = inter.end;
            events.push_back({st,+1});
            events.push_back({en,-1});
        }
        sort(begin(events),end(events));

        int count =0;
        int maxCount =0;
        for(auto &e:events)
        {
            count+=e.second;
            if(count>maxCount)
            {
                maxCount = count;
            }
        }
        return maxCount>1?false:true;
    }
};
