#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int T, N, M;
bool symptom_cnt[262144];
int patient_symp[50];
int control_symp[50];
int patient[50][18];
int control[50][18];
int min_symp;
bool foundIdentify;
int depth;

void dfs(int symp)
{
    bool _foundIdentify = true;
    ++depth;
    if (depth >= min_symp)
    {
        --depth;
        return;
    }
    // add index to patient_symp & control_symp
    for (int i = 0; i < N; ++i)
    {
        patient_symp[i] += patient[i][symp];
        symptom_cnt[patient_symp[i]] = true;
        control_symp[i] += control[i][symp];
    }
    for (int i = 0; i < N; ++i)
    {
        if (symptom_cnt[control_symp[i]])
        {
            _foundIdentify = false;
            break;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        symptom_cnt[patient_symp[i]] = false;
    }
    if (_foundIdentify)
    {
        foundIdentify = true;
        min_symp = depth;
    }
    for (int s = symp + 1; s < M; ++s)
    {
        dfs(s);
    }
    // subtract index to patient_symp & control_symp
    --depth;
    for (int i = 0; i < N; ++i)
    {
        patient_symp[i] -= patient[i][symp];
        control_symp[i] -= control[i][symp];
    }
}

int main()
{
    int tmp = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &N);
        scanf("%d", &M);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%d", &tmp);
                patient[i][j] = tmp << j;
            }
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%d", &tmp);
                control[i][j] = tmp << j;
            }
        }
        min_symp = INT_MAX;
        clock_t tStart = clock();
        for (int s = 0; s < M; ++s)
        {
            depth = 0;
            foundIdentify = false;
            memset(patient_symp, 0, 50 * sizeof(int));
            memset(control_symp, 0, 50 * sizeof(int));
            memset(symptom_cnt, false, 262144 * sizeof(bool));
            dfs(s);
            //printf("#%d %d\n", foundIdentify, min_symp);
        }
        printf("#%d %d\n", t, min_symp);
        printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    }
}