using System;

class BinarySearch
{
    static int BinarySearch(int[] numbers, int target)
    {
        int low = 0;
        int high = numbers.Length - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (numbers[mid] == target)
            {
                return mid;
            }
            else if (numbers[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }

    static void Main()
    {
        int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int result = BinarySearch(nums, 8);

        if (result != -1)
        {
            Console.WriteLine("Number found at index: {0}", result);
        }
        else
        {
            Console.WriteLine("Number not found");
        }
    }
}
