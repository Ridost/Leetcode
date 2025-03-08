class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mini = k,cur = 0;
        int n = blocks.size();
        int cnt = 0;
        for(int i = 0;i<k;i++){
            if(blocks[i]=='W') cur++;
        }
        mini = cur;
        for(int i = k;i<n;i++){
            if(blocks[i-k]=='W') cur--;
            if(blocks[i]=='W') cur++;
            mini = min(mini,cur);
        }
        return mini;
    }
};
