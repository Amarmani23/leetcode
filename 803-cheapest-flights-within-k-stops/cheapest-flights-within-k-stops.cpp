class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src]=0;

        for(int i=0;i <=k;i++){
            vector<int>temp=prices;
            for(const auto& flight:flights){
                int u=flight[0];
                int v =flight[1];
                int price=flight[2];

                if(prices[u] == INT_MAX) continue;
                if(prices[u]+price < temp[v]){
                    temp[v]=prices[u]+price;

                }
            }
            prices=temp;
        }
        return prices[dst]== INT_MAX ? -1 : prices[dst];
    }
};