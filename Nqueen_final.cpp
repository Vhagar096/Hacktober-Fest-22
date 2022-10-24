#include<bits/stdc++.h>
using namespace std;
class Nqueen{
	int **b;
	int n;
	bool sol=false;
	int c=0;
	public:
	Nqueen(int size){
		n=size;
		b=(int **)malloc(n*sizeof(int*));
		for(int i=0;i<n;i++){
			int *temp=(int *)malloc(n*sizeof(int ));
			for(int j=0;j<n;j++){
				temp[j]=0;
			}
				*(b+i)=temp;
		}
	}
	bool issafe(int r,int c){
		if(r>=n or c>=n or r<0 or c<0) return false;
		for(int i=r;i>=0;i--){
			if(b[i][c]==1) return false;
			
		}
		for(int i=c;i>=0;i--){
			if(b[r][i]==1) return false;
		}
		int i,j;
		for(i=r,j=c;i>=0 and j>=0;i--,j--){//upper left diagonal
			if(b[i][j]==1) return false;
			
		}
    //Check lower diagonal on left side */
    for (i = r, j = c; j >= 0 && i < n; i++, j--){
    	if (b[i][j])
            return false;
	}
        
    //Check upper diagonal on right side
    for (i = r, j = c; i >= 0 && j<n; i--, j++){
    	if (b[i][j])
            return false;
	}
        

    //Check lower diagonal on right side 
    for (i = r, j = c; j <n && i < n; i++, j++){
    	if (b[i][j])
            return false;
	}
        

    return true;					
	}
	bool solve(int r){
	
		if(r==n){
			sol=true;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					cout<<b[i][j]<<" ";
				cout<<endl;
			}
			cout<<"Solution"<<++c<<"---------------------------"<<endl;
			return true;
		}
		bool f=false;
		for(int i=0;i<n;i++){
			if(issafe(r,i)){
				b[r][i]=1;
				f=solve(r+1);
				b[r][i]=0;
			}
		}
		return f;
	}
	bool solve(){
		solve(0);
		return sol;
	}
};

int main() {
	Nqueen n=Nqueen(4);
	int f=n.solve();
	if(!f) cout<<"No solution exists";
}
