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
using namespace std;
struct People {
    int ID;
    char name[20];
    double score[5];
    double final_score;
    int rank;
} people[Total];

void inputInfo()
{
    printf("Please input data:\n");
    for (int i = 0; i < Total; i ++) {
        scanf("%d", &people[i].ID);
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
    int i;
    double m=0;
    vector<double> top(5);
    for(i=0;i<top.size();i++)
        cin>>top[i];
    sort(top.begin(),top.end());
    for(i=2;i<=4;i++)
        m+=top[i];
    m=m/3*7;
    cout<<"最高得分："<<top[3]<<" "<<top[4]<<endl;
    cout<<"最低得分："<<top[0]<<" "<<top[1]<<endl;
    printf("得分是：%.2lf\n",m);
    return 0;
}
