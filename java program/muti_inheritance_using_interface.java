interface firstname
{
    void first(); 
}
interface lastname
{
    void last();
}
class Name implements firstname,lastname{
    public void first()
    {
        System.out.print("Aryan");
    }
    public void last()
    {
        System.out.println(" Barsaiyan");
    }
}
public class muti_inheritance_using_interface {
    public static void main(String [] srgs)
    {
        Name myname=new Name();
        myname.first();
        myname.last();
    }
}
