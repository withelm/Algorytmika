using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Text;

namespace solver
{
    public enum Type
    {
        PROGRAMMING,
        QUESTION
    }

    public class Problem
    {
        public int contestId;
        public string problemsetName;
        public string index;
        public string name;
        public Type type;
        public double points;
        public int rating;
        public List<string> tags;
    }

    public class ProblemStatistics
    {
        public int contestId;
        public string index;
        public int solvedCount;
    }

    public class TwoList
    {
        public List<Problem> problems;
        public List<ProblemStatistics> problemStatistics;
    }

    public class Response
    {
        public string status;
        public TwoList result;
    }

    public class ProblemList
    {
        private const string _codeforceProblemSet = @"https://codeforces.com/api/problemset.problems";

        public static Response GetProblemList()
        {
            var response = HttpRequest.SendHttpWebPost(_codeforceProblemSet);

            return JsonConvert.DeserializeObject<Response>(response);
        }
    }
}