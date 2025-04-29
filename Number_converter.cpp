#include<iostream>
using namespace std;
int dectobin(int decimal){
   int ans=0,pow=1;
   while(decimal>0){
    int remainder=decimal%2;
    decimal=decimal/2;
    ans=ans+remainder*pow;
    pow=pow*10;
    
  }
return(ans);
}
int bintodec(int bineryNumber)
{
   
    int pow=1,ans=0;
    while (bineryNumber>0){
    int remainder=bineryNumber%10;
    ans+=remainder*pow;
    bineryNumber=bineryNumber/10;
    pow=pow*2;
    }
    return(ans);

    
}
int main(){
    int num,input,result;
    cout<<"enter a number"<<endl;
    cin>>num;
   cout<<"1 for binery to decimal or 2 for decimal to binery"<<endl;
    cin>>input;
    if(input==1){
        result=bintodec(num);
    }
    else 
    {
      result=dectobin(num);
    }
    
    cout<<result<<endl;
}