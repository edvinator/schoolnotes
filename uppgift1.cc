#include <iostream>
#include <stdexcept>
#include <array>
#include <vector>
using namespace std;


template <typename C> // C as container
typename C::size_type find_index(C const & container,typename C::value_type const &val)
{
  auto cbegin = container.begin();
  auto cend = container.end();
  typename C::size_type atindex{0};
  while (cbegin != cend && *cbegin != val)
    {
      ++atindex;
      ++cbegin;
    }
  
  if(cbegin == cend)
    throw out_of_range("index not found");
  return atindex;
}
int main()
{
    vector<int> vals{1,2,3,5,2};
    cout << "Index of the first 2: " << find_index(vals, 2) << endl;
    try
    {
        find_index(vals, 12);
    } 
    catch (std::out_of_range const & e)
    {
        cout << e.what() << endl;
    }
    array<double, 5> arr {1.3, 2.1, 3, 4.5, 5.0};
    cout << "Index of 3: " << find_index(arr, 3) << endl;
}
