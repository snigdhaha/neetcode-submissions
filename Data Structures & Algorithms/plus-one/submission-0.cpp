class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        int i=0;
        
        while(i<digits.size()){
            digits[i]+=carry;

            if(digits[i]<10){
                carry=0;
            }
            else{
                digits[i]=0;
                carry=1;
            }
            i++;

        }

        if(carry==1){
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());

        return digits;
    }
};
