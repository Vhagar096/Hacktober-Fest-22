#include<iostream>
using namespace std;

void show(int a[],int n)
{
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<"-------------------------"<<endl;
}
void in(int a[],int n){
	cout<<"Enter elements:"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
}
int countsort(int a[],int n,int o){
	int i,k,j,pass=0;
	int b[n];
	int c[o+1];
	for(i=0;i<=o;i++){
		c[i]=0;
		pass+=1;
	}
	for(i=0;i<n;i++){
		pass++;
		c[a[i]]+=1;
	}
	for(i=0;i<n;i++){
		b[i]=0;
	}
	cout<<"Count array "<<endl;
	show(c,o+1);
	for(i=1;i<=o;i++){
		c[i]+=c[i-1];
		pass+=1;
	}
	cout<<"Count array "<<endl;
	show(c,o+1);	
	for(j=n-1;j>=0;j--){
		i=c[a[j]]-1;
		b[i]=a[j];
		c[a[j]]-=1;
		pass++;
		cout<<"array c ";
		show(c,o+1);
		cout<<"array B ";
		show(b,n);
			}
	cout<<"output  array "<<endl;
	show(b,n);		
	for(i=0;i<n;i++){
	
		a[i]=b[i];
	}	

	return pass;
	}
int max(int a[],int n){
	int t=a[0];
	for(int i=1;i<n;i++)
		{
			if(t<a[i])
				t=a[i];
		}
		return t;
}
int main(void){
	int n;
	cout<<"Enter size ";
	cin>>n;
	int a[n];
	
	in(a,n);
	int y;
	y=countsort(a,n,max(a,n));
	show(a,n);
	cout<<"Pass no "<<y;
	return 0;
}
