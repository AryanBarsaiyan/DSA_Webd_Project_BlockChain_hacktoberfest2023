import javax.swing.*;  
public class sbu 
{     sbu()
  {    JFrame f=new JFrame("this is frame");
        JButton b=new JButton("click me");  

        b.setBounds(30,100,120,30);              // setting button position  
       f.add(b);                                           //adding button into frame  

       f.setSize(300,300);                         //frame size 300 width and 300 height  
       f.setLayout(null);                          //no layout manager  
       f.setVisible(true);                        //now frame will be visible, by default not visible  
  }  
 public static void main(String args[])
  {   sbu f =new sbu();  
   }
}
