//
//  prac.c
//  baekjoon1
//
//  Created by 김형중 on 2016. 10. 31..
//  Copyright © 2016년 김형중. All rights reserved.
//  1912 
//
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define NMAX 100001


int N;

int arr[NMAX];
int DP[NMAX];
int ans;

int max(int a , int b){ return a>b?a:b;}


int main(int argc, char * argv[]){
    
    memset(DP , -1 , sizeof(DP));
    
    
    scanf("%d", &N);
    
    for(int i = 1 ; i <= N ; i++)
        scanf("%d" , &arr[i]);
    
    DP[1] = arr[1];
    ans = DP[1];
    for(int i = 2 ; i <= N ; i++){
        DP[i] = max(DP[i-1] + arr[i], arr[i] );
        if(ans < DP[i])
            ans = DP[i];
    }
    
    printf("%d\n", ans);
    
    return 0;
}
