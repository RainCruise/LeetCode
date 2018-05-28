JS中打乱数组的方法有许多，总结下来主要有以下两种：

1. 利用randomsort打乱数组

```

let array1 = [1, 2, 3, 4, 5, 6, 7];

function randomsort(a, b) {

    return Math.random() > .5 ? 1 : -1;

}

array1.sort(randomsort);

console.log(array1);

```

这个方法非常直观，也非常简洁。因此许多人会忽略它的复杂度是O(nlogn)，而打乱数组其实只需要O(n)的时间就可以完成，我们来看看下面这个算法：

2. 利用Fisher-Yates洗牌算法:
```

let array2 = [1, 2, 3, 4, 5, 6, 7];

function shuffleArray(array) {

    for (let i = array.length - 1; i > 0; i--) {

        let randomPos = Math.floor(Math.random() * (i + 1));

        [array[i], array[randomPos]] = [array[randomPos], array[i]];

    }

}

shuffleArray(array2);

console.log(array2);

```

相比较而言，这个算法耗时更少。



参考链接：

https://stackoverflow.com/questions/2450954/how-to-randomize-shuffle-a-javascript-array?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa#comment29711767_18650169

http://www.cnblogs.com/idche/archive/2010/04/28/1722830.html
