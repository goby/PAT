#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = (N) - 1; I >= 0; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define REPCC(I,A, C) for (int I = (A); !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

struct cmp_t: binary_function<char const *, char const *, bool> {
public:
    bool operator()(char const *left, char const *right) const{
        return  strcmp(left, right) < 0;
    }
};

typedef map<char const *, vector<int>, cmp_t> Map;

void insert(Map& m, char * name, int course){
    auto it = m.find(name);
    if(it == m.end()){
        vector<int> v;
        v.push_back(course);
        m.insert(MP(name, v));
    }
    else{
        it->second.push_back(course);
    }
}

Map dict;

int main()
{
    DRII(N,M);
    REP(i, M){
        DRII(id, num);
        REP(j, num){
            char *name = new char[5];
            RS(name);
            insert(dict, name, id);
        }
    }
    
    char query[5];
    while(scanf("%s", query) != EOF){
        auto v = dict[query];
        int size = v.size();
        printf("%s %d", query, size);
        sort(ALL(v));
        REP(i, size){
            printf(" %d", v[i]);
        }
        printf("\n");
    }
    
    return 0;
}
