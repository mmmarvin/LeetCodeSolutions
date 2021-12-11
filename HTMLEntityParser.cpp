/**
 * Solution to https://leetcode.com/contest/weekly-contest-184/problems/html-entity-parser/
 **/ 

class Solution {
public:
    string get_symbol(const string& text, size_t& index)
    {
        string ret;
        ret.push_back(text[index]);
        
        for(size_t i = index + 1; i < text.size(); ++i) {
            auto c = text[i];
            ret.push_back(c);
                
            if(c == ';') {
                index = i + 1;
                break;
            }
        }
                
        return ret;
    }
    
    string convert_to_special_character(string symbol)
    {
        static const unordered_map<string, string> symbol_to_special = {
            { "&quot;", "\"" },
            { "&apos;", "\'" },
            { "&amp;", "&" },
            { "&gt;", ">" },
            { "&lt;", "<" },
            { "&frasl;", "/" },
        };
        
        if(symbol_to_special.find(symbol) == symbol_to_special.end())
            return symbol;
        
        return symbol_to_special.find(symbol)->second;
    }
    
    string entityParser(string text) {
        string ret;
        
        for(size_t i = 0; i < text.size(); ) {
            auto c = text[i];
            if(c == '&') {
                string symbol = get_symbol(text, i);
                ret += convert_to_special_character(symbol);
                continue;
            }
            else
                ret.push_back(c);
            ++i;
        }
        
        return ret;
    }
};
