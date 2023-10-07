#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> res;
        for (auto x : intervals) {
            if (x.end >= newInterval.start && x.start <= newInterval.end) {
                newInterval.start = std::min(newInterval.start, x.start);
                newInterval.end = std::max(newInterval.end, x.end);
            }
        }
        for (auto x : intervals) {
            if (x.end < newInterval.start || x.start > newInterval.end) {
                res.push_back(x);
            }
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i].start > newInterval.start) {
                res.insert(res.begin() + i, newInterval);
                break;
            }
        }
        if (res.empty() || res.back().end < newInterval.start) {
            res.push_back(newInterval);
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<Interval> intervals = {
        {1, 3},
        {6, 9}
    };  // Example input vector of Interval objects

    Interval newInterval(2, 5);  // New Interval to insert

    std::vector<Interval> result = solution.insert(intervals, newInterval);

    std::cout << "Merged intervals: ";
    for (const Interval& interval : result) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;

    return 0;
}
