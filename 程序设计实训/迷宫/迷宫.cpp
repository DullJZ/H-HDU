#include<iostream>
#include<stdio.h>
using namespace std;
#define StartX 1
#define StartY 1
#define EndX   8
#define EndY   8
int TraceRoute (int a[][10],int i,int j){
     //1.��2��ǵ�ǰ�ĵ��Ѿ��߹�
     a[i][j]=2;
     //2.����Ƿ����,end=0��ʾ��δ���յ�
     int end=0;
     if(i==EndX&&j==EndY){end=1;}//�����յ㣬��end=1��� 
     //3.·��ѡ�񣬹���4���߷�
     if(end!=1&&j+1<= EndY &&a[i][j+1]==1) //������ 
            {if(TraceRoute(a,i,j+1)==1) return 1;}
     if(end!=1&&i+1<= EndX &&a[i+1][j]==1)  //������ 
            {if(TraceRoute(a,i+1,j)==1) return 1;}
     if(end!=1&&j-1>= StartY &&a[i][j-1]==1)  //������ 
            {if(TraceRoute(a,i,j-1)==1) return 1;}
     if(end!=1&&i-1>= StartX &&a[i-1][j]==1)  //������ 
            {if(TraceRoute(a,i-1,j)==1) return 1;} 
     if(end!=1){a[i][j]=1;}
	  //4.����ߵ�������ͬ����û�е����յ㣬�߲�ͨ,����ǰ�㻹ԭΪ1
     return end;
}
int main(){
        int a[10][10] = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 0, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
            { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
            { 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
            { 0, 1, 0, 1, 1, 1, 0, 1, 1, 0 },
            { 0, 1, 0, 0, 0, 1, 0, 0, 1, 0 },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    for (int i = 0; i <= 9; i++)
	{
        for (int j = 0; j <= 9; j++)
		{
            cout << a[i][j] << " ";
        }
        cout << endl;
    }//���ԭʼ·�� 
    cout << endl;
    TraceRoute(a,StartX,StartY);
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }//������߹���·�� 
    system("pause");
    return 0;
}
