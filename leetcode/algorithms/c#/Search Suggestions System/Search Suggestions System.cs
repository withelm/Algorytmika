public class Solution
{
    public IList<IList<string>>
    SuggestedProducts(string[] products, string searchWord)
    {
        var result = new List<List<string>>();
        var productsList = products.ToList();
        for (int i = 1; i <= searchWord.Count(); i++)
        {
            var sr = searchWord.Substring(0, i);

            result
                .Add(productsList
                    .Where(x => x.StartsWith(sr))
                    .OrderBy(x => x)
                    .Take(3)
                    .ToList());
        }

        return result.ToList<IList<string>>();
    }
}
