class Solution {
private:
    long long fastpow(int base, int exp) {
        if(!exp)
            return 1;
        if(exp & 1)
            return base * fastpow(base, exp - 1);
        long long ans = fastpow(base, exp/2);
        return ans*ans;
    }
    
public:
    int reverse(int xx) {
        long long x = xx;
        stack<int> s;
        bool neg = false;
        long long ans = 0;
        
        if(x < 0)
            neg = true, x *= -1;
        while(x) {
            s.push(x % 10);
            x /= 10;
        }
        
        int pow = 0;
        while (s.size()) {
            long long temp = s.top() * fastpow(10, pow);
            ans += temp;
            if (ans > INT_MAX)
                return 0;
            s.pop();
            pow++;
        }

        if(neg)
            return ans*-1;
        return ans;
    }
};