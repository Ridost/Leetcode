class Solution {
public:
    int numTilePossibilities(string tiles) {
        int freq[26];
        int n = tiles.size();
        for(int i=0;i<n;i++){
            int idx = tiles[i] - 'A';
            freq[idx] = freq[idx]+1;
        }
        return dfs(freq);
    }
    int dfs(int freq[26]){
        int cnt = 0;
        for(int i =0;i<26;i++){
            if(freq[i]==0) continue;
            cnt++;
            freq[i]--;
            cnt += dfs(freq);
            freq[i]++;
        }
        return cnt;
    }
};
