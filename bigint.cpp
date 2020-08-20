#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
void reverseStr(string& str) //string reverser function
{ 
    int n = str.length();  
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
string addstr(string x,string z){			//function to add numbers in string form
	reverseStr(x);reverseStr(z);	
	string toplam="";
	string uzun,kisa;
	if(x.length()<z.length()){uzun=z;kisa=x;}	//firs we need to state which one is the shorter 
	else{uzun=x;kisa=z;}
	int border=min(x.length(),z.length());
	int reminder=0;								//also we need to keep track of the remainder
	if(uzun.length()==kisa.length()){uzun+="0";}//if the operands have equal length,add '0' to one of them to be able to add the remainder because if we dontthere will be no digit to add
	for (int a=0;a<border;a++){
		int xhol,zhol;				
		stringstream xol;						//we convert single chars to integers to add them one by one
		xol<<x[a];
		xol>>xhol;
		stringstream zol;
		zol<<z[a];
		zol>>zhol;								//add the remainder from the previous loop to one of the operands then refresh it
		xhol+=reminder;							
		reminder=0;
		int sum=xhol+zhol;
		if(sum>=10){
			sum=sum%10;
			reminder++;							//if the sum is bigger than 10,increase the remainder
		}
		string sum1=to_string(sum);
		toplam=toplam+sum1;						//add the sum to the sumstring
		
	}
	for (int a=border;a<uzun.length();a++){		//loop to pass out the rest of the long string
		stringstream tol;
		tol<<uzun[a];
		int topl;
		tol>>topl;
		topl+=reminder;
		string sum2=to_string(topl);
		toplam=toplam+sum2;						//add the digits to sumstring
	}
	
	if(toplam[toplam.length()-1]=='0'){			//if there was no remainder, we need to delete the '0' we added
		toplam.pop_back();
	}
	reverseStr(toplam);							//Don't forget to reverse the string to print correctly
	
	return toplam;

}

string multiplestr(string a,string b){
	string z,x;
	if(a.length()>b.length()){z=a;x=b;}else{z=b;x=a;}//z is the bigger one
	reverseStr(x);reverseStr(z);
	string* carp;
	carp=new string[x.length()];

	int* reminder;
	reminder=new int[x.length()+1];
	reminder[0]=0;
	for(int a=0;a<x.length();a++){
		carp[a]="";
		for(int b=0;b<z.length();b++){
			int xhol,zhol,sumhol;
			string sum;	
			stringstream sol;			
			stringstream xol;
			stringstream zol;
			xol<<x[a];
			xol>>xhol;
			zol<<z[b];
			zol>>zhol;
			sumhol=xhol*zhol;
			sumhol+=reminder[a];
			reminder[a]=0;
			sum=to_string(sumhol);
			if(sum.length()>1){
				sol<<sum[0];
				sol>>reminder[a];
				//cout<<reminder<<endl;
				sum=sum[1];
							
			}
			carp[a]=sum+carp[a];
			 
		}
		if(reminder[a]==0){}else{
	string rem;
	//cout<<reminder<<"here"<<endl;
	rem=to_string(reminder[a]);
	//cout<<rem<<endl;
	carp[a]=rem+carp[a];
}
	
	}
string result="";
for(int a=0;a<x.length();a++){
	for(int b=0;b<a;b++){


		carp[a]=carp[a]+"0";
        cout<<"CARP[A]: "<<carp[a]<<endl	;		
	}
	result=addstr(result,carp[a]);


}
return result;
}
int main(){
string num2,sum="1";
while(1)
{cin>>num2;
if(num2=="q"){
    break;
}
sum=multiplestr(sum,num2);
cout<<sum;
}
}






