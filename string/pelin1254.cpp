//
//  main.cpp
//  kook2
//
//  Created by 김형중 on 2016. 11. 15..
//  Copyright © 2016년 김형중. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char _input[1001];
char _copy[2002];

bool isPelin(int len){
    
    int mid = len / 2;
    
    if(len %2 == 0){
        int p = mid - 1 , q = mid;
        for(;p >= 0&& q < len;p--,q++) if(_copy[p] != _copy[q]) return 0;
    }else{
        int p =mid , q = mid;
        for(;p>=0 && q<len; p--,q++) if(_copy[p] != _copy[q]) return 0;
    }
    
    return 1;
}


int main(int argc, const char *argv[]){
    scanf("%s", _input);
    
    int _len = (int)strlen(_input);
    strcpy(_copy,_input);
    
    if(isPelin(_len)) {printf("%d\n", _len); return 0;}
    
    for(int i = 0 ; i < _len-1 ; i++){
        for(int j = i ; j >= 0 ; j--) _copy[_len+i-j] = _input[j];
        _copy[_len+i+1] = 0;
        if(isPelin(_len+i+1)){
            printf("%d\n" , _len+i+1);
            break;
        }
    }
    
    
    return 0;
}
