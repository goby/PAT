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

typedef struct _stu stu;

struct _stu {
    int id;
    int vg;
    int tg;
};

vector<stu> data[4];

bool cmp(stu l, stu r){
    if(l.tg + l.vg == r.tg + r.vg) {
        if (l.vg == r.vg)
            return l.id < r.id;
        else
            return l.vg > r.vg;
    }
    return l.tg + l.vg > r.tg + r.vg;
}

int main()
{
    int id, vg,tg,grade;
    DRIII(N, L, H);
    REP(i, N){
        RIII(id, vg, tg);
        if (vg >= L && tg >= L) {
            stu *s=new stu;
            s->id=id;s->vg=vg;s->tg=tg;
            if(vg >= H && tg >= H) grade=0;
            else if(vg >= H && tg < H) grade=1;
            else if(vg >= tg) grade=2;
            else grade=3;
            data[grade].push_back(*s);
        }
    }
    REP(i, 4) sort(ALL(data[i]), cmp);
    printf("%d\n", data[0].size()+data[1].size()+data[2].size()+data[3].size());
    REP(i, 4)
        for (auto it=data[i].begin(); it!=data[i].end(); it++)
            printf("%d %d %d\n", it->id,it->vg, it->tg);
    return 0;
}
