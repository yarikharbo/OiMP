#include <fstream>
#include <iostream>
#include <string>

void solve(std::ifstream& fin, std::ofstream& fout);
void check_ifile(std::ifstream& fin);
void check_ofile(std::ofstream& fout);
void check_integer(std::ifstream& fin, int32_t& a, int32_t& b);
bool check_separator(const char chr, std::string& sep);
bool isInteger(const std::string& str);

int32_t main()
{
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");
  try
  {
    check_ifile(fin);
    check_ofile(fout);
  }
  catch (const char* err)
  {
    std::cerr << err << std::endl;
    return 1;
  }
  try
  {
    solve(fin, fout);
  }
  catch (const char* err)
  {
    std::cerr << err << std::endl;
  }
  fout.close();
  fin.close();
  return 0;
}

void check_ifile(std::ifstream& fin)
{
  if (!fin.good())
  {
    throw "File doesn't exist";
  }
  if (fin.peek() == EOF)
  {
    throw "File is empty";
  }
}

void check_ofile(std::ofstream& fout)
{
  if (!fout)
  {
    throw "Failed to create output file";
  }
}

void solve(std::ifstream& fin, std::ofstream& fout)
{
  std::string sep;
  std::getline(fin, sep);
  int32_t a{}, b{};
  check_integer(fin, a, b);
  fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::string str, strf, ans;
  while (std::getline(fin, str))
  {
    strf = str;
    for (size_t i = 0; i <= str.size(); ++i)
    {
      if (i == str.size() || check_separator(str[i], sep))
      {
        if (!ans.empty() && isInteger(ans))
        {
          int32_t num = std::stoi(ans);
          if (num >= a && num <= b)
          {
            str.erase(i - ans.size(), ans.size());
            i -= ans.size();
            fout << ans << ' ';
          }
        }
        ans = "";
      }
      else
      {
        ans += str[i];
      }
    }
    if (strf != str)
    {
      fout << "|| ";
    }
    fout << str << std::endl;
  }
}

void check_integer(std::ifstream& fin, int& a, int& b)
{
  if (!(fin >> a >> b))
  {
    if (fin.fail() || abs(b) > INT_MAX || abs(a) > INT_MAX)
    {
      throw "Error. Enter integers";
    }
  }
}

bool check_separator(char chr, std::string& sep)
{
  for (size_t j = 0; j < sep.size(); ++j)
      {
        if (chr == sep[j])
        {
          return 1;
        }
      }
  return 0;
}

bool isInteger(const std::string& str) {
  if (str.empty()) return false;
  size_t i = 0;
  if (str[0] == '-')
  {
    i = 1;
    if (str.size() == 1) return false;
  }
  for (; i < str.size(); ++i)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

