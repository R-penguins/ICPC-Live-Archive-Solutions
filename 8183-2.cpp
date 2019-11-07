/**
 * Haiku
 * ICPC 2017 Mid-Atlantic
 * Regex based
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  regex qu("qu"), y("y([aeiou])"), vowel("[aeiouy]+");
  regex eOK("[a-z]*[^aeiouy]le$");
  regex esEnd("[a-z]*es$"), esOK("[a-z]*[^aeiouy][^aeiouy]es$");
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
      word = regex_replace(word, qu, "c");
      word = regex_replace(word, y, "c$1");
      if (word.back() == 'e' && !regex_match(word, eOK))
        word.pop_back();
      else if (regex_match(word, esEnd) && !regex_match(word, esOK))
        word.erase(word.size() - 2);
      int cnt = distance(sregex_iterator(word.begin(), word.end(), vowel), sregex_iterator());
      if (!cnt)
        cnt = 1;
      haiku[haikuLine] -= cnt;
      if (haiku[haikuLine] < 0)
        ok = false;
      else
      {
        ans.push_back(rawWord);
        if (haiku[haikuLine] > 0)
          ans.push_back(" ");
        else
        {
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
