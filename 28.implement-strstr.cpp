class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();
        int hsize = haystack.size();
        if (nsize == 0) return 0;
        int *next = new int[nsize];
        memset(next, 0, sizeof(int)*nsize);

        for (int i = 1, j = 0; i < nsize - 1;) {
            if (needle[i] != needle[j]) {
                if (j > 0) {
                    j = next[j - 1];
                } else {
                    i++;
                }
            } else {
                next[i] = j + 1;
                i++;
                j++;
            }
        }
        //matching
        for (int i = 0, match_pos = 0; i < hsize;) {
            if (haystack[i] == needle[match_pos]) {
                if (match_pos == nsize - 1) {
                    return i - (nsize - 1);
                } else {
                    i++;
                    match_pos++;
                }
            } else {
                if (match_pos == 0) i++;
                else match_pos = next[match_pos - 1];
            }
        }
        //delete[] next;    //Should add this ?
        return -1;
    }
};

/*Violent resolve:
    int m = haystack.size(), n = needle.size();
    if (n == 0) return 0;
    for (int i = 0; i < m - n + 1; i++) {
        int j = 0;
        for (; j < n; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
    }
    return -1;
*/

