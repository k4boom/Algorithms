#include<bits/stdc++.h>
using namespace std;
class employe
{
protected:
	string name;
	string departman;

public:
	employe(string names,string dep){
		name=names;departman=dep;
	};
	void employeIntro(){
		cout<<"It's "<<name<<" from "<<departman<<endl;
	}
	
};
class parttime:public employe
{
private:
	int Dailywage;
	int workhour;
public:
	 parttime(string nam,string dp):employe(nam,dp){};
	 void getWage(){
		cout<<name<<" earns "<<Dailywage<<"$ per Day"<<endl;
	}

	 void getWorkhour(){
	 	cout<<name<<" works "<<workhour<<" hours per Day"<<endl;
	 }

	 void setWorkhour(int hour){
	 	workhour=hour;
	 }
	 void setWage(){
	 	Dailywage=departman.size()*workhour;
	 }



	~ parttime(){
		cout<<"I work for nothing but need to eat something"<<endl;
	};
	
};
class fulltime:public employe
{
private:
	int salary;
public:
	fulltime(string nam,string dp):employe(nam,dp){
		
	}
	int workhour;
	void getSalary(){
		cout<<name<<" earns "<<salary<<"$ per Month"<<endl;
	}
	void getWorkhour(){
		cout<<name<<" works "<<workhour<<" hours per Week"<<endl;
	}
	void setHour(int hour){
		workhour=hour;
	}
	void setSalary(){
		salary=((float)workhour/departman.size())*1000;
	}
	~fulltime(){
		cout<<"Wait what?!?";
	}
};

int main(){
	fulltime John("john","Quality Assurance");
	parttime Elisa("elisa","Frontend Developer");
	
	John.setHour(40);
	John.setSalary();
	Elisa.setWorkhour(6);
	Elisa.setWage();
	Elisa.employeIntro();
	John.employeIntro();
	Elisa.getWorkhour();
	John.getWorkhour();
	
	John.getSalary();
	Elisa.getWage();
}
