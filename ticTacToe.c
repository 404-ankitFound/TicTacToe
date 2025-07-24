#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char gnd[4][4];
int i, j, r;
void print();
void input();
void compMove();
void check();
void check()
{
    int a, b;
    for (b = 1; b < 4; b++)
    {
        if (gnd[b][1] != '_' && gnd[b][1] == gnd[b][2] && gnd[b][2] == gnd[b][3])
        {
            print();
            if (gnd[b][1] == 'X')
            {
                printf("congrats you won!!!");
                exit(0);
            }
            else
            {
                printf("yeh!! comp won >_<");
                exit(0);
            }
        }
    }
    for (b = 1; b < 4; b++)
    {
        if (gnd[1][b] != '_' && gnd[1][b] == gnd[2][b] && gnd[2][b] == gnd[3][b])
        {
            print();
            if (gnd[1][b] == 'X')
            {
                printf("congrats you won!!!");
                exit(0);
            }
            else
            {
                printf("yeh!! comp won >_<");
                exit(0);
            }
        }
    }
    if (gnd[1][1] != '_' && gnd[1][1] == gnd[2][2] && gnd[2][2] == gnd[3][3])
    {
        print();
        if (gnd[1][1] == 'X')
        {
            printf("congrats you won!!!");
            exit(0);
        }
        else
        {
            printf("yeh!! comp won >_<");
            exit(0);
        }
    }
    if (gnd[3][1] != '_' && gnd[3][1] == gnd[2][2] && gnd[2][2] == gnd[1][3])
    {
        print();
        if (gnd[3][1] == 'X')
        {
            printf("congrats you won!!!");
            exit(0);
        }
        else
        {
            printf("yeh!! comp won >_<");
            exit(0);
        }
    }
}
void print()
{
    for (i = 1; i < 4; i++)
    {
        for (j = 1; j < 4; j++)
        {
            printf("%c    ", gnd[i][j]);
        }
        printf("\n\n");
    }
}
void input()
{
    int i, j, n;
    if (r == 8)
    {
        for (i = 1; i < 4; i++)
        {
            for (j = 1; j < 4; j++)
            {
                if (gnd[i][j] == '_')
                {
                    gnd[i][j] = 'X';
                    printf("you last entry was: %d,%d\n", i, j);
                    r++;
                    check();
                    print();
                    printf("match drawn!!");
                    exit(0);
                }
            }
        }
    }
    printf("enter the index of you entry: ");
    scanf("%d", &n);
    i = n / 10;
    j = n % 10;
    if (gnd[i][j] != '_')
    {
        printf("invalid move!!!\n");
        return;
    }
    r++;
    gnd[i][j] = 'X';
    if (r >= 5)
    {
        check();
    }
    if (r == 9)
    {
        print();
        printf("match drawn!!");
        return;
    }
    compMove();
    if (r >= 5)
    {
        check();
    }
    print();
    if (r == 9)
    {
        printf("match drawn!!");
        return;
    }
}
void compMove()
{
    r++;
    int a, b, f = 0;
    for (b = 1; b < 4; b++)
    {
        if (((gnd[b][1] == 'O' && gnd[b][2] == 'O') || (gnd[b][2] == 'O' && gnd[b][3] == 'O') || (gnd[b][1] == 'O' && gnd[b][3] == 'O')))
        {
            if (gnd[b][1] == '_')
            {
                gnd[b][1] = 'O';
                return;
            }
            else if (gnd[b][2] == '_')
            {
                gnd[b][2] = 'O';
                return;
            }
            else if (gnd[b][3] == '_')
            {
                gnd[b][3] = 'O';
                return;
            }
        }
    }
    for (b = 1; b < 4; b++)
    {
        if (((gnd[1][b] == 'O' && gnd[2][b] == 'O') || (gnd[2][b] == 'O' && gnd[3][b] == 'O') || (gnd[1][b] == 'O' && gnd[3][b] == 'O')))
        {
            if (gnd[1][b] == '_')
            {
                gnd[1][b] = 'O';
                return;
            }
            else if (gnd[2][b] == '_')
            {
                gnd[2][b] = 'O';
                return;
            }
            else if (gnd[3][b] == '_')
            {
                gnd[3][b] = 'O';
                return;
            }
        }
    }
    if (((gnd[1][1] == 'O' && gnd[2][2] == 'O') || (gnd[2][2] == 'O' && gnd[3][3] == 'O') || (gnd[1][1] == 'O' && gnd[3][3] == 'O')))
    {
        if (gnd[1][1] == '_')
        {
            gnd[1][1] = 'O';
            return;
        }
        else if (gnd[2][2] == '_')
        {
            gnd[2][2] = 'O';
            return;
        }
        else if (gnd[3][3] == '_')
        {
            gnd[3][3] = 'O';
            return;
        }
    }

    if (((gnd[1][3] == 'O' && gnd[2][2] == 'O') || (gnd[2][2] == 'O' && gnd[3][1] == 'O') || (gnd[1][3] == 'O' && gnd[3][1] == 'O')))
    {
        if (gnd[1][3] == '_')
        {
            gnd[1][3] = 'O';
            return;
        }
        else if (gnd[2][2] == '_')
        {
            gnd[2][2] = 'O';
            return;
        }
        else if (gnd[3][1] == '_')
        {
            gnd[3][1] = 'O';
            return;
        }
    }
    for (b = 1; b < 4; b++)
    {
        if (((gnd[b][1] == 'X' && gnd[b][2] == 'X') || (gnd[b][2] == 'X' && gnd[b][3] == 'X') || (gnd[b][1] == 'X' && gnd[b][3] == 'X')))
        {
            if (gnd[b][1] == '_')
            {
                gnd[b][1] = 'O';
                return;
            }
            else if (gnd[b][2] == '_')
            {
                gnd[b][2] = 'O';
                return;
            }
            else if (gnd[b][3] == '_')
            {
                gnd[b][3] = 'O';
                return;
            }
        }
    }
    for (b = 1; b < 4; b++)
    {
        if (((gnd[1][b] == 'X' && gnd[2][b] == 'X') || (gnd[2][b] == 'X' && gnd[3][b] == 'X') || (gnd[1][b] == 'X' && gnd[3][b] == 'X')))
        {
            if (gnd[1][b] == '_')
            {
                gnd[1][b] = 'O';
                return;
            }
            else if (gnd[2][b] == '_')
            {
                gnd[2][b] = 'O';
                return;
            }
            else if (gnd[3][b] == '_')
            {
                gnd[3][b] = 'O';
                return;
            }
        }
    }
    if (((gnd[1][1] == 'X' && gnd[2][2] == 'X') || (gnd[2][2] == 'X' && gnd[3][3] == 'X') || (gnd[1][1] == 'X' && gnd[3][3] == 'X')))
    {
        if (gnd[1][1] == '_')
        {
            gnd[1][1] = 'O';
            return;
        }
        else if (gnd[2][2] == '_')
        {
            gnd[2][2] = 'O';
            return;
        }
        else if (gnd[3][3] == '_')
        {
            gnd[3][3] = 'O';
            return;
        }
    }

    if (((gnd[1][3] == 'X' && gnd[2][2] == 'X') || (gnd[2][2] == 'X' && gnd[3][1] == 'X') || (gnd[1][3] == 'X' && gnd[3][1] == 'X')))
    {
        if (gnd[1][3] == '_')
        {
            gnd[1][3] = 'O';
            return;
        }
        else if (gnd[2][2] == '_')
        {
            gnd[2][2] = 'O';
            return;
        }
        else if (gnd[3][1] == '_')
        {
            gnd[3][1] = 'O';
            return;
        }
    }
    int k;
    while (2)
    {
        int i = 1 + rand() % (3);
        for (k = 0; k < 10; k++)
        {
            int j = 1 + rand() % (3);
            if (gnd[i][j] == '_')
            {
                gnd[i][j] = 'O';
                return;
            }
        }
    }
}

int main()
{
    srand(time(NULL)); // SEED THE RANDOM NUMBER
    int l, toss;
    for (i = 1; i < 4; i++)
    {
        for (j = 1; j < 4; j++)
        {
            gnd[i][j] = '_';
        }
    }
    printf("\n\nyou are 'X' and comp is 'O'\n");
    toss = rand() % 2;

    if (toss == 1)
    {
        printf("comp won the toss!!\n");
        compMove();
    }
    else
        printf("you won the toss!!\n");
    print();
    for (l = 0; l < 9; l++)
    {
        if (r == 9)
            break;
        input();
    }
    return 0;
}
