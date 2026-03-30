class Solution {
public:
    bool checkStrings(string s1, string s2) {
        long long eX = 0, oX = 0, eS = 0, oS = 0;

        for (int i = 0; i < s1.length(); ++i) {
            int v1 = s1[i], v2 = s2[i];
            int dx = v1 ^ v2;
            int ds = (v1 * v1) - (v2 * v2);
            if (i & 1) {
                oX ^= dx;
                oS += ds;
            } else {
                eX ^= dx;
                eS += ds;
            }
        }
        return !(eX | oX | eS | oS);
    }
};