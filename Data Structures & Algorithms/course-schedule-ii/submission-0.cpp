class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int> > adj(numCourses);

        for(auto &v: prerequisites){
            indegree[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
            cout << indegree[i] << " ";
        }
        cout << "\n";
        int finished = 0;
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cout << cur << "\n";
            ans.push_back(cur);
            finished++;
            for(auto nxt: adj[cur]){
                indegree[nxt]--;
                if(indegree[nxt] == 0){
                    q.push(nxt);
                }
            }
        }
        if(finished != numCourses){
            return {};
        }
        return ans;
    }
};
