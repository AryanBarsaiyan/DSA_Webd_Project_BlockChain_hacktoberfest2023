import java.util.*;
l
public class array_min {
    public static void main(String []  Aryan)
    {
        Scanner sc = new Scanner(System.in);
        int []arr = new int [5];
        int min = +9999;
        for(int i=0;i<5;i++)
        {
            arr[i]=sc.nextInt();
            if(min>arr[i])
            {
                min=arr[i];
            }
        }
        System.out.println(min);

    }    
}
