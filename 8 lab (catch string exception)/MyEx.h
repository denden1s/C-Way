#include <iostream>
#include <string> 
using namespace std;

class MyEx
{
	private:
		string message;
	public:
	MyEx(string _message)
	{
		message = _message;
	}
	void Show()
	{
		cout << message << endl;
	}
};