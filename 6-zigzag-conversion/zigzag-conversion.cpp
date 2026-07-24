class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1 || numRows>s.length()){
            return s;
        }
        vector<string> rows(min (static_cast<int>(s.length()),numRows));
        int curr=0;
        bool flag=false;
        for(const char& c:s){
            rows[curr]+=c;
            if(curr == 0 || curr==numRows-1){
                flag=!flag;
            }
            curr+=flag ? 1:-1;

        }
        string res;
        for(const string& row: rows){
            res+=row;
        }
        return res;
    }
};