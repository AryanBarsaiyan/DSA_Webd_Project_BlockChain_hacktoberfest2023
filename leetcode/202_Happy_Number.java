public boolean isHappy(int n) {
  Set<Integer> set = new HashSet<Integer>();
  
  while (n > 1) {
    int m = 0;
    
    while (n > 0) {
      int d = n % 10;
      m += d * d;
      n /= 10;
    }
    
    if (set.contains(m))
      return false;
        
    set.add(m);
    
    n = m;
  }
  
  return true;
}
