using System;

class LinkedListNode
{
    public int Data;
    public LinkedListNode Next;

    public LinkedListNode(int data)
    {
        Data = data;
        Next = null;
    }
}

class Queue
{
    private LinkedListNode Front;
    private LinkedListNode Back;

    public void Enqueue(int data)
    {
        LinkedListNode node = new LinkedListNode(data);

        if (Back == null)
        {
            Front = node;
            Back = node;
        }
        else
        {
            Back.Next = node;
            Back = node;
        }
    }

    public int Dequeue()
    {
        if (Front == null)
        {
            throw new InvalidOperationException("Queue is empty.");
        }

        int data = Front.Data;
        Front = Front.Next;

        if (Front == null)
        {
            Back = null;
        }

        return data;
    }
}

class Program
{
    static void Main()
    {
        Queue queue = new Queue();

        queue.Enqueue(20);
        queue.Enqueue(30);

        Console.WriteLine("Dequeued: {0}", queue.Dequeue());
        Console.WriteLine("Dequeued: {0}", queue.Dequeue());
    }
}
