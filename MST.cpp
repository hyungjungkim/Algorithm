//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 10. 29..
//  Copyright © 2016년 김형중. All rights reserved.
//  MST
//

#include <stdio.h>
#include <stdlib.h>


#define NMAX 10001
#define MMAX 100001

typedef struct edge{
    int src;
    int dest;
    int weight;
}EDGE;

typedef struct Heap{
    int size;
    EDGE array[MMAX];
}HEAP;


//union-find
int parent[NMAX];
int level[NMAX];

//Heap
HEAP h;

int N, M;
int ans;

//HEAP
void initHeap(HEAP *ptr){
    ptr->size = 0;
}

void insertHeap(HEAP *ptr, EDGE tmp){
    int idx = ++(ptr->size);
    
    while(idx != 1 && tmp.weight < ptr->array[idx/2].weight){
        ptr->array[idx] = ptr->array[idx/2];
        idx /= 2;
    }
    ptr->array[idx] = tmp;
}

void insertHeapEdge(HEAP *ptr , int _src, int _dest, int _weight){
    EDGE tmp;
    tmp.src = _src;
    tmp.dest = _dest;
    tmp.weight = _weight;
    
    insertHeap(ptr,tmp);
    
}

EDGE DeleteHeap(HEAP *ptr)
{
    int parent=1,child=2;
    EDGE ret,temp;
    
    ret = ptr->array[parent];
    temp = ptr->array[(ptr->size)--];
    
    while(child <= ptr->size)
    {
        if((child < ptr->size) && (ptr->array[child].weight) > ptr->array[child+1].weight)
            child++;
        
        if(temp.weight <= ptr->array[child].weight) break;
        
        ptr->array[parent] = ptr->array[child];
        parent = child;
        child *= 2;
    }
    
    ptr->array[parent]=temp;
    return ret;
} 

void InitUF(void) // 전역 변수 초기화
{
    int i;
    for(i=0;i<NMAX;i++)
    {
        parent[i]=-1;
        level[i]=1;
    }
}

int SetFind(int v) // v가 속하는 집합을 반환한다
{
    int i,p,temp;
    
    for(i=v;(p=parent[i])>=0;i=p); // 정점v의 루트를 찾는다
    
    temp=i; // 정점 v를 포함하는 집합의 대표 원소
    
    for(i=v;(p=parent[i])>=0;i=p)
        parent[i]=temp; // 집합의 모든 원소들의 부모를 s로 설정
    
    return temp;
}

void SetUnion(int v1,int v2) // 두개의 원소가 속한 집합을 합친다
{
    if(level[v1] < level[v2]) // 자식의 갯수로 비교
    {
        parent[v1]=v2; // 부모 변경
        level[v1]+=level[v2];
    }
    else
    {
        parent[v2]=v1; // 부모 변경
        level[v2]+=level[v1];
    }
}

int main(void) {
    
    int src, dest, weight;
    

    initHeap(&h);
    InitUF();
    
    scanf("%d %d" , &N , &M);
    
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d %d", &src, &dest, &weight);
        insertHeapEdge(&h,src,dest,weight);
    }

    
    int count = 0;
    EDGE tmp;
    int u , v;
    
    while(count < N-1){
        tmp=DeleteHeap(&h);
        
        u = SetFind(tmp.src);
        v = SetFind(tmp.dest);
        
        if(u != v)
        {
            ans += tmp.weight;
            count++;
            SetUnion(u,v);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
