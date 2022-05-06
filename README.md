# **COMP2113-92**
## **Group-92**
### **Gong Chuanqi 3033092216**
### **Liu Yilin 3035770783**
## Game Description & Rules: 
#### **Snake**
#### Players use the arrow keys to control a snake to swallow foods, while the snake body with the swallowed foods continue to grow. When the snake head hit the snake body or the barrier, the game is over. When the length of the snake is less than 1, the game is over. The initial length is 3. 
#### Rules
#### A snake in a closed enclosure, enclosure randomly appears a food, the player controls the snake to the four directions of up, down, left, and right, by pressing the keyboard. When the snake head knocked over the food, the food was eaten, the body of the snake becomes one section longer while recording 1 points. Then the food appeared randomly again, waiting for the snake to eat. If the snake in the movement of the wall or body cross snake head knocked over their own body, game over. There is also a bomb which will appear randomly just as the food, however, if the snake eats the bomb, the length of the snake will reduce 2. 
#### Start: Press any key to start the game. 

#### Remake: Press “p” to remake if the game is over. 

#### “s”: When pressed, the snake moves downward. 

#### “a”: When you press left, the snake goes left. 

#### “d”: When pressed right, the snake moves to the right. 

#### “w”: When pressed up, the snake moves upwards. 

#### When it touches the food, the length of the snake will add 1. 

#### “*”: Food (or so-called target). 

#### “■”: Barrier. 

#### “+”: Bomb. 
## **Features:**
#### **Direction** 

#### Use case & “if” to read the input and change the direction. 

#### **The length of the snake**

#### “void" & “for” loop to print the snake. 

#### **Print food and bomb**

#### “void” & “while”, “while” loop to determine if the location of the food and the snake is the same, if so, do not print 	food/bomb. 

#### “random” to print food or bomb on the map. 

#### **End game**

#### “void” & “if” , three cases: hit the barrier/ hit itself/ the length is less than 1. 

#### **Remake**

#### “bool” or “if”, to read the input and determine whether to remake. If not, jump to the page of score. 
#### A list of features that you have implemented, and explain how each coding element 1 to 5 listed under the coding requirements aforementioned support your features.
#### A list of non-standard C/C++ libraries, if any, that are used in your work and integrated to your code repo. Please also indicate what features in your game are supported by these libraries.
#### Compilation and execution instructions. Simply put, this serves like a "Quick start" of your game.
