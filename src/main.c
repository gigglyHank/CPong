//#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "ball.h"
#include "paddle.h"

int main ( void )
{
    InitWindow( 800, 400, "Pong" );
    SetTargetFPS( 60 );

    Ball ball = {
        .x = GetScreenWidth()/2,
        .y = GetScreenHeight()/2,
        .color = WHITE,
        .radius = 10,
        .speed_x = 3,
        .speed_y = 3
    };

    Paddle p1 = {
        .rect = { 785, 200, 10, 40 },
        .color = WHITE,
        .speed = 5,
        .segments = 4,
        .roundness = 4.0f
    };
    Paddle p2 = {
        .rect = { 5, 200, 10, 40 },
        .color = WHITE,
        .speed = 5,
        .segments = 4,
        .roundness = 4.0f
    };

    int ptsPlayer = 0;
    int ptsCpu = 0;

    while( !WindowShouldClose() )
    {
        // ------------------------------------------------- input
        inputPaddle( &p1 );
        // -------------------------------------------------

        // ------------------------------------------------- update
        updateBall( &ball );
        updatePaddle( &p1 );
        updateCpu( &p2, ball.x, ball.y );

        // check for collision on paddles
        if( CheckCollisionCircleRec( (Vector2){ball.x, ball.y}, ball.radius, (Rectangle){p1.rect.x, p1.rect.y, p1.rect.width, p1.rect.height} ) )
        {
            ball.speed_x *= -1;
            if( ball.speed_x > 0 ) ball.speed_x++;
            else ball.speed_x--;
        }
        if( CheckCollisionCircleRec( (Vector2){ball.x, ball.y}, ball.radius, (Rectangle){p2.rect.x, p2.rect.y, p2.rect.width, p2.rect.height} ) )
        {
            ball.speed_x *= -1;
            if( ball.speed_x > 0 ) ball.speed_x++;
            else ball.speed_x--;
        }

        // score
        if( ball.x + ball.radius >= GetScreenWidth() )
        {
            ptsCpu++;
            resetBall( &ball );
        }
        if( ball.x - ball.radius <= 0 )
        {
            ptsPlayer++;
            resetBall( &ball );
        }

        // -------------------------------------------------

        // ------------------------------------------------- draw
        BeginDrawing();
        ClearBackground( BLACK );

        // center line
        DrawLine( 400, 0, 401, 400, WHITE );

        drawPaddle( &p1 );
        drawPaddle( &p2 );
        drawBall( &ball );
        DrawText( TextFormat( "%d", ptsCpu ), 200, 10, 20, WHITE );
        DrawText( TextFormat( "%d", ptsPlayer ), 600, 10, 20, WHITE );
        // -------------------------------------------------

        EndDrawing();
    }

    CloseWindow();
    return EXIT_SUCCESS;
}
