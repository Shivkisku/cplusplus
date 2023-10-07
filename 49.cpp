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
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) { return a.start < b.start; });
        std::vector<Interval> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty() || res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = std::max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<Interval> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };  // Example input vector of Interval objects

    std::vector<Interval> result = solution.merge(intervals);

    std::cout << "Merged intervals: ";
    for (const Interval& interval : result) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;

    return 0;
}
