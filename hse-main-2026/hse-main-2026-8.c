#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int FIXED_LEN = 100;

int *calculate_pref(const char *str);
void heapify_in_place(int *arr, int n);
void sift_down(int *arr, int n, int i);

/*----------------------------------------------------------------------------*/

int main(void)
{
    char *str = (char *)malloc(sizeof(char) * FIXED_LEN);
    scanf("%s", str); int len = strlen(str); str[len] = '\0';
    int  *heap = (int *)malloc(sizeof(int) * len);
    int *pref = calculate_pref(str);
    for (int i = 0; i < len; ++i) heap[i] = pref[i];
    heapify_in_place(heap, len); for (int i = 0; i < len; ++i) printf("%d", heap[i]);
    printf("\n"); free(str); free(pref); return 0;
}

/*----------------------------------------------------------------------------*/

void sift_down(int *arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        sift_down(arr, n, smallest);
    }
}

void heapify_in_place(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        sift_down(arr, n, i);
    }
}


int *calculate_pref(const char *str)
{
    size_t n = strlen(str);
    int *pref = (int *)malloc(sizeof(int) * n);

    pref[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pref[i - 1];
        while (str[i] != str[j] && j > 0)
        {
            j = pref[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        pref[i] = j;
    }
    return pref;
}
