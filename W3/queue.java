import java.util.Scanner;

class Queue{
  private Node head;
  private int size; 
  private Node tail;
 
  private class Node{ 
    Character value;
    Node next;
  }
 
  public Queue(){
    head = null;
    tail = null;
    size = 0;
  }
 
  public boolean isEmpty(){
    return (size == 0);
  }
 
  //Remove item from the beginning of the list.
  public Character dequeue(){
    if (head == null){
      System.out.println("UnderFlow!");
      return null;
    }
    else {
      Node temp = head;
      head = head.next;
      temp.next = null;
      return temp.value;
    }
    
  }
 
  public void enqueue(Character value){
    Node new_node = new Node();
    new_node.value = value;
    new_node.next = null;
    if (head == null){
      head = new_node;
      tail = new_node;
    }
    else{
      Node temp = new Node();
      temp = tail;
      tail = new_node;
      temp.next = new_node;
    }
  }

  public void print_queue(){
    Node temp = head;
    while (temp!=null){
      System.out.print(temp.value + "  ");
      temp = temp.next;
    }
    System.out.println();
  }
  public int size(){
    return size;
  }

}

public class queue {
  public static void main(String[] args) {
    Queue q = new Queue();
    int option;
    Character value;
    Scanner input = new Scanner(System.in);
    while(true){
      System.out.println("Choose Option:");
      System.out.println("1) Enqueue");
      System.out.println("2) Dequeue");
      System.out.println("3) Print the Queue");
      System.out.println("4) Exit");

      option = input.nextInt();
      switch (option){
        case 1:{
          System.out.println("Enter value:");
          value = input.next().charAt(0);
          q.enqueue(value);
          break;
        }
        case 2: {
          System.out.println(q.dequeue());
          break;
        }
        case 3: {
          q.print_queue();
          break;
        }
        case 4: return;
      }
    }

  }
  
}