import java.util.Scanner;
class MyThread extends Thread{
    int sum;
    int i;
    int[] arr;
    public MyThread(){
        sum=0;
        i=0;
        arr = new int[30];
        System.out.println("Enter 30 numbers: ");

        Scanner sc = new Scanner(System.in);

        for (int j=0; j<30; j++)
            arr[j] = sc.nextInt();
    }    
    public MyThread(MyThread t){
        this.sum = t.sum;
        this.i = t.i;
        this.arr=t.arr;
    }
    public int getCount(){
        return sum;
    }
    public void run(){
        for (int c=0; c<10; c++){
            sum += arr[i+c];
        }
        i+=10;
    }
}
public class threadsum {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        t1.start();
        try{
            t1.join();
        }
        catch (Exception e){
            System.out.println(e);
        }
        System.out.println(t1.getCount());
        MyThread t2 = new MyThread(t1);
        t2.start();
        try{
            t2.join();
        }
        catch (Exception e){
            System.out.println(e);
        }
        MyThread t3 = new MyThread(t2);
        t3.start();
        System.out.println(t2.getCount());
        try{
            t3.join();
        }
        catch (Exception e){
            System.out.println(e);
        }
        System.out.println(t3.getCount());
    }
}
