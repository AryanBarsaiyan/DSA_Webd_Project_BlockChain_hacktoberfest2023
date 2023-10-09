
class Node{
    int val;
    Node next;
     
    Node(int val) { 
        this.val = val;
    }
   
}
 
public class Reverse_LL{

    public Node reverseList(Node h) {

        if(h==null|| h.next==null) return h;
        
        Node small = reverseList(h.next);
        Node t = small;

        while(t.next!=null) t = t.next;
        
        h.next = null;

        t.next = h;
      
        return small;
    }
}