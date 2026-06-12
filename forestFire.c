#include <stdio.h>
#include <math.h>
void input(float temp[][10], int sector, int tCount)
{
    for (int i = 0; i < sector; i++)
    {
        printf("Enter Temperatures for SECTOR %d: \n", i + 1);
        for (int j = 0; j < tCount; j++)
        {
            printf("Day %d: ", j + 1);
            scanf("%f", &temp[i][j]);
        }
    }
}
void showTable(float temp[][10], int sector, int tCount)
{
    printf("|         | Day 1 | Day 2 | Day 3 | Day 4| Day 5 | Day 6 | Day 7 | Day 8 | Day 9 | Day 10 |\n");
    for (int i = 0; i < sector; i++)
    {
        printf("|Sector %d |", i + 1);
        for (int j = 0; j < tCount; j++)
        {
            printf(" %.2f     |", temp[i][j]);
        }
        printf("\n");
    }
}
void dangerous(float temp[][10], int sector, int tCount)
{
    for (int i = 0; i < sector; i++)
    {
        float sum = 0, avg = 0;
        for (int j = 0; j < tCount; j++)
        {
            sum += temp[i][j];
        }
        avg = sum / tCount;
        if (avg > 40)
        {
            printf("Sector %d is a dangerous sector.\n", i + 1);
        }
    }
}
void spikes(float temp[][10], int sector, int tCount)
{
    for (int i = 0; i < sector; i++)
    {
        for (int j = 0; j < tCount - 1; j++)
        {
            float diff;
            diff = fabs(temp[i][j + 1] - temp[i][j]);
            if (diff >= 8)
            {
                printf("Sudden temperature spike detected in sector %d in Day %d and Day %d.\n", i + 1, j + 1, j + 2);
            }
        }
    }
}
void alert(float temp[][10], int sector, int tCount)
{
    for (int i = 0; i < sector; i++)
    {
        for (int j = 0; j < tCount; j++)
        {
            if (temp[i][j] > 45)
            {
                printf("Critical Fire Alert in Sector %d in Day %d\n", i + 1, j + 1);
            }
        }
    }
}
void avg(float temp[][10], int sector, int tCount)
{
    for (int i = 0; i < sector; i++)
    {
        float sum = 0, avg = 0;
        for (int j = 0; j < tCount; j++)
        {
            sum += temp[i][j];
        }
        avg = sum / tCount;
        if (avg < 30)
        {
            printf("Sector %d is SAFE.\n", i + 1);
        }
        else if (avg <= 40)
        {
            printf("Sector %d is WARNING.\n", i + 1);
        }
        else
        {
            printf("Sector %d is CRITICAL.\n", i + 1);
        }
    }
}
void separator()
{
    printf("________________________________________________\n");
}

int main()
{
    int sector = 5, tCount = 10;
    float temperature[5][10] = {0};
    int choice;
    int dataEntered = 0;

    do
    {
        printf("\n===== MENU ===== \n");
        printf("1.Enter Temperature Data\n");
        printf("2.Show Temperature Table\n");
        printf("3.Dangerous Sectors\n");
        printf("4.Temperature Spikes\n");
        printf("5.Find Each Sector Safe Criteria\n");
        printf("6.Critical Fire Alerts\n");
        printf("7.Return to Main Menu\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input(temperature, sector, tCount);
            dataEntered = 1;
            break;
        case 2:
            if (dataEntered)
            {
                showTable(temperature, sector, tCount);
                separator();
            }
            else
                printf("Enter Temperature Data First\n");

            break;
        case 3:
            if (dataEntered)
            {
                dangerous(temperature, sector, tCount);
                separator();
            }
            else
                printf("Enter Temperature Data First\n");

            break;
        case 4:
            if (dataEntered)
            {
                spikes(temperature, sector, tCount);
                separator();
            }

            else
                printf("Enter Temperature Data First\n");

            break;
        case 5:
            if (dataEntered)
            {
                avg(temperature, sector, tCount);
                separator();
            }

            else
                printf("Enter Temperature Data First\n");

            break;
        case 6:
            if (dataEntered)
            {
                alert(temperature, sector, tCount);
                separator();
            }
            else
                printf("Enter Temperature Data First\n");
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice Try Again.\n");
            break;
        }
    } while (choice != 7);
}