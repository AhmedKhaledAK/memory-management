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



void fifoalgorithm(int n, vector<int> refs){
    cout << "FIFO" << endl;
}

void clockalgorithm(int n, vector<int> refs){
    cout << "CLOCK" << endl;
}

void optimalalgorithm(int n, vector<int> refs){
    cout << "OPTIMAL" << endl;
}

void lrualgorithm(int n, vector<int> refs){
    cout << "LRU" << endl;
}


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
    
    switch(algo[0]){
        case 'F':
            fifoalgorithm(n, refs);
            break;
        case 'C': 
            clockalgorithm(n, refs);
            break;
        case 'O':
            optimalalgorithm(n,refs);
            break;
        case 'L':
            lrualgorithm(n, refs);
            break;
    }
    
	return 0;
}
