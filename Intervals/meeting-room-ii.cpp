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
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<pair<int,int>>events;
        for(auto &inter:intervals)
        {
            int st = inter.start;
            int en = inter.end;
            events.push_back({st,+1});
            events.push_back({en,-1});
        }
        sort(begin(events),end(events));
        int currRoom = 1;
        int maxRoom = 1;
        for(auto &e:events)
        {
            currRoom += e.second;
            maxRoom = max(maxRoom,currRoom);
        }
        return  maxRoom-1;
        
    }
};
