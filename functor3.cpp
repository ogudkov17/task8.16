#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Functor {
public:
	virtual void operator()(vector<string> args){};
	virtual int getArgNum(){};
};
class FunctorShow:public Functor {
public:
	FunctorShow(){};
	void operator()(vector<string> args){cout<<"show"<<endl;}	
	int getArgNum(){ return 0;};
};
class FunctorCreate:public Functor {
public:
	FunctorCreate(){};
	void operator()(vector<string> args){
		cout<<args[0]<<" "<<args[1]<<endl;
	}	
	int getArgNum(){ return 2;}
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
	if (fctr) {
		vector<string> strvec;
		int argnum = fctr->getArgNum();
		for (int i=0; i<argnum; i++) {
			string str;
			cin>>str;
			strvec.push_back(str);
		}
		(*fctr)(strvec);
	}
}
