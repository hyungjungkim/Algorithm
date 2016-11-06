//
//  main.cpp
//  kook2
//
//  Created by 김형중 on 2016. 11. 4..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;


int T , N;

long long v[1001];

int main(int argc, const char * argv[]) {
    
    scanf("%d", &T);
    
    while(T--){

        int ans  = 0;
        
        scanf("%d" , &N);
        
        
        for(int i = 0 ; i < N ; i++){
            scanf("%lld" , &v[i]);
        }
        sort(v , v+N);
        
        for(int i = 0 ; i < N ; i++){
            for(int j = i+1 ; j < N-1 ; j++){
                if( (v[j]-v[i]) > (v[N-1]-v[j]))
                    break;
                
                ll tmp = (2 * v[j]) - v[i];
                if(binary_search(v + j + 1, v + N, tmp))
                    ans++;
            }
        }
        printf("%d\n" , ans);
    }
    
    return 0;
}
