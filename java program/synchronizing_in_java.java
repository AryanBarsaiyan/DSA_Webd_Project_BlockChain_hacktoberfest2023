import java.util.*;
//import  java.lang.*;
class Account
{
    private int balance;
    public Account(int balance)
    {
        this.balance=balance;
    }
    public boolean isSuffBalance(int amount)
    {
        if(amount<=balance)
            return true;
        else
            return false;
    }

    public void withdraw(int amount)
    {
        balance=balance-amount;
        System.out.println("Withdrawl amount : "+amount);
        System.out.println("Your Current Balance is : "+balance);
    }
}
class Customer implements Runnable
{
    private String name;
    private Account account;
    public Customer(Account account,String s)
    {
        this.account=account;
        name=s;
    }
    public void run()
    {
        Scanner sc=new Scanner(System.in);
        synchronized(account)
        {
        System.out.println(name+": Enter the amount you want to withdraw");
        int am=sc.nextInt();
        if(account.isSuffBalance(am))
        {
            account.withdraw(am);
        }
        else
        {
            System.out.println("Insufficient Balance");
        }
        }
    }
}
class synchronizing_in_java
{
    public static void main(String [] sr)
    {
        Account ac=new Account(1000);
        Customer c1=new Customer(ac,"Aryan"),c2=new Customer(ac,"AA");
        Thread t1=new Thread(c1);
        Thread t2=new Thread(c2);
        t1.start();
        t2.start();

    }
}