//
//  binary search3079.c
//  practice4
//
//  Created by 김형중 on 2016. 10. 18..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>

#define NMAX 100001

int N;
long long M;

long long arr[NMAX];

long long  ans;


int main(int argc, char * argv[]){
    
    long long left , right = 0 , mid;
    
    scanf("%d %lld", &N , &M);
    
    for(int i = 0 ; i < N ; i++){
        scanf("%lld" , &arr[i]);
        if(right < arr[i])
            right = arr[i];
    }
    
    left = 1;
    right *= M;
    ans = right;
    
    while(left <= right){
        mid = (left + right)/2;
        long long sum = 0;
        for(int i = 0 ; i < N ; i ++){
            sum += mid / arr[i];
        }
        if(sum < M){
            left = mid +1;
        }else{
            if(ans > mid)
                ans = mid;
            right = mid - 1;
        }
    }
    
    printf("%lld\n" , ans);
    return 0;
}
