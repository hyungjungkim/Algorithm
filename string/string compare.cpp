//
//  main.cpp
//  skct
//
//  Created by 김형중 on 2016. 10. 21..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string input[101];
string cpy_input[101];
int main(int argc , char *argv[]){
    
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++){
        cin >> input[i];
        cpy_input[i] = input[i];
        reverse(cpy_input[i].begin(), cpy_input[i].end());
    }
    
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(input[i].compare(cpy_input[j])==0){
                size_t len = input[i].size();
                printf("%zu %c\n", len , input[i][len/2]);
                exit(0);
            }

        }
    }
    
    return 0;
    
}
