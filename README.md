# A Chip8 Emulator
This is a chip8 emulator using SDL2 for graphics handling  
some programs are in the `roms/` directory  
You can find compilation of additional roms [here](https://github.com/kripod/chip8-roms)

---

To compile the program   
```
$ make
```
To run 
You can supply the display scale and frame delay when running use higher scale on hiDpi displays  
```
$ ./main <Scale> <Delay> <RomFile>
```  
Example
```
$ ./main 20 2 roms/test_opcode.ch8
```
---
Credits  
[Wikipedia](https://en.wikipedia.org/wiki/CHIP-8)
Amazing article by [Austin Morlan](https://austinmorlan.com) [Building a CHIP-8 Emulator](https://austinmorlan.com/posts/chip8_emulator/)
