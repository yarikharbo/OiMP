#include <fstream>
#include <iostream>
#include <string>

void check_ifile(std::ifstream& fin);
void solve(std::ifstream& fin);

int32_t main()
{
  std::ifstream fin("input.txt");
  try
  {
    check_ifile(fin);
  }
  catch (const char* err)
  {
    std::cerr << err << std::endl;
    return 1;
  }
  solve(fin);
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

void solve(std::ifstream& fin)
{
  std::string first, str;
  std::getline(fin, first);
  int32_t ans{};
  while (fin >> str)
  {
    if (str == first)
    {
      ans++;
    }
  }
  std::cout << "How many times does the word \"" << first << "\" appear in the text: ";
  std::cout << ans << '\n';
}
