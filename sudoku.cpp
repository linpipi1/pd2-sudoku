#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Sudoku.h"
using namespace std;

void Sudoku::GiveQuestion()
{
  int element[12][12]={{ 4, 2, 6, 8, 7, 3, 9, 5, 1,-1,-1,-1},
                       { 0, 0, 3, 9, 5, 0, 6, 0, 4,-1,-1,-1},
                       { 9, 0, 1, 6, 2, 4, 8, 0, 0,-1,-1,-1},
                       {-1,-1,-1, 1, 3, 2, 0, 8, 7, 9, 5, 6},
                       {-1,-1,-1, 0, 8, 0, 1, 9, 0, 4, 2, 0},
                       {-1,-1,-1, 4, 9, 6, 2, 3, 0, 8, 7, 1},
                       { 1, 0, 0, 0, 4, 0,-1,-1,-1, 6, 9, 5},
                       { 0, 0, 4, 0, 6, 0,-1,-1,-1, 1, 3, 7},
                       { 6, 9, 5, 0, 1, 7,-1,-1,-1, 2, 8, 4},
                       ( 3, 1, 2,-1,-1,-1, 7, 4, 0, 5, 0, 9),
                       ( 7, 4, 8,-1,-1,-1, 0, 6, 9, 3, 0, 2),
                       ( 0, 6, 0,-1,-1,-1, 3, 1, 0, 7, 0, 8)};
  srand((unsigned)time(0));
  /*row在自己的九宮格內隨意交換的所有可能*/
  /**/
  int h,i,g,j;
  int changerow[4][6][3][12];
  int a,b,c;
  for(h=0;h<4;h++)
  {     for(i=0;i<6;i++)
        {       a=0+rand()%3;
                b=0+rand()%3;
                for(j=0;j<12;j++)
                {       if(a==b)
                        {   i=i-1;
                            break; }
                        c=(3+9*h)-a-b;
                        changerow[h][i][0][j]=element[a][j];
                        changerow[h][i][1][j]=element[b][j];
                        changerow[h][i][2][j]=element[c][j];
                }
        }
  }
  /*改好一次row先存起來*/
  int d;
  for(h=0;h<4;h++)
  {     d=1+rand()%6;
        for(g=0;g<3;g++)
        {       for(j=0;j<12;j++)
                { element[3*h+g][j]=changerow[h][d][g][j]; }
        }
  }
  /*column在自己的九宮格內隨意交換的所有可能*/
  int s,t,u,v;
  int changecol[4][6][3][12];
  int x,y,z;
  for(s=0;s<4;s++)
  {     for(t=0;t<6;t++)
        {       x=0+rand()%3;
                y=0+rand()%3;
                for(v=0;v<12;v++)
                {       if(x==y)
                        {   t=t-1;
                            break; }
                        z=(3+9*s)-x-y;
                        changerow[s][t][0][v]=element[x][v];
                        changerow[s][t][1][v]=element[y][v];
                        changerow[s][t][2][v]=element[z][v];
                }
        }
  }
  /*改完一次column再存一次*/
  int r;
  for(s=0;s<4;s++)
  {     r=1+rand()%6;
        for(u=0;u<3;u++)
        {       for(v=0;v<12;v++)
                { element[3*s+u][v]=changerow[s][r][u][v]; }
        }
  }
  /*改變-1的位置*/
  int direction;
  int question[12][12];
  int m,n;

  direction=1+rand()%4;
  /*direction=1,不動*/
  if(direction==1)
  {
        for(m=0;m<12;m++)
        {   for(n=0;n<12;n++)
            {   cout<<element[m][n];   }
            cout<<"\n";
        }
  }
  /*direction=2,向左轉90度*/
  if(direction==2)
  {     for(m=0;m<12;m++)
        {   for(n=0;n<12;n++)
            {   question[m][n]=element[11-n][m];
                cout<<question[m][n];
            }
            cout<<"\n";
        }
  }
  /*direction=3,向左轉180度*/
  if(direction==3)
  {     for(m=0;m<12;m++)
        {   for(n=0;n<12;n++)
            {   question[m][n]=element[11-m][11-n];
                cout<<question[m][n];
            }
            cout<<"\n";
        }
  }
  /*direction=,向左轉270度*/
  if(direction==4)
  {     for(m=0;m<12;m++)
        {   for(n=0;n<12;n++)
            {   question[m][n]=element[n][11-m];
                cout<<question[m][n];
            }
            cout<<"\n";
        }
  }

}

void Sudoku::ReadIn()
{
    int i,j;
    int antiquestion[12][12];
    for(i=0;i<12;i++)
    {   for(j=0;j<12;j++)
        {   cin>>antiquestion[12][12]; }
    }
}
void Sudoku::Solve()
{
    int number[9]={0,0,0,0,0,0,0,0,0};
    int i,j,a,num,k;
    for(i=0;i<12;i++)
        {   for(j=0;j<12;j++)
            {   if(antiquestion[i][j]==0)
                {   /*算行用過那些數字*/
                    for(a=0;a<12;a++)
                    {   for(num=1;num<10;num++)
                        {   if(antiquestion[i][a]==num)
                            {   number[num-1]++;
                                break;          }
                        }
                    }
                    /*算列用過那些數字*/
                    for(d=0;d<12;d++)
                    {   for(num=1;num<10;num++)
                        {   if(antiquestion[d][j]==num)
                            {   number[num-1]++;
                                break;          }
                        }
                    }
                    /*先確定是哪一個九宮格*/
                    for(m=0;m<=6;m=m+3)
                    {   if(i>(m-1)&&i<(m+3))
                        {   minrow=m;
                            maxrow=m+2;
                            break;   }
                    }
                      for(n=0;n<=6;n=n+3)
                    {   if(i>(n-1)&&i<(n+3))
                        {   mincol=n;
                            maxcol=n+2;
                            break;   }
                    }
                    /*算九宮格用過什麼數字*/
                    for(b=minrow;b<=maxrow;b++)
                    {   for(c=mincol;c<=maxcol;c++)
                        {   for(num=1;num<10;num++)
                            {   if(antiquestion[b][c]==num)
                                {   number[num-1]++;
                                    break;           }
                            }
                        }
                    }

                    for(a=0;a<9;a++)
                    {   if()

                    }


                }
            }
        }
   }
}

int main()
{
    Sudoku mySudoku;
    Sudoku antiSudoku;

    mySudoku.GiveQuestion();
    mySudoku.Solve();

    antiSudoku.ReadIn();
    antiSudoku.Solve();
}


