#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NMAX 1010

int n;
priority_queue<pair<int, pair<int, int> > > que;
vector<pair<pair<int, int>, int> > ans;
priority_queue<pair<int, pair<int, int> > > que2;
vector<pair<pair<int, int>, int> > ans2;
int parent[NMAX];
int _min , _max;

void init()
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

void input()
{
    int m;
    int one, two, w;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m+1; i++) {
        scanf("%d %d %d", &one, &two, &w);
        que.push(make_pair(w * -1, make_pair(one, two)));
        que2.push(make_pair(w , make_pair(one, two)));
    }
}

int find(int node)
{
    if (parent[node] == node)        return node;
    return parent[node] = find(parent[node]);
}

void kruskal()
{
    init();
    
    while (!que.empty()) {
        int w = que.top().first * -1;
        int one = que.top().second.first;
        int two = que.top().second.second;
        que.pop();
        
        if (find(one) != find(two)) {
            ans.push_back(make_pair(make_pair(one, two), w));
            _min += w;
            parent[find(one)] = find(two);
        }
    }
    
    init();
    
    while (!que2.empty()) {
        int w = que2.top().first;
        int one = que2.top().second.first;
        int two = que2.top().second.second;
        que2.pop();
        
        if (find(one) != find(two)) {
            ans2.push_back(make_pair(make_pair(one, two), w));
            _max += w;
            parent[find(one)] = find(two);
        }
    }
}

int main()
{
    input();
    
    kruskal();
    
    printf("%d\n" , (_max*_max) - (_min*_min));
    
    return 0;
}
