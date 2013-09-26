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

typedef struct _t{
    int arrive;
    int process;
}cst;

typedef pair<int,int> win;

struct cmp_t{
    bool operator()(const win& _Left, const win& _Right) const
	{	
        return (_Left.second > _Right.second);
	}
};

bool cmp(cst l, cst r){
    return l.arrive < r.arrive;
}
int tt[100]={0};
const int ftime=540*60+1;
int main()
{
    DRII(N,K);
    int p=0, total = 0;
    vector<cst> all;
    REP(i, N){
        int h,m,s;
        scanf("%d:%d:%d", &h, &m, &s);
        cst *t = new cst;
        t->arrive =(h - 8)*3600+m*60+s;
        DRI(process);
        t->process=process*60;
        all.push_back(*t);
    }
    sort(ALL(all), cmp);
    priority_queue<int, vector<int>,greater<int>> pq;
    REP(i, K) pq.push(0);
    while(p < N && all[p].arrive < ftime){
        int top = pq.top();
        pq.pop();
        if(top < all[p].arrive) top = all[p].arrive;/*IMPORTANT*/
        total +=  top - all[p].arrive;
        top += all[p].process;
        pq.push(top);
        p++;
    }
    if(p) printf("%.1f", total * 1.0 / 60 / p);
    else printf("0.0");
    return 0;
}
