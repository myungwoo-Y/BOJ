// 759. Employee Free Time
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> intervals, freeTimes;

        for (int i = 0; i < schedule.size(); i++) {
            auto& curIntervals = schedule[i];
            for (int j = 0; j < curIntervals.size(); j++) {
                intervals.push_back(curIntervals[j]);
            }
        }

        sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) -> bool{
            return l.start < r.start;
        });

        int time = intervals[0].start;

        for (auto& interval : intervals) {
            if (time < interval.start) {
                freeTimes.push_back({time, interval.start});
                time = interval.end;
            } else if (time >= interval.start && time < interval.end) {
                time = interval.end;
            }
        }
        
        return freeTimes;
    }
};