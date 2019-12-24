#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int n; // number of pages
    string algo; // the simulated algorithm
    
    cin >> n;
    cin >> algo;
    
    vector<int> refs; // page references
    
    int page;
    cin >> page;
    
    while (page != -1){
        refs.push_back(page);
        cin >> page;
    }
    
    cout << endl;
    
    lpi(refs.size()) cout << refs[i] << endl;
    
	return 0;
}
