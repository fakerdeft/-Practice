#include <stdio.h> 
#include <string.h> 
#include <time.h>
#include "Score.h"
 
void InsertionSort(Score DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    Score value = { 0, 0.0 };

    for (i = 1; i < Length; i++)
    {
        if (DataSet[i - 1].score <= DataSet[i].score)
            continue;

        value = DataSet[i];

        for (j = 0; j < i; j++)
        {
            if (DataSet[j].score > value.score)
            {
                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
                DataSet[j] = value;
                break;
            }
        }
    }
}

int main(void)
{
    //int DataSet[] = { 6, 4, 2, 3, 1, 5 };
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    clock_t starttime, endtime;
    float resulttime = 0.0f;

    starttime = clock();
    InsertionSort(DataSet, Length);
    endtime = clock();
    resulttime = (float)(endtime - starttime) / CLOCKS_PER_SEC;

    for (i = 0; i < 100; i++)
    {
        printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
    }
    printf("------------------------------------\n");
    for (i = 29900; i < Length; i++)
    {
        printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
    }

    printf("3만개 소팅 시간: %lf\n", resulttime);
    printf("\n");

    return 0;
}
