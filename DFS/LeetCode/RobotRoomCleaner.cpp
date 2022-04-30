// 489. Robot Room Cleaner

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



class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0}, // 0
        {0, 1}, // 1
        {1, 0}, // 2
        {0, -1} // 3
    };

    int rows = 100, cols = 200;

    bool visited[100][200];
    void cleanRoom(Robot& robot) {
        int r = 0, c = 0;
        visited[r][c] = true;
        robot.clean();
        searchRoom(r, c, 0, robot);
    }

    void searchRoom(int r, int c, int dir, Robot& robot) {
        for (int i = 0; i < directions.size(); i++) {
            int nextDir = (dir+i) % 4;
            int nextR = r + directions[nextDir][0];
            int nextC = c + directions[nextDir][1];
            
            if (i > 0) {
                robot.turnRight();
            }

            if (visited[(nextR + rows) % rows][(nextC + cols) % cols]) {
                continue;
            }

            int isMove = robot.move();

            if (isMove) {
                robot.clean();
                visited[(nextR + rows) % rows][(nextC + cols) % cols] = true;
                searchRoom(nextR, nextC, nextDir, robot);
            }
            
        }

        robot.turnLeft();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
