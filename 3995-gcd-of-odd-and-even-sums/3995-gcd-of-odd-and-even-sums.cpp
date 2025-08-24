class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd_sum = n*(n+1);
        int even_sum = n*n;

        return gcd(odd_sum, even_sum);
    }
};