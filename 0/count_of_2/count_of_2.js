var count_of_2 = function(n) {
    var count = 0;
    for (var i = 2; i <= n; i++) {
        var x = i;
        while (x > 0) {
            if (x % 10 == 2) count++;
            x = parseInt(x / 10);
        }
    }
    return count;
};
console.log(count_of_2(25)); // 9   (2, 12, 20, 21, 22, 23, 24 and 25)
