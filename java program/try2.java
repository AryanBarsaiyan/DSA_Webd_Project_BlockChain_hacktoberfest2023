import java.util.*;
//import  java.lang.*;
class Array
{
    private int []a;
    int sum,count;
    public Array()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter 30 numbers");
        a=new int[30];
        for(int i=0;i<30;i++)
        {
            a[i]=sc.nextInt();
        }
        sum=0;
        count=0;

    }
    public int getsum()
    {
        int x=0;
            for(int i=0;i<10;i++)
            {
                x+=a[i+10*count];
            }
        return x; 
    }
    public void Sum(int x){
        sum+=x;
    }
}
class Process implements Runnable
{
    private Array array;
    public Process(Array array)
    {
        this.array=array;
    }
    public void run()
    {
        
        synchronized(array)
        {
            int x=array.getsum();
            array.Sum(x);
            array.count++;
            if(array.count==3)
            {
                System.out.println(array.sum);
            }
        }
    }
}
class try2
{
    public static void main(String [] sr)
    {
        Array a=new Array();
        Process c1=new Process(a),c2=new Process(a),c3=new Process(a);
        Thread t1=new Thread(c1);
        Thread t2=new Thread(c2);
        Thread t3=new Thread(c3);
        t1.start();
        t2.start();
        t3.start();
    }
}