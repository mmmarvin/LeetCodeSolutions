#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// class Solution {
// public:
// 	bool exist(const vector<vector<char>>& board, string word) {
//         static const vector<pair<int, int>> paths =
//         {
//             			{0, -1},
//             {-1, 0},				{1, 0},
//             			{0, 1}
//         };

// 		auto fl = word[0];
// 		for(size_t i = 0, isize = board.size(); i < isize; ++i) {
// 			const auto& bv = board[i];
// 			for(size_t j = 0, jsize = bv.size(); j < jsize; ++j) {
// 				auto bc = bv[j];

// 				if(bc == fl) {
// 					if(word.size() > 1) {
// 						vector<unordered_map<size_t, bool>> marked(board.size() ? board.size() * board[0].size() : 0);
// 						queue<tuple<make_signed_t<size_t>, make_signed_t<size_t>, make_signed_t<size_t>>> q;
// 						q.push({i, j, 1});

// 						while(!q.empty()) {
// 							auto t = q.front();
// 							q.pop();

// 							auto x = get<0>(t), y = get<1>(t), wi = get<2>(t);
// 							for(const auto& pp : paths) {
// 								auto nx = x + pp.first;
// 								auto ny = y + pp.second;

// 								if(nx >= 0 && nx < isize && ny >= 0 && ny < jsize) {
// 									auto nbc = board[nx][ny];

// 									auto fi = x * isize + y;
// 									auto ti = nx * isize + ny;
// 									auto fit = marked[fi].find(ti);
// 									if((fit == marked[fi].end() || !fit->second) && nbc == word[wi]) {
// 										if(wi == word.size() - 1)
// 											return true;
// 										marked[fi][ti] = true;
// 										marked[ti][fi] = true;
// 										q.push({nx, ny, wi + 1});
// 									}
// 								}
// 							}
// 						}
// 					} else
// 						return true;
// 				}
// 			}
// 		}

// 		return false;
// 	}
// };

// class Solution {
// public:
//     bool exist(const vector<vector<char>>& board, string word) {
//         static const vector<pair<int, int>> paths =
//         {
//             {-1, -1},	{0, -1},	{1, -1},
//             {-1, 0},				{1, 0},
//             {-1, 1},	{0, 1},		{1, 1}
//         };

//         auto fl = word[0], ll = word.back();
//         for(auto i = 0ul, isize = board.size(); i < isize; ++i) {
//             const auto& bv = board[i];
//             for(auto j = 0ul, jsize = bv.size(); j < jsize; ++j) {
//                 auto bc = bv[j];
//                 if(fl == bc) {
//                     if(word.size() > 1) {
//                         queue<tuple<int, int, int>> q;
//                         q.push({i, j, 1});
//                         while(!q.empty()) {
//                             auto t = q.front();
//                             q.pop();

//                             auto x = std::get<0>(t), y = std::get<1>(t), wi = std::get<2>(t);
//                             if(word[wi] == ll)
//                                 return true;

//                             for(const auto& pp : paths) {
//                                 auto nx = x + pp.first;
//                                 auto ny = y + pp.second;

//                                 if(nx >= 0 && nx < isize && ny >= 0 && ny < jsize) {
//                                     auto nbc = board[nx][ny];
//                                     if(nbc == word[wi]) {
//                                         q.push({nx, ny, wi + 1});
//                                     }
//                                 }
//                             }
//                         }
//                     } else
//                         return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution
{
public:
	bool exist(const vector<vector<char>>& board, string word) {
        static const vector<pair<int, int>> paths =
        {
            			{0, -1},
            {-1, 0},				{1, 0},
            			{0, 1}
        };

		auto fl = word[0];
		for(size_t i = 0, isize = board.size(); i < isize; ++i) {
			const auto& bv = board[i];
			for(size_t j = 0, jsize = bv.size(); j < jsize; ++j) {
				auto bc = bv[j];

				if(bc == fl) {
					if(word.size() > 1) {
						vector<bool> marked(board.size() * board[0].size());
						stack<tuple<make_signed_t<size_t>, make_signed_t<size_t>, make_signed_t<size_t>>> s;
						stack<pair<make_signed_t<size_t>, make_signed_t<size_t>>> s2;

						s.push({i, j, 1});
						s2.push({i, j});

						while(!s.empty()) {
							auto t = s.top();
							s.pop();

							auto x = get<0>(t), y = get<1>(t), wi = get<2>(t);
							marked[x * isize + y] = true;
							s2.push({x, y});

							bool fc = false;
							for(const auto& pp : paths) {
								auto nx = x + pp.first;
								auto ny = y + pp.second;

								if(nx >= 0 && nx < isize && ny >= 0 && ny < jsize) {
									auto nbc = board[nx][ny];
									if(!marked[nx * isize + ny] && nbc == word[wi]) {
										if(wi == word.size() - 1)
											return true;
										s.push({nx, ny, wi + 1});
										fc = true;
									}
								}
							}

							if(!fc) {
								marked[x * isize + y] = false;

								// auto nt = s.top();
								auto t2 = s2.top();
								while(/*get<0>(nt) != t2.first && get<1>(nt) != t2.second &&*/ !s2.empty()) {
									marked[t2.first * isize + t2.second] = false;
									s2.pop();
									if(!s2.empty()) 
										t2 = s2.top();
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

//    [['A','B','C','E'], ['S','F','C','S'], ['A','D','E','E']]
// [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
// "ABCESEEEFS"

// {'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}}
// "ABCESEEEFS" 

int main() 
{
	Solution sol;
	// cout << sol.exist({{'a', 'a'}}, string("aaa")) << endl;
	cout << sol.exist({{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}}, "ABCESEEEFS") << endl;
}