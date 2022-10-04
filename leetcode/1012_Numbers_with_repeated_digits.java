class Ans {
  public int Num1(int n) {
    return n - count(n);
  }

  private int count(int n) {
    final int Sizee = (int) Math.log10(n) + 1;
   
    dp = new Integer[Sizee + 1][1 << 10][2];
    return count(String.valueOf(n), Sizee, 0, true) - 1; 
  }

  private Integer[][][] dp;

  private int count(final String s, int Sizee, int Num2, boolean val) {
    if (Sizee == 0)
      return 1;
    if (dp[Sizee][Num2][val ? 1 : 0] != null)
      return dp[Sizee][Num2][val ? 1 : 0];

    int ans = 0;
    final int maxDigit = val ? s.charAt(s.length() - Sizee) - '0' : 9;

    for (int digit = 0; digit <= maxDigit; ++digit) {
     
      if ((Num2 >> digit & 1) == 1)
        continue;
     
      final boolean nextIsTight = val && (digit == maxDigit);
      if (Num2 == 0 && digit == 0) 
        ans += count(s, Sizee - 1, Num2, nextIsTight);
      else
        ans += count(s, Sizee - 1, Num2 | 1 << digit, nextIsTight);
    }

    return dp[Sizee][Num2][val ? 1 : 0] = ans;
  }
}