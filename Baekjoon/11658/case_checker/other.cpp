#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int table_size;
int table[1025][1025];
int tree[1025][1025];

int sum(int r, int c){
  int result=0;
  for(int row= r; row>0 ; row -= (row & -row))
    for(int col = c; col>0 ; col -=(col & -col))
      result += tree[row][col];
    
  return result;
}

void update(int r, int c, int num){
  for(int row= r; row<=table_size ; row += (row & -row))
    for(int col = c; col<=table_size ; col +=(col & -col))
      tree[row][col] += num;
    
}

int main(){
  int operation_num;
  scanf("%d %d", &table_size, &operation_num);
  memset(tree,0,sizeof(tree));

  for(int r=1; r<=table_size ; ++r){
    for(int c=1; c<=table_size ; ++c){
      scanf("%d",&table[r][c]);
      update(r, c, table[r][c]);
    }
  }

  int  w, r1, c1, r2, c2, num;
  while(operation_num--){
    scanf("%d", &w);
    if(w==0){
      scanf("%d %d %d",&r1, &c1,&num);
      update(r1, c1, num - table[r1][c1]);
      table[r1][c1] = num;
    }else if(w==1){
      scanf("%d %d %d %d",&r1, &c1,&r2, &c2);
      printf("%d\n",sum(r2, c2) - sum(r2, c1-1) - sum(r1-1,c2) + sum(r1-1,c1-1));
    }
  }

  return 0;
}
