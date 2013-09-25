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

const char *dict="ACME";

typedef struct _stu{
    int id;
    int score[4];
} stu;

int scorerank[4][100];
int table[1000000][4];

template<int i>
bool cmp(stu l, stu r)
{
    return l.score[i] > r.score[i];
}

void best(int *score, char &c, int &rk){
    int max=0;
    rk=1000000;
    REP(i,4){
        if(rk>score[i]){
            rk=score[i];
            max=i;
        }
    }
    c=dict[max];
}


int main()
{
    DRII(N,M);
    vector<stu> students;
    REP(i,N){
        stu *tmp = new stu;
        RI(tmp->id);
        RIII(tmp->score[1], tmp->score[2], tmp->score[3]);
        tmp->score[0] = (tmp->score[1]+tmp->score[2]+tmp->score[3])/3;
        students.push_back(*tmp);
    }
    MS0(scorerank);
    MS1(table);
    sort(ALL(students), cmp<0>);
    REP(i,N) {
        if(!scorerank[0][students[i].score[0]])
            scorerank[0][students[i].score[0]]=i+1;
    }
    sort(ALL(students), cmp<1>);
    REP(i,N) {
        if(!scorerank[1][students[i].score[1]])
            scorerank[1][students[i].score[1]]=i+1;
    }
    sort(ALL(students), cmp<2>);
    REP(i,N) {
        if(!scorerank[2][students[i].score[2]]) 
            scorerank[2][students[i].score[2]]=i+1;
    }
    sort(ALL(students), cmp<3>);
    REP(i,N) {
        if(!scorerank[3][students[i].score[3]]) 
            scorerank[3][students[i].score[3]]=i+1;
    }
    REP(i,N) {
        REP(j,4){
            table[students[i].id][j]=scorerank[j][students[i].score[j]];
        }
    }
    REP(i, M){
        DRI(id);
        char c;int rk;
        best(table[id], c, rk);
        if(rk<0) printf("N/A\n");
        else printf("%d %c\n", rk, c);
    }

    return 0;
}
