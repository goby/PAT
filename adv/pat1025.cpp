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

typedef struct _data data;

vector<data*> testee[101];

struct _data {
    char id[14];
    int score;
    int group;
    int rank;
};

bool cmp(data* l, data* r){
    if(l->score == r->score) return strcmp(l->id, r->id) < 0;
    return l->score > r->score;
}

int main()
{
    DRI(N);
    REP(i,N){
        DRI(K);
        REP(j, K){
            data *d = new data;
            RS(d->id);
            RI(d->score);
            d->group=i+1;
            testee[i].push_back(d);
            testee[N].push_back(d);
        }
    }
    
    REP(i, N) sort(ALL(testee[i]), cmp);
    sort(ALL(testee[N]), cmp);
    REP(i, N) {
        int size=testee[i].size();
        int pre=-1; int rank=0;
        REP(j, size){
            if(testee[i][j]->score==pre)
                testee[i][j]->rank=rank;
            else {
                rank=j+1;
                pre = testee[i][j]->score;
                testee[i][j]->rank=rank;
            }
        }
    }
    
    int size=testee[N].size();
    int pre=-1; int rank=0;
    printf("%d\n", size);
    REP(j, size){
        printf("%s", testee[N][j]->id);
        if(testee[N][j]->score==pre){
            printf(" %d", rank);
        }
        else {
            rank=j+1;
            pre = testee[N][j]->score;
            printf(" %d", rank);
        }
        printf(" %d %d\n", testee[N][j]->group, testee[N][j]->rank);
    }
    
    return 0;
}
