# CPP_CellularAutomata_pt2_DevilsHeart
A C++ OpenGL Renderer Of A Hexagonal Cellular Automata Using Sine And Probability To Give Dynamic Analog Growth.
Again, another file dump of a cellular automata. This one was very trippy and cool and seeemed to give real dynamic, unique scenes each time. I had some rand() in the sine function, but decided to remove it for this dump because it got a little messy.
In this prog from the lasts I tried cleaning up the pipeline a little more and removing some redunant parts I added for implementation speed more than stability. I got runtime working much better with a seperation from .think() also calling the update and instead seperated it so I didn't have to pass a address through think to get to .turnOn().

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/25ba0fbb-037c-442b-b4f0-01f89125207e" alt="Cornstarch <3" width="95" height="99">


I am planning on adding multiple threads ontop of this as I could get some better runtime benefits now that I can pass the address of the buffer into the threads to allow quick color updates to many cells per tick instead of having the main thread doing all this work. I also wish to clean up the edges of the graph as I currently have 2 hexagon padding on each end which could be optimized as is working as wasteful checks on a static state.
The visual breathing of the colors has to do with a loop for the color in which checks if it exceeds a max value of 1.0f in the red channel and if so will reset our color back to 0. Because each cell is birthed in a given "Wave" of reproduction in the population some sections will share the same colors so will breathe in relation to these siblings. (also note the .gif format is chud and had to remove some frames so is a little choppy looking)


----------------------------------------------
<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/091d6125-d1ed-4f6a-b06a-794447a01e28" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/091d6125-d1ed-4f6a-b06a-794447a01e28" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/091d6125-d1ed-4f6a-b06a-794447a01e28" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/091d6125-d1ed-4f6a-b06a-794447a01e28" alt="Cornstarch <3" width="55" height="49">


**The Breakdown:**


----------------------------------------------

**Features:**

![devilsHeart-ezgif com-optimize](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/622c675a-811d-44e8-a83e-998abe13deae)

![devilsBloom-ezgif com-optimize (1)](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/16805969-3efd-4904-b78c-034b08c63f86)
