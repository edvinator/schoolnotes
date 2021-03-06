#include <iostream>
#include <vector>
#include <array>
#include <iterator>

using namespace std;

template <typename T,int N>
class Ring_Buffer
{
public:
   void put(T const & val)
   {
     *writepos = val;
     increasewrite();
   
       
   }
   T const & get()
   {
     T &tmp = *readpos;
     increaseread();
     return tmp;
   }
  
private:
  array<T,N> vals;
  T *writepos{begin(vals)};
  T *readpos{begin(vals)};
  //typename array<T,N>::iterator read{begin(vals)},write{begin(vals)};
  void increaseread()
  {
    ++readpos;
    overtake = false;
    if(readpos==end(vals))
     readpos = begin(vals);
  }
  void increasewrite()
  {
    ++writepos;
    if(writepos==end(vals))
      {
	writepos = begin(vals);
      }
    if(writepos == readpos)
      overtake = true;

    increaseread();
  }
  bool overtake{false};
};


int main()
{
    Ring_Buffer<int, 5> buf;
    for ( int i {}; i < 7; ++i )
    {
        buf.put(i);
    }
    // The content of the buffer
    // Added values 0-4:
    // 0 1 2 3 4
    // Added 5 and 6:
    // 5 6 2 3 4

    cout << "Should print 2: " << buf.get() << endl;
    cout << "Should print 3: " << buf.get() << endl;
    cout << "Should print 4: " << buf.get() << endl;
    cout << "Should print 5: " << buf.get() << endl;
}
