#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

istream& operator>>(istream &lhs,pair<string,double> &fruit)
{
  lhs>>fruit.first;
  lhs>>fruit.second;
  return lhs;
}
int main()
{
  vector<pair<string,double>> unsortedv;
  set<pair<string,double>> sortedcont;
  map<string,double> sorteduniquecont;
  pair<string,double> tmp;
  ifstream fs{"frukt.txt"};
  while(fs.good())
    {
      fs>>tmp;
      sortedcont.insert(tmp);
    }
  fs.close();
  
  for(auto & elem: sortedcont)
    {
      cout<<elem.first<<' '<<elem.second<<endl;
    }
  for(auto const &elem: sortedcont)
    {
      sorteduniquecont[elem.first] += elem.second;
    }
  cout<<"\n\n";
  auto largest_pair = std::max_element(begin(sorteduniquecont),end(sorteduniquecont),[](pair<string,double> a,pair<string,double> b)
				       {
					 return a.first.size() < b.first.size();
				       }
				       );
  for(std::pair<string,double> const &elem: sorteduniquecont)
    {
      cout<<setw((*largest_pair).first.size())<<left<<elem.first<<' '<<elem.second<<endl;
    }
  
  
  return 0;
}
