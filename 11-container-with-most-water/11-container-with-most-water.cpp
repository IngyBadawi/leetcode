class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int x1 = 0, x2 = height.size() - 1;
        while (x1 < x2) {
            int curr_height = min(height[x1], height[x2]);
            area = max(area, (x2 - x1) * curr_height);
            while (height[x1] <= curr_height && x1 < x2)
                x1++;
            while(height[x2] <= curr_height && x1 < x2)
                x2--;
        }
        return area;
    }
};