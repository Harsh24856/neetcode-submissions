class Solution {
public:
    int reverse(int x) {
        bool neg = (x < 0);

        long long z = abs((long long)x);

        string temp = to_string(z);

        std::reverse(temp.begin(), temp.end());

        z = stoll(temp);

        if (neg)
            z = -z;

        if (z > INT_MAX || z < INT_MIN)
            return 0;

        return z;
    }
};