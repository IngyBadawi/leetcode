class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> boxes (n) ;
        for (int i = 0 ; i < n ; i++) 
            boxes.push_back({boxTypes[i][1], boxTypes[i][0]});
        sort(boxes.rbegin(), boxes.rend());
        
        int ans = 0;
        
        for (int i = 0 ; i < n ; i++) {
            if (truckSize == 0)
                break;
            while (boxes[i].second && truckSize) {
                truckSize--;
                ans += boxes[i].first;
                boxes[i].second --;
            }
        }
        return ans;
    }
};