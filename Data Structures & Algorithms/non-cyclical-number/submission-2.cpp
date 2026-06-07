class Solution {
public:

    int sumOfSquaresOfDigit(int n) {
        if(n == 0) return 0;

        int digit = n % 10;
        int newNum = n/10;

        //sum+=digit*digit;

        return digit * digit + sumOfSquaresOfDigit(newNum);
    }

    // void sumOfSquaresOfDigit(int n,int &sum){
    //     if(n<=0 ) return;

    //     int digit = n/%10;
    //     int newNum = n/10;
        
    //     sum+=digit*digit;
        
        

    //     sumOfSquares(newNum,sum);
    // }

    bool isHappy(int n) {
        // if(n==1) return true;

        // if(sumOfSquaresOfDigit(n)==1) return true;

        // return false;
        unordered_set<int> visit;

        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = sumOfSquaresOfDigit(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
             
    }
};
