class Solution {
public:
    bool checkTwoChessboards(std::string coordinate1, std::string coordinate2) {
        auto isBlack = [](const std::string& coord) {
            return (coord[0] - 'a' + 1 + (coord[1] - '0')) % 2 == 0;
        };

        return isBlack(coordinate1) == isBlack(coordinate2);
    }
};