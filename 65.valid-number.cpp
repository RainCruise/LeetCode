class Solution {
public:
    int curState;
    bool check() {
        if (curState == 2 || curState == 4 || curState == 7) {
            return true;
        }
        return false;
    }
    bool isNumber(string s) {
        int len = s.length();
        if (len == 0) {
            return false;
        }
        // 删除空格
        int preSpaceNum = 0;
        while (s[0] == ' ') {
            preSpaceNum ++;
            len --;
        }
        s = s.substr(preSpaceNum, len);
        while (s[len - 1] == ' ') {
            len --;
        }
        s = s.substr(0, len);

        curState = 0;
        int pos = 0;
        while (pos < len) {
            char c = s[pos];
            switch (curState) {
                case 0 :
                    if (c == '+' || c == '-') {

                    } else {
                        pos --;
                    }
                    curState ++;
                    break;
                case 1:
                    if (c == '.') {
                        curState = 3;
                    } else if ('0' <= c && c <= '9') {
                        curState = 2;
                    } else {
                        return false;
                    }
                    break;
                case 2:
                    if (c >= '0' && c <= '9') {

                    } else if (c == '.') {
                        curState = 4;
                    } else if (c == 'e') {
                        curState = 5;
                    } else {
                        return false;
                    }
                    break;
                case 3:
                    if (c >= '0' && c <= '9') {
                        curState = 4;
                    } else {
                        return false;
                    }
                    break;
                case 4:
                    if (c >= '0' && c <= '9') {

                    } else if (c == 'e') {
                        curState = 5;
                    } else {
                        return false;
                    }
                    break;
                case 5:
                    if (c == '+' || c == '-') {

                    } else {
                        pos--;
                    }
                    curState = 6;
                    break;
                case 6:
                    if (c >= '0' && c <= '9') {
                        curState = 7;
                    } else {
                        return false;
                    }
                    break;
                case 7:
                    if (c >= '0' && c <= '9') {

                    } else {
                        return false;
                    }
                    break;
            }
            pos++;
        }
        return check();
    }
};
