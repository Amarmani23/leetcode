class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        if(s.empty() || words.empty()) return result;
        int wordlen=words[0].length();
        int wordcount = words.size();
        int slen=s.length();
        int totallen=wordlen*wordcount;
        if(slen<totallen) return result;
        unordered_map<string,int>wordfreq;
        for(const string& w:words){
            wordfreq[w]++;

        }
        for(int i=0;i<wordlen;i++){
            int left=i;
            unordered_map<string,int>seen;
            int count = 0;
            for(int right =i;right + wordlen <= slen;right+=wordlen){
                string word =s.substr(right,wordlen);
                if(wordfreq.count(word)){
                    seen[word]++;
                    count++;
                    while(seen[word]>wordfreq[word]){
                        string leftword =s.substr(left,wordlen);
                        seen[leftword]--;
                        count--;
                        left+=wordlen;
                    }
                    if(count == wordcount){
                        result.push_back(left);
                    }
                }else {
                    seen.clear();
                    count=0;
                    left = right +wordlen;
                }

            }
        }
        return result;
    }
};