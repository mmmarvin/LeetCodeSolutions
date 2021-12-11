class Solution {
public:
    bool judgeCircle(const std::string& moves)
    {
        int horizontal_moves = 0;
        int vertical_moves = 0;

        for(std::string::const_iterator it = moves.begin(), it_end = moves.end(); it != it_end; ++it) {
            char move = *it;

            switch(move) {
            case 'U':
                vertical_moves += 1;
                break;
            case 'D':
                vertical_moves -= 1;
                break;
            case 'L':
                horizontal_moves += 1;
                break;
            case 'R':
                horizontal_moves -= 1;
                break;
            }
        }

        return horizontal_moves == 0 && vertical_moves == 0;
    }
};
