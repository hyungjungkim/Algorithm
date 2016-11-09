//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 9..
//  Copyright © 2016년 김형중. All rights reserved.
//  DP
//  icpc.me/9084
//
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

#define MMAX 10000

int coin[21];
int cache[MMAX + 1];

int T , N , M;


int main(int argc , const char *argv[]){
    
    scanf("%d", &T);
    
    while(T--){
        
        scanf("%d" , &N);
        
        memset(cache , 0 , sizeof(cache));
        
        for(int i = 1 ; i <= N ; i++)
            scanf("%d" , &coin[i]);
        
        scanf("%d" , &M);
        cache[0] = 1;
        
        for(int i = 1 ; i <= N; i++){
            for(int j = 1 ; j <= M ; j++){
                if(coin[i] <= j){
                    cache[j] += cache[j - coin[i]];
                }
            }
        }
        printf("%d\n" , cache[M]);
    }

    return 0;
}
