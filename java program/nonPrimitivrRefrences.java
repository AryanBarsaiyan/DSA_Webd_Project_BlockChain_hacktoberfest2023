class Point{
    int x;
    int y;
}
public class nonPrimitivrRefrences {
    public static void main(String [] ar)
    {
        Point  p1 = new Point();
        p1.x=10;  p1.y=20;
        Point p2=p1;        // P2 STRT REFRENCING THE ADDRESS OF P1 NOW ANY CHANGE IN P2 SHOULD ALSO REFLECT IN P1
        p2.x=50;
        System.out.println(p1.x);
        System.out.println(p2.x);
    }
}
