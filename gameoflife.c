#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main()
{
    int grid[25][45];
    int nextgrid[25][45];
    int i, j, livecount, b, generations, choice, preset;
    int cellnumber, x, y;
    int S;
    int temp;
    int livecount23;
    int nextgrid2;
    int cellalive;
    int a;
    int k;

    system("chcp 65001 > nul");

//------------------------------------------------ main fucntion starts here

    // no recursionn anywhere in this code only lots of iteraton bro

//-------------------edit this if u want

printf("Want to know the rules ?\n");
printf("If yes press 1\n");
printf("if no then press 2 \n");
scanf("%d",&b);

if(b ==1 )
{

printf("                      ####Conway's Game of Life Rules#### \n");
printf("->Any live cell with fewer than two live neighbors dies\n");
printf("->Any live cell with two or three live neighbors lives on\n");
printf("->Any live cell with more than three live neighbors dies\n");
printf("->Any dead cell with exactly three live neighbors becomes live\n");

printf("Press any key to begin");
getch();

printf("press any alphabet to clear screen");
system("cls");
}

else
{
    printf("No? okay , Have it your way then\n\n");
}


Sleep(2000);

// this is the title part i made it look cool

printf("\n                    Conway's Game of Life \n\n");
printf("                      Made by Anuraag \n");
printf("Opion ON this project : Had some struggles with this one\n");


printf("\n\n");


printf("\n\n\n                                  ###Initial Cell Placement###\n ");
printf("\n                  Choose Option : \n\n");
printf("1. Enter cells manually\n");
printf("2. Use Preset Artistic Pattern\n");
scanf("%d",&choice);

//-------------------edit

// this part is for choosing how u want to start the game
if(choice == 1)
{
    printf("How many live cells do you want to place ?\n");
    scanf("%d",&cellnumber);

printf("\n=== HOW TO ENTER COORDINATES ===\n");
printf("Enter Row and Column separated by SPACE\n");
printf("Example : 5 12\n\n");

    for(i=0;i<25;i++)        
        for(j=0;j<45;j++)
            grid[i][j] = 0;

    for(i=0;i<cellnumber;i++)   
    {
        printf("Cell %d : Enter Row Column : ", i+1);
        scanf("%d %d",&x,&y);
        if(x>=1 && x<=25 && y>=1 && y<=45)
        {
            grid[x-1][y-1] = 1;
            printf("✓ Placed at (%d,%d)\n",x,y);
        }
        else
        {
            printf("Invalid! Try again.\n");
            i--;
        }
    }
}

else if(choice == 2)
{
    printf("\nChoose Preset Pattern:\n");
    printf("1. Glider (Moving Pattern)\n");
    printf("2. Blinker (Oscillator)\n");
    printf("3. Pulsar (Beautiful Big Art)\n");
    printf("4. Toad (Oscillator)\n");
    printf("5. Random Artistic Scatter\n");
    printf("Enter choice : ");
    scanf("%d",&preset);

    for(i=0;i<25;i++)     
        for(j=0;j<45;j++)
            grid[i][j] = 0;

    if(preset == 1)  // Glider
    {
        grid[5][6] = 1; 
        grid[6][7] = 1; 
        grid[7][5] = 1; 
        grid[7][6] = 1; 
        grid[7][7] = 1;
    }
    else if(preset == 2)  // Blinker
    {
        grid[10][20] = 1; 
        grid[11][20] = 1; 
        grid[12][20] = 1;
    }
    else if(preset == 3)  // Pulsar
    {
        int cx=10, cy=18;
        grid[cx-2][cy-1]=1; grid[cx-2][cy]=1; grid[cx-2][cy+1]=1;
        grid[cx-1][cy-3]=1; grid[cx-1][cy+3]=1;
        grid[cx][cy-3]=1;   grid[cx][cy+3]=1;
        grid[cx+1][cy-3]=1; grid[cx+1][cy+3]=1;
        grid[cx+2][cy-1]=1; grid[cx+2][cy]=1; grid[cx+2][cy+1]=1;

        grid[cx-6][cy-1]=1; grid[cx-6][cy]=1; grid[cx-6][cy+1]=1;
        grid[cx-5][cy-3]=1; grid[cx-5][cy+3]=1;
        grid[cx-4][cy-3]=1; grid[cx-4][cy+3]=1;
        grid[cx-3][cy-1]=1; grid[cx-3][cy]=1; grid[cx-3][cy+1]=1;
    }
    else if(preset == 4)  // Toad
    {
        grid[12][20]=1; grid[12][21]=1; grid[12][22]=1;
        grid[13][19]=1; grid[13][20]=1; grid[13][21]=1;
    }
    else if(preset == 5)  // Random
    {
        srand(time(0));
        for(i=0;i<180;i++)     
        {
            x = rand()%25;
            y = rand()%45;
            grid[x][y] = 1;
        }
    }
}
else
{
    printf("Invalid choice! Defaulting to empty grid.\n");
}


printf("\nPress any key to start simulation...\n");
getch();
printf("press any alphabet to clear screen");
system("cls");

//------------------------------------------------ main game loop (iteraton) here

generations = 0;

while(1)     
{
printf("Generation = ");
printf("%d",generations);
printf("\n\n");

    for(i=0;i<25;i++)      
    {
        for(j=0;j<45;j++)
        {
            if(grid[i][j] == 1)
                printf("██");
            else
                printf("  ");
        }
        printf("\n");
    }

printf("\nPress any key for next generation (ESC to exit)\n");

    if(getch() == 27) break;

    system("cls");

    for(i=0;i<25;i++)
    {
        for(j=0;j<45;j++)
        {
            livecount = 0;
            for(int a=-1;a<=1;a++)      
            {
                for(int b=-1;b<=1;b++)
                {
                    if(a==0 && b==0) continue;
                    int row = i + a;
                    int col = j + b;
                    if(row>=0 && row<25 && col>=0 && col<45)
                        if(grid[row][col] == 1) livecount++;
                }
            }

            if(grid[i][j] == 1)
                nextgrid[i][j] = (livecount == 2 || livecount == 3) ? 1 : 0;
            else
                nextgrid[i][j] = (livecount == 3) ? 1 : 0;
        }
    }

    for(i=0;i<25;i++)      
        for(j=0;j<45;j++)
            grid[i][j] = nextgrid[i][j];

    generations++;
}

//------------------------------------------------ main game loop (iteraton) ends here

printf("Simulation ended\n");
getch();

//------------------------------------------------ main fucntion ends here

return 0;
}