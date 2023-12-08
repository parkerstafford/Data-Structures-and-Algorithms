using System;

class Program
{
    static void Main()
    {
        EatBanana(10);
    }

    static void EatBanana(int bananas)
    {
        if (bananas < 1) return;
        Console.WriteLine("You ate a banana!");
        EatBanana(bananas - 1);
    }
}
