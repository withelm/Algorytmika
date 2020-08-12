﻿using System;

namespace _58
{

    using System.Linq;
    public class Solution
    {
        public int LengthOfLastWord(string s)
        {
            var tab = s.Split(' ', StringSplitOptions.RemoveEmptyEntries);
            if (tab.Count() == 0) return 0;
            return tab.Last().Length;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

        }
    }
}
