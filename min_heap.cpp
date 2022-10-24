#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
class min_heap{
	int r;
	int size;
	int *a;
	public:
	min_heap(int n)
	{
		r=-1;
		size=n;
		a=(int*)malloc(sizeof(int));
	}
	void heapify(int i)
	{
		if(i>=(r/2)+1 )
			return;
		int lc,rc,smallest;
		lc=i*2+1;
		rc=i*2+2;
		smallest=i;
		if(lc<=r and a[lc]<a[smallest])
			smallest=lc;
		if(rc<=r and a[rc]<a[smallest])
			smallest=rc;
		if(smallest!=i)
		{
			swap(&a[i],&a[smallest]);
			heapify(smallest);
		}
	}
	void insert(int data)
	{
		if(r==size-1)
		{
			cout<<"Underflow"<<endl;
			return;
		}
		r++;
		a[r]=data;
		int p=(r-1)/2;
		do
		{
			heapify(p);
			p=(p-1)/2;
			
		}while(p!=0);
		heapify(0);
	}
	void show()
	{
		if(r==-1)
		{
			cout<<"Underflow"<<endl;
			return;
		}
				
		for(int i=0;i<=r;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	void pop()
	{
		if(r==-1)
		{
			cout<<"Underflow"<<endl;
			return;		
		}
		if(r==0)
		{
			r--;
			return;
		}
		swap(a[0],a[r]);
		r--;
		heapify(0);
	}
	int top(){
		return a[0];
	}
};
int main(void){
	min_heap p=min_heap(5);
	p.insert(10);
	p.insert(20);
	p.insert(8);
	p.insert(50);
	p.insert(30);
	cout<<p.top()<<endl;
	p.show();
	p.pop();
	cout<<p.top()<<endl;
	p.show();
}
