#include <iostream>
#include <climits>
using namespace std;

struct var{
    int n = INT_MAX;
    int* p = new int[n];
};

var get_digNo_digs(int n){
    
    var value;
    value.n = 0;

    
    do{
        value.p[value.n] = n%10;
        value.n++;
        n = n/10;
        
    }while(n>0);
    

    return value;
    
}

int* num_rev(int* N, int T){
    
    int* A = new int[T];
    
    for(int i=0; i<T; i++){
        A[i] = 0;
    }
    

    for(int i=0; i<T; i++){
        
        var value = get_digNo_digs(N[i]);
        
        for(int j=0; j<value.n; j++){
            
            A[i] += value.p[j]*(10^((value.n)-j));
            
        }
    }
    
    return(A);
}


int main() {
    int T;
    cin>>T;
    int* N = new int[T];
    
    for(int i=0; i<T; i++){
        cin>>N[i];
    }
    
    N = num_rev(N, T);
    
    for(int i=0; i<T; i++){
        cout<<N[i]<<"\n";
    }
    
	return 0;
}


