/*

Leetcode question: Wildcard matching (hard)

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Solution:

First, we need to create a 2d dp table dp. The size of this table is (s.size() + 1) * (p.size() + 1). We introduce +1 here to better handle the edge cases where we have an empty string or an empty pattern. dp[i][j] means whether the substring from index 0 to i - 1 of the original string s matches with the subpattern from index 0 to j - 1 of the original pattern p.

Next, we initialize the base cases. There are three base cases:

When both the string and the pattern are empty.
Always match. dp[0][0] = true;
When only the string is empty.
Only if the subpattern only consists of *, we have a match.
When only the pattern is empty.
Always not match.
There are two special characters that we need to take special care in the pattern.

?
This is actually easy to deal with. Everytime when we encounter this, we can consider it matches with any character in the string. Say we are currently at dp[i][j], and we have p[j - 1] == '?', then we know it matches with s[i - 1], no matter what s[i - 1] actually is.
*
This is slightly hard to deal with. A small technique while dealing this kind of question is to actually draw out the dp table, and try to fill out the table manually, when the state transfer function is not very straightforward. Everything will become much clearer after you fill out one row or two.
When we encounter a * in the pattern, and assuming that we're currently trying to figure out what dp[i][j] is. Then we need to consider two cases if p[j - 1] == '*'.
Is dp[i - 1][j] true?
If yes, it means the current subpattern p[0...j - 1] we have matches the substring s[0... i - 2]. Then will p[0...j - 1] match with s[0... i - 1]? The answer is yes, because * can match any sequence of characters, so it's able to match one more character s[i - 1].
Is dp[i][j - 1] true?
If yes, it just means the current substring s[0...i - 1] matches with the subpattern p[0...j - 2]. Therefore, if we add one more * into the subpattern, it will also match as * can match empty subsequence.




*/



// O(mn) space


  bool isMatch(string s, string p) {
      vector<vector<bool>> dp(s.size() + 1, vector(p.size() + 1, false));
      dp[0][0] = true;
      for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
          dp[0][j + 1] = true;
      }

      for (int i = 1; i <= s.size(); ++i) {
          for (int j = 1; j <= p.size(); ++j) {
              if (p[j - 1] == '*') {
                  dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
              } else {
                  dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
              }
          }
      }

      return dp[s.size()][p.size()];
  }




// O(n) space
// We can also use 1d table to solve this problem, but the code will be less readable.

  bool isMatch(string s, string p) {
      vector<bool> dp(p.size() + 1, false);
      dp[0] = true;
      for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
          dp[j + 1] = true;
      }

      for (int i = 1; i <= s.size(); ++i) {
          dp[0] = false;
          bool neighborLastRow = i == 1;
          for (int j = 1; j <= p.size(); ++j) {
              bool currLastRow = dp[j];
              if (p[j - 1] == '*') {
                  dp[j] = currLastRow || dp[j - 1];
              } else {
                  dp[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && neighborLastRow;
              }
              neighborLastRow = currLastRow;
          }
      }

      return dp[p.size()];
  }


