class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        bool flag = false;
        for (int i = 0 ; i < 31 ; i++) {
            if (n & (1<<i))
                if (flag)
                    return false;
                else
                    flag = true;
        }
        return true;
    }
};