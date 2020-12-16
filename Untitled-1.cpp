
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<pair<int,int>>x1,x2;

void printPrimeFactors(int n) {
    cout<<n<<" = ";
    bool f1=true,f2=true;
    while (n%2 == 0){
        for(int i=0;i<x1.size();i++){
            if(2==x1[i].first){
                x1[i].second++;
                f1=false;
                break;
            }
        }
        cout<<"2*";
        if(f1)
            x1.push_back(make_pair(2,1));
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            for(int j=0;j<x1.size();j++){
                if(i==x1[j].first){
                    x1[j].second++;
                    f2=false;
                    break;
                }
            }
            cout<<i<<"*";
            if(f2)
            x1.push_back(make_pair(i,1));
            
            n = n/i;
            f2=true;
        }
    }
   if (n > 2){
        cout<<n;
        x1.push_back(make_pair(n,1));
   }
   cout<<endl;
}
void printPrimeFactorsb(int n) {
    cout<<n<<" = ";
    bool f1=true,f2=true;
    while (n%2 == 0){
        for(int i=0;i<x2.size();i++){
            if(2==x2[i].first){
                x2[i].second++;
                f1=false;
                break;
            }
        }
        cout<<"2*";
        if(f1)
            x2.push_back(make_pair(2,1));
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            for(int j=0;j<x2.size();j++){
                if(i==x2[j].first){
                    x2[j].second++;
                    f2=false;
                    break;
                }
            }
            cout<<i<<"*";
            if(f2)
            x2.push_back(make_pair(i,1));
            
            n = n/i;
            f2=true;
        }
    }
   if (n > 2){
        cout<<n;
        x2.push_back(make_pair(n,1));
   }
   cout<<endl;
}
int main()
{
    int a,b,ans=1;
    cin>>a>>b;
    printPrimeFactors(a);
    printPrimeFactorsb(b);
    
    cout<<"gcd = ";

        for(int i=0;i<x1.size();i++){
            for(int j=0;j<x2.size();j++){
                if(x1[i].first==x2[j].first){
                    if(x1[i].second<x2[j].second){
                        cout<<x1[i].first<<" power("<<x1[i].second<<") *";
                    }
                    else
                        cout<<x2[j].first<<" power("<<x2[j].second<<") *";
                }
                
            }
        }
    
     
    return 0;
}