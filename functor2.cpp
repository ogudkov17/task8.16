#include <iostream>
#include <string>
#include <map>

using namespace std;

class Functor {
public:
	virtual void operator()(){};
};
class FunctorShow:public Functor {
public:
	FunctorShow(){};
	void operator()(){cout<<"show"<<endl;}	
};
class FunctorCreate:public Functor {
public:
	FunctorCreate(){};
	void operator()(){
		cin>>classname>>value;
		cout<<classname<<" "<<value<<endl;
	}	
private:
	string classname;
	int value;
};

map <string, Functor*> mfunc;

int main()
{
	Functor *f = new FunctorShow;
	Functor *fc = new FunctorCreate;
	mfunc["showall"]=f;
	mfunc["create"]=fc;
	string command;
	cin>>command;
	Functor *fctr = mfunc[command];
	if (fctr) (*fctr)();
}
