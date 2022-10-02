class box{
    public int l,b,h;
    public box(int a,int b,int c)
    {
        l=a;
        this.b=b;
        h=c;
    }
    public void show_Dimension()
    {
        System.out.println("length l= "+ l +" breadth b="+ b + " height h="+h);
    }
    public void volume()
    {
        System.out.println("Volume = " + l*b*h);
    }
}
public class box_class_parametric_constructor {
    public static void main(String[] args) {
        box b=new box(1,2,3);
        b.show_Dimension();
        b.volume();
    }
}
