class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false;
        queue<pair<int,int>>q;
        q.push({0,0});
        set<pair<int,int>> visited;
        visited.insert({0,0});
        while(!q.empty()){
            auto [curr1,curr2]=q.front();
            q.pop();
            if(curr1==target || curr2 == target || curr1+curr2==target){
                return true;
            }
            // nex state;
            vector<pair<int,int>>nextstate={
                {x,curr2},{curr1,y},{curr1,0},{0,curr2},
                // pour jug1->jug2
                {curr1-min(curr1,y-curr2),curr2+min(curr1,y-curr2)},
                //pour jug2->jug1
                {curr1+min(curr2,x-curr1),curr2-min(curr2,x-curr1)}
            };
            for(const auto& next:nextstate){
                if(visited.find(next)==visited.end()){
                    visited.insert(next);
                    q.push(next);
                }
            }

        }
        return false;

    }
};