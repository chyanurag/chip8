# A Chip8 Emulator
This is a chip8 emulator using SDL2 for graphics handling  
ROM files are in the `roms/` directory  
You can find additional roms [here](https://github.com/kripod/chip8-roms)

---

To compile the program  
```$ make```
To run  
You can supply the display scale and frame delay when running
```$ ./main <Scale> <Delay> <RomFile>```  
Example
```$ ./main 20 2 roms/test_opcode.ch8```
