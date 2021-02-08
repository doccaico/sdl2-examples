### LifeGame
#### Build and Run
```
# terminal mode
# gcc -O2 -Wall -DTERMINAL_BUILD -o lifegame_terminal game.c main_sdl2.c -lSDL2
$ ./lifegame_terminal

# sdl2 mode
# gcc -O2 -Wall -DSDL2_BUILD -o lifegame_sdl2 game.c main_sdl2.c -lSDL2
$ ./lifegame_sdl2

# terminal mode (ninja)
$ ninja # or ninja lifegame_terminal
$ ./lifegame_terminal

# sdl2 mode (ninja)
$ ninja lifegame_sdl2
$ ./lifegame_sdl2
```

### lifegame\_terminal
![lifegame\_terminal](https://github.com/doccaico/sdl2-examples/blob/main/LifeGame/img/lifegame_terminal.png?raw=true)

### lifegame\_sdl2
![lifegame\_sdl2](https://github.com/doccaico/sdl2-examples/blob/main/LifeGame/img/lifegame_sdl2.png?raw=true)
