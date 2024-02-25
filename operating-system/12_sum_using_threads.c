#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_NUMBERS 100
struct ThreadArgs {
    int *numbers;
    int start;
    int end;
    long long sum;
};
void *calculateSum(void *arg) {
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    args->sum = 0;
    for (int i = args->start; i <= args->end; i++) {
        args->sum += args->numbers[i];
    }
    pthread_exit(NULL);
}
int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid input for n. Please enter a positive integer less than or equal to %d.\n", MAX_NUMBERS);
        return 1;
    }
    int numbers[MAX_NUMBERS];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    if (num_threads <= 0 || num_threads > n) {
        printf("Invalid input for the number of threads. Please enter a positive integer less than or equal to %d.\n", n);
        return 1;
    }
    pthread_t threads[num_threads];
    struct ThreadArgs args[num_threads];
    int elements_per_thread = n / num_threads;
    int remaining_elements = n % num_threads;
    int start = 0;
    for (int i = 0; i < num_threads; i++) {
        args[i].numbers = numbers;
        args[i].start = start;
        args[i].end = start + elements_per_thread - 1 + (remaining_elements > 0 ? 1 : 0);
        start = args[i].end + 1;
        remaining_elements--;
        pthread_create(&threads[i], NULL, calculateSum, (void *)&args[i]);
    }
    long long total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_sum += args[i].sum;
    }
    printf("Sum of %d numbers: %lld\n", n, total_sum);
    return 0;
}
