#include <stdio.h>
#include <time.h>
#include "Score.h"

void BubbleSort(Score DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    Score temp = { 0, 0 };

    int IsChange = 0;

    for (i = 0; i < Length - 1; i++)
    {
        IsChange = 0;

        for (j = 0; j < Length - (i + 1); j++)
        {

            if (DataSet[j].score > DataSet[j + 1].score)
            {
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;

                IsChange = 1;
            }
        }

        if (!IsChange) break;
    }
}

int main(void)
{
    //int DataSet[] = {6, 4, 2, 3, 1, 5}; 
    //int DataSet[] = { 5, 2, 3, 4, 6, 1 };

    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    clock_t starttime, endtime;
    float resulttime = 0.0f;

    starttime = clock();
    BubbleSort(DataSet, Length);
    endtime = clock();
    resulttime = (float)(endtime - starttime) / CLOCKS_PER_SEC;


    for (i = 0; i < 100; i++)
    {
        printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
    }
    printf("---------------------------------------------");

    for (i = 29900; i < Length; i++)
    {
        printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
    }

    printf("3만개 소팅 시간: %lf\n", resulttime);
    printf("\n");

    return 0;
}