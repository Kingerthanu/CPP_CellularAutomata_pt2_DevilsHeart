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

  This C++ Program Works With GLSL And OpenGL In Order To Create A Window To Simulate A 2D-Hexagonal Representation Of Conways Game Of Life.

  This Program Uses A Single VAO, VBO, And EBO In Which Is Instantiated At Runtime Dynamically. This Will Hold All The Hexagons On Our Screen In Which Will Represent A Cell In Which Can Have A State Of Either Alive Or Dead.

  During Runtime We Will Run OUr Algorthm In Which Will Feed Into Each Hexagon A Integer In Which Will Represent Its Offset From The Initial Position In The VBO Where "It's" Vertexes Will Lie. This ALlows Each Cell To Have A Single Value In Which Will Allow It To Adjusts Itself (Color, Position, texture, etc.) This Is Also Because We Know Each Cell Will Be Equally Sided So Can "Hard-Code" To Check **n** Vertexes After The Initial One In The Buffer For Even Quicker Updating.

  The Hexagonal Cell Has A Reaction Function In Which Will Count The Amount Of Alive Adjacent Neighbors It Has By Checking Around It In The 2D-Cell Map. At Every Cycle Of The Main Loop, From The Bottom Row, From Left To Right We Will Tell Each Cell To "React" To Its Surroundings. This Will Proceed From The Lowest Row Of Hexagons All The Way Up To The Top, Starting At Each Row From The Left-Most Hexagon. This Is Very Important In The Update Routine As To Cutdown On Runtime As Well As Space Complexity (Also Because I Like Making Myself Suffer And Learning The Hard Way) I Updated Each Cell In-Place In The 2D-Cell Map. 

  Updating The Cells In-Place Means That Right After Executing Their React Function And Dying Or Becoming Alive The Cell Will Update Its State. This Isn't A Major Error And In Many Automatas I've Made It's Been There But Also Gives Some Depth To The Design As What This Bug/Feature Can Do Is Lets Say We Have A Drop Of Water Represented As One Of Our Hexagons:

  If This Water Was To Flow From Right -> Left, Represented By Turning Off One Hexagon In The 2D-CellMap And Turning On THe Hexagon To The Left Of It. 
  
  Because We Are Our 2D Array In Which We Are Indexing And Calling Each Reaction Of A Given Cell We Will Index from:
  
  0 -> ROW_SIZE

  Because Of This,

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/19b4d951-4221-416e-9f90-5f5470c25269" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/19b4d951-4221-416e-9f90-5f5470c25269" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/19b4d951-4221-416e-9f90-5f5470c25269" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/19b4d951-4221-416e-9f90-5f5470c25269" alt="Cornstarch <3" width="55" height="49">


----------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/5f277365-2a2c-4488-9d74-7e709dedc618" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/5f277365-2a2c-4488-9d74-7e709dedc618" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/5f277365-2a2c-4488-9d74-7e709dedc618" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/5f277365-2a2c-4488-9d74-7e709dedc618" alt="Cornstarch <3" width="55" height="49">


**Features:**

![devilsHeart-ezgif com-optimize](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/622c675a-811d-44e8-a83e-998abe13deae)

![devilsBloom-ezgif com-optimize (1)](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/16805969-3efd-4904-b78c-034b08c63f86)

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/02b3ee49-47b0-4440-a08c-86efec608e76" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/02b3ee49-47b0-4440-a08c-86efec608e76" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/02b3ee49-47b0-4440-a08c-86efec608e76" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_DevilsHeart/assets/76754592/02b3ee49-47b0-4440-a08c-86efec608e76" alt="Cornstarch <3" width="55" height="49">
