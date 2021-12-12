public class Solution {
    public int CountCharacters(string[] words, string chars) {
        int count = 0;
        Dictionary<char, int>[] dictionaries = new Dictionary<char, int>[words.Length];
        for(int i = 0; i < dictionaries.Length; ++i)
            dictionaries[i] = new Dictionary<char, int>();
        
        // initialize the dictionary
        for(int i = 0; i < words.Length; ++i) {
            foreach(char c in words[i]) {
                if(dictionaries[i].ContainsKey(c))
                    ++dictionaries[i][c];
                else
                    dictionaries[i][c] = 1;
            }
        }

        foreach(Dictionary<char, int> dictionary in dictionaries) {
            bool foundAll = true;
            foreach(char c in chars) {
                if(!dictionary.ContainsKey(c)) {
                    foundAll = false;
                } else {
                    if(dictionary[c] > 1)
                        --dictionary[c];
                    else {
                        if(dictionary.Count() == 1)
                            break;
                        else
                            dictionary.Remove(c);
                    }
                }
            }

            if(foundAll)
                ++count;
        }

        return count;
    }
}
