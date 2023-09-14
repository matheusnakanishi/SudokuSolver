#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSudoku(int mat[9][9])
{
    printf("\n\t\t\t\t\t%c",201);

    for (int i = 0; i < 33; i++)
    {
        if (i == 11 || i == 22)
            printf("%c",203);
        printf("%c",205);
    }
    printf("%c\n",187);
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
                printf("\t\t\t\t\t%c",186);
            
            printf(" %d ",mat[i][j]);

            if (j == 2 || j == 5 || j == 8)
                printf("%c",186);
            else
                printf("%c",179);
        }
        if (i!= 8){
            if (i != 2 && i != 5){
                for (int k = 0; k < 36; k++)
                {
                    if (k == 0)
                        printf("\n\t\t\t\t\t%c",186);
                    else if (k == 12 || k == 24)
                        printf("%c",186);
                    else if (k % 4 == 0)
                        printf("%c",197);
                    else
                        printf("%c",196);
                }
                printf("%c\n",186);
            }
            else{
                printf("\n\t\t\t\t\t%c",204);
                for (int k = 0; k < 35; k++){
                    if (k == 11 || k == 23)
                    {
                        printf("%c",206);
                    }
                    else{
                        printf("%c",205);
                    }
                }
                printf("%c\n",185);
            }
        }    
    }
    printf("\n\t\t\t\t\t%c",200);
    for (int i = 0; i < 33; i++)
    {
        if (i == 11 || i == 22)
            printf("%c",202);
        printf("%c",205);
    }
    printf("%c\n\n\n",188);
}

//adicionar funções de verificar linha, coluna e quadrante


bool validPosition(int mat[9][9], int x, int y, int num) //Chama as funções de linha, coluna e quadrante
{
    return scan_row(mat,x,num) && scan_column(mat,y,num) && scan_square(mat,x,y,num);
}

bool findEmptyPosition(int mat[9][9], int *row, int *column) //Procura posição vazia na matriz caso houver
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*column = 0; *column < 9; (*column)++)
        {
            if (mat[*row][*column] == 0)
                return true;
        }
    }

    return false;
}

bool sudokuSolver(int mat[9][9])
{
    int row, column;

    if (!find_empty_position(mat,&row,&column))
        return true; //Todas posições completadas

    for (int num = 1; num <= 9; num++)
    {
        if (valid_position(mat,row,column,num))
        {
            mat[row][column] = num;

            if (sudoku_solver(mat)) //Recursão
                return true;

            mat[row][column] = 0;
        }
    }

    return false;
}

int main()
{
    //Matriz exemplo
     int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    print_sudoku(mat);



    return 0;
}