//
//  main.cpp
//  kook2
//
//  Created by 김형중 on 2016. 11. 18..
//  Copyright © 2016년 김형중. All rights reserved.
//  icpc.me/12789
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int N, x, flag = 1;

stack<int> s;

int main(int argc , const char *argv[]){
    
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &x);
        s.push(x);
        
        while(!s.empty()){
            if(s.top() == flag) s.top() , flag++;
            else break;
        }
    }
    
    if(s.empty()) printf("Nice\n");
    else printf("Sad");
    
    return 0;
}
