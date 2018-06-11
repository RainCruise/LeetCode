/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows <= 1) {
        return s;
    }
    let result = [];
    let index = 0, step = 1;
    for (let i = 0; i < s.length; i++) {
        if (result[i] === undefined) {
            result[i] = '';
        }
        result[index] += s[i];
        if (index === 0) {
            step = 1;
        } else if (index === numRows - 1) {
            step = -1;
        }
        index += step;
    }
    return result.join('');
};
