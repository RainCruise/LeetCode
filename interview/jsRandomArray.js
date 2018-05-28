let array1 = [1, 2, 3, 4, 5, 6, 7];
let array2 = [1, 2, 3, 4, 5, 6, 7];
function randomsort(a, b) {
    return Math.random() > .5 ? 1 : -1;
}
array1.sort(randomsort);

function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        let randomPos = Math.floor(Math.random() * (i + 1));
        [array[i], array[randomPos]] = [array[randomPos], array[i]];
    }
}
shuffleArray(array2);
console.log(array1);
console.log(array2);
