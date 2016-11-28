//
//  main.cpp
//  kook2
//
//  Created by 김형중 on 2016. 11. 22..
//  Copyright © 2016년 김형중. All rights reserved.
//  icpc.me/12787
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int N , type;
ll inp, result;
char input[200];

int main(int argc , const char *argv[]){
    scanf("%d" , &N);
    
    while(N--){
        string output = "" , ret = "";
        result = 0;
        cin >> type;
        if(type == 1){
            
            cin >> input;
            
            char * pch = strtok(input, ".");
            while(pch!= NULL){
                int tmp = atoi(pch);
                for(int i = 7 ; i>= 0 ; i--){
                    output += (((tmp >> i)&1) + '0');
                }
                pch = strtok(NULL,".");
            }
            reverse(output.begin() , output.end());
            
            for(int i = 0; i < (int)output.size() ; i++){
                if(output[i] == '1'){
                    result += (ll)pow(2,(double)i);
                }
            }
            printf("%llu\n" , result);
            
        }else{
            cin >> inp;
            if(inp == 0){
                printf("0.0.0.0.0.0.0.0\n");
                continue;
            }
            for(int i = 63 ; i >= 0 ; i--){
                output += (((inp >> i)& 1) + '0');
            }
            
            int cnt = 0;
            string ptr = "";
            int sz = (int)output.size();
            for(int i = 0 ; i < sz ; i++){
                if(cnt == 7){
                    ptr += output[i];
                    reverse(ptr.begin() , ptr.end());
                    for(int j = 0 ; j < 8 ; j++){
                        if(ptr[j] == '1')
                            result += (ll)pow(2,(double)j);
                    }
                    ret += to_string(result);
                    if( i != sz-1)
                        ret += ".";
                    cnt = 0;
                    result = 0;
                    ptr.clear();
                }else{
                    ptr += output[i];
                    cnt ++;
                }
            }
            
            cout << ret << endl;
        }
    }
    
    return 0;
}
