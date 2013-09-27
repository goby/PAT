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

vector<int> data;

typedef pair<int, int> intpair;

int center(int start, int end){
    int size = end-start;
    int tmp=size, fill=0;
    while (size>0) {
        fill = (fill << 1)+1;
        size = size >> 1;
    }
    int offset=(fill-tmp) - (fill+1)/4;
    offset=offset< 0 ? 0 : offset;
    int c = fill/2 - offset + start;
    return c;
}

int main()
{
    CASET{
        DRI(num);
        data.push_back(num);
    }
    
    sort(ALL(data));
    queue<intpair> q;
    int size=data.size();
    q.push(MP(0, size));
    bool first = true;
    while (!q.empty()) {
        intpair f = q.front();
        int c = center(f.first, f.second);
        q.pop();
        if(first) { printf("%d", data[c]); first=false;}
        else printf(" %d", data[c]);
        if(c > f.first)  q.push(MP(f.first, c));
        if(f.second > c+1)  q.push(MP(c+1, f.second));
    }
    return 0;
}
