/**
 * 3ms solution to https://leetcode.com/problems/baseball-game
 * Faster than 100% Uses less memory than 100%
 * Marvin Manese
 **/

class Solution
{
public:
    int calPoints(vector<string>& ops)
    {
        int sum = 0;
        int lvx = -1;
        vector<int> v;
        v.reserve(20);

        for(string& str : ops) {
            if(str == "C") {
                int tv = v[lvx--];
                sum -= tv;
            } else if(str == "D") {
                int tv = v[lvx] * 2;
                addValue(v, tv, lvx);
                sum += tv;
            } else if(str == "+") {
                pair<int, int> lp = grabLast2(v, lvx);
                int tv = lp.first + lp.second;
                addValue(v, tv, lvx);
                sum += tv;
            } else {
                int num = stoi(str);
                addValue(v, num, lvx);
                sum += num;
            }
        }

        return sum;
    }

private:
    void addValue(vector<int>& v, int val, int& lvx)
    {
        if(++lvx >= v.size())
            v.push_back(val);
        else {
            v[lvx] = val;
        }
    }

    pair<int, int> grabLast2(vector<int>& v, int lvx)
    {
        return pair<int, int>(v[lvx], v[lvx - 1]);
    }
};
