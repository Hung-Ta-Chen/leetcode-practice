class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        // Cycle detection with floyd's algorithm
        while(fast != 1 && next(fast) != 1){
            slow = next(slow);
            fast = next(next(fast));
            // If fast equals slow, cycle detected
            if(slow == fast) return false;
        }
        return true;
    }
    int next(int n){
        if(n == 1) return 1;
        int sum = 0, res;
        while(n != 0){
            res = n % 10;
            n = n / 10;
            sum += (res * res);
        }
        return sum;
    }
};
