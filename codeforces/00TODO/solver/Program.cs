using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Linq;

namespace solver
{
    internal class Program
    {
        private const string _sourcePath = @"\..\Solve\";

        private static void Main(string[] args)
        {
            var result = ProblemList.GetProblemList();
            List<Problem> problemList = result.result.problems;

            problemList.Sort(delegate (Problem x, Problem y)
            {
                return x.rating.CompareTo(y.rating);
            });

            foreach (var item in problemList
                .Where(x => x.rating != 0)
                .Where(x => x.contestId != 1002)
                )
            {
                string sourcePath = Directory.GetCurrentDirectory() + _sourcePath + item.contestId + item.index;
                bool isExist = Directory.Exists(sourcePath);
                if (!isExist)
                {
                    Console.Write(item.contestId + item.index);
                    break;
                }
            }
        }
    }
}