class Solution {
public:

    int getProduct(int n) {
        int ans = 1;
        while(n) {
            ans *= n % 10; // get the last digit and multiply it by the answer
            n /= 10; // remove the last digit
        }
        return ans;
    }

    int getSum(int n) {
        int ans = 0;
        while(n) {
            ans += n % 10; // get the last digit and add it to the answer
            n /= 10; // remove the last digit
        }
        return ans;
    }

    int subtractProductAndSum(int n) {
        int product = getProduct(n);
        product -= getSum(n);
        return product;
    }
};