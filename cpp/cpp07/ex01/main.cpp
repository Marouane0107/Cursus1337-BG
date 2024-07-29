# include "iter.hpp"


int main() {
  int	tab[] = { 0, 1, 2, 3, 4 };
  char	tab2[] = {"hello"};

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<char> );

  return 0;
}