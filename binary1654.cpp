//
//  main.cpp
//  practice4
//
//  Created by 김형중 on 2016. 10. 18..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>
#include <climits>

#define KMAX 10001

int K , N;
long long arr[KMAX];

int main(int argc, const char * argv[]) {
    
    long long right= 0 , left = 0;
    long long ans = 0;
    
    scanf("%d %d" , &K, &N);
    
    for(int i = 0 ; i < K ; i++){
        scanf("%lld", &arr[i]);
        if(right < arr[i])
            right = arr[i];
    }
    
    
    while(left <= right){
        long long mid = (left + right)/ 2;
        int sum = 0;
        
        for(int i = 0 ; i < K; i++)
            sum += (arr[i] / mid);
        
        if(sum >= N){
            left = mid + 1;
            if( mid > ans)
                ans = mid;
        }else{
            right = mid -1;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
