#include <fstream>
#include <iostream>
#include <string>
//#include <filesystem>

void check_file(std::ifstream& fin);
void check_file(std::ofstream& fout);

int32_t main()
{
  std::ifstream fin ("input.txt");
  std::ofstream fout ("output.txt");
  try
  {
    check_file(fin);
    check_file(fout);
  }
  catch (const char* err)
  {
    fin.close();
    fout.close();
    std::cout << err << std::endl;
    return 0;
  }
  std::string str;
  while (std::getline(fin, str))
  {
    fout << str << std::endl;
  }
  fin.close();
  fout.close();
  std::cout << "File is done" << std::endl;
  return 0;
}

void check_file(std::ifstream& fin)
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

void check_file(std::ofstream& fout)
{
  if (!fout.good())
  {
    throw "File doesn't exist";
  }
}
