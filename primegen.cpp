#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int genvar=0,ivar[10];
int var[10],count[10],primelist[10000],primevar1=0,beg,endi;//ivar[],var[] are arrays of simple loop variables
int num,start[20],finish[20];
int main(){
	//cin>>num;
	scanf("%d\n",&num);									//where to take number of inputs
	for(ivar[0]=0;ivar[0]<num;ivar[0]++){				//where to take inputs
		//cin>>start[ivar[0]]>>finish[ivar[0]];
		scanf("%d %d\n",&start[ivar[0]],&finish[ivar[0]]);
	}
	
	for(ivar[1]=0;ivar[1]<num;ivar[1]++){				//ivar[] is just array of simple loop variables
		beg=start[ivar[1]];
	 	endi=finish[ivar[1]];

		for (var[0]=beg;var[0]<=endi;var[0]++){
			count[0]=0;
			if(var[0]==1){continue;}
			for (var[1]=2;var[1]<=sqrt(var[0]);var[1]++){//where to prime check
				if(var[0]%var[1]==0){
					count[0]++;break;
				}
			}
			if(count[0]==0){							//if there is no divisor of the number,put it in the prime list
				primelist[primevar1]=var[0];primevar1++;
			}
			else{
				count[0]=0;continue;}					//else refresh the count variable
 		}
		for(var[2]=0;var[2]<primevar1;var[2]++){
			printf("%d\n",primelist[var[2]]);
			//cout<<primelist[var[2]]<<endl;
		}
		printf("\n");
		//cout<<endl;
		primevar1=0;
	}
}


