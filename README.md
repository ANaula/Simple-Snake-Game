# Simple Snake Game

A simple game which involves the player controlling the head of a "snake" and trying to come into contact with a ball to score points. The player must avoid the window edges or else the game will end. The player controls the head using the w-a-s-d keys and once the player starts moving the head, the head will not stop moving and will go in the last direction the player inputted. Once the game ends a screen will appear showing their total points.

## How it works
The game uses the SFML library (which could be downloaded here- https://www.sfml-dev.org/download/sfml/2.5.1/) for the window creation and the multimedia components. Apart from that, the game is controlled by 4 classes which each controlling a different aspect of the program. The game class controls the window and the updating and rendering of the game as well as when the game ends. It also does some of the in-game calculations such as the tail movement and growth. The player class controls the user-controlled snake head and defines functions that allow the head to be moved and prevents the head from exiting the view of the window. The tail class controls the “body” of the snake and defines the body’s color and size. The body of the snake is consisting of many circles, with a circle being added to the body after the head meets a ball. The balls class controls the balls spawned in the window. Each time the head encounters a ball, the ball randomly places itself somewhere else on the window and a point is added to the player’s score. The class also defines its shape and color. 


![Alt Text](https://media.giphy.com/media/iU8ENTozJBOxIFbSDl/giphy.gif)
