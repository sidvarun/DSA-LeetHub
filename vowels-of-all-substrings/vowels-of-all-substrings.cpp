class Solution {
public:
    long long countVowels(string word) {
        long long res = 0;
        long long n = word.length();
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        for(long long i = 0; i<word.length(); i++){
            if(vowels.find(word[i]) != vowels.end())
                res += (i + 1) * (n - i);
        }
        return res;
    }
};