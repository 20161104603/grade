//
//  main.cpp
//  grade
//
//  Created by 20161104603 on 18/6/25.
//  Copyright © 2018年 20161104603. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0
#define	MAXSIZE  1000

struct student{
    double num;
    char name[30];
    int score[20];
    int sum;
    double iphone;

};

struct referee
{//裁判
    string ID;
    string name;
    string sex;
    string tel;
};
struct referee r[10];
typedef struct student ElemType;
typedef  struct
{
    ElemType  elem[MAXSIZE];
    int       last;
}SeqList;


void Add(SeqList* L);
void menu(SeqList* L);
void Change(SeqList *L);
void Insert(SeqList* L);
void Show(SeqList *L);
void JM();
int Find(SeqList* L);
int Find1(referee *r);
void search(SeqList* L);
void read(SeqList* L);
void save(SeqList* L);
void Del(SeqList* L);
void sort(SeqList* L);
void put(referee *r);
void outreferee(referee *r);
void calculateScore(SeqList* L);
void sortcalculateScore(SeqList* L);
void ChangeReferee(SeqList *r);


void put(referee *r)
{  int i;
    cout<<"输入裁判信息:"<<endl;
    for(i=0;i<5;i++)
    {
        
        cout<<"ID:"<<endl;
        cin>>r[i].ID;
        cout<<"name:"<<endl;
        cin>>r[i].name;
        cout<<"sec:"<<endl;
        cin>>r[i].sex;
        cout<<"tel:"<<endl;
        cin>>r[i].tel;
    }
}
void outreferee(referee *r)
{int i;
    for(i=0;i<5;i++)
    {
        
        cout<<"ID:"<<endl;
        cout<<r[i].ID;
        cout<<"name:"<<endl;
        cout<<r[i].name;
        cout<<"sec:"<<endl;
        cout<<r[i].sex;
        cout<<"tel:"<<endl;
       cout<<r[i].tel;
    }
}


void read(SeqList *L)
{
    int i = 0, Score[20], Sum;
    double Num;
    char Name[30];
    double Iphone;
    FILE* fp;
    fp = fopen("/Users/a20161104603/Desktop/grade/student.csv", "r");
    if(fp == NULL)
        printf("该文件为空!\n");
    else
    {
        while(fscanf(fp,"%lf %s %lf %d %d %d %d %d %d", &Num, Name, &Iphone, &Score[0], &Score[1], &Score[2], &Score[3], &Score[4], &Sum)!=EOF)
        {
            L->elem[i].num = Num;
            strcpy(L->elem[i].name, Name);
            L->elem[i].iphone = Iphone;
            L->elem[i].score[0] = Score[0];
            L->elem[i].score[1] = Score[1];
            L->elem[i].score[2] = Score[2];
            L->elem[i].score[3] = Score[3];
            L->elem[i].score[4] = Score[4];
            L->elem[i].sum = Sum;
            i++;
            L->last++;
        }
        fclose(fp);
    }
}

void save(SeqList* L)
{
    int i;
    FILE* fp;
    fp = fopen("/Users/a20161104603/Desktop/grade/student.csv", "w");
    if(fp == NULL)
        printf("当前文件夹不能被打开!\n");
    else
    {
        for(i=0; i<L->last; i++)
        {
            fprintf(fp,"%lf %s %lf %d %d %d %d %d %d\n",L->elem[i].num, L->elem[i].name,L->elem[i].iphone, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2],L->elem[i].score[3],L->elem[i].score[4], L->elem[i].sum);
        }
        printf("信息保存成功\n");
        fclose(fp);
        return;
    }
}
void JM()
{
    printf("**********************************************\n");
    printf("**--------------功能菜单表--------------------**\n");
    printf("**********************************************\n");
    printf("**------------1.添加参赛人员信息---------------**\n");
    printf("**------------2.修改参赛人员信息---------------**\n");
    printf("**------------3.删除参赛人员信息---------------**\n");
    printf("**------------4.显示全部参赛人员信息------------**\n");
    printf("**------------5.插入参赛人员信息---------------**\n");
    printf("**------------6.保存参赛人员信息---------------**\n");
    printf("**------------7.查询参赛人员信息---------------**\n");
    printf("**------------8.按照总成绩排序-----------------**\n");
    printf("**------------9.添加裁判人员信息---------------**\n");
    printf("**------------10.输出裁判信息-----------------**\n");
    printf("**------------11.显示参赛人员平均成绩-----------**\n");
    printf("**------------8.按照平均成绩排序---------------**\n");
    printf("**------------0.退出评分系统------------------**\n");
    printf("**********************************************\n");
}


void menu(SeqList* L)
{
    JM();
    read(L);
    int i;
    printf("选择要进行的功能");
   	while(scanf("%d",&i)!=EOF)
    {
        switch(i)
        {
            case 1: Add(L);break;
            case 2: Change(L);break;
            case 3: Del(L);break;
            case 4: Show(L);break;
            case 5: Insert(L);break;
            case 6: save(L);break;
            case 7: search(L);break;
            case 8: sort(L);break;
            case 9: put(r);break;
            case 10: outreferee(r);break;
            case 11: calculateScore(L);break;
            case 12: sortcalculateScore(L);break;
            case 0: exit(0);break;
        }
        
    }
}

void Add(SeqList* L)
{
    printf("进入添加参赛人员信息系统\n");
    int i;
    i = L->last;
    printf("请输入参赛人员赛号");
    scanf("%lf", &L->elem[i].num);
    
    printf("请输入参赛人员姓名");
    scanf("%s", L->elem[i].name);
    
    printf("请输入参赛人员手机号");
    scanf("%lf", &L->elem[i].iphone);
    
    printf("请输入参赛人员成绩\n");
    printf("一号评委成绩");
    scanf("%d", &L->elem[i].score[0]);
    printf("二号评委成绩");
    scanf("%d", &L->elem[i].score[1]);
    printf("三号评委成绩");
    scanf("%d", &L->elem[i].score[2]);
    printf("四号评委成绩");
    scanf("%d", &L->elem[i].score[3]);
    printf("五号评委成绩");
    scanf("%d", &L->elem[i].score[4]);
    L->elem[i].sum = L->elem[i].score[0] + L->elem[i].score[1] + L->elem[i].score[2]+ L->elem[i].score[3]+ L->elem[i].score[4];
    L->last++;
    printf("信息添加成功！");
    
}
void Del(SeqList* L)
{
    printf("进入删除参赛人员信息系统\n");
    int i, s;
    s = Find(L) - 1;
    for(i=s; i<L->last; i++)
    {
        L->elem[i] = L->elem[i+1];
    }
    L->last--;
    printf("删除成功！\n");
}

int Find(SeqList* L)
{
    double n;
    printf("请输入要查找的赛号\n");
    scanf("%lf", &n);
    int i=0;
    while ((i <= L->last) && (L->elem[i].num != n))
        i++;
    if(i<=L->last)
        return i+1;
    else
        return -1;
}



void Insert(SeqList* L)
{
    printf("进入插入参赛人员信息系统\n");
    int i, s;
    printf("输入插入位置");
    scanf("%d", &s);
    s--;
    L->last++;
    for(i=L->last-1; i>s; i--)
    {
        L->elem[i] = L->elem[i-1];
    }
    printf("请输入参赛人员赛号");
    scanf("%lf", &L->elem[s].num);
    printf("请输入参赛人员姓名");
    scanf("%s", L->elem[s].name);
    printf("请输入参赛人员手机号");
    scanf("%lf", &L->elem[s].iphone);
    printf("请输入参赛人员成绩\n");
    printf("一号评委成绩");
    scanf("%d", &L->elem[s].score[0]);
    printf("二号评委成绩");
    scanf("%d", &L->elem[s].score[1]);
    printf("三号评委成绩");
    scanf("%d", &L->elem[s].score[2]);
    printf("四号评委成绩");
    scanf("%d", &L->elem[s].score[3]);
    printf("五号评委成绩");
    scanf("%d", &L->elem[s].score[4]);
    L->elem[s].sum = L->elem[s].score[0] + L->elem[s].score[1] + L->elem[s].score[2] + L->elem[s].score[3] + L->elem[s].score[4];
    
    printf("信息添加成功！");
    
}


void Change(SeqList *L)
{
    printf("进入修改参赛人员信息系统\n");
    int  s;
    int have;
    s = Find(L) - 1;
    if(s != -1)
    {
        printf("找到赛号为%.0lf的参赛人员信息。",L->elem[s].num);
        printf("选择要修改的信息：\n\t1.修改名字。\n\t2.修改赛号。\n\t3.修改手机号\n\t4.修改一号评委成绩。\n\t5.修改二号评委成绩。\n\t6.修改三号评委成绩。\n\t7.修改四号评委成绩。\n\t8.修改五号评委成绩。\n");
        scanf("%d", &have);
        printf("请输入要修改的信息");
        switch(have)
        {
                
            case 1:scanf("%s",L->elem[s].name);break;
            case 2:scanf("%lf",&L->elem[s].num);break;
            case 3:scanf("%lf",&L->elem[s].iphone);break;
            case 4:scanf("%d",&L->elem[s].score[0]);break;
            case 5:scanf("%d",&L->elem[s].score[1]);break;
            case 6:scanf("%d",&L->elem[s].score[2]);break;
            case 7:scanf("%d",&L->elem[s].score[3]);break;
            case 8:scanf("%d",&L->elem[s].score[4]);break;
        }
        if( have==4 || have==5 || have==6|| have==7|| have==8 )
            L->elem[s].sum = L->elem[s].score[0] + L->elem[s].score[1] + L->elem[s].score[2]+ L->elem[s].score[3]+ L->elem[s].score[4];
        printf("修改成功\n");
    }
    else
        printf("未找到参赛人员信息\n");
}
void search(SeqList *L)
{
    printf("进入查询参赛人员信息系统\n");
    int  s;
    int have;
    s = Find(L) - 1;
    if(s != -1)
    {
        printf("找到赛号为%.0lf的参赛人员信息。",L->elem[s].num);
         printf("选择要查找的信息：\n\t1.查找一号评委成绩。\n\t2.查找二号评委成绩。\n\t3.查找三号评委成绩。\n\t4.查找四号评委成绩。\n\t5.查找五号评委成绩。\n");
        scanf("%d", &have);
        switch(have)
        {
            case 1:printf("一号评委成绩%d",L->elem[s].score[0]);break;
            case 2:printf("二号评委成绩%d",L->elem[s].score[1]);break;
            case 3:printf("三号评委成绩%d",L->elem[s].score[2]);break;
            case 4:printf("四号评委成绩%d",L->elem[s].score[3]);break;
            case 5:printf("五号评委成绩%d",L->elem[s].score[4]);break;
        }
        printf("查找成功\n");
    }
    else
        printf("未找到参赛人员信息\n");
}


void calculateScore(SeqList *L)
{
    printf("显示全部参赛人员平均成绩\n");
    int i;
    printf("     赛号       姓名        平均成绩成绩   \n");
    for(i=0; i<L->last; i++)
    {
    printf("     %.0lf         %s       %d \n",L->elem[i].num, L->elem[i].name,L->elem[i].sum/5);
    }
}
void Show(SeqList *L)
{
    printf("显示全部参赛人员信息\n");
    int i;
    printf("     赛号       姓名        手机号  一号评委成绩 二号评委成绩 三号评委成绩 四号评委成绩 五号评委成绩   总成绩   \n");
    for(i=0; i<L->last; i++)
    {
        printf("     %.0lf         %s       %.0lf      %d        %d       %d         %d        %d          %d \n",L->elem[i].num, L->elem[i].name,L->elem[i].iphone, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2], L->elem[i].score[3], L->elem[i].score[4],L->elem[i].sum);
    }
}
void sort(SeqList *L)
{
    int i,j,n;
    ElemType temp;
    n=L->last;
    for(i=0;i<n-1;i++)
    {
        
        for(j=0;j<n-i;j++)
        {
            if(L->elem[j].sum<L->elem[j+1].sum)
            {
                temp=L->elem[j];
                L->elem[j]=L->elem[j+1];
                L->elem[j+1]=temp; 
            }
            
            
        }
        printf("     赛号       姓名        手机号    一号评委成绩 二号评委成绩 三号评委成绩 四号评委成绩 五号评委成绩   总成绩   \n");
        for(i=0; i<L->last; i++)
        {
            printf("     %.0lf         %s       %.0lf        %d        %d       %d         %d        %d          %d \n",L->elem[i].num, L->elem[i].name,L->elem[i].iphone, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2], L->elem[i].score[3], L->elem[i].score[4],L->elem[i].sum);
        }
    }
    
    
}
void  sortcalculateScore(SeqList* L)
{
    int i,j,n;
    ElemType temp;
    n=L->last;
    for(i=0;i<n-1;i++)
    {
        
        for(j=0;j<n-i;j++)
        {
            if(L->elem[j].sum/5<L->elem[j+1].sum/5)
            {
                temp=L->elem[j];
                L->elem[j]=L->elem[j+1];
                L->elem[j+1]=temp;
            }
            
            
        }
        printf("     赛号       姓名        手机号    一号评委成绩 二号评委成绩 三号评委成绩 四号评委成绩 五号评委成绩   平均成绩   \n");
        for(i=0; i<L->last; i++)
        {
            printf("     %.0lf         %s       %.0lf        %d        %d       %d         %d        %d          %d \n",L->elem[i].num, L->elem[i].name,L->elem[i].iphone, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2], L->elem[i].score[3], L->elem[i].score[4],L->elem[i].sum/5);
        }
    }
    
    
}

int main()
{
    SeqList L;
    L.last = 0;
    menu(&L);
    return 0;
}

