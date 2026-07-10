#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <setjmp.h>
jmp_buf jumpBuffer;
int match = 0, computer = 0, you = 0;
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
                you += 1;
                longjmp(jumpBuffer, 1);
                exit(0);
            }
            else
            {
                printf("yeh!! comp won >_<");
                computer += 1;
                longjmp(jumpBuffer, 1);
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
                you += 1;
                longjmp(jumpBuffer, 1);
                exit(0);
            }
            else
            {
                printf("yeh!! comp won >_<");
                computer += 1;
                longjmp(jumpBuffer, 1);
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
            you++;
            longjmp(jumpBuffer, 1);
            exit(0);
        }
        else
        {
            printf("yeh!! comp won >_<");
            computer++;
            longjmp(jumpBuffer, 1);
            exit(0);
        }
    }
    if (gnd[3][1] != '_' && gnd[3][1] == gnd[2][2] && gnd[2][2] == gnd[1][3])
    {
        print();
        if (gnd[3][1] == 'X')
        {
            printf("congrats you won!!!");
            you++;
            longjmp(jumpBuffer, 1);
            exit(0);
        }
        else
        {
            printf("yeh!! comp won >_<");
            computer++;
            longjmp(jumpBuffer, 1);
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
                    longjmp(jumpBuffer, 1);
                    exit(0);
                }
            }
        }
    }
    printf("enter the index of your move: ");
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
        longjmp(jumpBuffer, 1);
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
        longjmp(jumpBuffer, 1);
        return;
    }
}
void compMove()
{
    printf("Thinking a move!!\n");
    sleep(3);
    r++;

    int a, b;
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
    if (gnd[2][2] == '_' && r >= 2)
    {
        gnd[2][2] = 'O';
        return;
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

int l, toss, series;
int main()
{
    if (match == 0)
    {
        srand(time(NULL)); // SEED THE RANDOM NUMBER
        printf("enter no of matches in series: ");
        scanf("%d", &series);
        printf("\n\nyou are 'X' and comp is 'O'\ninput ex- 32 for 3rd row 2nd column\n");
    }
    if (setjmp(jumpBuffer) != 0 && match < series)
    {
        printf("\n\n\ncurrent status: (%d-%d)\n",you,computer);
        printf("starting match (%d/%d): \nloading board!!!\n",match+1,series);
        sleep(3);
    }

    if (match < series)
    {

        r = 0;
        match++;
        for (i = 1; i < 4; i++)
        {
            for (j = 1; j < 4; j++)
            {
                gnd[i][j] = '_';
            }
        }

        toss = rand() % 2;

        if (toss == 1)
        {
            printf("comp won the toss!!\n\n\n");
            compMove();
        }
        else
            printf("you won the toss!!\n\n\n");
        print();
        for (l = 0; l < 9; l++)
        {
            if (r == 9)
                break;
            input();
        }
    }
    else
    {
        if (computer < you)
            printf("\n\ngreat mind you won the series by (%d-%d)\n\n", you, computer);
        else if (you < computer)
            printf("\n\nyou lost series by computer by (%d-%d)\n\n", you, computer);
        else
            printf("\n\nseries drawn by (%d-%d)\n\n", you, you);

        // printf("\nholia kaam\n");
    }
    return 0;
}
