class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int step = 0;
        long long pos = 0;
        while(pos < target){
            step++;
            pos += step;
        }
        int diff = pos - target;
        if(diff % 2 == 0) return step;
        return step + 1 + (step & 1);
        }

};