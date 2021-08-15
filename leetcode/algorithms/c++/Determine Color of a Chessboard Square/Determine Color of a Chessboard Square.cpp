class Solution {
public:
  bool squareIsWhite(string coordinates) {
    int x = (coordinates[0] - 'a' + 1) % 2;
    int y = (coordinates[1] - '0') % 2;
    return (x + y) % 2;
  }
};