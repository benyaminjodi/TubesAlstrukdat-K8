main :
	gcc src/main.c src/console.c src/ADT/arraydinamis/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/queue/queue.c src/ADT/queue/queueDD.c src/diner-dash.c src/tictactoe.c -o main
clear :
	rm main
