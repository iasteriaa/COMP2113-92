#include<iostream>
#include<deque>
#include<ctime>
#include<stdexcept>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<fcntl.h>
#include <termio.h>
using namespace std;

void clearScreen(){ //clean the screen, prepare for the game
	printf("\033[2J");
}

struct Snake { 
    char image;
    short x, y; 
};

int getch(void){// achieve getch() in Linux
        struct termios tm, tm_old;
        int fd = 0, ch;
        if (tcgetattr(fd,&tm)<0){
            return -1;
        }
        tm_old = tm;
        cfmakeraw(&tm);
        if (tcsetattr(fd, TCSANOW, &tm)<0){
            return -1;
        }
        ch = getchar();
        if (tcsetattr(fd, TCSANOW, &tm_old) < 0){
            return -1;
        }
        return ch;
    }



class snakeGame {
    public:
    snakeGame();
    void Map_initialize();
    void gotoxy(short x, short y) {
        printf("\033[%d;%dH",(x),(y));// Locate the coordinates by this
    }
    void HideCursor() // Hide the cursor when playing games or the screen will keep flashing
    {
        printf("\033[?25l");
    }
    void Snake_initialize() { // Initialize the snake, the intial snake is '@+++'
        snake.push_front({'@', height / 2, width / 2});
         for (int i=0; i<3;++i)
            snake.push_back({'+', static_cast<short>(height/2+i+1), width/2});
        
    }
    int Loc_contradict() { //judge if the location of food contradicts with Snake
        for (Snake body : snake){
            if(body.x == food_x && body.y == food_y) return 0;
            if(body.x == bomb_x && body.y == bomb_y) return 0;
            if(bomb_x==food_x && bomb_y==bomb_y) return 0;}
        return 1;
    }
    void createFood() {
		do {
			food_x = rand() % (height-1) + 2 ;
			food_y = rand() % (width-2) + 3 ;
		} while (!Loc_contradict());
		gotoxy(food_x,food_y); cout << '*' << endl; //print the food
    }
    
    void createBomb() {
		do {
			bomb_x = rand() % (height-1) + 2 ;
			bomb_y = rand() % (width-2) + 3 ;
		} while (!Loc_contradict());
		gotoxy(bomb_x,bomb_y); cout << '+' << endl; //print the bomb
    }
    void printSnake();
    inline void clearSnake(Snake &tail) {
        gotoxy(tail.x, tail.y); cout << ' '; // Cover the snake's tail use ' '
    }
    void judgeCrash();
    void foodEaten();
    void touchBomb();
    void Input_user() {
		char ch; 
		ch=getch();
        switch(ch) {
            case 'w':if (direction_Snake != 's') direction_Snake = ch;break;
            case 'a':if (direction_Snake != 'd') direction_Snake = ch;break;
            case 's':if (direction_Snake != 'w') direction_Snake = ch;break;
            case 'd':if (direction_Snake != 'a') direction_Snake = ch;break;
            case ' ':gotoxy(width / 2, height+2); 
			cout << "Paused, press any key to continue"; 
			getch();
            gotoxy(width / 2, height+2); cout << "                     ";
			break;
            default:break;
        }
		
    }
    deque<Snake> snake1;
    private:
    enum MapSize {height = 20,width = 80}; //the gsize of map is 20*80
    char direction_Snake; //direction
    bool beg,eatFood,touchbomb=false;
    deque<Snake> snake;
    
    int food_x,food_y, bomb_x, bomb_y;
    int score=0;
};

void snakeGame::foodEaten() { // Determine whether the snake eats food, if yes, score + 1
    createFood();
    eatFood=true;
    ++score;
}
void snakeGame::touchBomb(){
    createBomb();
    touchbomb=true;
}
void snakeGame::judgeCrash() { // Determine whether the game is over
    int flag=0;
    if (snake.size()>=4) {// When the snake hits itself, the game ends
        deque<Snake>::iterator iter = snake.begin() + 1;
        int x = (iter-1)->x, y = (iter-1)->y;
        for (; iter != snake.end(); ++iter) {
            if (iter->y == y && iter->x == x  ) flag=1;
        }}
    if (snake.size()<1)
    flag =1;
    if (flag || snake.front().y == 1 || snake.front().y == width+1 || snake.front().x == 1 || snake.front().x == height+1 )// When the snake hits the wall, game over
    {
        gotoxy(height /2, width / 2 - 10);
        cout << "Game Over! Score: " << score << " Press 'p' to remake"<<endl;
        while(1) {
            direction_Snake = getch();
            if (direction_Snake == 'p')// after game over, if press "p", remake
            {clearScreen();
            snakeGame();}
            } 
        runtime_error quit("Game Over, quit"); throw quit;
    }
    
}

void snakeGame::printSnake() { // print the snake with @ and +
    deque<Snake>::const_iterator iter = snake.begin();
    for (; iter <= snake.begin() + 1 && iter < snake.end(); ++iter) {
        gotoxy(iter->x, iter->y); cout << iter->image;
    }
}
void snakeGame::Map_initialize() { //print the map with ■
    int i;

  for (i = 0; i != width+2; i += 2)
  {
    gotoxy(1,i+1);
    cout << "■"; //top wall
    //gotoxy(2,i+1);
    //cout << i;
  }


  for (i = 1; i != height+1; ++i)
  {
      gotoxy(i, 1);
      cout << "■";//left wall
  }

  for (i = 1; i != height+1; ++i) {
      gotoxy(i,width+1);
      cout << "■";//right wall
  }


    for (i = 0; i != width+2; i += 2)
    {
        gotoxy(height+1, i+1);
        cout << "■";
    }//bottom wall
	cout <<endl;
	cout<<"Press 'j' to start"<<endl;
	cout<<"Press 'w' to move upward"<<endl;
	cout<<"Press 'a' to move leftward"<<endl;
	cout<<"Press 's' to move downward"<<endl;
	cout<<"Press 'd' to move rightward"<<endl;
	cout<<"Press 'p' to remake"<<endl;
	cout<<"Press 'space' to pause"<<endl;

}



snakeGame::snakeGame() { //Start the game
    HideCursor(); 
	srand(static_cast<unsigned int>(time(NULL)));
    beg=true;
    Snake tmp1,tmp2;
	
	
	while (1) {
		if(beg) {
			Map_initialize();
			direction_Snake = getch();
			Snake_initialize();
			createFood();
            createBomb();
			beg = eatFood = touchbomb = false;
		}
		tmp2=snake.back(); 
		tmp1=snake.front();
		snake.pop_back();
		if (eatFood) {
			tmp2.image='+'; 
			snake.push_back(tmp2);
			eatFood=false;
		}else 		 
			clearSnake(tmp2);
		if (touchbomb){
            deque<Snake>::iterator itr=snake.end();
        tmp2=*(itr-1);
            snake.pop_back();
            clearSnake(tmp2);
        tmp2=*(itr-2);
            snake.pop_back();
            clearSnake(tmp2);//remove the last item in the deque
            touchbomb=false;
        }
        else 
          clearSnake(tmp2);
		if(direction_Snake == 's') 
			++tmp1.x;
        else if (direction_Snake == 'a') 
			--tmp1.y;
        else if (direction_Snake == 'd') 
			++tmp1.y;
        else 				 
			--tmp1.x;
		
		try{
			judgeCrash();
		} catch(runtime_error &quitSignal) {
			throw quitSignal;
		}
		
		snake.front().image='+'; 
		snake.push_front(tmp1);
		printSnake();
		if (tmp1.x == food_x && tmp1.y == food_y) 
			foodEaten();
		if (tmp1.x == bomb_x && tmp1.y == bomb_y)
            touchBomb();
			Input_user();
	}
}


int main() {
    clearScreen();
    system("mode con cols=120 lines=42");
    try{
        snakeGame game;
    }
    catch(runtime_error &gameEnd) { //end
        system("cls");
        cout<<gameEnd.what();
        getch();
    }
}