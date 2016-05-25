#include <iostream>
#include <string>
#include <map>

using namespace std;

class Functor {
public:
	virtual void operator()(){};
	virtual void operator()(string, int){};
};
class FunctorShow:public Functor {
public:
	FunctorShow(){};
	void operator()(){cout<<"show"<<endl;}	
};
class FunctorCreate:public Functor {
public:
	FunctorCreate(){};
	void operator()(string classname, int value){cout<<classname<<endl;}	
};

map <int, Functor*> mfunc;

int main()
{
	Functor *f = new FunctorShow;
	Functor *fc = new FunctorCreate;
	mfunc[0]=f;
	mfunc[1]=fc;
	Functor *fctr = mfunc[0];
	(*fctr)();
	Functor *fctr1 = mfunc[1];
	(*fctr1)(string("asdf"), 1);
}
