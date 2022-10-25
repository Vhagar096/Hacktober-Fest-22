#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void show(int a[],int n){
	for(int y=0;y<n;y++)
		cout<<a[y]<<"  ";
	cout<<endl;
}
int hoare_leftpartition(int a[],int i,int n){
	
	int pi=i;
	int l=i;
	int r=n;

	while(l<r){
	
		
		while(a[++l]<a[pi] and l<=r){
			
		}
		
		while(a[r]>a[pi] &&r>0){
			r--;
		}
		
		if(l>=r)
			break;
			
		else
			swap(&a[l],&a[r]);	
	
	}
	//if(l=r)
//	if(l)	
		swap(&a[r],&a[pi]);	
	return r;
}
void quick(int a[],int i,int r){
	
	if(i>=r)
		return;
	int m=partition(a,i,r);
//	cout<<"m-- "<<m<<" i- "<<i<<endl;
	quick(a,i,m-1);
	quick(a,m+1,r);
}

int main(void){
	int n;
	cout<<"Enter no of elements-";
	cin>>n;
	int a[n];
	in(a,n);
	quick(a,0,n-1);
	show(a,n);
}
