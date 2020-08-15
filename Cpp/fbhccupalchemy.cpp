#include<bits/stdc++.h>
using namespace std;
char pop(char spring[],int index,int springvar){  //the function for poping an element from a given index
	char x=spring[index];
	int i;
	for (i=0;index+i<springvar;i++){
		spring[index+i]=spring[index+i+1];
	}
	spring[springvar-1]=-1;
	return x;
}
char majority(char arrr[]){						//the function that returns the element which is the majority
		if(arrr[0]==arrr[1]){
			return arrr[0];
		}
		else{
			return arrr[2];
		}
	
}
int main(){
int numoftry;
scanf("%d",&numoftry);							//input how many shard set is going to be fused
for(int a=0;a<numoftry;a++){
	int len;
	string para;
	scanf("%d",&len);							//input how many shards is there in the set
	cin>>para;									//input the shard set as a string
	char* arr;
	arr=new char[len];
	int popvar=len;
	for(int b=0;b<len;b++){						//turn the string to a char array
		arr[b]=para[b];
	}
	int an=0;									//"an" is the variable that indicates the beginnig place to take the colour input
	while(popvar!=3-2 ){						//the while loop which will work until there is only one stone
		
		char* vararr;
		vararr=new char[3];
		for(int v=0;v<3;v++){					
			vararr[v]=arr[an+v];				//take the colour input in threes
		}
		
		if(an==popvar-2){						//if "an" is at the last position possible to take colour input, it means we can not fuse this set of shards
			printf("Case #%d: N\n",a+1);break;
		}
		else if(vararr[0]==vararr[1] && vararr[0]==vararr[2])
			{an++;}								//if all the elements of the colour input is the same,goto next one by increasing "an" variable
		else{
			pop(arr,an,popvar);popvar--;		//otherwise; we can fuse these shards.We can use pop function and we don't have to change the index
			pop(arr,an,popvar);popvar--;		//because second input will fall down to the first place and one more.
			arr[an]=majority(vararr);			//We don't have to pop the third.It's enough to change the colour value to the majority colour.
			an=0;		}						//Also now we have a new shard set.Don't forget to refresh the "an" variable
	
			delete vararr;
	}
	
	if(an==0){
	printf("Case #%d: Y\n",a+1);}				//After the while loop;if ann==0,it means there is only single stone left and the loop is not left
												//with break condition.So,we successfully fused these shards.
	delete arr;

}

}