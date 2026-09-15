class Solution {
private:
    const vector<string> belowTwenty = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    
    const vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    
    string helper(int n){
        if(n == 0) return "";
        if(n < 20){
            return belowTwenty[n] + " ";
        }
        if(n < 100){
            return tens[n / 10] + " " + helper(n % 10);
        }
        // FIX 1: Added a space after "Hundred " so numbers like 100 don't bunch up
        return helper(n / 100) + "Hundred " + helper(n % 100);
    }
    
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        string result = "";
        
        // FIX 2: Only recursively call numberToWords if the remainder is > 0
        if(num >= 1000000000){
            result += helper(num / 1000000000) + "Billion " + (num % 1000000000 ? numberToWords(num % 1000000000) : "");
        } else if(num >= 1000000){
            result += helper(num / 1000000) + "Million " + (num % 1000000 ? numberToWords(num % 1000000) : "");
        } else if(num >= 1000){
            result += helper(num / 1000) + "Thousand " + (num % 1000 ? numberToWords(num % 1000) : "");
        } else {
            result += helper(num);
        }
        
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};
