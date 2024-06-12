class Node{
    int data;
    Node next;
    Node(int d){
        data = d;
        next = null;
    }
    Node(){
        next = null;
    }
}
public class Linkedlist{

    public static void display(Node head){
        Node temp = head;
        while(temp!= null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public static Node insertFirst(Node head, int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
            return head;
        }
        newNode.next = head;
        head = newNode;
        return head;
    }

    public static void insertLast(Node head, int data){
        if(head == null){
            insertFirst(head, data);
        }else if(head.next == null){
            Node newNode = new Node(data);
            head.next = newNode;
        }else{
            Node temp = head;
            while(temp.next != null){
                temp = temp.next;
            }
            Node newNode = new Node(data);
            temp.next = newNode;
        }
    }

    public static void main(String args[]){
        Node head = null;
        head = Linkedlist.insertFirst(head, 10);
        head = Linkedlist.insertFirst(head, 20);
        Linkedlist.insertLast(head,30);
        Linkedlist.display(head);
    }
}