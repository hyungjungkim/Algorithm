#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int from, to, weight;
};

bool cmp(node n1, node n2) {
    return n1.weight < n2.weight;
}

int p[10001];
int ffind(int x) {
    if (x == p[x])
        return x;
    else
        return p[x] = ffind(p[x]);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    vector<node> v(E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].weight);
    }
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 1; i <= V; i++)
        p[i] = i;
    
    int ans = 0;
    for (int i = 0; i < E; i++) {
        int rootU = ffind(v[i].from);
        int rootV = ffind(v[i].to);
        if (rootU != rootV) {
            p[rootU] = rootV;
            ans += v[i].weight;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
