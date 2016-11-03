//
//  main.cpp
//  prac4
//
//  Created by 김형중 on 2016. 11. 4..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 100000


int N , K;
int arr[NMAX];
vector<pair<int , int>> s;
vector<pair<int,int>>res;

bool compare(int a , int b){ return a > b;}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &K);
    
    for(int i = 0 ; i < K ; i++){
        int A , B;
        scanf("%d %d", &A , &B);
        s.push_back(make_pair(A,0));
        s.push_back(make_pair(B,1));
    }
    
    while(!s.empty()){
        pair<int , int> tmp = s.back();
        s.pop_back();
        int _f = tmp.first;
        while(!s.empty() && _f >= s.back().first ){
            s.pop_back();
        }
        res.push_back(tmp);
    }
    reverse(res.begin(),res.end());
    for(int i = 0 ; i < res.size() ; i++){
        if(res[i].second)
            sort(arr , arr+res[i].first , compare);
        else
            sort(arr , arr+res[i].first);
    }
    
    for(int i = 0 ; i < N ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
