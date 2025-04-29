//kadanes's algo.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
vector<int> nums={3,-4,5,4,-1,7,-8};
    int size,maxsum=INT_MIN,sum=0;
    size=nums.size();
    for(int i=0;i<size;i++)
  {
    sum+=nums[i];
    maxsum=max(sum,maxsum);
    if(sum<0){
        sum=0;
    }
  }
cout<<maxsum;
}