using System;
using System.Numerics;

namespace _664A
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string input = Console.ReadLine();

            var numbers = input.Split(' ');

            BigInteger a = BigInteger.Parse(numbers[0]);
            BigInteger b = BigInteger.Parse(numbers[1]);

            if (a == b) Console.WriteLine(a.ToString());
            else Console.WriteLine("1");
        }
    }
}