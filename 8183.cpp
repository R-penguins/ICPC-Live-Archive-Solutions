/**
 * Haiku
 * ICPC 2017 Mid-Atlantic
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  string vowel = "aeiouy", vowelNoY = "aeiou";
  string line;
  while (getline(cin, line))
  {
    vector<int> haiku {5, 7, 5};
    int haikuLine = 0;
    vector<string> ans;
    bool ok = true;
    stringstream ss(line);
    string rawWord;
    while (ok && (ss >> rawWord))
    {
        string word = "";
        for (char c : rawWord)
        {
            if (!isalpha(c))
                break;
            word += tolower(c);
        }
        if (word.size() && haikuLine >= 3)
        {
            ok = false;
            break;
        }
        size_t pos = 0;
        while ((pos = word.find("qu", pos)) != string::npos)
        {
            word.erase(pos + 1, 1);
            ++pos;
        }
        pos = 0;
        while ((pos = word.find('y', pos)) != string::npos)
        {
            if (pos + 1 < word.size() && vowelNoY.find(word[pos + 1] != string::npos))
                word[pos] = 'c';
            ++pos;
        }
        if (word.back() == 'e' && !(word.size() >= 3 && word[word.size() - 2] == 'l' && vowel.find(word[word.size() - 3] == string::npos)))
            word.pop_back();
        else if (word.size() >= 2 && word.substr(word.size() - 2, 2) == "es" && !(word.size() >= 4 && vowel.find(word[word.size() - 3]) == string::npos && vowel.find(word[word.size() - 4]) == string::npos))
            word.erase(word.size() - 2);
        pos = 0;
        while ((pos = word.find_first_of(vowel, pos)) != string::npos)
        {
            if (pos + 1 < word.size() && vowel.find(word[pos + 1]) != string::npos)
                word.erase(pos, 1);
            ++pos;
        }
        int cnt = 0;
        for (char c : word)
            if (vowel.find(c) != string::npos)
                ++cnt;
        if (!cnt)
            cnt = 1;
        haiku[haikuLine] -= cnt;
        if (haiku[haikuLine] < 0)
            ok = false;
        else
        {
            ans.push_back(rawWord);
            ans.push_back(" ");
            if (haiku[haikuLine] == 0)
            {
                ans.pop_back();
                ans.push_back("\n");
                ++haikuLine;
            }
        }
    }
    if (haikuLine < 2)
        ok = false;
    if (ok)
        for (string &str : ans)
            cout << str;
    else
        cout << line << "\n";
  }
}
