import java.io.*;

public class BufferedReader1 {
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a String");
        String S=br.readLine();
        System.out.println("Your Input String is " + S);
        System.out.println("Enter a Integer");
        int x=Integer.parseInt(br.readLine());
        System.out.println(x);
    }
    
}
