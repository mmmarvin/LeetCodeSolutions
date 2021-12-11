#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int negativeCount = 0;
        for(const auto& row : grid) {
            negativeCount += countNegativesInRow(row);
        }

        return negativeCount;
    }

private:
    int countNegativesInRow(const vector<int>& grid)
    {
        if(grid.empty())
            return 0;

        int floor = 0;
        int ceil = grid.size();
        int mid = (ceil + floor) / 2;

        cout << floor << ", " << ceil << endl;

        if(floor == ceil - 2) {
            auto v1 = grid[floor];
            auto v2 = grid[ceil - 1];

            if(v1 >= 0 && v2 < 0)
                return 1;
            else if(v1 < 0 && v2 < 0)
                return 2;

            return 0;
        }

        while(floor != ceil - 2) {
            cout << "CEIL: " << ceil << "FLOOR" << floor << endl;

            auto v1 = grid[mid];
            auto v2 = grid[mid + 1];

            if(v1 >= 0 && v2 < 0)
                return grid.size() - mid;

            if(v1 < 0 && v2 < 0) {

                ceil = mid;
            }

            if(v1 > 0 && v2 > 0)
                floor = mid;
        }

        return 0;
    }
};

int main()
{
    std::vector<std::vector<int>> v = 
    {
        { 4, 3, 2, -1 },
        { 3, 2, 1, 0},
        { 1, 1, 1, 0},
        { -1, -1, -2, -3 }
    };

    Solution sol;
    cout << sol.countNegatives(v) << endl;

    return 0;
}