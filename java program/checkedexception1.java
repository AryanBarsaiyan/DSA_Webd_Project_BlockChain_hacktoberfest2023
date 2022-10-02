import java.io.*;
public class checkedexception1{
    public static void main(String [] arg) throws IOException
    {
        try{
        throw new IOException("hii");
        }
        catch(IOException e)
        {
            System.out.println("IOException: " +e.getMessage());
        }
        System.out.println("After exception"); 
    }
}