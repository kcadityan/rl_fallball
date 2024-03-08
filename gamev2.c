//version 1

// #include "raylib.h"
// #include "raymath.h"

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);


// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }


// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
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
//     bool gameRunning = true;

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the player and the circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             if (balleny < screenHeight / 2) // If the circle is above the center of the screen
//             {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
//                 balleny = 0; // Reset the y position of the yellow ball
//                 coinspeed += 0.5;
//             }
//             else // If the circle is below the center of the screen, spawn a red ball
//             {
//                 score += 5; // Increment score by 5
//                 playerSize += 3; // Increase player size
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
//                 balleny = 0; // Reset the y position of the red ball
//             }
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//             playerSize -= 3; // Decrease player size

//             // Check for game over or win conditions
//             if (playerSize <= 0) {
//                 gameRunning = false; // Transition to game over screen
//             } else if (playerSize >= 300) {
//                 gameRunning = false; // Transition to win screen
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawCircle(ballenx, balleny, radii1, (balleny < screenHeight / 2) ? YELLOW : RED); // Yellow or red ball
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

//             // Draw game over screen if player size is less than or equal to 0
//             if (playerSize <= 0) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             } else if (playerSize >= 300) {
//                 DrawWinScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }


//version 1.1
// #include "raylib.h"
// #include "raymath.h"

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);

// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
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
//     bool gameRunning = true;

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the player and the circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             if (balleny < screenHeight / 2) // If the circle is above the center of the screen
//             {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
//                 balleny = 0; // Reset the y position of the yellow ball
//                 coinspeed += 0.5;
//             }
//             else // If the circle is below the center of the screen, spawn a red ball
//             {
//                 score += 5; // Increment score by 5
//                 playerSize += 3; // Increase player size
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
//                 balleny = 0; // Reset the y position of the red ball
//             }
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//             playerSize -= 3; // Decrease player size

//             // Check for game over or win conditions
//             if (playerSize <= 0 || score == -1) {
//                 gameRunning = false; // Transition to game over screen
//             } else if (score == 100) {
//                 gameRunning = false; // Transition to win screen
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawCircle(ballenx, balleny, radii1, (balleny < screenHeight / 2) ? YELLOW : RED); // Yellow or red ball
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

//             // Draw game over screen if player size is less than or equal to 0 or score is -1
//             if (playerSize <= 0 || score == -1) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             } else if (score >= 100) {
//                 DrawWinScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 1.2
// #include "raylib.h"
// #include "raymath.h"

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);

// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
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
//     bool gameRunning = true;
//     int yellowBallCount = 0; // Track the number of yellow balls dropped
//     int redBallInterval = GetRandomValue(2, 5); // Interval for dropping red balls
//     bool dropRedBall = false; // Flag to track when to drop a red ball

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer

//             // Check if it's time to drop a red ball
//             if (dropRedBall) {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Spawn a red ball
//                 balleny = 0;
//                 dropRedBall = false; // Reset the flag
//                 redBallInterval = GetRandomValue(2, 5); // Generate a new interval for dropping red balls
//             } else {
//                 yellowBallCount++; // Increment the count of yellow balls dropped

//                 // Check if it's time to drop a red ball based on the interval
//                 if (yellowBallCount >= redBallInterval) {
//                     dropRedBall = true; // Set the flag to drop a red ball
//                     yellowBallCount = 0; // Reset the count of yellow balls
//                 }
//             }
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the player and the circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             if (balleny < screenHeight / 2) // If the circle is above the center of the screen
//             {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
//                 balleny = 0; // Reset the y position of the yellow ball
//                 coinspeed += 0.5;
//             }
//             else // If the circle is below the center of the screen, spawn a red ball
//             {
//                 score += 5; // Increment score by 5
//                 playerSize += 3; // Increase player size
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
//                 balleny = 0; // Reset the y position of the red ball
//             }
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//             playerSize -= 3; // Decrease player size

//             // Check for game over or win conditions
//             if (playerSize <= 0 || score == -1) {
//                 gameRunning = false; // Transition to game over screen
//             } else if (score == 100) {
//                 gameRunning = false; // Transition to win screen
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawCircle(ballenx, balleny, radii1, (dropRedBall) ? RED : YELLOW); // Draw red or yellow ball based on flag
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
//             // Draw game over screen if player size is less than or equal to 0 or score is -1
//             if (playerSize <= 0 || score == -1) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             } else if (score >= 100) {
//                 DrawWinScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 1.3
// #include "raylib.h"
// #include "raymath.h"

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);

// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int playerHealth = 10; // Initial player health
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
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
//     bool gameRunning = true;
//     int yellowBallCount = 0; // Track the number of yellow balls dropped
//     int redBallInterval = GetRandomValue(2, 5); // Interval for dropping red balls
//     bool dropRedBall = false; // Flag to track when to drop a red ball

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer

//             // Check if it's time to drop a red ball
//             if (dropRedBall) {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Spawn a red ball
//                 balleny = 0;
//                 dropRedBall = false; // Reset the flag
//                 redBallInterval = GetRandomValue(2, 5); // Generate a new interval for dropping red balls
//             } else {
//                 yellowBallCount++; // Increment the count of yellow balls dropped

//                 // Check if it's time to drop a red ball based on the interval
//                 if (yellowBallCount >= redBallInterval) {
//                     dropRedBall = true; // Set the flag to drop a red ball
//                     yellowBallCount = 0; // Reset the count of yellow balls
//                 }
//             }
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the player and the circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             if (balleny < screenHeight / 2) // If the circle is above the center of the screen
//             {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
//                 balleny = 0; // Reset the y position of the yellow ball
//                 coinspeed += 0.5;
//             }
//             else // If the circle is below the center of the screen, spawn a red ball
//             {
//                 score += 5; // Increment score by 5
//                 playerSize += 3; // Increase player size
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
//                 balleny = 0; // Reset the y position of the red ball
//             }
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//             playerSize -= 3; // Decrease player size

//             // Check for game over or win conditions
//             if (playerSize <= 0 || score == -1) {
//                 gameRunning = false; // Transition to game over screen
//             } else if (score == 100) {
//                 gameRunning = false; // Transition to win screen
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawCircle(ballenx, balleny, radii1, (dropRedBall) ? RED : YELLOW); // Draw red or yellow ball based on flag
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Player Health: %02i", playerHealth), 10, 70, 30, RED); // Draw player health
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);
//             // Draw game over screen if player size is less than or equal to 0 or score is -1
//             if (playerSize <= 0 || score == -1) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             } else if (score == 100) {
//                 DrawWinScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 1.4
// #include "raylib.h"
// #include "raymath.h"

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);

// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int playerHealth = 10; // Initial player health
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 20; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
//     int newCircleInterval = 30 * 60; // Interval for spawning a new circle (in frames)
//     int newCircleTimer = 0; // Timer to keep track of elapsed time for spawning a new circle
//     int triangleBase = 40; // Base length of the deadly triangles
//     int triangleHeight = 40; // Height of the deadly triangles
//     int wallThickness = 20; // Thickness of the walls
//     bool gameRunning = true;
//     int yellowBallCount = 0; // Track the number of yellow balls dropped
//     int redBallInterval = GetRandomValue(2, 5); // Interval for dropping red balls
//     bool dropRedBall = false; // Flag to track when to drop a red ball
//     int triangleInterval = 150; // Interval for dropping deadly triangles (in frames)
//     int triangleTimer = 0; // Timer to keep track of elapsed time for dropping triangles

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update timers
//         timer++;
//         newCircleTimer++;
//         triangleTimer++;

//         // Spawn a new circle every 30 seconds
//         if (newCircleTimer >= newCircleInterval)
//         {
//             // Spawn a new circle
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer

//             // Check if it's time to drop a red ball
//             if (dropRedBall) {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Spawn a red ball
//                 balleny = 0;
//                 dropRedBall = false; // Reset the flag
//                 redBallInterval = GetRandomValue(2, 5); // Generate a new interval for dropping red balls
//             } else {
//                 yellowBallCount++; // Increment the count of yellow balls dropped

//                 // Check if it's time to drop a red ball based on the interval
//                 if (yellowBallCount >= redBallInterval) {
//                     dropRedBall = true; // Set the flag to drop a red ball
//                     yellowBallCount = 0; // Reset the count of yellow balls
//                 }
//             }
//         }

//         // Spawn deadly triangles at regular intervals
//         if (triangleTimer >= triangleInterval) {
//             // Spawn a deadly triangle
//             ballenx = GetRandomValue(triangleBase / 2, screenWidth - triangleBase / 2); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             triangleTimer = 0; // Reset the timer
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the player and the circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             if (balleny < screenHeight / 2) // If the circle is above the center of the screen
//             {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
//                 balleny = 0; // Reset the y position of the yellow ball
//                 coinspeed += 0.5;
//             }
//             else // If the circle is below the center of the screen, spawn a red ball
//             {
//                 score += 5; // Increment score by 5
//                 playerSize += 3; // Increase player size
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
//                 balleny = 0; // Reset the y position of the red ball
//             }
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//             playerSize -= 3; // Decrease player size

//             // Check for game over or win conditions
//             if (playerSize <= 0) {
//                 gameRunning = false; // Transition to game over screen
//             } else if (playerSize >= 300) {
//                 gameRunning = false; // Transition to win screen
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawCircle(ballenx, balleny, radii1, (balleny < screenHeight / 2) ? YELLOW : RED); // Yellow or red ball

//             // Draw deadly triangles
//             if (triangleTimer < triangleInterval) {
//                 DrawTriangle((Vector2){ballenx - triangleBase / 2, balleny + triangleHeight}, (Vector2){ballenx + triangleBase / 2, balleny + triangleHeight}, (Vector2){ballenx, balleny}, RED);
//             }

//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

//             // Draw game over screen if player size is less than or equal to 0
//             if (playerSize <= 0) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             } else if (playerSize >= 300) {
//                 DrawWinScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 1.5
// #include "raylib.h"
// #include "raymath.h"

// // Falling Triangle structure
// typedef struct FallingTriangle {
//     Vector2 position;
//     float base;
//     float height;
//     float speed;
//     bool active;
// } FallingTriangle;

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);

// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int score = 0;
//     int health = 10; // Player health
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
//     int wallThickness = 20; // Thickness of the walls
//     bool gameRunning = true;

//     // Falling triangles setup
//     const int maxTriangles = 10;
//     FallingTriangle triangles[maxTriangles];

//     for (int i = 0; i < maxTriangles; i++) {
//         triangles[i].position.x = GetRandomValue(0, screenWidth);
//         triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//         triangles[i].base = GetRandomValue(20, 50);
//         triangles[i].height = GetRandomValue(20, 50);
//         triangles[i].speed = GetRandomValue(2, 5);
//         triangles[i].active = true;
//     }

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update teleport timer
//         if (teleportTimer > 0) {
//             teleportTimer--;
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Update falling triangles positions
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active) {
//                 triangles[i].position.y += triangles[i].speed;
//                 if (triangles[i].position.y > screenHeight) {
//                     triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//                     triangles[i].position.x = GetRandomValue(0, screenWidth);
//                 }
//             }
//         }

//         // Check for collision between the player and the triangles
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y, triangles[i].base, triangles[i].height })) {
//                 triangles[i].active = false;
//                 health--; // Reduce player health
//                 if (health <= 0) {
//                     gameRunning = false; // Game over condition
//                     break;
//                 }
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Player Health: %02i", health), 10, 70, 30, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

//             // Draw falling triangles
//             for (int i = 0; i < maxTriangles; i++) {
//                 if (triangles[i].active) {
//                     DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, RED);
//                 }
//             }

//             // Draw game over screen if player size is less than or equal to 0
//             if (playerSize <= 0) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//1.6
// #include "raylib.h"
// #include "raymath.h"

// // Falling Triangle structure
// typedef struct FallingTriangle {
//     Vector2 position;
//     float base;
//     float height;
//     float speed;
//     bool active;
// } FallingTriangle;

// // Function prototypes
// void DrawGameOverScreen(int screenWidth, int screenHeight);
// void DrawWinScreen(int screenWidth, int screenHeight);

// // Function to draw the game over screen
// void DrawGameOverScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// // Function to draw the win screen
// void DrawWinScreen(int screenWidth, int screenHeight) {
//     ClearBackground(RAYWHITE);
//     DrawText("You Win!", screenWidth / 2 - MeasureText("You Win!", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
//     DrawText("Press ESC to quit", screenWidth / 2 - MeasureText("Press ESC to quit", 20) / 2, screenHeight / 2 + 10, 20, BLACK);
// }

// int main(void){
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE BALL!");
//     int playerSize = 50; // Initial size of the player
//     int score = 0;
//     int health = 1; // Player health
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
//     int wallThickness = 20; // Thickness of the walls
//     bool gameRunning = true;

//     // Falling triangles setup
//     const int maxTriangles = 10;
//     FallingTriangle triangles[maxTriangles];

//     for (int i = 0; i < maxTriangles; i++) {
//         triangles[i].position.x = GetRandomValue(0, screenWidth);
//         triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//         triangles[i].base = GetRandomValue(20, 50);
//         triangles[i].height = GetRandomValue(20, 50);
//         triangles[i].speed = GetRandomValue(2, 5);
//         triangles[i].active = true;
//     }

//     SetTargetFPS(60);
//     while (gameRunning)
//     {
//         // Update teleport timer
//         if (teleportTimer > 0) {
//             teleportTimer--;
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Update falling triangles positions
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active) {
//                 triangles[i].position.y += triangles[i].speed;
//                 if (triangles[i].position.y > screenHeight) {
//                     triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//                     triangles[i].position.x = GetRandomValue(0, screenWidth);
//                 }
//             }
//         }

//         // Check for collision between the player and the triangles
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y, triangles[i].base, triangles[i].height })) {
//                 triangles[i].active = false;
//                 health--; // Reduce player health
//                 if (health <= 0) {
//                     gameRunning = false; // Game over condition
//                     break;
//                 }
//             }
//         }

//         // Check for collision between the player and the yellow balls
//         if (CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ ballenx - 10, balleny - 10, 20, 20 })) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset ballenx
//             balleny = 0; // Reset balleny
//             score++;
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + 20) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Player Health: %02i", health), 10, 70, 30, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

//             // Draw falling triangles
//             for (int i = 0; i < maxTriangles; i++) {
//                 if (triangles[i].active) {
//                     DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, RED);
//                 }
//             }

//             // Draw yellow balls
//             DrawCircle(ballenx, balleny, 10, YELLOW);

//             // Draw game over screen if player size is less than or equal to 0
//             if (playerSize <= 0) {
//                 DrawGameOverScreen(screenWidth, screenHeight);
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

//version 1.7
// #include "raylib.h"
// #include "raymath.h"

// int main(void)
// {
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "CATCH THE COINS");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 500;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
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

//     // Falling Triangle structure
//     typedef struct FallingTriangle {
//         Vector2 position;
//         float base;
//         float height;
//         float speed;
//         Color color;
//         bool active;
//     } FallingTriangle;

//     // Falling triangles setup
//     const int maxTriangles = 10;
//     FallingTriangle triangles[maxTriangles];

//     for (int i = 0; i < maxTriangles; i++) {
//         triangles[i].position.x = GetRandomValue(0, screenWidth);
//         triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//         triangles[i].base = GetRandomValue(20, 50);
//         triangles[i].height = GetRandomValue(20, 50);
//         triangles[i].speed = GetRandomValue(2, 5);
//         triangles[i].color = RED;
//         triangles[i].active = true;
//     }

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
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             newCircleTimer = 0; // Reset the timer
//         }

//         // Update teleport timer
//         teleportTimer--;

//         if (teleportTimer < 0) {
//             teleportTimer = 0; // Ensure teleportTimer never becomes negative
//         }

//         // Update player movement
//         if (IsKeyDown(KEY_RIGHT) && ballx + playerSize < screenWidth) ballx += playerspeed;
//         if (IsKeyDown(KEY_LEFT) && ballx - playerSize > 0)  ballx -= playerspeed;
//         if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspe  ed;

//         // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
//         if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
//             ballx = GetMouseX();
//             bally = GetMouseY();
//             teleportTimer = teleportCooldown * 60; // Reset the teleport timer
//             playerSize += 3; // Increase player size
//         }

//         // Update circle positions
//         balleny += coinspeed; 

//         // Check for collision between the player and the circles
//         if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
//             score++;
//             if (balleny < screenHeight / 2) // If the circle is above the center of the screen
//             {
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the yellow ball
//                 balleny = 0; // Reset the y position of the yellow ball
//                 coinspeed += 0.5;
//             }
//             else // If the circle is below the center of the screen, spawn a red ball
//             {
//                 score += 5; // Increment score by 5
//                 playerSize += 3; // Increase player size
//                 ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
//                 balleny = 0; // Reset the y position of the red ball
//             }
//         }

//         // Wrap the circles around the screen
//         if (balleny > screenHeight + radii1) {
//             ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//             balleny = 0;
//             score -= 1;
//         }

//         // Update falling triangles positions
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active) {
//                 triangles[i].position.y += triangles[i].speed;
//                 if (triangles[i].position.y > screenHeight) {
//                     triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//                     triangles[i].position.x = GetRandomValue(0, screenWidth);
//                 }
//             }
//         }

//         // Check for collision between the player and the triangles
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ triangles[i].position.x, triangles[i].position.y, triangles[i].base, triangles[i].height })) {
//                 triangles[i].active = false;
//                 score -= 1; // Reduce score
//             }
//         }

//         BeginDrawing();
//             ClearBackground(BLACK);
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
//             DrawCircle(ballenx, balleny, radii1, YELLOW); // Yellow ball
//             DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
//             DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

//             // Draw falling triangles
//             for (int i = 0; i < maxTriangles; i++) {
//                 if (triangles[i].active) {
//                     DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, triangles[i].color);
//                 }
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// } 

//version 1.8
#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 1000; 
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "FALL BALL v1.8");
    int playerSize = 50; // Initial size of the player
    int radii1 = 20;
    int score = 0;
    int ballx = 500;
    int bally = 500;
    int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
    int balleny = GetRandomValue(0, 0); // Initial y position is 0
    float coinspeed = 5;
    int playerspeed = 5;
    int dropInterval = 5; // Interval for dropping new circles (in seconds)
    int timer = 0; // Timer to keep track of elapsed time
    int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
    int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
    int newCircleInterval = 10 * 60; // Interval for spawning a new circle (in frames)
    int newCircleTimer = 0; // Timer to keep track of elapsed time for spawning a new circle
    int wallThickness = 70; // Thickness of the walls


    // Falling Triangle structure
    typedef struct FallingTriangle {
        Vector2 position;
        float base;
        float height;
        float speed;
        Color color;
        bool active;
    } FallingTriangle;

    // Falling triangles setup
    const int maxTriangles = 10;
    FallingTriangle triangles[maxTriangles];

    for (int i = 0; i < maxTriangles; i++) {
        triangles[i].position.x = GetRandomValue(0, screenWidth);
        triangles[i].position.y = GetRandomValue(-screenHeight, 0);
        triangles[i].base = 30;
        triangles[i].height = 30;
        triangles[i].speed = GetRandomValue(2, 5);
        triangles[i].color = RED;
        triangles[i].active = true;
    }

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        ClearBackground(BLACK);
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
        //nah this code below me aint that  good at working
        // Check for collision between the player and the circles
        if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
            // score++;
            if (balleny < screenHeight / 2) // If the circle is above the center of the screen
            {
                ballenx = GetRandomValue(playerSize, screenWidth - playerSize);
                playerSize += 1; // Reset the position of the yellow ball
                balleny = 0; // Reset the y position of the yellow ball
                coinspeed += 0.5;
            }
            //dont think it is neccesary
            // else // If the circle is below the center of the screen, spawn a red ball
            // {
            //     score += 5; // Increment score by 5
            //     playerSize += 3; // Increase player size
            //     ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Reset the position of the red ball
            //     balleny = 0; // Reset the y position of the red ball
            // }
        }

        // Wrap the circles around the screen
        if (balleny > screenHeight + radii1) {
            ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
            balleny = 0;
            score -= 1;
        }

        // Update falling triangles positions
        for (int i = 0; i < maxTriangles; i++) {
            if (triangles[i].active) {
                triangles[i].position.y += triangles[i].speed;
                if (triangles[i].position.y > screenHeight) {
                    triangles[i].position.y = GetRandomValue(-screenHeight, 0);
                    triangles[i].position.x = GetRandomValue(0, screenWidth);
                }
            }
        }

       // Check for collision between the player and a ball
    if (CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ ballenx - radii1, balleny - radii1, radii1 * 2, radii1 * 2 })) {
    // Collision detected
        score += 1;
        ballenx = GetRandomValue(playerSize, screenWidth - playerSize);
        playerSize += 1; // Reset the position of the yellow ball
        balleny = 0; // Reset the y position of the yellow ball
        coinspeed += 0.5;
    }
   


        // Check for collision between the player and the triangles
        for (int i = 0; i < maxTriangles; i++) {
            if (triangles[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ triangles[i].position.x, triangles[i].position.y, triangles[i].base, triangles[i].height })) {
                triangles[i].active = false;
                playerSize -= 1000; // DIE
            }
        }

        if (playerSize <= -10 ){
            ClearBackground(RAYWHITE);
            DrawText("YOU DIED",400,450,50,RED);
            DrawText("PRESS ESC AND RUN ME AGAIN",350,400,20,RED);
        }

        if (score <= -1 ){
            ClearBackground(RAYWHITE);
            DrawText("Quick score more or else you will lose",200,450,30,RED);
        }

        if (score <= -3 ){
            ClearBackground(RAYWHITE);
            DrawText("YOU LOSE",400,450,50,RED);
            DrawText("PRESS ESC AND RUN ME AGAIN",350,400,20,RED);
            CloseWindow();
        }

        if (score >= 20 ){
            ClearBackground(RAYWHITE);
            DrawText("YOU WIN",400,450,50,RED);
            DrawText("PRESS ESC AND RUN ME AGAIN",350,400,20,RED);
        }

        
        BeginDrawing();
            // Draw walls
            DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
            DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
            DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
            DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
            DrawCircle(ballx, bally, playerSize, BLUE); // Player circle
            DrawCircle(ballenx, balleny, radii1, GREEN);
            DrawText(TextFormat("Score: %02i", score), 10, 10, 50, GREEN);
            DrawText(TextFormat("Time to teleport: %02i/%02i", teleportTimer / 60, teleportCooldown), screenWidth - 400, 10, 30, RED);

            // Draw falling triangles
            for (int i = 0; i < maxTriangles; i++) {
                if (triangles[i].active) {
                    DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, triangles[i].color);
                }
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
} 
