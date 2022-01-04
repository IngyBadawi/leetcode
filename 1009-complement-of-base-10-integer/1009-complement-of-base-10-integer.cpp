class Solution {
public:
    int bitwiseComplement(int num) {
        int first_one = -1;
        for (int i = 30; i >=0 ; i--){
            if (num & (1<<i)) {
                int temp = 1<<i;
                first_one = i;
                break;
            }
        }
        if (first_one == -1)
            return 1;
        int mask = make_mask(first_one);
        return int(num ^ mask);
    }
private:
    int make_mask(int first_one) {
        int mask = 0;
        for (int i = first_one ; i >= 0 ; i--) {
            mask |= (1 << i);
        }
        return mask;
    }
};