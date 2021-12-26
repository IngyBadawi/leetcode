class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        int mx = 0, w = 0;
        heights.push_back(0);
        for(int i = 0 ; i < heights.size() ; i++){
            if(s.empty() || heights[i] >= heights[s.top()]) s.push(i);
            else{
                int curr_ind = s.top();
                s.pop();
                if(s.empty()) w = i;
                else w = i - s.top() - 1;
                mx = max(mx, heights[curr_ind] * w);
                i--;
            }
        }
        return mx;
    }
};