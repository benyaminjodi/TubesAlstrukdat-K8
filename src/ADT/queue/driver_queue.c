#include <stdio.h>
#include "queue.h"
#include "../../boolean.h"
#include <stdlib.h>

int main() {
    Queue Q;
    CreateQueue(&Q);
    if (isEmpty(Q)) {
        printf("Queue kosong\n");
    }
    int n;
    printf("Masukkan banyaknya elemen yang ingin dienqueue (< 10): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ElType val;
        scanf("%d", &val);
        enqueue(&Q, val);
        printf("\n");
    }
    printf("Panjang Queue saat ini: %d\n", length(Q));
    if (isFull(Q)) {
        printf("Queue sudah penuh\n");
    } else {
        printf("Queue belum penuh\n");
    }
    printf("\n");
    displayQueue(Q);
    return 0;
}