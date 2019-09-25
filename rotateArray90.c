/******************************************************************************
Given an array rotate it by 90 degrees
Example:
Input:
 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15 16 

Output:
 4  8 12 16 
 3  7 11 15 
 2  6 10 14 
 1  5  9 13

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
void rotate90Degrees(int **array,int arraySize){
    int row, col, x, eachRow,tempVal1 = 0, tempVal2 = 0;
    int i=0,j=0;
    int y = 0;
    for(row = 0, col = 0; row < arraySize/2; row++, col++){
        x = arraySize - 1 - row - col;
        y = 0;
        for(eachRow = row; eachRow < arraySize - 1; eachRow++){
            i = eachRow + x, j = col + y;
            tempVal1 = array[i][j];
            array[i][j] = array[eachRow][col];
            i = i - y, j = j + x;
            tempVal2 = array[i][j];
            array[i][j] = tempVal1;
            i = i - x, j = j - y;
            tempVal1 = tempVal2;
            tempVal2 = array[i][j];
            array[i][j] = tempVal1;
            i = i + y, j = j - x;
            array[i][j] = tempVal2;
            x--;
            y++;
            if(x == 0)
                break;
            
            
        }
    }
    for(i = 0; i < arraySize; i++){
        for(j = 0; j < arraySize; j++){
            printf("%d, ",array[i][j]);
        }
        printf("\n");
    }
    return;
} 
int main()
{
    int b,i,j,N;
    scanf("%d",&b);
    for(int k = 0; k <= b; k++){
    scanf("%d",&N);
    int **arr = (int **) malloc( N * sizeof(int *) );
    for (i = 0; i < N; i++){
        arr[i] = (int *) malloc(N*sizeof(int));
    }
    for(i = 0; i < N; i++){
       for(j = 0; j < N; j++){
           scanf("%d", *(arr + i) + j);
       } 
    }
    rotate90Degrees(arr, N);
    }
    return 0;
}
