class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        while (L <= R)
            count += 665772 >> __builtin_popcount(L++) & 1;
        return count;
    }
};