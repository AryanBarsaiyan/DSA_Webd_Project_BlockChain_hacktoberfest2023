public class answer1d {
    public static void main(String [] arg)
    {
        String s=new String("Aryan");
        s=s+" Barsaiyan";
        System.out.println(s);
        StringBuffer s2=new StringBuffer("Aryan");
        s2.append(" Barsaiyan");
        System.out.println(s2);
        StringBuilder s3=new StringBuilder("Aryan");
        s3.append(" Barsaiyan");
        System.out.println(s3);
    }
}
