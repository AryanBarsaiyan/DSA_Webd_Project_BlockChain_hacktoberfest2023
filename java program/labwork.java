import java.io.IOException;

public class labwork {
    public static void main(String []arg)  throws IOException
    {
        try{
            throw new IOException("welcome to exception world");
        }
        catch(IOException e)
        {
            System.out.println("IOException : "+ e.getMessage());
        }
        finally
        {
            System.out.println("HII");
        }
    }
}
