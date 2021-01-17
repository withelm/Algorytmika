/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution
{

private:
    set<vector<int>> vis;
    vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(Robot &robot, int x, int y, int dir)
    {
        robot.clean();
        vis.insert({x, y});
        for (int i = 0; i < 4; i++)
        {
            int d = (i + dir) % 4;
            int nx = x + moves[d][0];
            int ny = y + moves[d][1];
            bool isExsit = vis.find({nx, ny}) != vis.end();
            if (!isExsit && robot.move())
            {
                dfs(robot, nx, ny, d);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }

public:
    void cleanRoom(Robot &robot)
    {
        dfs(robot, 0, 0, 0);
    }
};