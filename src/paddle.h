#ifndef PADDLE_H
    #define PADDLE_H

#include "raylib.h"

typedef struct {
    Rectangle rect;
    Color color;
    int speed;
    int segments;
    float roundness;
    float targetY;              // target position to track
    float trackingRange;        // distance from paddle to start tracking
    float reactionTime;         // delay before responding to ball
    float lastReactionTime;     // timestamp of last movement
} Paddle;

/**
 * Move Paddle using it's x and y values.
 */
void inputPaddle( Paddle* paddle );

/**
 * Update Paddle
 */
void updatePaddle( Paddle* paddle );

/**
 * Logic for Cpu
 */
void updateCpu( Paddle* paddle, int ball_x, int ball_y );

/**
 * Draw Paddle on the screen.
 */
void drawPaddle( Paddle* paddle );

#endif  // PADDLE_H
