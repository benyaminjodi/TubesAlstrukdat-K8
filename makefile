main :
	gcc src/main.c src/console.c src/ADT/arraydinamis/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/stack/stack.c src/ADT/queue/queue.c src/ADT/queue/queueDD.c src/ADT/map/map.c src/ADT/arrayofmap/arrayofmap.c src/ADT/linkedlist/linkList.c src/game/snakeOnMeteor.c src/game/diner-dash.c src/game/tictactoe.c src/game/hangman.c src/game/chooseyouradv.c src/game/hanoi.c -o main
clear :
	rm main
