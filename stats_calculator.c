#include <stdio.h>
#include <stdlib.h>

void sort(int rides[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (rides[j] > rides[j+1]) {
                int temp = rides[j];
                rides[j] = rides[j+1];
                rides[j+1] = temp;
            }
}

float mean(int rides[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += rides[i];
    return (float)sum / n;
}

float median(int rides[], int n) {
    sort(rides, n);
    if (n % 2 == 0)
        return (rides[n/2 - 1] + rides[n/2]) / 2.0;
    else
        return rides[n/2];
}

void mode(int rides[], int n) {
    int max_count = 0;
    sort(rides, n);

    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i + 1 < n && rides[i] == rides[i + 1]) {
            count++;
            i++;
        }
        if (count > max_count)
            max_count = count;
    }

    printf("Mode(s): ");
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i + 1 < n && rides[i] == rides[i + 1]) {
            count++;
            i++;
        }
        if (count == max_count)
            printf("%d ", rides[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of drivers: ");
    scanf("%d", &n);

    int rides[n];
    for (int i = 0; i < n; i++) {
        printf("Enter rides completed by driver %d: ", i + 1);
        scanf("%d", &rides[i]);
    }

    printf("\nRide Sharing System Statistics\n");
    printf("Average rides per driver (Mean): %.2f\n", mean(rides, n));
    printf("Median rides per driver: %.2f\n", median(rides, n));
    mode(rides, n);

    return 0;
}
