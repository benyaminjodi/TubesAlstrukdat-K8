#include "queueDD.h"
#include <stdio.h>

int main() {
    QueueDD test;
    CreateQueueDD(&test);
    if (isEmptyDD(test)) {
        printf("QueueDD kosong\n");
    }
    int n;
    printf("Masukkan banyaknya elemen yang ingin dienqueue (< 20): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ElTypeDD val;
        int id, durasi, ketahanan, harga;
        printf("Masukkan ID makanan ke-%d: ",i+1);
        scanf("%d", &id);
        printf("Masukkan durasi  masak makanan ke-%d: ",i+1);
        scanf("%d", &durasi);
        printf("Masukkan ketahanan makanan ke-%d: ",i+1);
        scanf("%d", &ketahanan);
        printf("Masukkan harga makanan ke-%d: ",i+1);
        scanf("%d", &harga);
        val.id = id;
        val.durasiMasak = durasi;
        val.ketahanan = ketahanan;
        val.harga = harga;
        enqueueDD(&test, val);
        printf("\n");
    }
    printf("Panjang QueueDD saat ini: %d\n", lengthDD(test));
    if (isFullDD(test)) {
        printf("QueueDD sudah penuh\n");
    } else {
        printf("QueueDD belum penuh\n");
    }
    printf("\n");
    for (int i = 0; i < lengthDD(test); i++) {
        ElTypeDD val = test.buffer[i];
        printf("ID makanan ke-%d: M%d\n",i+1, val.id);
        printf("Durasi  masak makanan ke-%d: %d\n",i+1, val.durasiMasak);
        printf("Ketahanan makanan ke-%d: %d\n",i+1, val.ketahanan);
        printf("Harga makanan ke-%d: %d\n",i+1, val.harga);
        printf("\n");
    }
    int m;
    printf("Masukkan banyaknya elemen yang ingin didequeue (< 20): ");
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
        ElTypeDD del;
        dequeueDD(&test, &del);
    }
    printf("\n");
    for (int i = 0; i < lengthDD(test); i++) {
        ElTypeDD val = test.buffer[i];
        printf("ID makanan ke-%d: M%d\n",i+1, val.id);
        printf("Durasi  masak makanan ke-%d: %d\n",i+1, val.durasiMasak);
        printf("Ketahanan makanan ke-%d: %d\n",i+1, val.ketahanan);
        printf("Harga makanan ke-%d: %d\n",i+1, val.harga);
        printf("\n");
    }
    return 0;
}