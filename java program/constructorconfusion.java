class point{
    int x,y;
    point(int a ,int b)
    {
        x=a;
        y=b;
    }
    void print()
    {
        System.out.println("x = " +x + " y = " + y );
    }
}
public class constructorconfusion {
    public static void main(String [] args)
    {
        point p =new point();
        p.print();
    }

    
}
