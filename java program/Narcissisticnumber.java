class narcissistic
{
 
int dig_count(int n)
{
    if (n == 0)
        return 0;
  
    return 1 + dig_count(n / 10);
}
boolean check(int n)
{   
    int sum = 0;
    int l = dig_count(n);
    int temp = n;
    
  
    while(temp > 0)
    {
        sum += pow(temp % 10, l);
        temp /= 10;
    }
  
    return (n == sum);
}
  
public static void main(String args[])
 {
    narcissistic obj = new narcissistic();
    int n = 1634;
    if (obj.check(n))
        System.out.println("The Given number is narcissistic.");
    else
        System.out.println("The Given number is not narcissistic.");
  }
}