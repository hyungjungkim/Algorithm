//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 7..
//  Copyright © 2016년 김형중. All rights reserved.
//  LSI
//
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

#define NMAX 101
#define MMAX 10000001

typedef long long ll;


int N , disable[NMAX] ,ans;
int M , able[NMAX] , DP[MMAX] , sz;


int main(int argc , const char *argv[]){
    
    scanf("%d %d", &N , &M);
 
    //input
    for(int i = 0 ; i < N ; i++)
        scanf("%d" , &able[i] );
    
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &disable[i]);
        sz+= disable[i];
    }
    for(int i = 0; i < N ; i++){
        for(int j = sz ; j >= disable[i] ; j--)
            if(DP[j] < DP [j-disable[i]] + able[i]) DP[j] = DP[j-disable[i]] + able[i];
    }
    
    for(int i = 0 ; i < sz ; i++){
        if(DP[i] >= M){
            ans = i;
            break;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
