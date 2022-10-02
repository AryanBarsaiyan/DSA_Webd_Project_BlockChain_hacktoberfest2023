
class employee
{
    String name;
    float salary;
    int id;
    void setdata(int a,String b,float c)
    {
        id=a;
        salary=c;
        name=b;
    }
    void show_data()
    {
        System.out.println(id +"  "+  name + "   "+ salary);
    }
}
public class Test {
    public static void main(String a[])
    {
        employee e1 = new employee();
        e1.setdata(1, "AMAN", 20000);
        employee e2=  new employee();
        e2.setdata(2, "ADARSH", 80000);
        e1.show_data();
        e2.show_data();
    }
    
}
