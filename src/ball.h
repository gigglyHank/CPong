#ifndef BALL_H
    #define BALL_H

#include "raylib.h"

typedef struct {
    int x;
    int y;
    Color color;
    int radius;
    int speed_x;
    int speed_y;
} Ball;

/** Update the ball.
 *
 */
void updateBall( Ball* ball );


/** Draw ball.
 *
 */
void drawBall( Ball* ball );

/**
 * Rest ball.
 */
void resetBall( Ball* ball );

#endif // BALL_H
