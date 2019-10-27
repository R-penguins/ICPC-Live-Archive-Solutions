/**
 * Hy-phe-na-tion Rulez
 * ICPC 2014 Mid-Atlantic
 */
#include <bits/stdc++.h>
using namespace std;
string tl(const string str)
{
  string ans = "";
  for (auto &c : str)
    ans += tolower(c);
  return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const set<string> CONS {"qu", "tr", "br", "st", "sl", "bl", "cr", "ph", "ch"};
  const string VO("aeiouyAEIOUY");
  string line;
  while (getline(cin, line) && line != "===")
  {
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
      string cv, lw = tl(word);
      vector<string> ref;
      for (int i = 0; i < word.size(); ++i)
        if (VO.find(word[i]) != string::npos)
        {
          cv += 'v';
          ref.push_back(string(1, word[i]));
        }
        else if (isalpha(word[i]))
        {
          cv += 'c';
          if (i + 3 <= word.size() && lw.substr(i, 3) == "str")
          {
            ref.push_back(word.substr(i, 3));
            i += 2;
          }
          else if (i + 2 <= word.size() && CONS.count(lw.substr(i, 2)))
          {
            ref.push_back(word.substr(i, 2));
            ++i;
          }
          else
            ref.push_back(string(1, word[i]));
        }
        else
        {
          cv += word[i];
          ref.push_back(word.substr(i, 1));
        }
      for (int i = 0; i < cv.size(); ++i)
        if (i + 2 < cv.size() && cv.substr(i, 2) == "vc")
          if (cv[i + 2] == 'v' && !(i + 2 == cv.size() - 1 && tolower(ref[i + 2][0]) == 'e'))
          {
            ref[i] += '-';
            ++i;
          }
          else if (i + 3 < cv.size() && cv.substr(i + 2, 2) == "cv")
          {
            ref[i + 1] += '-';
            i += 2;
          }
      for (string &s : ref)
        cout << s;
      cout << "\n";
    }
  }
}

