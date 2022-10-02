import java.util.Scanner;

import java.util.Scanner;
public class UsingScannerClass {
    public static void main(String [] args)
    {
        Scanner sc =new Scanner(System.in);
        String s=sc.nextLine();
        System.out.println("You Enter the String " + s);
        int x=sc.nextInt();
        System.out.println("You Enter the Integer  " + x);
        Float y=sc.nextFloat();
        System.out.println("You Enter the Float " + y);
        int X=sc.nextInt();
        System.out.println("You Enter the Integer  " + X);
        int Z =X+x;
        System.out.println("Sum is " +Z);

    }
    
}
