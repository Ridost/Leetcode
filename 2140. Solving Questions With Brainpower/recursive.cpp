class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return recursive(questions,0);
    }
    long long recursive(vector<vector<int>>& questions,int n){
        if(n>questions.size()-1) return 0;
        long long get_n = questions[n][0] + recursive(questions,n+questions[n][1]+1);
        long long not_get_n = recursive(questions,n+1);
        return max(get_n,not_get_n);  
    }
};
