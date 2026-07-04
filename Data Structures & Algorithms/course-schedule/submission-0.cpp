class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int> > adj(numCourses);

        for(auto &v: prerequisites){
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        int finished = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            finished++;
            for(auto nxt: adj[cur]){
                indegree[nxt]--;
                if(indegree[nxt] == 0){
                    q.push(nxt);
                }
            }
        }
        return (finished == numCourses);
    }
};
