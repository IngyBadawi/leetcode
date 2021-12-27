class Solution {
public:
    int findComplement(int num) {
        int first_one = -1;
        for (int i = 30; i >=0 ; i--){
            if (num & (1<<i)) {
                int temp = 1<<i;
                cout<<"temp = "<<temp<<endl;
                first_one = i;
                cout<<"first 1 = "<<first_one<<endl;
                break;
            }
        }
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