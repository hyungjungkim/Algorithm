//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 4..
//  Copyright © 2016년 김형중. All rights reserved.
//  MST
//

#include <stdio.h>
#include <stdlib.h>


#define NMAX 1010
#define MMAX 500001

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
HEAP h , h2;

int N, M;
int ans_min , ans_max;

//HEAP
void initHeap(HEAP *ptr){
    ptr->size = 0;
}

void insertMinHeap(HEAP *ptr, EDGE tmp){
    int idx = ++(ptr->size);
    
    while(idx != 1 && tmp.weight < ptr->array[idx/2].weight){
        ptr->array[idx] = ptr->array[idx/2];
        idx /= 2;
    }
    ptr->array[idx] = tmp;
}

void insertMinHeapEdge(HEAP *ptr , int _src, int _dest, int _weight){
    EDGE tmp;
    tmp.src = _src;
    tmp.dest = _dest;
    tmp.weight = _weight;
    
    insertMinHeap(ptr,tmp);
    
}

EDGE DeleteMinHeap(HEAP *ptr)
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
void insertMaxHeap(HEAP *ptr, EDGE tmp){
    int idx = ++(ptr->size);
    
    while(idx != 1 && tmp.weight > ptr->array[idx/2].weight){
        ptr->array[idx] = ptr->array[idx/2];
        idx /= 2;
    }
    ptr->array[idx] = tmp;
}

void insertMaxHeapEdge(HEAP *ptr , int _src, int _dest, int _weight){
    EDGE tmp;
    tmp.src = _src;
    tmp.dest = _dest;
    tmp.weight = _weight;
    
    insertMaxHeap(ptr,tmp);
    
}

EDGE DeleteMaxHeap(HEAP *ptr)
{
    int parent=1,child=2;
    EDGE ret,temp;
    
    ret = ptr->array[parent];
    temp = ptr->array[(ptr->size)--];
    
    while(child <= ptr->size)
    {
        if((child < ptr->size) && (ptr->array[child].weight) < ptr->array[child+1].weight)
            child++;
        
        if(temp.weight >= ptr->array[child].weight) break;
        
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
    initHeap(&h2);
    InitUF();
    
    scanf("%d %d" , &N , &M);
    
    for(int i = 0 ; i < M+1 ; i++){
        scanf("%d %d %d", &src, &dest, &weight);
        insertMinHeapEdge(&h,src,dest,weight);
        insertMaxHeapEdge(&h2,src,dest,weight);
    }
    
    
    int count = 0;
    EDGE tmp;
    int u , v;
    
    while(count < N){
        tmp= DeleteMinHeap(&h);
        
        u = SetFind(tmp.src);
        v = SetFind(tmp.dest);
        
        if(u != v)
        {
            ans_min += tmp.weight;
            count++;
            SetUnion(u,v);
        }
    }
    
    InitUF();
    count  = 0;
    while(count < N){
        tmp= DeleteMaxHeap(&h2);
        
        u = SetFind(tmp.src);
        v = SetFind(tmp.dest);
        
        if(u != v)
        {
            ans_max += tmp.weight;
            count++;
            SetUnion(u,v);
        }
    }
    printf("%d\n", ((N-ans_min)*(N-ans_min)) - ((N-ans_max)*(N-ans_max)));
    
    return 0;
}
