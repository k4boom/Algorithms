#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;
string strdivision(string divident,string divider);
string strsubstract(string from,string that);
void reverseStr(string& str) //string reverser function
{ 
    int n = str.length();  
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
string multiplestr(string a,string b);
string addstr(string x,string z){			//function to   add numbers in string form
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
int main(){
    string a,b;
    cin>>a>>b;
    cout<<strdivision(a,b);

    
}
string multiplestr(string a,string b){
    string z,x;
    if(a.length()>b.length()){z=a;x=b;}else{z=b;x=a;}
    reverseStr(x);reverseStr(z);
    string *carp;
    carp=new string[x.length()];
    int *reminder;
    reminder=new int[x.length()];
    reminder[0]=0;
    for(int a=0;a<x.length();a++){
        carp[a]="";
        reminder[a]=0;
        for(int b=0;b<z.length();b++){
                int xhol,zhol,sumhol;
                string sum;
                xhol=x[a]-48;
                zhol=z[b]-48;
                sumhol=xhol*zhol;
                sumhol+=reminder[a];
                reminder[a]=0;
                sum=to_string(sumhol);
                if(sum.length()>1){
                    reminder[a]=sum[0]-48;
                    sum=sum[1];
                }
                carp[a]=sum+carp[a];
        }
        if(reminder[a]==0){}else{
            string rem;
            rem=to_string(reminder[a]);
            carp[a]=rem+carp[a];
        }
    }
    //TO DO: carp[a] ları ve carpma işlemlerini kontrol et sonra 0 ları ekle
    for(int i=0;i<x.length();i++){
        
        for(int b=0;b<i;b++){
        	carp[i]=carp[i]+"0";
        }
        cout<<"carp[i]:"<<carp[i]<<endl;
    }
    string result="";
    for(int i=0;i<x.length();i++){
    	result=addstr(result,carp[i]);
    }
    return result;
}
string strsubstract(string from,string that){
    //find which one is bigger
    //TODO: create a more complicated algorithm for the numbers with the same number of digits

    string big,small;
    if(from.length()>=that.length()) {big=from;small=that;}
    else{ big=that;small=from;}
    
    //reverse the stringsr
    reverseStr(big);reverseStr(small);
    
    //find the gap
    string result,gap;
    //substract the digits from each other with the same index
    for(int a=0;a<small.length();a++){
        int bigholder,smallholder,sumholder,extraholder;
        bigholder=big[a]-48;
        smallholder=small[a]-48;
       
        
        //if digit of big is smaller,take 1 from the next digit of the big
        if(smallholder>bigholder){
            
            extraholder=big[a+1]-48;
            big[a+1]=(extraholder-1)+48;
            bigholder+=10;
        } 
        sumholder=bigholder-smallholder;
        gap=to_string(sumholder)+gap;
    }
   
    //let the digits that left fall down to the result 
    for(int i=small.length();i<big.length();i++){
        gap=big[i]+gap;
    }
   
    //reverseStr(gap);
    result=gap;
    //delete the zeros at the beginning
    while(result[0]=='0'){
        result.erase(0,1);
    }
    //return the result with minus or not
     
    if(from.length()>=that.length()) return result;
    return "-"+result;
}
//TODO: Create a compare function
bool isBig(string supposedtobeBig,string supposedtobeSmall){

//digit camparison
    if(supposedtobeBig.length()>supposedtobeSmall.length()){
        return 1;
    }
    else if(supposedtobeBig.length()<supposedtobeSmall.length()){
        return 0;
    }
//if equal:for length 
    else{
        int i;
        for(i=0;i<supposedtobeSmall.length();i++){
            int bigholder,smallholder;
            bigholder=supposedtobeBig[i]-48;
            smallholder=supposedtobeSmall[i]-48;
            if(bigholder>smallholder){
                return 1;break;
            }
            else if(bigholder<smallholder){
                return 0;break;
            }
            
        }
        if(i==supposedtobeSmall.length()){
            return 0;
        }
    }
//from the beginning compare each digit until one of them is bigger
}
//TODO: Create a division functıon
string strdivision(string divident,string divider){
//Compare the divident and divider and if divider is bigger quit
if(isBig(divider,divident)){
    cout<<"Divider may not be bigger than divident for this program"<<endl;
    exit(EXIT_SUCCESS);
}
string result="0";
//Reverse the strings
reverseStr(divident);reverseStr(divider);
//Compare the first digits of the bölen(divider) and bölünen(divident)
//if the first digit of the divident is bigger than divider:
while(isBig(divident,divider)){
    int bigholder,smallholder,extraholder;
    bigholder=divident[0]-48;
    smallholder=divider[0]-48;
    if(bigholder>=smallholder){
        extraholder=bigholder/smallholder;
        string extra,sideresult;
        extra=to_string(extraholder);
        sideresult=multiplestr(extra,divider);
        while(isBig(sideresult,divident)){
        extraholder-=1;
        extra=to_string(extraholder);
        sideresult=multiplestr(extra,divider);
        }  
        result=addstr(result,extra);
        divident=strsubstract(divident,sideresult);
        cout<<divident<<endl;  
    }return result;
}
//  divide the digits and multiply the result with the digits of the divider
//  if the result of the multiplication is bigger than divident multiply with 1 less and substract it from the divident
//  add the result to the quotient as addition
//  keep doing this until the divident is less than divider
//if not:
//  get one more digit from divident
//  divide
//after substraction drop one digit from the divident if there is
}
