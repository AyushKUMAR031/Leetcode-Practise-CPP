//  static_cast performs the type conversion at compile time, which makes it safer than a C-style cast because it checks for validity during compilation.
class Solution {
public:
    enum Direction { North, East, South, West };

    int x=0,y = 0;
    int MaxDistance =0;
    Direction turnRight(Direction currentDirection) {
        return static_cast<Direction>((currentDirection + 1) % 4);
    }
    Direction turnLeft(Direction currentDirection) {
        return static_cast<Direction>(
            (currentDirection + 3) %
            4); // static_cast helps in converting type better than C-style.
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        Direction currentDirection = North;

        unordered_set<string> obstacle;

        for (int i = 0; i < obstacles.size(); i++) {
            string num =
                to_string(obstacles[i][0]) + "," + to_string(obstacles[i][1]);
            obstacle.insert(num);
            cout<<num<<endl;
        }

        for (int dir : commands) {
            if (dir == -1) {
                currentDirection = turnRight(currentDirection);
            }else if (dir == -2) {
                currentDirection = turnLeft(currentDirection);
            } else {
                for (int i = 0; i < dir; i++) {
                    int nextx = x, nexty = y;
                    if (currentDirection == North) {
                        nexty += 1;
                    } else if (currentDirection == East) {
                        nextx += 1;
                    } else if (currentDirection == South) {
                        nexty -= 1;
                    } else if (currentDirection == West) {
                        nextx -= 1;
                    }

                    // checking obstacle
                    string checknum = to_string(nextx) + "," + to_string(nexty);
                    if (obstacle.find(checknum) != obstacle.end()) {
                        break;
                    }
                    x = nextx;
                    y = nexty;

                    MaxDistance = max(MaxDistance,x*x+y*y);
                }
            }
        }
        return MaxDistance;
    }
};
