#include "chip.h"
#include "platform.h"
#include <chrono>
#include <iostream>


int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
		std::exit(EXIT_FAILURE);
	}
	int videoScale = std::stoi(argv[1]);
	int cycleDelay = std::stoi(argv[2]);
	char const* romFilename = argv[3];
	Platform platform("CHIP-8 Emulator", VIDEO_WIDTH * videoScale, VIDEO_HEIGHT * videoScale, VIDEO_WIDTH, VIDEO_HEIGHT);
	Chip chip;
	chip.LoadROM(romFilename);
	int videoPitch = sizeof(chip.video[0]) * VIDEO_WIDTH;
	auto lastCycleTime = std::chrono::high_resolution_clock::now();
	bool quit = false;
	while (!quit) {
		quit = platform.ProcessInput(chip.keypad);
		auto currentTime = std::chrono::high_resolution_clock::now();
		float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();
		if (dt > cycleDelay)
		{
			lastCycleTime = currentTime;
			chip.Cycle();
			platform.Update(chip.video, videoPitch);
		}
	}
	return 0;
}
