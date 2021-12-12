public class Solution {
    public IList<string> CommonChars(string[] A) {
        List<String> ret = new List<String>();
        Dictionary<char, int>[] dictionary = new Dictionary<char, int>[A.Length - 1];
        for(int i = 0; i < dictionary.Length; ++i) 
            dictionary[i] = new Dictionary<char, int>();

        // initialize the dictionary
        for(int i = 1; i < A.Length; ++i) {
            foreach(char c in A[i]) {
                if(dictionary[i - 1].ContainsKey(c))
                    dictionary[i - 1][c] = dictionary[i - 1][c] + 1;
                else
                    dictionary[i - 1][c] = 0;
            }
        }

        foreach(char c in A[0]) {
            bool foundInAll = true;
            foreach(Dictionary<char, int> d in dictionary) {
                if(!d.Contains(c)) {
                    foundInAll = false;
                    break;
                } else {
                    if(d[c] > 1)
                        d[c] = d[c] - 1;
                    else
                        d.Remove(c);
                }
            }

            if(foundInAll)
                ret.Add(c.ToString());
        }
        
        return ret;
    }
}