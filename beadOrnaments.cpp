//My failed attempt at a c++ implementation
//Most likely does not work due to overflow errors
//Or something of that nature
//Works on test cases 0-5, but fails 6-9
#include <iostream>
using namespace std;

long long int myPow(long long int a, long long int b){
    if(b==0){
        return 1;
    }
    long long int ans=a;
    while(b>1){
        ans*=a;
        b--;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int t,n,b;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int ans=1,sum=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>b;
            sum+=b;
            ans*=myPow(b,b-1);
            ans = ans % 1000000007;
        }
        if(n-2>=0)
            ans*=myPow(sum,n-2);
        else
            ans/=sum;
        ans = ans % 1000000007;
        cout<<ans<<'\n';
    }
    return 0;
}
