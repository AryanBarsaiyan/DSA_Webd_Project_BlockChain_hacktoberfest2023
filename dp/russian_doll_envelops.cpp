/*

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).



*/



bool static compare(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }

    return a[0] < b[0];
}







int maxEnvelopes(vector<vector<int>> &envelopes){
    
    int n = envelopes.size();
    if(n == 0){
        return 0;
    }

    sort(envelopes.begin(), envelopes.end(), compare);
    vector<int> sub;

    vector<int> dp(n, 1);   // dp[i] is the max number of non overlapping envelopes until ith envelope  
    dp[0] = 1;
    int ans = 1;

    for(int i=1; i<n; i++){
        dp[i] = 1;
        // iterate over the previous envelopes and check if we can add ith envelope to largest set of non intersecting envelopes.
        for(int j=0; j<i; j++){   // for nesting, the smaller envelop has to be strictly smaller.
            if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        ans = max(ans, dp[i]);
    }

    return ans;

}



