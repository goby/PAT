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


int rate[24];
typedef struct _record{
    char name[21];
    int time[3];
    bool flag;
}record;

bool cmp(record l, record r){
    int value = strcmp(l.name, r.name);
    if(value==0)
        return l.time[0]*24*60+l.time[1]*60+l.time[2] < r.time[0]*24*60+r.time[1]*60+r.time[2];
    return value < 0;
}

int cost(record &re){
    int result = 0;
    REP(i, re.time[1]){
        result += rate[i]*60;
    }
    result += rate[re.time[1]]*re.time[2];
    REP(i, 24){
        result += (rate[i]*60)*(re.time[0]-1);
    }
    return result;
}

int diff(record &l, record &r){
    return l.time[0]*24*60+l.time[1]*60+l.time[2] - (r.time[0]*24*60+r.time[1]*60+r.time[2]);
}

int main()
{
    int  month;
    float sum = 0;
    char prename[9]={0};
    char hang[9];
    vector<record> records;
    REP(i,24) RI(rate[i]);
    CASET{
        record *r = new record;
        RS(r->name);
        scanf("%d:%d:%d:%d", &month, r->time, r->time+1, r->time+2);
        RS(hang);
        r->flag = hang[1]=='n';
        records.push_back(*r);
    }
    sort(ALL(records), cmp);
    int size=records.size();
    REP(i, size-1){
        record on =records[i], off=records[i+1];
        if(on.flag && !off.flag && (strcmp(on.name, off.name)==0)){
            if(strcmp(prename, on.name)!=0){
                strcpy(prename, on.name);
                if(sum) printf("Total amount: $%.2f\n", sum);
                printf("%s %02d\n", prename, month);
                sum = 0;
            }
            float tmp = (cost(off)-cost(on))/100.0;
            sum+=tmp;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", on.time[0],on.time[1],on.time[2],
                off.time[0],off.time[1],off.time[2],diff(off, on), tmp);
        }
    }
    if(sum) printf("Total amount: $%.2f\n", sum);
    return 0;
}
