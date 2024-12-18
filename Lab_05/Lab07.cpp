#include<bits/stdc++.h>
using namespace std;
int heap[1000],n;
void reheapup(int position)
{
    int parent;
    if(position>1)
    {
        parent=position/2;
        if(heap[position]>heap[parent])
        {
            swap(heap[position],heap[parent]);
            reheapup(parent);
        }
        else return;
    }
}
void buildheap(int data[])
{
   int i=0;
   while(i<=n)
   {
       i=i+1;
       heap[i]=data[i];
       reheapup(i);
   }
}

void reheapdown(int position,int lastposition)
{
    int leftchild= position*2;
    int child;
    int rightchild=position*2+1;
    if(rightchild<=lastposition && heap[rightchild]>heap[leftchild])
    {
        child=rightchild;
    }
    else child=leftchild;
    if(heap[child]>heap[position])
    {
        swap(heap[child],heap[position]);
         reheapdown(child,lastposition);
    }


}
void deleteheap()
{
  for(int i=1;i<=n;i++)
  {
      if(heap[i]==0)
        cout<<"heap is empty"<<endl;
      return;
  }

  for(int i=0;i<n;i++)
  {
       int mindata=heap[0];
     int count=n;
     heap[0]=heap[count];
     count=count-1;
     reheapdown(0,count);
  }
}
void printheap()
{
    int i;
    for(i=1;i<=n;i++)
    {
        cout<<heap[i]<<" ";
    }

}
int main()
{

    int i;
    int data[1000];
    cout<< "Enter your Data: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>data[i];
        heap[i]=data[i];
        reheapup(i);
    }

    for(i=1;i<=n;i++)
    {
        buildheap(data);
    }
    deleteheap();
    printheap();
}


