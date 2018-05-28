/*
 * 实现类似add(1)(2)(3)调用方式的方法
 */

function add(num) {
    let sum = num;
    let _add = function(x) {
        sum += x;
        return _add;
    }
    _add.toString = function() {
        return sum;
    }
    _add.valueOf = function() {
        return sum;
    }
    return _add;
}

console.log(add(1)(2) == '3');
console.log(add(1)(2)(2) == 5);
console.log(add(1)(3)(5));
console.log(add(1, 2) == '3');
