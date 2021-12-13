#include<iostream>
#include<cstring>
using namespace std;

template<class T>
struct Status
{
  T* currentItem;
  int count;
};

template<class T>
class SmartPoint
{
  Status<T> *StatPtr;
  string name;
public: 
  SmartPoint(string _name,T* ptr = 0)
  {
      if(!ptr)
        StatPtr = NULL;
      else
      {
        StatPtr = new Status<T>;
        StatPtr->currentItem = ptr;
        StatPtr->count = 1;
        name = _name;
      }    
  }
  SmartPoint(const SmartPoint &p): StatPtr(p.StatPtr)
  {
    cout << "copy constructor" << endl;
    if(StatPtr)
    {
      name = "copy " + p.name;
      StatPtr->count++;
      cout << name << " count:" << StatPtr->count <<endl;
    }
  }
  ~SmartPoint()
  {
    cout << "destructor" << endl;
    StatPtr->count--;
    cout << name << " count:" << StatPtr->count <<endl;
    
    if(StatPtr->count <= 0)
    {
      cout << "delete " << name << " by smart-point" << endl;
      delete StatPtr->currentItem;
      delete StatPtr;
    }
    else
      cout << name << " cant delete" <<endl;
  }
  T* operator ->() const
  {
    if(StatPtr)
      return StatPtr->currentItem;
    else 
      return NULL;
  }

  void SetValue(T* p)
  {
    StatPtr->currentItem = p;
  }
  T* GetValue()
  {
    return StatPtr->currentItem;
  }
  
  SmartPoint operator = (const SmartPoint &p)
  {
    cout << "operator '=' " << endl;
    if(StatPtr)
    {
      StatPtr->count--;
      cout << name << " count:" << StatPtr->count <<endl;
      
      if(StatPtr->count <= 0)
      {
        cout << "delete " << name << " by smart-point" << endl;
        delete StatPtr->currentItem;
        delete StatPtr;
      }
      else
        cout << name << " cant delete" <<endl;
    }
    StatPtr = p.StatPtr;
    if(StatPtr)
    {
      StatPtr->count++;
      cout << name << " count:" << StatPtr->count <<endl;
    } 
    return *this;
  }
};