#include <stdio.h>

typedef struct {
    int start;
    int finish;
} Activity;

int compare(const void *a, const void *b) {
    Activity *act1 = (Activity *)a;
    Activity *act2 = (Activity *)b;

    return act1->finish - act2->finish;
}

void activitySelection(Activity arr[], int n) {
    qsort(arr, n, sizeof(Activity), compare);

    int i = 0;
    printf("Following is maximum number of activities that can be done by a single person:\n");
    printf("%d ", arr[i].start);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("%d ", arr[j].start);
            i = j;
        }
    }
}

int main() {
    Activity arr[] = { {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9} };
    int n = sizeof(arr) / sizeof(arr[0]);

    activitySelection(arr, n);

    return 0;
}