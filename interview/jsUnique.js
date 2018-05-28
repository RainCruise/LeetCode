function jsUnique(array) {
    let myObject = {};
    for (let i = 0; i < array.length; i++) {
        if (myObject[array[i]]) {
            continue;
        } else {
            myObject[array[i]] = true;
        }
    }
    return Object.keys(myObject).map(item => Number(item));
}

let arr = [1, 1, 2, 1, 3, 2, 6, 19, 82, 19, 20];

function jsUnique2(array) {
    return Array.from(new Set(array));
}

//console.log(jsUnique(arr));
console.log(jsUnique2(arr));
