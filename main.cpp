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

void print(int page, map<int,int> frames, bool fault){
    if(page < 10) {
        cout << "0";
    }
    cout << page;
    if(fault) {
        cout << " F   ";
    } else { 
        cout << "     ";
    }
    for(auto a = frames.begin(); a != frames.end(); a++){
        if(a->second < 10) cout << "0";
        cout << a->second << " ";
    }
    cout << endl;
}

void fifoalgorithm(int n, vector<int> refs){
    cout << "Replacement Policy = FIFO" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Page   Content of Frames" << endl;
    cout << "----   -----------------" << endl;
    
    

map<int,int> frames;
    unordered_map<int, bool> isinq;
    
    int j=0, in =0, faults=0;
    
    lpi(refs.size()){
        if(isinq[refs[i]]) {
            print(refs[i], frames, false);
            continue; 
        }
        if(frames.size() == n){
            isinq[frames[j]] = false;
            frames[j++]=refs[i];
            if(j==n)j=0;
            print(refs[i], frames, true);
            faults++;
        } else {
            frames[in++] = refs[i];
            print(refs[i], frames, false);
        }
        isinq[refs[i]] = true;
    }
    cout << "-------------------------------------" << endl;
    cout << "Number of page faults = " << faults << endl;
}


void clockalgorithm(int n, vector<int> refs){
    cout << "Replacement Policy = CLOCK" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Page   Content of Frames" << endl;
    cout << "----   -----------------" << endl;
    
    map<int,int> frames;
    unordered_map<int, bool> used;
    unordered_map<int, bool> isinq;
    unordered_map<int, int> whichframe;
    
    int j =0, in=0, faults =0;
    
    lpi(refs.size()){
        if(isinq[refs[i]]){
            used[whichframe[refs[i]]]=true;
            print(refs[i], frames, false);
            continue;
        }
        if(frames.size() == n){
            while(used[j]){
                used[j++]=false;
                j%=n;
            }
            isinq[frames[j]]=false;
            whichframe[frames[j]] = -1; // not necessary, just in case.
            frames[j] = refs[i];
            isinq[frames[j]]=true;
            used[j] = true;
            whichframe[refs[i]]=j;
            j++;
            j%=n;
            print(refs[i], frames, true);
            faults++;
        } else {
            frames[in] = refs[i];
            isinq[refs[i]] = true;
            whichframe[refs[i]] = in;
            used[in++]=true;
            print(refs[i], frames, false);
        }
    }
    cout << "Number of page faults = " << faults << endl;
    
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
