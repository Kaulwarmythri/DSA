class Solution {
public:
    int poorPigs(int buckets, int minToDie, int minToTest) {
        int p = 0;
        while(pow((minToTest / minToDie + 1), p) < buckets) p++;
        return p;
    }
};



//Let's say we have minToTest = 60, minToDie = 15 => We can perform 4 tests (60 / 15)
//  1    2   3   4   5
//  6    7   8   9  10
// 11   12  13  14  15
// 16   17  18  19  20
// 21   22  23  24  25

//We can use 2 pigs -> 1 to drink a row (then wait for minToDie minutes and then test again...)
//ans 1 to drink a column (then wait for minToDie minutes to test again...)

//Suppose, row pig dies in row 1 and column pig doesn't die in column 1 that means one of the buckets 2 3 4 5 can be poisonous.

//So we can use remaining 3 tests by letting column pigs drink the next 3 columns. It it doesn't die in any column => poisonous bucket is in column 5 ie; 5th bucket.

//So we can use 2 pigs to test a 5 x 5 grid. Similarly, we can use 3 to test 5 x 5 x 5 one for x-axis, one for y-axis, one for z-axis)

//So we test (minToTest / minToDie + 1) ^ p buckets with p pigs.