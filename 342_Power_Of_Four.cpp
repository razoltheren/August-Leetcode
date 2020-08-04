class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num-1)) == 0) && ((num & 0xaaaaaaaa) == 0);
        
        //return (num > 0) && ((num & (num-1)) == 0) && (num % 3 == 1);
        
        
        // Log4(n)
        /*if(num < 1) return false;
        int n = num, count = 0;
        while(n > 1){
            n >>= 2;
            count += 2;
        }
        return (n << count) == num;
        */
    }
};