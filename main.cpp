//
//  main.cpp
//  grade
//
//  Created by 20161104603 on 18/6/25.
//  Copyright © 2018年 20161104603. All rights reserved.
//
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#define Total 10
#define	MAXSIZE  100
using namespace std;
struct People {
    double ID;
    char name[20];
    double score[5];
    double final_score;
    int rank;
} people[Total];

typedef struct People ElemType;
typedef  struct
{
    ElemType  elem[MAXSIZE];
    int       last;
}SeqList;

void inputInfo(SeqList* L);
void Add(SeqList* L);
void menu(SeqList* L);
void Show(SeqList *L);
void JM();
void save(SeqList* L);
void sort(SeqList* L);
void read(SeqList* L);


void JM()
{
    printf("******************************************\n");
    printf("**-------------大赛评分系统---------------**\n");
    printf("******************************************\n");
    printf("**------------1.计算选手成绩--------------**\n");
    printf("**------------2.显示选手成绩--------------**\n");
    printf("******************************************\n");
}


void menu(SeqList* L)
{
    JM();
    read(L);
    int i;
    printf("欢迎进入大赛评分系统");
   	while(scanf("%d",&i)!=EOF)
    {
        switch(i)
        {
            case 1: inputInfo(L);break;
                case 2: Show(L);break;
        }
        
    }
}

void Show(SeqList *L)
{
    printf("选手成绩\n");
    int i;
    printf("|    选手号码   |    选手姓名   | 评委一成绩 | 评委二成绩 |  评委三成绩 |  评委四成绩  |  评委五成绩  |  最终成绩  |\n");
    for(i=0; i<L->last; i++)
    {
        printf("|%11.0lf|%13s|%10f|%12f|%10f|%10f|%10f|%10f|\n",L->elem[i].ID, L->elem[i].name, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2],L->elem[i].score[3],L->elem[i].score[4],L->elem[i].final_score);
    }
}

void inputInfo(SeqList* L)
{
    printf("Please input data:\n");
    for (int i = 0; i < Total; i ++) {
        scanf("%lf", &people[i].ID);
        getchar();
        scanf("%s", people[i].name);
        scanf("%lf", &people[i].score[0]);
        scanf("%lf", &people[i].score[1]);
        scanf("%lf", &people[i].score[2]);
        scanf("%lf", &people[i].score[3]);
        scanf("%lf", &people[i].score[4]);
        people[i].final_score = 0.0;
        people[i].rank = i + 1;
    }
}
int main()
{
    SeqList L;
    L.last = 0;
    menu(&L);
    return 0;}
