#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void show(int a[],int n){
	for(int y=0;y<n;y++)
		cout<<a[y]<<"  ";
	cout<<endl;
}
class heapsort{
	int r;
	int size;
	public:
	heapsort(int n)
	{
		r=-1;
		size=n;
		
	}
	void show(int a[],int n)
	{
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
	}
	
	void heapify(int a[],int i,int r)//i is the index from where funcn heapify is starting
	{
		if(i>(r/2))//checking if i is leaf node then breaking
			return;
		int lc,rc,smallest;
		lc=i*2+1;//index of left child
		rc=i*2+2;
		smallest=i;//considering i as smallest
		if(lc<=r and a[lc]<a[smallest])//if left child less than smallest then
			smallest=lc;
		if(rc<=r and a[rc]<a[smallest])
			smallest=rc;
		if(smallest!=i)
		{
			swap(&a[i],&a[smallest]);//the ele frm where heapify was starting swapped with the smallest
			heapify(a,smallest,r);//checking heapify funcn until leaf node
		}
	}
	void buildheap(int a[],int n)//from root until before leaf node calling heapify funcn
	{
		for(int i=n/2;i>-1;i--)
			heapify(a,i,n-1);
	}
	void pop(int a[],int n)
	{	show(a,n);
		//cout<<endl;
		int r=n-1;
		while(r)
		{
			swap(&a[0],&a[r]);
			//show(a,n);
			r--;
			heapify(a,0,r);	
			//cout<<"h";
			
			//show(a,n);
		}
	}
    void heap_sort(int a[],int n)
    {
    	buildheap(a,n);
    	pop(a,n);
	}
};
int main(void){
	heapsort p=heapsort(5);
    int n;
	cout<<"SIZE OF THE ARRAY--";
	cin>>n;
	int a[n];
	cout<<"ENTER THE ARRAY "<<endl;
	p.in(a,n);
	p.heap_sort(a,n);
	cout<<"SORTED ARRAY"<<endl;
	p.show(a,n);

}
