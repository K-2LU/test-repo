#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
  freopen("argv[1]", "r", stdin);
  
  int n;
  std::cin >> n;
  
  if (n > 1000 || n < 1) {
    std::cout << n << std::endl;
    std::cout << "Invalid input (out of bounds)" << std::endl;
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    int x; std::cin >> x;
    if (x > 10000 || x < 1) {
      std::cout << "Invalid input (out of bounds)" << std::endl;
      return 1;
    }
  }
  std::cout << "Valid input" << std::endl;

  return 0;
}

