class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>geneBank(bank.begin(),bank.end());
        if(geneBank.find(endGene)==geneBank.end()){
            return -1;
        }
        int mutation=0;
        queue<string>q;
        q.push(startGene);
        unordered_set<string>visited;
        visited.insert(startGene);
        vector<char>choices={'A','C','G','T'};
        while(!q.empty()){
            int size=q.size();
            for(int i =0;i<size;i++){
                auto curr=q.front();
                q.pop();
                if(curr==endGene){
                    return mutation;
                }
                for(int j=0;j<8;j++){
                    char original=curr[j];
                    for(char c:choices){
                        if(c==original) continue;
                        curr[j]=c;
                        if(geneBank.count(curr) && !visited.count(curr)){
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[j]=original;
                }
            }
            mutation++;
        }
        return -1;
    }
};