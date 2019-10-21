#include <bits/stdc++.h>
using namespace std;
struct Pb
{
  int w = 1;
  shared_ptr<Pb> l = nullptr, r = nullptr;
};
string line;
int parseInt(int &i)
{
  int ans = 0;
  while (isdigit(line[i]))
  {
    ans *= 10;
    ans += line[i++] - '0';
  }
  return ans;
}
void build(shared_ptr<Pb> ptr, int &i)
{
  ++i;
  while (isspace(line[i]))
    ++i;
  if (line[i] == '[')
    build(ptr->l, i);
  else if (isdigit(line[i]))
    ptr->w += parseInt(i) + 2;
}
int main()
{
  while (getline(cin, line) && line != "[]")
  {
    shared_ptr<Pb> root = make_shared<Pb>();
    build(root, 0);
  }
}
