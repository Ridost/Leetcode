class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector <int> answer(len);
        for(int i = 0;i<len;i++){
            for(int j = i+1;j<len;j++){
                answer[i] += 1;
                if(temperatures[i]<temperatures[j]) break;
                else if(j==len-1) answer[i] = 0;
            
            }

        }
        return answer;
    }
};
