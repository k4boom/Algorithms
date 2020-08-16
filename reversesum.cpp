#include <bits/stdc++.h>
using namespace std;
void reverseStr(string& str) //string reverser function
{ 
    int n = str.length();  
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
  
int main(){
	int no,first[10],sec[10],final[10];
	cin>>no;
	string s[10],s2[10],s3[10];
	for(int a=0;a<no;a++){
		
		cin>>first[a]>>sec[a];
		
		s[a]=to_string(first[a]);s2[a]=to_string(sec[a]);		//make them string
		
		reverseStr(s[a]);reverseStr(s2[a]);						//reverse them
		
		s3[a]=to_string(stoi(s[a])+stoi(s2[a]));				//add them and make the sum string
		
		reverseStr(s3[a]);										//reverse the sum
		
		final[a]=stoi(s3[a]);									//make the sum integer
		
		cout<<final[a]<<endl;
	} 


    
}
