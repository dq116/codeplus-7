
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
const int DATH = 0;
const int ALIVE = 1;
const int maxn = 50;
const int m =15 ,n = 31;
const int dx[] = { -1,-1,-1,0,1,1,1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };

int map[m][n], newmap[m][n];
int general = 0;
const char* s="0	0	1	0	0	1	0	0	1	1	0	0	1	0	0	1	0	0	1	1	0	0	1	0	0	1	0	0	0	0	1\
0	0	1	0	0	1	0	0	0	0	0	0	1	0	0	1	0	0	0	0	0	0	0	1	0	0	0	0	1	0	0\
0	0	1	0	1	1	1	1	0	0	0	0	1	0	0	1	1	1	0	0	1	1	0	1	0	1	0	1	1	1	0\
0	0	1	0	1	1	0	1	0	1	0	0	1	0	1	1	0	1	1	0	0	0	0	1	1	0	1	0	1	0	0\
0	0	1	0	0	1	1	0	0	0	0	1	0	0	0	1	0	0	0	0	1	0	1	1	0	0	0	0	1	1	0\
0	0	1	0	0	1	0	1	0	0	0	0	1	0	1	1	0	0	1	0	1	0	1	1	1	1	0	0	0	0	0\
0	0	1	1	0	1	1	1	0	1	0	0	1	1	0	1	1	1	0	1	1	1	0	1	1	0	1	0	0	1	0\
0	0	1	0	0	0	1	0	0	0	0	0	1	0	1	1	1	0	0	0	0	0	0	0	0	1	0	1	1	0	0\
0	1	1	0	0	0	1	1	1	0	0	1	1	0	0	1	0	0	1	1	0	1	1	0	1	0	1	1	1	0	1\
0	1	1	1	0	1	0	0	0	0	0	1	0	0	0	1	0	0	1	0	0	0	0	1	0	0	0	1	1	1	0\
0	0	1	0	1	0	0	1	0	0	0	1	0	1	0	0	0	1	0	1	0	0	0	0	0	0	0	0	0	1	1\
0	0	1	0	0	1	0	1	0	0	0	1	0	0	0	1	0	0	1	1	1	0	1	1	0	0	1	1	1	1	1\
0	0	0	0	1	0	0	1	0	0	0	1	0	1	0	0	0	1	0	0	1	0	1	1	0	0	1	1	1	1	1\
0	0	0	0	0	1	0	0	0	1	0	0	1	0	0	1	0	0	1	0	0	0	0	0	0	0	0	0	0	1	0\
0	0	0	0	0	0	1	0	1	0	0	0	1	0	0	0	0	0	1	0	0	0	0	1	0	1	1	0	0	1	0";



//计算(x,y)周围存活细胞的个数
int neighbor_num(int x, int y,int map[][n])
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny])  cnt++;
    }
    return cnt;
}

//打印第i代的结果
void print_general()
{
    printf("第%d代：\n", general);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (map[i][j])  printf("■");
            else printf("□");
        printf("\n");
    }
}

//将map复制到tmp_map
void copy_map(int map[][n], int tmp_map[][n])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            tmp_map[i][j] = map[i][j];
}

//得到下一代
void iteration()
{
    int tmp_map[m][n];
    copy_map(map, tmp_map);        //保存之前图像，使得当前元素状态的改变还是基于之前的地图，而不是被修改了的
    for(int i = 0;i < m;i++)
        for (int j = 0; j < n; j++)
        {
            int cnt = neighbor_num(i, j, tmp_map);
            switch (cnt)
            {
            case 2: continue;
            case 3: map[i][j] = ALIVE; break;
            default: map[i][j] = DATH; break;
            }
        }

    general++;
    print_general();
}
void init(const char*s)
{
    
    int counter=0,row=0,column=0;

    for (int i=0;i<strlen(s);i++)
    {
        
        if (s[i]=='0' or s[i]=='1')
        {
            map[row][column]=s[i]-'0';
            counter+=1;
            if (counter>=n)
            {
                counter=0;
                row+=1;
                if (row==n)
                    break;
                column=0;
            }
            else
            {
               
                column+=1;
            }
            
            
        }

    }
   

}
int main()
{
    
    init(s); 
    iteration();
  
}