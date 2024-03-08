// version 0.1

// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000 ; 
//     const int screenHeight= 1000 ;
//     InitWindow(screenHeight,screenWidth,"DODGE DEEZ BALLS");
//     int radii = 50;
//     int radii1 = 50;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = {(GetRandomValue(1,800))};
//     int balleny = {(GetRandomValue(0,0))};

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         balleny = balleny + 5; 
//         if (IsKeyDown(KEY_RIGHT)) ballx += 5.0;
//         if (IsKeyDown(KEY_LEFT))  ballx -= 5.0;
//         if (IsKeyDown(KEY_DOWN)) bally += 5.0;
//         if (IsKeyDown(KEY_UP)) bally -= 5.0;
//         if (balleny > 1100) balleny = balleny - 1100,ballenx = GetRandomValue(0,1000);
//         if (radii + radii1 == (sqrt((ballx-ballenx)*(ballx-ballenx))+sqrt((bally-balleny)*(bally-balleny)))) score = score +1 ;
//         BeginDrawing();
//             // ClearBackground(RAYWHITE);
//             DrawCircle(ballx,bally,radii,BLUE);
//             DrawCircle(ballenx,balleny,radii1,RED);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 0.2
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(1, 800);
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     int coinspeed = 5;
//     int playerspeed = 5;

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         balleny += coinspeed; 
//         if (IsKeyDown(KEY_RIGHT)) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT))  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN)) bally += playerspeed;
//         if (IsKeyDown(KEY_UP)) bally -= playerspeed;
        
//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(0, screenWidth); // Reset the position of the red ball
//             balleny = 0; // Reset the y position of the red ball
//             coinspeed = coinspeed + 1;
//         }

//         // Wrap the red ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(0, screenWidth);
//             balleny = 0;
//             score = score - 1;
//             playerspeed = playerspeed + 1;
//         }

//         BeginDrawing();
//             // ClearBackground(RAYWHITE);
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }



//version t0.3
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(1, 800);
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         balleny += coinspeed; 
//         if (IsKeyDown(KEY_RIGHT) && ballx + radii < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - radii > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + radii < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - radii > 0) bally -= playerspeed;
        
//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(0, screenWidth); // Reset the position of the yellow ball
//             balleny = 0; // Reset the y position of the yellow ball
//             coinspeed = coinspeed + 0.5;
//         }

//         // Wrap the yellow ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(0, screenWidth);
//             balleny = 0;
//             score = score - 1;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, 10, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - 10, screenWidth, 10, GRAY); // Bottom wall
//             DrawRectangle(0, 0, 10, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - 10, 0, 10, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }


//version 0.4
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(1, 800);
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 20; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         // Update timer
//         timer++;
//         if (timer >= dropInterval * 60) // 60 frames per second
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(0, screenWidth);
//             balleny = 0;
//             timer = 0; // Reset the timer
//         }

//         balleny += coinspeed; 
//         if (IsKeyDown(KEY_RIGHT) && ballx + radii < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - radii > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + radii < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - radii > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed
//         if (IsKeyPressed(KEY_SPACE)) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//         }

//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(0, screenWidth); // Reset the position of the yellow ball
//             balleny = 0; // Reset the y position of the yellow ball
//             coinspeed += 0.5;
//         }

//         // Wrap the yellow ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(0, screenWidth);
//             balleny = 0;
//             score -= 1;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, 10, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - 10, screenWidth, 10, GRAY); // Bottom wall
//             DrawRectangle(0, 0, 10, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - 10, 0, 10, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 0.5
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(1, 800);
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 20; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         // Update timers
//         timer++;
//         if (timer >= dropInterval * 60) // 60 frames per second
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(0, screenWidth);
//             balleny = 0;
//             timer = 0; // Reset the timer
//         }

//         teleportTimer--;

//         balleny += coinspeed; 
//         if (IsKeyDown(KEY_RIGHT) && ballx + radii < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - radii > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + radii < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - radii > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//         }

//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(0, screenWidth); // Reset the position of the yellow ball
//             balleny = 0; // Reset the y position of the yellow ball
//             coinspeed += 0.5;
//         }

//         // Wrap the yellow ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(0, screenWidth);
//             balleny = 0;
//             score -= 1;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, 10, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - 10, screenWidth, 10, GRAY); // Bottom wall
//             DrawRectangle(0, 0, 10, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - 10, 0, 10, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 0.6
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 20; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         // Update timers
//         timer++;
//         if (timer >= dropInterval * 60) // 60 frames per second
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             timer = 0; // Reset the timer
//         }

//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         balleny += coinspeed; 
//         if (IsKeyDown(KEY_RIGHT) && ballx + radii < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - radii > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + radii < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - radii > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//         }

//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Reset the position of the yellow ball
//             balleny = 0; // Reset the y position of the yellow ball
//             coinspeed += 0.5;
//         }

//         // Wrap the yellow ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, 10, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - 10, screenWidth, 10, GRAY); // Bottom wall
//             DrawRectangle(0, 0, 10, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - 10, 0, 10, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 0.7
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 20; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
//     int newCircleInterval = 30 * 60; // Interval for spawning a new circle (in frames)
//     int newCircleTimer = 0; // Timer to keep track of elapsed time for spawning a new circle
//     int wallThickness = 20; // Thickness of the walls

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + radii < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - radii > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + radii < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - radii > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Reset the position of the yellow ball
//             balleny = 0; // Reset the y position of the yellow ball
//             coinspeed += 0.5;
//         }

//         // Wrap the yellow ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }


//versions 0.8
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int radii = 50;
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 20; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
//     int newCircleInterval = 30 * 60; // Interval for spawning a new circle (in frames)
//     int newCircleTimer = 0; // Timer to keep track of elapsed time for spawning a new circle
//     int dodgeInterval = 15 * 60; // Interval for dodging the player (in frames)
//     int dodgeTimer = 0; // Timer to keep track of elapsed time for dodging the player
//     int wallThickness = 20; // Thickness of the walls

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;
//         dodgeTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + radii < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - radii > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + radii < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - radii > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             score++; // Increment score when teleporting
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the two circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, radii, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Reset the position of the yellow ball
//             balleny = 0; // Reset the y position of the yellow ball
//             coinspeed += 0.5;
//         }

//         // Dodge the player every 15 seconds
//         if (dodgeTimer >= dodgeInterval)
//         {
//             // Check if the falling ball is close to the player's position
//             if (Vector2Distance((Vector2){ ballenx, balleny }, (Vector2){ ballx, bally }) < 200) {
//                 // Move the falling ball away from the player's position
//                 if (ballenx < ballx) ballenx -= 50;
//                 else ballenx += 50;
//                 if (balleny < bally) balleny -= 50;
//                 else balleny += 50;
//             }
//             dodgeTimer = 0; // Reset the dodge timer
//         }

//         // Wrap the yellow ball around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(radii, screenWidth - radii); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, radii, BLUE);
//             DrawCircle(ballenx, balleny, radii1, YELLOW);
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 0.9    
#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 1000; 
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
    int playerSize = 50; // Initial size of the player
    int radii1 = 20;
    int score = 0;
    int ballx = 500;
    int bally = 500;
    int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
    int balleny = GetRandomValue(0, 0); // Initial y position is 0
    float coinspeed = 5;
    int playerspeed = 5;
    int dropInterval = 20; // Interval for dropping new circles (in seconds)
    int timer = 0; // Timer to keep track of elapsed time
    int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
    int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
    int newCircleInterval = 30 * 60; // Interval for spawning a new circle (in frames)
    int newCircleTimer = 0; // Timer to keep track of elapsed time for spawning a new circle
    int wallThickness = 20; // Thickness of the walls

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Update timers
        timer++;
        newCircleTimer++;

        // Spawn a new circle every 30 seconds
        if (newCircleTimer >= newCircleInterval)
        {
            // Spawn a new circle
            ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
            balleny = 0;
            newCircleTimer = 0; // Reset the timer
        }

        // Update teleport timer
        teleportTimer--;

        if (teleportTimer < 0) {
            teleportTimer = 0; // Ensure teleportTimer never becomes negative
        }

        // Update player movement
        if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
        if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
        if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
        if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

        // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
        if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
            ballx = GetMouseX();
            bally = GetMouseY();
            teleportTimer = teleportCooldown * 60; // Reset the teleport timer
            playerSize += 3; // Increase player size
        }

        // Update circle positions
        balleny += coinspeed; 

        // Check for collision between the player and the circles
        if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
            score++;
            if (balleny < screenHeight / 2) // If the circle is above the center of the screen
            {
                ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
                balleny = 0; // Reset the y position of the yellow ball
                coinspeed += 0.5;
            }
            else // If the circle is below the center of the screen, spawn a red ball
            {
                score += 5; // Increment score by 5
                playerSize += 3; // Increase player size
                ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
                balleny = 0; // Reset the y position of the red ball
            }
        }

        // Wrap the circles around the screen
        if (balleny > screenHeight + radii1) {
            ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
            balleny = 0;
            score -= 1;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            // Draw walls
            DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
            DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
            DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
            DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
            DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
            DrawCircle(ballenx, balleny, radii1, (balleny < screenHeight / 2) ? YELLOW : RED); // Yellow or red ball
            DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
            DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

