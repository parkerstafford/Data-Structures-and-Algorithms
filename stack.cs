using System;

class Stack
{
    private int ArraySize;
    private int Top;
    private int[] Array;

    public Stack(int arraySize)
    {
        ArraySize = arraySize;
        Top = -1;
        Array = new int[arraySize];
    }

    public void Push(int value)
    {
        if (Top == ArraySize - 1)
        {
            Console.WriteLine("Stack Overflow");
            return;
        }
        Top += 1;
        Array[Top] = value;
    }

    public int Pop()
    {
        if (Top > -1)
        {
            int value = Array[Top];
            Top = Top - 1;
            return value;
        }
        else
        {
            Console.WriteLine("Stack Underflow");
            return -1; 
        }
    }
}

class Program
{
    static void Main()
    {
        Stack first = new Stack(5);

        first.Push(10);
        first.Push(20);
        first.Push(30);

        Console.WriteLine("Popped: {0}", first.Pop());
        Console.WriteLine("Popped: {0}", first.Pop());
    }
}
