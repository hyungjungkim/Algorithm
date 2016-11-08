//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 7..
//  Copyright © 2016년 김형중. All rights reserved.
//  완전 탐색
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define ABS(A) ((A) < 0 ? -(A) : (A))


typedef long long ll;
typedef pair<ll,ll> pll;

pll input[4];

vector<ll> v;

int dx[4][2] = {{1,1},{-1,1},{-1,-1},{1,-1}};
int zero_cnt;
ll ans = LLONG_MAX;

int min(int a , int b){ return a>b ? b: a;}

int main(int argc , const char *argv[]){
    
    for(int i = 0 ; i < 4 ; i++){
        ll x, y;
        scanf("%lld %lld" , &x , &y);
        if(x == 0 && y == 0)
            zero_cnt++;
        input[i].first = x;
        input[i].second = y;
        v.push_back(x);
        v.push_back(y);
    }
    // all  (0,0)
    if(zero_cnt == 4){
        printf("1\n");
        exit(0);
    }
    
    
    ll dist = 0;
    
    //permutation
    for(int j = 0 ; j < v.size() ; j++){
        int pos[4] = {0,1,2,3};
        do{
            ll tmp = 0;
            for(int i = 0 ; i < 4 ; i++){
                tmp+= ABS(input[i].first - v[j]*dx[pos[i]][0]) + ABS(input[i].second - v[j]*dx[pos[i]][1]);
            }
            if(ans > tmp){
                ans = tmp;
                dist = ABS(v[j]*2);
            }
            if(ans == tmp) {
                if(dist < ABS(v[j]*2)) dist = ABS(v[j]*2);
            }
        }while(next_permutation( pos , pos + 4));
    }
    
    printf("%lld\n", dist);
    
    
    return 0;
}
