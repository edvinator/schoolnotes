#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;
template <typename it>
void first_lowest(it beg, it end,it stop)
{
    while (beg != stop)
      {
	swap(*(min_element(beg,end)),*beg);
	++beg;
      }
}
int main(int argc,char* argv[])
{
  ifstream file;
  file.open(argv[1]);
  istream_iterator<int> filebeg{file};
  istream_iterator<int> fileend{};

  vector<int> numbs{filebeg,fileend};
  cout<<"Antal nummer: "<<numbs.size()<<endl;

  copy(begin(numbs),end(numbs),ostream_iterator<int>{cout," "});
  auto numbneg = count_if(begin(numbs),end(numbs),[](int num)
			  {
			    if (num < 0)
			      return true;
			    return false;
			  }
			  );
  cout<<"\nAntal negativa tal: "<<numbneg<<endl;
  for_each(begin(numbs),end(numbs),[](int &num)
	   {
	     if(num<0)
	       num = num * -1;
	       });
  copy(begin(numbs),end(numbs),ostream_iterator<int>{cout," "});
  cout<<endl;
  for_each(begin(numbs),end(numbs),[](int &num)
	   {
	     if(num<0)
	       num = num * -1;
	       });
  first_lowest(begin(numbs),end(numbs), begin(numbs)+5);
  copy(begin(numbs),end(numbs),ostream_iterator<int>{cout," "});
  cout<<endl;
  numbs.erase(begin(numbs),begin(numbs) + 5);
  copy(begin(numbs),end(numbs),ostream_iterator<int>{cout," "});
  cout<<endl;
  
  return 0;
}
