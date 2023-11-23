Ores - Tech Task by Miguel Brito

Approach

I prioritized tasks and features that focus on my technical skills for a better evalution over making the game look more interesting.
Therefore, this were my main tasks in order of execution:

1. Game Engine module

I implemented a graphics engine that abstracted the usage of the SDL to the remaining modules, adding the bare minimum functionalities needed to display and interact with the game. This required configure and load the SDL libraries, draw rectangles and text, handle clicking game objects and create complex game objects by combining multiple game objects.

2. Game logic modules

I implemented the game logic usign a MVC similar approach. The Data module has the current state of the game. The Services modules offers methods that implement the game's rules and modify the Data layer. The presentation layer has classes that extend the Game Engine Game Objects to display the game state to the player and handle their inputs, which calls the services methods.
To update the presentation layer, I followed the Observer pattern. The Observers module has the skeleton that each observer class must implement, while data and services offer attach and dettach methods. Presentation objects then implement this observers skeleton and attach themselves to data or services.

3. Animations

After obtaining a MVP of the game implementation, I implemented animations into the project as I thought it would be the most interesting feature in a technical point of view.

Further Development

Obviously it's very hard to make a complete ready to ship game in two weeks. Here are my considerations from what could have been done if I had more time (or budget)

1. Threads

I didn't dwell into threads as it's something I'm not confortable enough to tackle in a two week project. However, it would be a good practice to have a draw thread and add a timer functionality independent of the Game Engine module. Itches me a bit that a Game Object controls when a new column appears.

2. Images and Sounds

I'm not completely unhappy with the very retro style of the game, but images and sound could help a lot to add flair to the game. The main reason why I prefer other features were because Image and Sound loading would be implemented in the same way I implemented the load of Fonts, so it woulndn't add much technically speaking.

3. Balancing

The final version of the game turned very hard to be playing after half a minute and there's not real motivation for replaying it. That means that the game is not properly balanced or some interesting features are missing, like the levels and score presented in the example video.

4. Code improvements

Although I'm confortable programming in C++, I'm used to program in C# and I'm not aware of all the specifics of the C++ language and due to time constraints I didn't explore too much. Examples of things that I know could improve the code are the usage of smart pointers and find a way to update the presentation module without the observer implementation. My initial idea was to have a notification service, but I dropped once I noticed that template methods can't be virtual.

Conclusion

I think overall, this tasks shows that I have good architectural and organization skills and I try to use my skills to focus of performance and writing clean code. It also shows that I'm confortable programming in c++, but I still have much to learn about this complex language.