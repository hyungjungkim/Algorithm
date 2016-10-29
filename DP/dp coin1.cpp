//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 10. 25..
//  Copyright © 2016년 김형중. All rights reserved.
//


#include <stdio.h>

int main(void) {
    
    int i,j,n,k,coin[100]={0},cache[10001]={0};
    
    scanf("%d%d",&n,&k);
    
    cache[0]=1;
    
    for(i=0;i<n;i++){
        scanf("%d",&coin[i]);
    }
    for(i = 0; i < n ;i++){
        for(j = 1 ; j <= k ; j++){
            if(coin[i]<=j)
                cache[j] += cache[j - coin[i]];
        }
    }
    printf("%d\n",cache[k]);
    return 0;
}
