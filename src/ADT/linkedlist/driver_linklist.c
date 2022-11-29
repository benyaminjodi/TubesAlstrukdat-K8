#include "linkList.h"

int main() {
    List l;
    CreateEmptyList(&l);
    if (IsEmptyList(l)) {
        printf("List kosong\n");
    }
    int n;
    printf("Masukkan jumlah elemen yang ingin ditambahkan ke elemen: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        infotypeNode a;
        int x, y;
        printf("X elemen ke-%d: ", i+1);
        scanf("%d", &x);
        printf("Y elemen ke-%d: ", i+1);
        scanf("%d", &y);
        InsVLast(&l, x, y);
    }
    printf("Isi list: ");
    PrintForward(l);
    printf("\n");

    int xFirst, yFirst;
    printf("Tambahkan elemen pertama: ");
    scanf("%d %d", &xFirst, &yFirst);
    InsVFirst(&l, xFirst, yFirst);

    printf("Isi list: ");
    PrintForward(l);
    printf("\n");

    printf("Tes Search\n");
    int searchX, searchY;
    printf("Masukkan nilai X dan Y: ");
    scanf("%d %d", &searchX, &searchY);
    addressNode p = SearchList(l, searchX, searchY);
    if (p != NIL) {
        printf("<%d %d>\n", p->info.x, p->info.y);
    } else {
        printf("X dan Y tidak ditemukan\n");
    }

    printf("Tes Delete\n");
    int delX, delY;
    printf("Masukkan nilai X yang ingin dihapus: ");
    scanf("%d", &delX);
    printf("Masukkan nilai Y yang ingin dihapus: ");
    scanf("%d", &delY);
    addressNode Pdel = SearchList(l, delX, delY);
    if (Pdel != NIL) {
        addressNode Prec = Prev(Pdel);
        addressNode delNode;
        DelAfter(&l, &delNode, Prec);
    } else {
        printf("Nilai X dan Y tidak ada di list\n");
    }
    printf("Isi list: ");
    PrintForward(l);
    printf("\n");
    return 0;
}