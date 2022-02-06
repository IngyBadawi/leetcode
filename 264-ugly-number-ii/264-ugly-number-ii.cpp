class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers(1, 1);
        int last_two = 0, last_three = 0, last_five = 0;
        while(ugly_numbers.size() < n) {
            int next_ugly_number = get_next_ugly_number(last_two, last_three, last_five, ugly_numbers);
            ugly_numbers.push_back(next_ugly_number);
            update_lasts(last_two, last_three, last_five, ugly_numbers);
            if (ugly_numbers.back() == ugly_numbers[ugly_numbers.size() - 2])
                ugly_numbers.pop_back();
        }
        return ugly_numbers.back();
    }
    
private:
    void update_lasts(int &last_two, int &last_three, int &last_five, vector<int> &ugly_numbers) {
        int target = ugly_numbers.back();
        if (ugly_numbers[last_two] * 2 == target) {
            last_two++;
            return;
        }
        if (ugly_numbers[last_three] * 3 == target) {
            last_three++;
            return;
        }
        if (ugly_numbers[last_five] * 5 == target) {
            last_five++;
            return;
        }
    }
    
    int get_next_ugly_number(int last_two, int last_three, int last_five, vector<int> &ugly_numbers) {
        int next_two = ugly_numbers[last_two] * 2;
        int next_three = ugly_numbers[last_three] * 3;
        int next_five = ugly_numbers[last_five] * 5;
        return min(next_two, min(next_three, next_five));
    }
};