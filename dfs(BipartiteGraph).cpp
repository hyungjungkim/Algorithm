//
//  main.cpp
//  algoprac
//
//  Created by 김형중 on 2016. 11. 23..
//  Copyright © 2016년 김형중. All rights reserved.
//  icpc.me/1707
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, V, E, from, to;
vector< vector<int> > v;
int chk[20002];

bool dfs(int pos , bool flag){
    chk[pos] = flag;
    for(int i = 0 ; i < v[pos].size() ; i++){
        int next = v[pos][i];
        if(chk[next] == flag) return false;
        if(chk[next] == -1 && !dfs(next, !flag)) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    scanf("%d" , &T);
    
    while(T--){
        int ans = 1;
        memset(chk , -1 , sizeof(chk));
        v = vector<vector<int>>(20002);
        
        scanf("%d %d", &V, &E);
        
        for(int i = 0 ; i < E ; i++){
            scanf("%d %d", &to , &from);
            v[to].push_back(from);
            v[from].push_back(to);
        }
        
        for(int i = 1 ; i <= V ; i++){
            if(chk[i] == -1 && !dfs(i , true)){
                ans = 0;
                break;
            }
        }
        
        ans ? printf("YES\n") : printf("NO\n");
        
    }
    return 0;
}
