/* 
    Time: O(nlogn)
    Space: O(n)
    Tag: Maths, Geometry (tan inverse and radian to degree conversion), Sorting, Sliding Window
    Difficulty: H
*/
#define PI 3.14159

class Solution {
    vector<double> angles;

    int findAngles(vector<vector<int>> points, vector<int> loc) {
        int x, y;
        double angleInRad;
        int samePoints = 0;
        for (auto &v : points) {
            x = v[0] - loc[0];
            y = v[1] - loc[1];
            if (x == 0 && y == 0) {
                samePoints++;
            } else {
                angles.push_back(atan2(y, x) * 180 / PI);
                if (angles.back() < 0) angles.back() = 360 + angles.back();
            }
        }
        return samePoints;
    }

public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        int n = points.size();
        angles.reserve(2*n);
        int res = findAngles(points, location);
        sort(angles.begin(), angles.end());
        int size=angles.size();
        for(int i=0;i<size;i++){
            angles.push_back(360+angles[i]);
        }
        int ans = 0;
        int start = 0;
        for (int i = 0; i < angles.size(); i++) {
            while (angles[i] - angles[start] > angle || angles[i]-angles[start]>=360) start++;
            ans = max(ans, i - start + 1);
        }
        return res + ans;
    }
};