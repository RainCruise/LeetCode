class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size(), i, j, iStar = -1, jStar = -1;
        for (i = 0, j = 0; i < slen; ++i, ++j) {
            //meet a new '*', update traceback i/j info
            if (p[j] == '*') {
                iStar = i;
                jStar = j;
                --i;
            } else {
                // mismatch happens
                if (p[j] != s[i] && p[j] != '?') {
                    // met a '*' before, then do traceback
                    if (iStar >= 0) {
                        i = iStar++;
                        j = jStar;
                    } else return false; //fail
                }
            }
        }
        while (p[j] == '*') ++j;
        return j == plen;
    }
};
/*
The reason that the iterative solution is much faster for this case is we only need to save (and deal with) the positions (iStar for s, jStar for p) of the last "" we met. We only need to do traceback using iStar and jStar and all the previous "" can be ignored since the last "" will cover all the traceback cases for the previous "".
What we need to do are

    if the current p character is '' (i.e. p[j]==''), then we update iStar and jStar with the cureent i and j values. iStar/jStar will be used for traceback. Also we do --i to start the depth first search with the case that '*' represents a null string.
    if p[j]!='', then we check if mismatch occurs (i.e. p[j]!=s[i] and p[j]!='?'), if so we check if we met a '' before (iStar>=0), if not, then we return false since no match can achieve. Otherwise, we traceback to the positions at which the last '*' happens and do the next possible dfs search (i.e. i = iStar++; j = jStar; remember to update iStar too to save the i position to try in the next traceback).
    The loop will quit when we reach the end of s. At last, we need to skip all the '*' in p to see if we can reach the end of p. if so, match, otherwise mismatch
*/
