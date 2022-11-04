#include "diner-dash.h"

void displayData(int saldo, Queue Qpesanan, Queue Qmasak, Queue Qsaji) {
// I.S. saldo, Qpesanan, Qmasak, dan Qsaji terdefinisi. Qpesanan pasti sudah terisi. Qmasak dan Qsaji mungkin kosong
// F.S. Menampilkan nilai saldo, Qpesanan, Qmasak, dan Qsaji dalam bentuk tabel
  printf("\n");
  printf("SALDO: %d\n", saldo);
  printf("\n");
  printf("Daftar Pesanan\n");
  printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
  printf("--------------------------------------------\n");
  for (int i = IDX_HEAD(Qpesanan); i < length(Qpesanan); i++) {
    ElType currentPesanan;
    currentPesanan.id = Qpesanan.buffer[i].id;
    currentPesanan.durasiMasak = Qpesanan.buffer[i].durasiMasak;
    currentPesanan.ketahanan = Qpesanan.buffer[i].ketahanan;
    currentPesanan.harga = Qpesanan.buffer[i].harga;
    printf("M%d      | %d              | %d         | %d    \n", currentPesanan.id, currentPesanan.durasiMasak, currentPesanan.ketahanan, currentPesanan.harga);
  }
  printf("\n");
  printf("Daftar Makanan yang sedang dimasak\n");
  printf("Makanan | Sisa durasi memasak\n");
  printf("-----------------------------\n");
  if (!isEmpty(Qmasak)) {
    for (int i = IDX_HEAD(Qmasak); i < length(Qmasak); i++) {
      ElType currentMasak;
      currentMasak.id = Qmasak.buffer[i].id;
      currentMasak.durasiMasak = Qmasak.buffer[i].durasiMasak;
      printf("M%d      | %d\n", currentMasak.id, currentMasak.durasiMasak);
    }
  } else {
    printf("        |\n");
  }
  printf("\n");
  printf("Daftar Makanan yang dapat disajikan\n");
  printf("Makanan | Sisa ketahanan makanan\n");
  printf("--------------------------------\n");
  if (!isEmpty(Qsaji)) {
    for (int i = IDX_HEAD(Qsaji); i < length(Qsaji); i++) {
      ElType currentSaji;
      currentSaji.id = Qsaji.buffer[i].id;
      currentSaji.ketahanan = Qsaji.buffer[i].ketahanan;
      printf("M%d      | %d\n", currentSaji.id, currentSaji.ketahanan);
    }
  } else {
    printf("        |\n");
  }
  printf("\n");
  printf("\n");
}

int rng(int lower, int upper)
// Menghasilkan bilangan random antara [lower..upper]
{
  int r = (rand() % (upper - lower + 1)) + lower;
  return r;
}

void initPesanan(Queue *Qpesanan)
// I.S. Queue pesanan terdefinisi dan merupakan queue kosong
// F.S. Queue pesanan terisi 3 elemen yang bernilai random 
{
  for (int i = 0; i < 3; i++) {
    int durasi = rng(1, 5);
    int ketahanan = rng(1, 5);
    int harga = rng(10000, 50000);
    ElType test;
    test.id = i;
    test.durasiMasak = durasi;
    test.ketahanan = ketahanan;
    test.harga = harga;
    enqueue(Qpesanan, test);
  }
}

void copyElemen(int processID, Queue *Qin, Queue Qout) {
  // I.S. Qin, Qout, dan idx terdefinisi. Elemen dengan indeks idx terdapat pada Qout
  // F.S. Menyalin sebuah elemen queue berindeks idx ke queue lain (Qin) tanpa menghapus elemen dari Qout
  ElType temp;
  int idx = 0;
  while(Qout.buffer[idx].id != processID) {
    idx++;
  }
  temp.id = Qout.buffer[idx].id;
  temp.durasiMasak = Qout.buffer[idx].durasiMasak;
  temp.ketahanan = Qout.buffer[idx].ketahanan;
  temp.harga = Qout.buffer[idx].harga;
  enqueue(Qin, temp);
}

boolean isCook(char* command) {
  // Mengecek apakah masukan berupa 'cook', akan mengembalikan true jika iya
  if (*command == 'c' || *command == 'C') {
    if (*(command+1) == 'o' || *(command+1) == 'O') {
      if (*(command+2) == 'o' || *(command+2) == 'O') {
        if (*(command+3) == 'k' || *(command+3) == 'K') {
          if (*(command+4) == '\0' || *(command+4) == '\0') {
            return true;
          }
        }
      }
    }
  }
  return false;
}

boolean isServe(char* command) {
  // Mengecek apakah masukan berupa 'serve', akan mengembalikan true jika iya
  if (*command == 's' || *command == 'S') {
    if (*(command+1) == 'e' || *(command+1) == 'E') {
      if (*(command+2) == 'r' || *(command+2) == 'R') {
        if (*(command+3) == 'v' || *(command+3) == 'V') {
          if (*(command+4) == 'e' || *(command+4) == 'E') {
            if (*(command+5) == '\0' || *(command+5) == '\0') {
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

void sortDurasi(Queue *Qin) {
  // I.S. Qin terdefinisi, mungkin terurut
  // F.S. Qin terurut membesar berdasarkan durasi memasak
  if (!isEmpty(*Qin)) {
    ElType temp;
    for(int i = 0; i < length(*Qin)-1; i++) {
      for(int j = 0; j < length(*Qin)-i-1; j++) {
        if((*Qin).buffer[j].durasiMasak > (*Qin).buffer[j+1].durasiMasak) {
          temp = (*Qin).buffer[j];
          (*Qin).buffer[j] = (*Qin).buffer[j+1];
          (*Qin).buffer[j+1] = temp;
        }
      }
    }
  }
}

void sortID(Queue *Qin) {
  // I.S. Qin terdefinisi, mungkin terurut
  // F.S. Qin terurut membesar berdasarkan id
  if (!isEmpty(*Qin)) {
    ElType temp;
    for(int i = 0; i < length(*Qin)-1; i++) {
      for(int j = 0; j < length(*Qin)-i-1; j++) {
        if((*Qin).buffer[j].id > (*Qin).buffer[j+1].id) {
          temp = (*Qin).buffer[j];
          (*Qin).buffer[j] = (*Qin).buffer[j+1];
          (*Qin).buffer[j+1] = temp;
        }
      }
    }
  }
}

void sortKetahanan(Queue *Qin) {
  // I.S. Qin terdefinisi, mungkin terurut
  // F.S. Qin terurut membesar berdasarkan id
  ElType temp;
  for(int i = 0; i < length(*Qin)-1; i++) {
    for(int j = 0; j < length(*Qin)-i-1; j++) {
      if((*Qin).buffer[j].ketahanan > (*Qin).buffer[j+1].ketahanan) {
        temp = (*Qin).buffer[j];
        (*Qin).buffer[j] = (*Qin).buffer[j+1];
        (*Qin).buffer[j+1] = temp;
      }
    }
  }
}

boolean isMemberID(Queue Qcek, int processID) {
// Mengecek apakah sebuah ID makanan terdapat pada suatu queue. Jika ada, akan mengembalikan true
  int i = 0;
  boolean found = false;
  while (i < length(Qcek) && !found) {
    if (Qcek.buffer[i].id == processID) {
      found = true;
    } else {
      i++;
    }
  }
  return found;
}

void displayStatusCook(int processID, Queue Qpesanan, Queue *Qmasak, Queue Qsaji) {
// I.S. processID, Qpesanan, Qmasak, dan Qsaji terdefinisi. Qpesanan tidak mungkin kosong
// F.S. Memproses command jika panjang Qmasak tidak lebih dari 5. Jika memenuhi, maka akan menyalin elemen dengan processID dari Qpesanan ke Qmasak
  if (length(*Qmasak) <= 5) {
    copyElemen(processID, Qmasak, Qpesanan); 
    printf("Berhasil memasak M%d\n", processID);
  } else {
    printf("Jumlah makanan yang dimasak tidak boleh melebihi 5\n");
  }
}

void displayStatusServe(int processID, int *saldo, int *countTerlayani, Queue *Qpesanan, Queue *Qsaji, Queue *Qmasak) {
// I.S. processID, saldo, countTerlayani, Qpesanan, dan Qsaji terdefinisi. Qpesaanan tidak mungkin kosong
// F.S. Makanan pada Qsaji dan Qpesanan didequeue
// Proses:  menghilangkan pesanan dari Qpesanan dan Qsaji, menambahkan saldo sesuai harga pesanan, dan menambah jumlah pelanggan terlayani 
  sortID(Qsaji);
  ElType temp1, temp2;
  dequeue(Qpesanan, &temp1);
  dequeue(Qsaji, &temp2);
  (*saldo) += temp1.harga;
  (*countTerlayani)++;
}

void newRound(Queue *Qmasak, Queue *Qsaji) {
// I.S. Qmasak dan Qsaji terdefinisi. 
// F.S. Mengurangi durasi dari setiap elemen pada Qmasak dan mengurangi ketahanan pada setiap elemen pada Qsaji
  // Mengurangi durasi
  for(int i = 0; i < length(*Qmasak); i++) {
    (*Qmasak).buffer[i].durasiMasak--;
  }
   // Mengurangi ketahanan
  for(int i = 0; i < length(*Qsaji); i++) {
    (*Qsaji).buffer[i].ketahanan--;
  }
}

void pindahElemenQmasak(Queue *Qmasak, Queue *Qsaji) {
// I.S. Qmasak dan Qsaji terdefinisi 
// F.S. Elemen pada Qmasak tidak ada yang berdurasi 0
// Proses: mengurut Qmasak berdasarkan durasi sehingga lebih mudah untuk didequeue
  sortDurasi(Qmasak);
  while ((*Qmasak).buffer[0].durasiMasak == 0 && !isEmpty(*Qmasak)) {
    ElType temp;
    dequeue(Qmasak, &temp);
    enqueue(Qsaji, temp);
  }
}

void pindahElemenQsaji(Queue *Qsaji, Queue *Qpesanan) {
// I.S. Qsaji dan Qpesanan terdefinisi 
// F.S. Elemen pada Qsaji tidak ada yang memiliki ketahanan 0
  sortKetahanan(Qsaji);
  while ((*Qsaji).buffer[0].ketahanan == 0 && !isEmpty(*Qsaji)) {
    ElType temp;
    dequeue(Qsaji, &temp); 
  }
}

boolean validasiCommand(char *command, int processID, Queue Qpesanan, Queue Qmasak, Queue Qsaji) {
// Mengecek apakah command yang dimasukkan valid atau tidak. Jika valid, akan menghasilkan nilai true
  boolean isValid = false;
 
  if (isCook(command)) {
    if (isMemberID(Qpesanan, processID)) {
      isValid = true;
    } else {
      if (isMemberID(Qsaji, processID)) {
        printf("M%d sudah selesai dimasak dan bisa disajikan\n", processID);
      } else {
        printf("M%d tidak ada dalam daftar pesanan\n", processID);
      }
    }
  } else if (isServe(command)) {
    if (isMemberID(Qsaji, processID)) {
      if (processID == HEAD_ID(Qpesanan)) {
        printf("Berhasil mengantar M%d\n", processID);
        isValid = true;
      } else {
        printf("M%d belum dapat disajikan karena M%d belum selesai dimasak\n", processID, processID-1);
      }
    } else {
      if (isMemberID(Qmasak, processID)) {
        printf("M%d sedang dimasak\n", processID);
      } else if (isMemberID(Qpesanan, processID)) {
        printf("M%d belum mulai dimasak\n", processID);
      } else {
        printf("M%d tidak ada dalam daftar pesanan\n", processID);
      }
    }
  } else {
    printf("Anda melakukan typo. Silahkan ulangi lagi\n");
  }
  return isValid;
}

void addPesanan(Queue *Qpesanan, int *IDpesanan) {
// I.S. Qpesanan dan IDPesanan terdefinisi
// F.S. Menambahkan elemen ke Qpesanan 
  ElType inpt;
  (*IDpesanan)++;
  inpt.id = *IDpesanan;
  inpt.durasiMasak = rng(1, 5);
  inpt.ketahanan = rng(1, 5);
  inpt.harga = rng(10000, 50000);
  enqueue(Qpesanan, inpt);
}

int main() {
  printf("Selamat Datang di Diner Dash!\n");
  int saldo = 0;
  Queue Qpesanan, Qmasak, Qsaji;
  CreateQueue(&Qpesanan);
  CreateQueue(&Qmasak);
  CreateQueue(&Qsaji);

  // INISIALISASI QUEUE PESANAN
  srand(time(NULL));
  initPesanan(&Qpesanan);
  int IDpesanan = 2;

  // DISPLAY DATA PERTAMA KALI
  displayData(saldo, Qpesanan, Qmasak, Qsaji);

  int countTerlayani = 0;
  while (length(Qpesanan) <= 7 && countTerlayani <= 15) {
    // Menerima command
    char *command;
    command = (char *) malloc (6 * sizeof(char));
    char *commandID;
    commandID = (char *) malloc (4 * sizeof(char));
    printf("MASUKKAN COMMAND: ");
    scanf("%s", command);
    scanf("%s", commandID);

    // Validasi command
    commandID++;
    int processID = *commandID - '0';
    commandID++;
    if (*commandID != '\0') {
      int x = *commandID - '0';
      processID = processID*10 + x;
    }
    
    while(!validasiCommand(command, processID, Qpesanan, Qmasak, Qsaji)){
      printf("MASUKKAN COMMAND: ");
      scanf("%s", command);
      scanf("%s", commandID);
    }

    // Memproses command
    if (isCook(command)) {
      displayStatusCook(processID, Qpesanan, &Qmasak, Qsaji);
    } else if (isServe(command)) {
      displayStatusServe(processID, &saldo, &countTerlayani, &Qpesanan, &Qsaji, &Qmasak);
    }
   
    for(int i = IDX_HEAD(Qmasak); i < length(Qmasak); i++) { 
      if((Qmasak).buffer[i].durasiMasak == 0) {
        printf("Makanan M%d telah selesai dimasak\n", (Qmasak).buffer[i].id);
      }
    }
    printf("====================================================\n");

    addPesanan(&Qpesanan, &IDpesanan);
    pindahElemenQmasak(&Qmasak, &Qsaji);
    pindahElemenQsaji(&Qsaji, &Qpesanan);
    if (!isEmpty(Qsaji)) {
      sortID(&Qsaji);
      while(HEAD_ID(Qsaji) < HEAD_ID(Qpesanan)) {
        ElType temp;
        dequeue(&Qsaji, &temp);
      }
    }
    displayData(saldo, Qpesanan, Qmasak, Qsaji);
    newRound(&Qmasak, &Qsaji);
  }
  printf("GAME OVER\n");
  printf("Skor Anda: %d\n", saldo);
  return 0;
}