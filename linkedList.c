using System;

class Node
{
    public int Data;
    public Node Next;

    public Node(int data)
    {
        Data = data;
        Next = null;
    }
}

class LinkedList
{
    public static Node InsertAtBeginning(int data, Node head)
    {
        Node newNode = new Node(data);
        newNode.Next = head;
        return newNode;
    }

    public static Node LinkedListInsert(Node head, int index, int data)
    {
        if (index == 0)
        {
            return InsertAtBeginning(data, head);
        }

        Node current = head;
        Node previous = null;
        int count = 0;

        while (count < index && current != null)
        {
            previous = current;
            current = current.Next;
            count++;
        }

        if (count < index)
        {
            Console.WriteLine("Invalid index error.");
            return head;
        }

        Node newNode = new Node(data);
        newNode.Next = previous.Next;
        previous.Next = newNode;

        return head;
    }

    public static Node LinkedListLookup(Node head, int elementNumber)
    {
        Node current = head;
        int count = 0;

        while (count < elementNumber && current != null)
        {
            current = current.Next;
            count++;
        }

        return current;
    }

    public static Node LinkedListDelete(Node head, int index)
    {
        if (head == null)
        {
            return null;
        }

        if (index == 0)
        {
            Node newHead = head.Next;
            head.Next = null;
            return newHead;
        }

        Node current = head;
        Node previous = null;
        int count = 0;

        while (count < index && current != null)
        {
            previous = current;
            current = current.Next;
            count++;
        }

        if (current != null)
        {
            previous.Next = current.Next;
            current.Next = null;
        }
        else
        {
            Console.WriteLine("Invalid index");
        }

        return head;
    }

    static void Main()
    {
        Node one = new Node(2);
        Node two = new Node(3);

        Node newHead = LinkedListInsert(one, 0, 3);
        Node newNode = LinkedListInsert(one, 1, 3);

        Console.WriteLine("Address of newHead's next: {0}", newHead?.Next);
        Console.WriteLine("Address of newNode: {0}", newNode);
    }
}
