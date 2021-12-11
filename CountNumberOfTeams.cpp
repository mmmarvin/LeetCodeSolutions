/**
 * Solution to https://leetcode.com/problems/count-number-of-teams/
 **/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt =  0;
        for(size_t i = 0; i < rating.size() - 2; ++i) {
            for(size_t j = i + 1; j < rating.size() - 1; ++j) {
                for(size_t k = j + 1; k < rating.size(); ++k) {     
                    if((rating[i] < rating[j] && rating[j] < rating[k]) ||
                       (rating[i] > rating[j] && rating[j] > rating[k])) {
                        ++cnt;
                    }
                }
            }
        }
        
        return cnt;
    }
};
