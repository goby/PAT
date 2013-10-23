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
typedef struct {
    int id;
    char name[10];
    int score;
} Student;


template <int i>
bool cmp(Student left, Student right){
    if(i == 0)
        return left.id < right.id;
    if(i == 1) {
        int res = strcmp(left.name, right.name);
        if(res == 0)
            return left.id < right.id;
        return res < 0;
    }
    else {
        if(left.score == right.score)
            return left.id < right.id;
        return left.score < right.score;
    }
}

vector<Student> students;

int main()
{
    DRII(N, C);
    REP(i, N){
        Student s;
        cin >> s.id >> s.name >> s.score;
        students.push_back(s);
    }
    switch (C) {
        case 1:
            sort(ALL(students),cmp<0>);
            break;
        case 2:
            sort(ALL(students),cmp<1>);
            break;
        case 3:
            sort(ALL(students),cmp<2>);
            break;
        default:
            break;
    }
    
    for (auto it = students.begin(); it != students.end(); it++) {
        printf("%06d %s %d\n", it->id, it->name, it->score);
    }
}
