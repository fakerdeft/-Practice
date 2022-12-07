#include <stdio.h>
#include <time.h>
#include "Score.h"

void Swap(Score* A, Score* B)
{
    Score Temp = *A;
    *A = *B;
    *B = Temp;
}


int Partition(Score DataSet[], int Left, int Right)
{
    int First = Left;
    double Pivot = DataSet[First].score;

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left].score <= Pivot && Left < Right)
            ++Left;

        while (DataSet[Right].score >= Pivot && Left <= Right)
            --Right;


        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}



void QuickSort(Score DataSet[], int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}

int main(void)
{
    ///int DataSet[] = { 5, 1, 6, 4, 8, 3, 7, 9, 2 };// {6, 4, 2, 3, 1, 5}; // {5, 1, 6, 4, 8, 3, 7, 9, 2}
    //int DataSet[] =  {6, 4, 2, 3, 1, 5}; 
    int Length = sizeof DataSet / sizeof DataSet[0];   // Length : 9
    int i = 0;

    clock_t startime, endtime;
    float resulttime = 0.0f;

    startime = clock();   // 시작 시간
    QuickSort(DataSet, 0, Length - 1); // 0
    endtime = clock();   // 끝나는 시간

    resulttime = (float)(endtime - startime) / CLOCKS_PER_SEC;

    for (i = 0; i < 100; i++)
    {
        printf("%d:number:%d, score:%.4lf\n", i, DataSet[i].number, DataSet[i].score);;
    }

    for (i = 29900; i < Length; i++)
    {
        printf("%d:number:%d, score:%.4lf\n", i, DataSet[i].number, DataSet[i].score);;
    }

    printf("3만개 소팅 시간: %lf\n", resulttime);

    printf("\n");

    return 0;
}