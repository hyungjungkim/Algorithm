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

using namespace std;

#define NMAX 40001

int DP[NMAX];
int N , lastidx , input;

int find(int low , int high , int target){
    int res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(DP[mid] > target){
            res = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return res;
}


int main(int argc , const char *argv[]){
    scanf("%d", &N);
    scanf("%d" ,&input);
    DP[lastidx] = input;
    
    for(int i = 1 ; i < N ; i++){
        scanf("%d" , &input);
        if(DP[lastidx] < input){
            lastidx ++;
            DP[lastidx] = input;
        }else if(DP[0] > input)
            DP[0] = input;
        else{
            int idx = find(0 , lastidx , input);
            DP[idx] = input;
        }
    }
    printf("%d\n" , lastidx + 1);
    return 0;
}
