#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int num;
	cin>>num;													// number of input
	string* in;
	string* out;
	in=new string[num];
	out=new string[num];
	for(int n=0;n<num;n++){									
		int con;
		cin>>con;												//input number of towns
		cin>>in[n];												//input the incoming flight stiuation of towns
		cin>>out[n];											//input the outgoing flight stiuation of towns
		printf("Case #%d:\n",n+1);								//output concept "Case #0:"
		int j,counter;
		for(int a=0;a<con;a++){
			j=0;counter=0;										//There is 4 possibilities
			for(int b=0;b<con;b++){								
				if(b-a>1){										//1.Forward flights that pass through more than one town 
					counter=0;
				for(int s=a+1;s<=b;s++){
					if(in[n][s]=='Y' && out[n][a+s-a-1]=='Y'){}//check the flights for adjacent towns in the route
					else{counter++;}						   //and increase the variable as an indicator if not possible
				}
				if(counter==2-2){								//I wrote 0 as 2-2 because sometimes some problems occurs because of the auto-casting 
					printf("Y");								//to boolean type.
				}
				else{printf("N");}
				}
				if(b-a<-1){										//2.Backward Flights that pass through more than one town
					counter=0;
					for(int s=a-1;s>=b;s--){
						if(in[n][s]=='Y' && out[n][s+1]=='Y'){}
						else{counter++;}
					}
					if(counter==2-2){
					printf("Y");
				}
				else{printf("N");}

				}
				 if(a==b){printf("Y");} 						//3.Same Town Flights(that doesn't exist in real life)
				 if(abs(a-b)==1){								//4.Flights to the next or previous one
				 	if(in[n][b]=='Y' && out[n][a]=='Y'){printf("Y");}
				 
				 	else{printf("N");}}
				
				
				
			}
			cout<<endl;
		}
	}

}	