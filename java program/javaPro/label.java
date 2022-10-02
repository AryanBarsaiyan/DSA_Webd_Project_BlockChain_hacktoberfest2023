import javax.swing.*;  
public class label
{     label()
  {   JFrame f=new JFrame();
       JLabel l=new JLabel("First label");  
       JButton b=new JButton("click");
       l.setBounds(50,50, 100,30);  
       b.setBounds(150,150, 200,150);  
       f.add(l);                                          //adding label into frame  
       f.add(b);
       f.setSize(300,300);                       //frame size 300 width and 300 height  
       f.setLayout(null);                        //no layout manager  
       f.setVisible(true);                       //now frame will be visible, by default not visible  
   }  
 public static void main(String args[])
  {   label f =new label();  
  }
} 
