/* 
1394. Goat Latin
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.

For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append
it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.

Example
Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

Notice
S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/

// make use of istringstream to separate word

class Solution {
public:
    string  toGoatLatin(string &S) {
        istringstream line(S);
        string result, word;
        string append = "maa";
        while(line >> word) // get a word from sentence
        {
            // add word
            if (!isVowel(word[0]))
            {
                word += word[0];
                result = result + word.substr(1, word.size() - 1);
            }
            else
            {
                result = result + word;
            }
            // append ma and a to result
            result += append;
            // add a to append
            append += 'a';
            // add space to result
            result += ' ';
        }
        // remove the last space
        result.resize(result.size() - 1);
        // return
        return result;

    }
    
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
};


/// FIRST PASS
/*
class Solution {
public:
    string  toGoatLatin(string &S) {
        if (S.empty()) return S;
        string result;
        
        // find start and end of earch word by locating dividers
        vector<int> wordIndices;
        if (S[0] != ' ') wordIndices.push_back(0);
        for(int i = 0; i < S.size(); i++)
        {
            // a divider
            if (S[i] == ' ')
            {
                if (i !=0 && S[i-1] != ' ') // prev end
                    wordIndices.push_back(i - 1);
                if (i < S.size() - 1 && S[i + 1] != ' ') // next begin
                    wordIndices.push_back(i + 1);
            }
        }
        if (S[S.size() - 1] != ' ') wordIndices.push_back(S.size() - 1);
        
        // if empty
        if (wordIndices.empty()) return result;
        // for each word
        int iword(0);
        while(iword < wordIndices.size() / 2)
        {
            int wlen = wordIndices[2 * iword + 1] - wordIndices[2 * iword] + 1;
            int wstart = wordIndices[2 * iword];
            bool isV = isVowel(S[wstart]);
            // copy the word
            for(int i = 0; i < wlen; i++)
            {
                // put the last one to the end
                if (!isV)
                {
                    result.push_back(S[(i + 1) % wlen + wstart]);
                }
                else
                {
                    result.push_back(S[wstart + i]);
                }
            }
            // append a
            appendMaa(result, iword + 1);
            result = result + ' ';
            iword++;
        }
        result.resize( result.size() - 1 );
        return result;
    }
    
    void appendMaa(string& str, int cnt)
    {
        str  = str + "ma";
        for(int i = 0; i < cnt; i++)
        {
            str = str + 'a';
        }
    }
    
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
};
// find the divider between words by finding space or end of string
// if next start not vowel, move the first to the end
// append ma
// count the index of word
// append a
*/