main :
	gcc src/main.c src/console.c src/ADT/arraydinamis/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/stack/stack.c src/ADT/queue/queue.c src/ADT/queue/queueDD.c src/ADT/map/map.c src/ADT/arrayofmap/arrayofmap.c src/ADT/linkedlist/linkList.c src/snakeOnMeteor.c src/diner-dash.c src/tictactoe.c src/hangman.c -o main
clear :
	rm main
