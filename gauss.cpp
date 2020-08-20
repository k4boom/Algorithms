#include <iostream>
#include<math.h>
#include<stdio.h>
#include <limits>
using namespace std;
double inf = std::numeric_limits<double>::infinity();
int main(){
float var;
//float ar[3][3]={2,3,2,4,2,3,6,5,2};
int raw,col;cout<<"Pls enter the rawxcolumn"<<endl;cin>>raw>>col;
float ar[raw][col];
for(int d=0;d<raw;d++){
	for (int be=0;be<col;be++){
		cout<<"Enter the"<<d+1<<"x"<<be+1<<endl;
		cin>>ar[d][be];
	}
}

for(int a=0;a<raw;a++){
	for(int b=0;b<raw;b++){
		var=ar[b][a]/ar[a][a];
		for(int d=0;d<raw;d++){cout<<endl;
			for (float be:ar[d]){
		cout<<be<<" ";
		}
		}cout<<endl<<endl;
		for(int c=0;c<col;c++){
			if(b==a){
				continue;
			}
			else{
			//cout<<ar[b][c]<<" ";
			ar[b][c]-=(var*ar[a][c]);
			//cout<<ar[b][c]<<endl;
		}}
	}
}
if(col>raw){
	for(int a=0;a<raw;a++){
	for(int b=0;b<col-raw;b++){
		if(ar[a][a+(col-raw)+1]==0){continue;}
		var=ar[b][a+(col-raw)+1]/ar[a][a+(col-raw)+1];
		if(var==0){continue;}
		for(int d=0;d<raw;d++){cout<<endl;
			for (float be:ar[d]){
		printf("%.2f",be);
		cout<<"  ";
		}
		}cout<<endl<<endl;
		for(int c=0;c<col;c++){
			if(b+(col-raw)+1==a+(col-raw)+1){
				continue;
			}
			else{
			//cout<<ar[b][c]<<" ";
			ar[b][c]-=(var*ar[a][c]);
			if(ar[b][c]==inf){ar[b][c]+=(var*ar[a][c]);}
			//cout<<ar[b][c]<<endl;
		}}
	}
}
}
for(int a=0;a<raw;a++){
	for(int b=0;b<raw;b++){
		var=ar[b][a]/ar[a][a];
		for(int d=0;d<raw;d++){cout<<endl;
			for (float be:ar[d]){
		cout<<be<<" ";
		}
		}cout<<endl<<endl;
		for(int c=0;c<col;c++){
			if(b==a){
				continue;
			}
			else{
			//cout<<ar[b][c]<<" ";
			ar[b][c]-=(var*ar[a][c]);
			//cout<<ar[b][c]<<endl;
		}}
	}
}
for(int d=0;d<3;d++){cout<<endl;
	for (float be:ar[d]){
		//cout<<be<<" ";
	}
}
}
