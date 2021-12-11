#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution1
{
public:
    bool isMatch(string s, string p)
    {
        static const char ANY = '.';
        static const char FOR_N = '*';

        // edge cases
        if(p.empty())
            return true;
        if(s.empty() && !p.empty())
            return false;

        decltype(s.size()) i = 0, j = 0;
        decltype(s.size()) i_size = p.size(), j_size = s.size();
        for(; i < i_size; ++i) {
            auto pc1 = p[i];
            auto i1 = i + 1;

            // check if there is a proceding character
            if(i1 < i_size) {
                auto pc2 = p[i1];

                // if the preceding character is an *, get the next terminating character
                if(pc2 == FOR_N) {
                    i = i1;
                    auto i2 =  i + 1;

                    // traverse the string  until the terminating character is found
                    if(i2 < i_size) {
                        i = i2;
                        auto terminatingChar = p[i2];

                        if(pc1 == ANY) {
                            bool foundTerminatingChar = false;

                            while(j < j_size && !foundTerminatingChar) {
                                auto sj = s[j++];
                                if(sj == terminatingChar)
                                    foundTerminatingChar = true;
                            }
                            if(!foundTerminatingChar)
                                return false;
                        } else {
                            bool foundTerminatingChar = false;
                            bool foundFirstInstance = false;
                            auto originalJ = j;

                            while(j < j_size && !foundTerminatingChar) {
                                auto sj = s[j++];
                                if(!foundFirstInstance && sj == pc1)
                                    foundFirstInstance = true;
                                else if(sj == terminatingChar) {
                                    foundTerminatingChar = true;
                                    if(!foundFirstInstance) {
                                        j = originalJ;
                                        i = i1;
                                    }
                                } else if(sj != pc1) {
                                    if(terminatingChar == ANY) {
                                        foundTerminatingChar = true;
                                        break;
                                    } else if(!foundFirstInstance) {
                                        j = originalJ;
                                        i = i1;
                                        break;
                                    }

                                    return false;
                                }
                            }

                            if(!foundTerminatingChar && foundFirstInstance)
                                return false;
                        }
                    } else {
                        // if there is no terminating character, the patter of the string must be pc* till end
                        while(j < j_size && (pc1 == ANY || s[j] == pc1))
                            ++j;
                    }
                } else {
                    if(j >= j_size)
                        return false;
                    auto sj = s[j++];
                    if(pc1 != ANY && sj != pc1)
                        return false;
                }
            // if there is no preceding character it is the last character
            } else {
                if(j >= j_size)
                    return false;
                auto sj = s[j++];
                if(pc1 != ANY && sj != pc1)
                    return false;
            }
        }

        return j == j_size;
    }
};

class Solution2
{
public:
    int romanToInt(string s)
    {
        static const unordered_map<char, int> ROMAN_TO_INT_TABLE =
        {
            { 'I',  1 },
            { 'V',  5 },
            { 'X',  10 },
            { 'L',  50 },
            { 'C',  100 },
            { 'D',  500 },
            { 'M',  1000 },
        };

        static const unordered_map<char, unordered_map<char, int>> ROMAN_EDGE_CASES_TO_INT_TABLE =
        {
            { 'I', { { 'V', 4 }, { 'X', 9 } } },
            { 'X', { { 'L', 40 }, { 'C', 90 } } },
            { 'C', { { 'D', 400 }, { 'M', 900 } } },
        };


        int ret = 0;
        for(decltype(s.size()) i = 0, i_size = s.size(); i < i_size; ++i) {
            auto c1 = s[i];

            // check for edge cases first
            auto it1 = ROMAN_EDGE_CASES_TO_INT_TABLE.find(c1);
            if(it1 != ROMAN_EDGE_CASES_TO_INT_TABLE.end()) {
                auto i1 = i + 1;
                if(i1 < i_size) {
                    const auto& it_r = (*it1).second;
                    auto c2 = s[i1];
                    auto it2 = it_r.find(c2);
                    if(it2 != it_r.end()) {
                        ++i;
                        ret += (*it2).second;
                        continue;
                    }
                }
            }

            auto jt = ROMAN_TO_INT_TABLE.find(c1);
            if(jt != ROMAN_TO_INT_TABLE.end()) {
                ret += (*jt).second;
            }
        }

        return ret;
    }
};

class Solution3
{
public:
    int numUniqueEmails(vector<string>& emails)
    {
        set<string> emailSet;

        for(const auto& s : emails) {
            // strip the '.' and +
            auto ss = stripEverything(s);
            emailSet.insert(ss);
        }

        return emailSet.size();
    }

private:
    string stripEverything(const string& s)
    {
        string ret = "";
        bool foundAt = false;
        bool foundPlus = false;

        for(char c : s) {
            if(!foundAt) {
                if(c == '@')
                    foundAt = true;
                else if(foundPlus)
                    continue;
                else if(c == '.')
                    continue;
                else if(c == '+') {
                    foundPlus = true;
                    continue;
                }

                ret += c;
            } else {
                ret += c;
            }
        }

        return ret;
    }
};

class Solution4 {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;

        for(int i = left; i <= right; ++i) {
            bool err = false;
            auto itemp = i;
            while(itemp && !err) {
                auto j = itemp % 10;
                if(j == 0 || i % j != 0)
                    err = true;
                itemp /= 10;
            }

            if(!err)
                ret.push_back(i);
        }

        return ret;
    }
};

class Solution5 {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        static const map<char, string> LETTER_TO_MORSE =
        {
            { 'a', ".-" },
            { 'b', "-..." },
            { 'c', "-.-." },
            { 'd', "-.." },
            { 'e', "." },
            { 'f', "..-." },
            { 'g', "--." },
            { 'h', "...." },
            { 'i', ".." },
            { 'j', ".---" },
            { 'k', "-.-" },
            { 'l', ".-.." },
            { 'm', "--" },
            { 'n', "-." },
            { 'o', "---" },
            { 'p', ".--." },
            { 'q', "--.-" },
            { 'r', ".-." },
            { 's', "..." },
            { 't', "-" },
            { 'u', "..-" },
            { 'v', "...-" },
            { 'w', ".--" },
            { 'x', "-..-" },
            { 'y', "-.--" },
            { 'z', "--.." }
        };

        set<string> unique_transformations;
        for(const auto& str : words) {
            string tstr = "";
            for(char c : str) {
                auto it = LETTER_TO_MORSE.find(c);
                if(it != LETTER_TO_MORSE.end())
                    tstr.append((*it).second);
            }

            unique_transformations.insert(tstr);
        }

        return unique_transformations.size();
    }
};

class Solution6 {
public:
    int repeatedNTimes(vector<int>& A)
    {
        set<int> unique_letters;
        int r = 0;
        for(auto n : A) {
            auto it = unique_letters.find(n);
            if(it != unique_letters.end())
                unique_letters.insert(n);
            else {
                r = (*it);
            }

        }

        return r;
    }
};

class Solution8 {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        jewels.insert(J.begin(), J.end());

        int ret = 0;
        for(auto c : S) {
            auto it = jewels.find(c);
            if(it != jewels.end())
                ++ret;
        }

        return ret;
    }
};

class Solution7 {
public:
    int hammingWeight(std::uint32_t n) {
        int count = 0;
        std::size_t ns = sizeof(n);
        std::size_t nsh = 0;

        while(nsh < ns) {
            // shift the value nsh amount of bits
            n = n >> nsh;

            // grab first 8 bits
            unsigned char f8b = n;

            // count how many 1s
            unsigned char m = 0x1;
            while(m) {
                // mask the bits, and determine if the value is anything
                // but 0
                if(m & f8b)
                    ++count;

                // shift by 1 bit
                m = m << 1;
            }

            // increment by 8 bits
            nsh += 8;
        }

        return count;
    }
};

class Solution {
public:
    bool exist(const vector<vector<char>>& board, string word) {
        static const vector<pair<int, int>> paths =
        {
                        {0, -1},
            {-1, 0},				{1, 0},
                        {0, 1}
        };

        vector<bool> marked(board.size() ? board.size() + board[0].size() : 0, false);

        auto fl = word[0];
        for(auto i = 0ul, isize = board.size(); i < isize; ++i) {
            const auto& bv = board[i];
            for(auto j = 0ul, jsize = bv.size(); j < jsize; ++j) {
                auto bc = bv[j];
                if(fl == bc) {
                    if(word.size() > 1) {
                        queue<tuple<int, int, int>> q;

                        marked[i * isize + j] = true;
                        q.push({i, j, 1});
                        while(!q.empty()) {
                            auto t = q.front();
                            q.pop();

                            auto x = std::get<0>(t), y = std::get<1>(t), wi = std::get<2>(t);
                            for(const auto& pp : paths) {
                                auto nx = x + pp.first;
                                auto ny = y + pp.second;

                                if(nx >= 0 && nx < isize && ny >= 0 && ny < jsize) {
                                    auto nbc = board[nx][ny];
                                    //if(word[wi] == ll && wi == word.size() - 1)
                                    //    return true;
                                    auto mp = nx * isize + ny;
                                    if(!marked[mp] && nbc == word[wi]) {
                                        if(wi == word.size() - 1)
                                            return true;

                                        q.push({nx, ny, wi + 1});
                                    }
                                }
                            }
                        }
                    } else
                        return true;
                }
            }
        }

        return false;
    }
};

int strStr(string haystack, string needle)
{
    if(needle.empty())
        return 0;

    std::size_t i = 0;
    std::size_t iSize = haystack.size();
    int si = -1;

    std::size_t j = 0;
    std::size_t jSize = needle.size();
    for(; i < iSize && j < jSize; ++i) {
        auto hc = haystack[i];
        auto nc = needle[j];

        if(hc == nc) {
            if(si < 0)
                si = i;
            ++j;
        } else {
            if(si >= 0) {
                i = si;
            }

            si = -1;
            j = 0;
        }
    }

    if(j == needle.size())
        return si;

    return -1;
}

int main()
{
    cout << strStr("aabaaabaaac", "aabaaac");
//    Solution sol;
//    cout << sol.exist({{'A', 'A'}}, "AAA") << endl;
}
