import javax.swing.*;  
public class textfield1
{    textfield1()
  {     JFrame f=new JFrame();
         JTextField t =new JTextField("Enter your name:",5);  

          t.setBounds(50,100,200,30);                
         f.add(t);                               

         f.setSize(300,300);  
         f.setLayout(null);         
         f.setVisible(true);                         
   }  
 public static void main(String args[])
  {     textfield1 F=new textfield1();  
  }} 
