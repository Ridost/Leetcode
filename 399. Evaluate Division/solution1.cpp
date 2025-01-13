class Solution {
public:
    double dfs(string start,string end,unordered_map<string,unordered_map<string,double>>&graph,unordered_set<string>&visited){
        if(graph.find(start)==graph.end()) return -1;
        if(graph[start].find(end)!=graph[start].end()) return graph[start][end];

        for(const auto& nei:graph[start]){
            if(find(visited.begin(),visited.end(),nei.first)!=visited.end()) continue;
            visited.insert(nei.first);
            double res;
            if((res = dfs(nei.first,end,graph,visited))!=-1){
                return graph[start][end] = graph[start][nei.first] * res;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     unordered_map <string, unordered_map<string,double>> map;
     int N = equations.size();

     for(int i =0; i< N;i++)
     {
        const vector<string>& equation = equations[i];
        const string & u = equation[0];
        const string & v = equation[1];
        map[u][u] = 1;
        map[v][v] = 1;
        map[u][v] = values[i];
        map[v][u] = 1/values[i];
     }   
     vector<double> ans;
     unordered_set<string> visited;

     for(vector<string>query:queries){
        const string & u = query[0];
        const string & v = query[1];
        visited = {u};
        ans.push_back(dfs(u,v,map,visited));
     }
     return ans;
    }
};
