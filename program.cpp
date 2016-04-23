#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;

// though we can do it with comparison based merge sorting or any divide conquer sorting,
// I am impementing priority queue with Binary Heap where heap will be built on the basis of priority.
// Maximum priority element will be at Root and so on!
class PriorityHeap{
public:
    int *heapArr;
    int size=0;
    PriorityHeap() {
      heapArr = new int[100000];
      for(int i=0;i<100000;i++)heapArr[i]=0;
      size=0;
    }
    void push(int x) {
      int pos = size++;
      while(pos && abs(x) > abs( heapArr[(pos-1)/2]) ) {
        heapArr[pos] = heapArr[(pos-1)/2];
        heapArr[(pos-1)/2]=x;
        pos = (pos-1)/2;
      }
      heapArr[pos] = x;
    }
    void PriorityHeapify(int pos){
      int small=pos;
      int right=2*pos+1;
      int left=right++;
      if(left < size && abs(heapArr[left]) > abs(heapArr[small]) )
        small=left;
      if(right < size && abs(heapArr[right]) > abs(heapArr[small]) )
        small=right;
      if(small!=pos){
        int tmp=heapArr[small];
        heapArr[small]=heapArr[pos];
        heapArr[pos]=tmp;
        PriorityHeapify(small);
      }
    }
    int extractHighPriorityElement(){
      int ans=heapArr[0],small=0;
      heapArr[0]=heapArr[size-1];
      PriorityHeapify(0);
      return ans;
    }
};

int main(){
  fstream in,out;
  PriorityHeap ph;
  in.open("testIn.txt");
  out.open("testOut.txt");
  int x,count=0,n;
  while(in>>x){
    ph.push(x);
    count++;
  };
  // for(int i=0;i<ph.size;i++)
  //   cout<<ph.heapArr[i]<<" ";
  cout<<"\nHow many number you wanna get????\n";
  cin>>n;
  if(n<=count){
    while(n--){
      x=ph.extractHighPriorityElement();
      cout<<x<<" ";
      out<<x<<" ";
    }
  }
  in.close();
  out.close();
  return 0;
}
