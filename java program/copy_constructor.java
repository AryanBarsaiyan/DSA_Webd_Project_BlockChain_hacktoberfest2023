import javax.management.remote.SubjectDelegationPermission;

class Student
{
    private int roll;
    private String name;
    public Student(int x,String s)
    {
        roll=x;
        name=s;
    }
    public Student(Student student)
    {
        roll=student.roll;
        name=student.name;
    }
    public void show_data()
    {
        System.out.println("Roll no. = "+roll+" name = "+name);
    }
}
public class copy_constructor {
    public static void main(String []args)
    {
        Student s=new Student(1,"xyz");
        Student s2=new Student(s);
        s.show_data();
        s2.show_data();

    }
}
