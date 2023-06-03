
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, height = 20, width = 20,x, y, fruitx, fruity, flag, gameover, score;

  
    
void draw()
{
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                printf("#");
            }
            else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("score = %d\npress X to stop", score);

}

void setup()
{
    x = height / 2;
    y = width / 2;
    gameover = 0;

    here:
    fruitx = rand() % height;
    if (fruitx == 0)
        goto here;
    here2:
    fruity = rand() % width;
    if (fruity == 0)
        goto here2;
    score = 0;
}

void input()
{
    if (kbhit()) {
        switch (getch()) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    sleep(1.0);
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x > height
        || y < 0 || y > width)
        gameover = 1;

    if (x == fruitx && y == fruity) {
        here3:
        fruitx = rand() % height;
        if (fruitx == 0)
            goto here3;

        here4:
        fruity = rand() % width;
        if (fruity == 0)
            goto here4;
        score += 10;
    }
}

void main()
{
    int m, n;

    setup();


    while (!gameover) {


        draw();
        input();
        logic();
    }
}
