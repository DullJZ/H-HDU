#include <stdio.h>
int FindTheEnterence(int, int, int);
void type(int);
int maze[10][10];
int memory[100];

int main() {
    int i,j;
    FILE* p;
    p = fopen("/Users/����/Desktop/project.txt","r");//�������ϴ����ļ�
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)//�����Թ�
            fscanf(p,"%d", &maze[i][j]);
    FindTheEnterence(1, 1, 0);//�������
}

int FindTheEnterence(int i, int j, int n){
    if(8==i&&8==j){
        maze[i][j]=1;
        type(n);
        exit(0);//�����յ�
    }
    if(1==maze[i][j])
        return 0;
    else{
        memory[n]=i;
        memory[n+1]=j;//���õ�
        maze[i][j]=1; /*���߹���·��Ϊǽ����ֹ�ظ�����������·*/
        FindTheEnterence(i, j+1, n+2);//��
        FindTheEnterence(i+1, j, n+2);//��
        FindTheEnterence(i, j-1, n+2);//��
        FindTheEnterence(i-1, j, n+2);//��
    }
    return 0;
}

void type(int n){
    int i;
    for(i=0; i<n; i+=2)
        printf("(%d,%d)->",memory[i],memory[i+1]);
    printf("(8,8)\n");
}
