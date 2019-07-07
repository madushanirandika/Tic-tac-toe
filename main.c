#include <stdio.h>
#include <stdlib.h>

//Developing by Madushani Randika

void main();
void gameDisplay();
void computerPlay();
void playerPlay();
void gameDraw();
int gameWinner();
int check();
void clear();
void clearArray();
void checkTurn(int n);
int runGame(int n1);
char symbol[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int board[9]= {0,0,0,0,0,0,0,0,0};
int line[8]= {0,0,0,0,0,0,0,0};
int lineVal[8]= {0,0,0,0,0,0,0,0};
int box[9]= {0,0,0,0,0,0,0,0,0};
char sel[3][3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int turn=1; //count the number of turn
int computer; //if a human plays first computer value is zero & if a computer plays first computer value is one



void main()   //display the menu & if a human plays first calling the playerPlay
{
    //function,if a computer plays first calling the computerPlay function or exit
    int choice; //to select the menu: first player is human or computer or exit

    system("COLOR F1"); //put the color F- background white & 1-letter blue
    system("cls"); //clear the menu and display the board
    printf("\n\t*****madushani******\n\n"); //display the menu
    printf("\tTIC TAC TOE GAME\n\n");
    printf("\n\t--------MENU--------");
    printf("\n\t1 : First Player");
    printf("\n\t2 : First Computer");
    printf("\n\t3 : Exit");
    printf("\n\t--------------------");
    printf("\n\tEnter your choice:>");
    scanf("%d",&choice); //give the choice your own (1,2,3)

    switch (choice)
    {

    case 1:
        computer=0; //if a human plays first computer value is zero
        gameDisplay(); //calling a gameDisplay function
        playerPlay(); //calling a playerPlay function
        break;

    case 2:
        computer=1; //if a computer plays first computer value is one
        computerPlay(); //calling a ComputerPlay function
        break;

    case 3:
        exit(1); //exit the game
    default:
        main(); //again go to the main function
    }
}


void gameDisplay()  //Display the game interface
{

    system("cls"); //clear the first display and display the second display

    printf("\n\t*****madushani******\n\n");
    printf("\tTIC TAC TOE GAME\n\n");
    printf("\n\t       |      |      ");
    printf("\n\t    %c  |   %c  |  %c  ",symbol[0],symbol[1],symbol[2]); //display the main board
    printf("\n\t ______|______|______");
    printf("\n\t       |      |      ");
    printf("\n\t    %c  |   %c  |  %c  ",symbol[3],symbol[4],symbol[5]);
    printf("\n\t ______|______|______");
    printf("\n\t       |      |      ");
    printf("\n\t    %c  |   %c  |  %c  ",symbol[6],symbol[7],symbol[8]);
    printf("\n\t       |      |      \n\n\n");


    printf("  your select Square: ");
    printf("\n\t       |      |       \t\t\tup    - press w key"); //display the select board
    printf("\n\t    %c  |   %c  |  %c  ",sel[0][0],sel[1][0],sel[2][0]);
    printf("\n\t ______|______|______ \t\t\tdown  - press s key");
    printf("\n\t       |      |      ");
    printf("\n\t    %c  |   %c  |  %c   \t\t\tleft  - press a key",sel[0][1],sel[1][1],sel[2][1]);
    printf("\n\t ______|______|______");
    printf("\n\t       |      |       \t\t\tright - press d key");
    printf("\n\t    %c  |   %c  |  %c  ",sel[0][2],sel[1][2],sel[2][2]);
    printf("\n\t       |      |       \t\t\tenter - press enter key \n");

} //end the gameDisplay function

void playerPlay()  //where takes * placement check the empty squares.
{
    //if it is empty show the input symbol.then call computerPlay function
    int place; //after enter the "*" take the value of the square
    gameDraw(); //calling a gameDraw function
    gameWinner(); //calling a gameWinner function

    place=check(); //calling a check function

    if(symbol[place-1] != ' ')  //check the square is empty or not
    {
        playerPlay(); //again calling playerPlay function
    }

    checkTurn(place); //calling checkTurn function & transfer the place value
    gameDisplay(); //calling a gameDisplay function
    clear(); //calling a clear function
    computerPlay(); //calling a computerPlay function
}


void checkTurn(int n)  //first player select "X" symbol & second player select "O" symbol.
{
    //Count the turns

    if(turn % 2)  //check the turn is odd number
    {
        symbol[n-1]='X'; //put the value "X"
    }
    else   //turn is even number
    {
        symbol[n-1]='O'; //put the value "O"

    }
    turn++; //turn=(turn+1)
}


void computerPlay()  //display the computer chance & call the PlayerPlay function
{
    int zero,w; //* placement value number

    w=runGame(zero); //calling the runGame function
    checkTurn(w); //calling the checkTurn
    gameDisplay();
    playerPlay();

} //end the computer function


int runGame(int n1)  //where computer select square according to the logic count & return the square number
{
    int i,x,s; //declare the for loop value
    int n; //n is highest (num+1)
    int value,num; //value is highest square value & num is each array number

    value=0; //value is zero (max value in box array)
    num=0; //num is zero (array number of max value)

    for(i=0; i<9; i++) //start the for loop
    {
        if(symbol[i]=='X')  //if symbol is "X", value is 30
        {
            board[i]=30;
        }
        if(symbol[i]=='O')  //if symbol is "O", value is 5
        {
            board[i]=5;
        }
        if(symbol[i]==' ')  //if no symbol, value is 0
        {
            board[i]=0;
        }
    }


    for(i=0; i<8; i++) //clear the line & lineVal arrays
    {
        line[i]=0;
        lineVal[i]=0;
    }
    for(i=0; i<9; i++) //clear the box array
    {
        box[i]=0;
    }


    line[0]=board[0]+board[1]+board[2]; //sum of the 1st row
    line[1]=board[3]+board[4]+board[5]; //sum of the 2nd row
    line[2]=board[6]+board[7]+board[8]; //sum of the 3rd row
    line[3]=board[0]+board[3]+board[6]; //sum of the 1st column
    line[4]=board[1]+board[4]+board[7]; //sum of the 2nd column
    line[5]=board[2]+board[5]+board[8]; //sum of the 3rd column
    line[6]=board[0]+board[4]+board[8]; //sum of 1st diagonal
    line[7]=board[2]+board[4]+board[6]; //sum of 2nd diagonal

    for(x=0; x<8; x++)
    {

        if (line[x] == 0) //if line value is 0,then line value is 1
            lineVal[x] = 1;
        else if (line[x] == 30) //if line value is 30,then line value is 9
            lineVal[x] = 9;
        else if (line[x] == 5) //if line value is 5,then line value is 10
            lineVal[x] = 10;
        else if (line[x] == 10) //if line value is 10,then line value is 1000
            lineVal[x] = 1000;
        else if (line[x] == 60) //if line value is 60,then line value is 100
            lineVal[x] = 100;
        else //if line value is other value,then line value is 0
            lineVal[x] = 0;
    }



    box[0]=lineVal[0]+lineVal[3]+lineVal[6]; //sum of 1st square
    box[1]=lineVal[0]+lineVal[4]; //sum of 2nd square
    box[2]=lineVal[0]+lineVal[5]+lineVal[7]; //sum of 3rd square
    box[3]=lineVal[1]+lineVal[3]; //sum of 4th square
    box[4]=lineVal[1]+lineVal[4]+lineVal[6]+lineVal[7]; //sum of 5th square
    box[5]=lineVal[1]+lineVal[5]; //sum of 6th square
    box[6]=lineVal[2]+lineVal[3]+lineVal[7]; //sum of 7th square
    box[7]=lineVal[2]+lineVal[4]; //sum of 8th square
    box[8]=lineVal[2]+lineVal[5]+lineVal[6]; //sum of 9th square

    for(s=0; s<9; s++)
    {
        if(box[s]>=value)  //check the square is grater than or equal value
        {
            if(board[s]!=0)  //check each square value is not zero
            {
                value=value; //no change value
                num=num;
            }
            else
            {
                value=box[s]; //change value is square value
                num=s;
            }
        }
        else
        {
            value=value;
            num=num;
        }
    }

    n=num+1; //array value change square number
    return n; //return square number

}//end the runGame function



void gameDraw()  //if the number of playing turns are grater than 9, display the game draw & change the colour
{

    if(turn > 9)  //check the turn value grater than 9
    {
        system("COLOR F5"); //change the color F-background white & 5-letter purple
        printf("\n\a    **** Game Draw ****"); //display the "game draw"
        getch(); //it will stop until press a key
        clearArray();
        main(); //calling the main function
    }
}//end the gameDraw function


int gameWinner()  //check row,column & diagonal first select who is win the game,
{
    //display the winner & change the colour
    int i,x; //declare the for loop value
    for(i=0; i<9; i++)
    {
        if(symbol[i]=='X')  //if symbol is "X", value is 30
        {
            board[i]=30;
        }
        if(symbol[i]=='O')  //if symbol is "O", value is 5
        {
            board[i]=5;
        }
        if(symbol[i]==' ')  //if no symbol, value is 0
        {
            board[i]=0;
        }
    }

    line[0]=board[0]+board[1]+board[2]; //sum of the 1st row
    line[1]=board[3]+board[4]+board[5]; //sum of the 2nd row
    line[2]=board[6]+board[7]+board[8]; //sum of the 3rd row
    line[3]=board[0]+board[3]+board[6]; //sum of the 1st column
    line[4]=board[1]+board[4]+board[7]; //sum of the 2nd column
    line[5]=board[2]+board[5]+board[8]; //sum of the 3rd column
    line[6]=board[0]+board[4]+board[8]; //sum of 1st diagonal
    line[7]=board[2]+board[4]+board[6]; //sum of 2nd diagonal

    for(x=0; x<8; x++)
    {

        if (line[x] == 15)  //check the line value is 15
        {
            if(computer ==0)  //if a human plays,computer is zero value
            {
                system("COLOR F4"); //change the color F-background white & 5-letter red
                printf("\n\a    **** Computer win ****");
            }
            else
            {
                system("COLOR F2"); //change the color F-background white & 5-letter green
                printf("\n\a    **** Player win ****");
            }

            getch(); //it will stop until press a key
            clearArray(); //calling the clearArray function
            main(); //calling the main function

        }
        else if (line[x] == 90)   //check the line value is 90
        {
            if(computer ==1)  //if a computer plays,computer is one value
            {
                system("COLOR F4"); //change the color F-background white & 5-letter red
                printf("\n\a    **** Computer win ****");
            }
            else
            {
                system("COLOR F2"); //change the color F-background white & 5-letter green
                printf("\n\a    **** player win ****");
            }

            getch(); //it will stop until press a key
            clearArray(); //calling the clearArray function
            main(); //calling the main function
        }

    }
    return 0;
} //end the gameWinner function

void clearArray()  //when the game is over, symbol array is clear the game
{
    int i;

    for(i=0; i<9; i++) //clear the symbol array & turn value is one
    {

        symbol[i]=' ';
        turn=1;
    }

} //end the clearArray function

int check()  //Identify the pressing key & go to the place where "*" stands
{

    int c; //if key press, take the ASCII value
    int x,y,i;
    x=1;
    y=1;

    sel[1][1]='*'; //display "*" in middle square
    gameDisplay();

    for(i=1; i>0; i++)
    {
        c=getch();


        if (c  == 119 || c  == 87)  //if ASCII value is 119,take it is has w
        {
            //if ASCII value is 89,take it is has W
            x=x;
            y=y-1;
            if(x==0 && y==-1)
            {
                x=0;
                y=2;
                sel[0][0]=' ';
            }
            if(x==1 && y==-1)
            {
                x=1;
                y=2;
                sel[1][0]=' ';
            }
            if(x==2 && y==-1)
            {
                x=2;
                y=2;
                sel[2][0]=' ';
            }
            sel[x][y]='*';
            sel[x][y+1]=' ';
            gameDisplay();

        }
        else if(c == 115 || c  == 83)   //if ASCII value is 115,take it is has s
        {
            //if ASCII value is 83,take it is has S
            x=x;
            y=y+1;
            if(x==0 && y==3)
            {
                x=0;
                y=0;
                sel[0][2]=' ';
            }
            if(x==1 && y==3)
            {
                x=1;
                y=0;
                sel[1][2]=' ';
            }
            if(x==2 && y==3)
            {
                x=2;
                y=0;
                sel[2][2]=' ';
            }
            sel[x][y]='*';
            sel[x][y-1]=' ';
            gameDisplay();

        }
        else if (c == 97 || c  == 65)   //if ASCII value is 97,take it is has a
        {
            //if ASCII value is 65,take it is has A
            x=x-1;
            y=y;
            if(x==-1 && y==0)
            {
                x=2;
                y=0;
                sel[0][0]=' ';
            }
            if(x==-1 && y==1)
            {
                x=2;
                y=1;
                sel[0][1]=' ';
            }
            if(x==-1 && y==2)
            {
                x=2;
                y=2;
                sel[0][2]=' ';
            }
            sel[x][y]='*';
            sel[x+1][y]=' ';
            gameDisplay();
        }
        else if (c == 100 || c==68)  //if ASCII value is 100,take it is has d
        {
            //if ASCII value is 68,take it is has D
            x=x+1;
            y=y;
            if(x==3 && y==0)
            {
                x=0;
                y=0;
                sel[2][0]=' ';
            }
            if(x==3 && y==1)
            {
                x=0;
                y=1;
                sel[2][1]=' ';
            }
            if(x==3 && y==2)
            {
                x=0;
                y=2;
                sel[2][2]=' ';
            }
            sel[x][y]='*';
            sel[x-1][y]=' ';
            gameDisplay();

        }
        else if(c == 13)  //if ASCII value is 13,take it is has ENTER key
        {

            if((x>=0 && x<=2) && (y>=0 && y<=2))
            {
                if(x==0 && y==0)
                {
                    return 1;
                }
                if(x==0 && y==1)
                {
                    return 4;
                }
                if(x==0 && y==2)
                {
                    return 7;
                }
                if(x==1 && y==0)
                {
                    return 2;
                }
                if(x==1 && y==1)
                {
                    return 5;
                }
                if(x==1 && y==2)
                {
                    return 8;
                }
                if(x==2 && y==0)
                {
                    return 3;
                }
                if(x==2 && y==1)
                {
                    return 6;
                }
                if(x==2 && y==2)
                {
                    return 9;
                }
                break;
            }
        }
    }
}

void clear()  //when the player select square, sel array is clear the game
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            sel[i][j]=' ';
        }
    }
}
