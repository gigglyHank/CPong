#include "paddle.h"

void inputPaddle( Paddle* paddle )
{
    if( IsKeyDown( KEY_UP ) )
    {
        paddle->rect.y -= paddle->speed;
    }
    if( IsKeyDown( KEY_DOWN ) )
    {
        paddle->rect.y += paddle->speed;
    }
}

/**
 * Make sure Paddle is visable on the board (screen)
 */
static void collisionPaddleScreen( Paddle* paddle )
{
    // check top
    if( paddle->rect.y <= 0 )
    {
        paddle->rect.y = 0;
    }
    // check bottom
    if( paddle->rect.y + paddle->rect.height >= GetScreenHeight() )
    {
        paddle->rect.y = GetScreenHeight() - paddle->rect.height;
    }
}

void updatePaddle( Paddle* paddle )
{
    collisionPaddleScreen( paddle );
}

void updateCpu( Paddle* paddle, int ball_x, int ball_y )
{
    if( ball_x < GetScreenWidth() / 4 )
    {
        if( paddle->rect.y + paddle->rect.height / 2 > ball_y )
        {
            paddle->rect.y = paddle->rect.y - paddle->speed - 5;
        }
        if( paddle->rect.y + paddle->rect.height / 2 <= ball_y )
        {
            paddle->rect.y = paddle->rect.y + paddle->speed + 5;
        }
    }

    collisionPaddleScreen( paddle );
}

void drawPaddle( Paddle* paddle )
{
    //DrawRectangle( paddle->x, paddle->y, paddle->width, paddle->height, paddle->color );
    DrawRectangleRounded( paddle->rect, paddle->roundness, paddle->segments, paddle->color );
}
