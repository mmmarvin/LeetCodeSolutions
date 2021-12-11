#include <vector>


struct Interval
{
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    int start;
    int end;
};

class Solution {
public:
    typedef std::vector<Interval>                   IntervalContainerType;
    typedef std::vector<std::pair<Interval, int>>   IntervalIntPairContainerType;

    int eraseOverlapIntervals(const std::vector<Interval>& intervals)
    {
        if(intervals.size() == 0)
            return 0;

        int max_count = 0;
        IntervalIntPairContainerType temp_intervals;

        for(IntervalContainerType::const_iterator it = intervals.begin(), it_end = intervals.end(); it != it_end; ++it) {
            const Interval& interval = *it;

            int count = 0;
            if(hasCollision(temp_intervals, interval, max_count)) {
                count = 1;
            }

            temp_intervals.emplace_back(interval, count);
        }

        int num_ties = 0;
        if(max_count > 0) {
            for(IntervalIntPairContainerType::const_iterator it = temp_intervals.begin(), it_end = temp_intervals.end(); it != it_end; ++it) {
                const std::pair<Interval, int>& temp_interval = (*it);

                if(temp_interval.second == max_count) {
                    std::cout << "TIES: " << temp_interval.first.start << ", " << temp_interval.first.end << std::endl;
                    ++num_ties;
                }
            }
        }

        if(num_ties > 1 || num_ties == 0)
            return max_count;
        return max_count - 1;
    }

private:
    bool hasCollision(IntervalIntPairContainerType& intervals, const Interval& interval, int& max_count)
    {
        bool found = false;
        for(IntervalIntPairContainerType::iterator it = intervals.begin(), it_end = intervals.end(); it != it_end; ++it) {
            std::pair<Interval, int>& interval_int_pair = *it;

            int start = interval.start;
            int end = interval.end;
            int pair_start = interval_int_pair.first.start;
            int pair_end = interval_int_pair.first.end;

            if(pair_start == end || pair_end == start) {
                continue;
            } else
            if(((start >= pair_start && start < pair_end) || (end > pair_start && end <= pair_end)) ||
               ((pair_start >= start && pair_start < end) || (pair_end > start && pair_end <= end))) {
                int& count = interval_int_pair.second;
                ++count;
                max_count = std::max(max_count, count);


                std::cout << "[" << interval.start << ", " << interval.end << "] has collision with [" << pair_start << ", " << pair_end << "]!" << std::endl;

                found = true;
            }
        }

        return found;
    }
};

int main()
{

}
