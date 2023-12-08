using System;

class LinearSearch
{
    static int LinearSearch(int[] arr, int target)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    static void Main()
    {
        int[] arr = { 12, 45, 7, 23, 56, 89, 34, 8 };
        int target = 23;

        int result = LinearSearch(arr, target);

        if (result != -1)
        {
            Console.WriteLine($"Element {target} found at index {result}.");
        }
        else
        {
            Console.WriteLine($"Element {target} not found in the array.");
        }
    }
}
