#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

const int MAX = 10000;

void solve();
void check_separator(char sep);
bool is_integer(const std::string& str);
void sieve(bool* m);

int32_t main()
{
  try
  {
    solve();
  }
  catch (const char* err)
  {
    std::cerr << err << std::endl;
  }
  return 0;
}

void solve()
{
  std::cout << "Enter a separator(Examples:  !#$%&'()*+,-./:;<=>?@[]^_`{|}~):\n";
  char sep;
  std::cin.get(sep);
  check_separator(sep);
  std::cout << "Enter a string:\n";
  std::string str, ans;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, str);
  bool m[MAX]{};
  sieve(m);
  std::cout << "All prime numbers in the string:\n";
  for (size_t i = 0; i <= str.size(); ++i)
  {
    if (i == str.size() || str[i] == sep)
    {
      if (!ans.empty() && is_integer(ans))
      {
        int32_t num = std::stoi(ans);
        if (!m[num] && num < MAX && num > 1)
        {
          std::cout << ans << ' ';
        }
      }
      ans = "";
    }
    else
    {
      ans += str[i];
    }
  }
}

void check_separator(char sep)
{
  std::string separators{" !#$%&'()*+,-./:;<=>?@[]^_`{|}~"};
  bool findsep = 0;
  for (size_t i = 0; i < separators.size(); ++i)
  {
    if (sep == separators[i])
    {
      findsep = 1;
      return;
    }
  }
  if (!findsep)
  {
    throw "Error. Separator not found.";
  }
}

bool is_integer(const std::string& str) {
  if (str.empty()) return 0;
  for (size_t i = 0; i < str.size(); ++i)
  {
    if (!std::isdigit(str[i]))
    {
      return 0;
    }
  }
  return 1;
}

void sieve(bool* m)
{
  for (size_t i = 2; i * i < MAX; ++i)
  {
    if (!m[i])
    {
      for (size_t j = i * i; j < MAX; j += i)
      {
        m[j] = 1;
      }
    }
  }
}
