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
#### 1.**Direction** 

#### Use case & “if” to read the input and change the direction. 

#### 2.**The length of the snake**

#### “void" & “for” loop to print the snake. 

#### 3. **Print food and bomb**

#### “void” & “while”, “while” loop to determine if the location of the food and the snake is the same, if so, do not print 	food/bomb. 

#### “random” to print food or bomb on the map. 

#### 4. **End game**

#### “void” & “if” , three cases: hit the barrier/ hit itself/ the length is less than 1. 

#### 5.**Remake**

#### “bool” or “if”, to read the input and determine whether to remake. If not, jump to the page of score. 
## Features implemented
#### Print the snake: use a deque to store the snake body
#### Initialize the map
#### Put the food
#### Put the bomb
## No non-standard C/C++ libraries required
## Compilation and execution instructions
