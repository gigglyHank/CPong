//#include <stdio.h>
#include "ball.h"

/** Collision detection.
 *
 */
static void collisionBall( Ball* ball )
{
    // doesn't account for when x == 0 or windows height
    /*
    if( ball->x + ball->radius >= GetScreenWidth() || ball->x - ball->radius <= 0 )
    {
        ball->speed_x *= -1;
        if( ball->speed_x > 0 )
        {
            ball->speed_x++;
            printf("%d\n", ball->speed_x);
        }
        else {
            ball->speed_x--;
            printf("%d\n", ball->speed_x);
        }
    }
    */
    // y collision
    if( ball->y + ball->radius >= GetScreenHeight() || ball->y - ball->radius <= 0 )
    {
        ball->speed_y *= -1;
    }
}

void updateBall( Ball* ball )
{
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    // check collision here
    collisionBall( ball );
}

void drawBall( Ball* ball )
{
    DrawCircle( ball->x, ball->y, ball->radius, ball->color );
}

void resetBall( Ball* ball )
{
    ball->x = GetScreenWidth() / 2;
    ball->y = GetScreenHeight() / 2;
    int speed_choices[ 2 ] = { -3, 3 }; // also sets the direction
    ball->speed_x = speed_choices[ GetRandomValue(0, 1) ];
    ball->speed_y = speed_choices[ GetRandomValue(0, 1) ];
}
