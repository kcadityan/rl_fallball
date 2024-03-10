// #include "raylib.h"
// #include "raymath.h"

// #define MAX_SQUARES 100

// int main(void)
// {
//     int sqhp = 5;
//     const int screenWidth = 1000; 
//     const int screenHeight = 1000;
//     InitWindow(screenWidth, screenHeight, "FALL BALL LVL:2");
//     int playerSize = 50; // Initial size of the player
//     int radii1 = 20;
//     int score = 0;
//     int ballx = 500;
//     int bally = 900;
//     int ballenx = GetRandomValue(playerSize, screenWidth - playerSize); // Ensure ballenx doesn't spawn within the walls
//     int balleny = GetRandomValue(0, 0); // Initial y position is 0
//     float coinspeed = 5;
//     int playerspeed = 5;
//     int dropInterval = 5; // Interval for dropping new circles (in seconds)
//     int timer = 0; // Timer to keep track of elapsed time
//     int teleportCooldown = 10; // Cooldown time for teleportation (in seconds)
//     int teleportTimer = teleportCooldown * 60; // Timer for teleportation cooldown
//     int newCircleInterval = 10 * 60; // Interval for spawning a new circle (in frames)
//     int newCircleTimer = 0; // Timer to keep track of elapsed time for spawning a new circle
//     int wallThickness = 70; // Thickness of the walls
//     int squareSize = 70; // Size of the square to be placed above the player
//     bool squaresActive[MAX_SQUARES] = { false }; // Whether each square is active or not
//     Rectangle squares[MAX_SQUARES] = { 0 }; // Initialize the squares' positions and sizes

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
//     int maxTriangles = 50;
//     FallingTriangle triangles[maxTriangles];

//     for (int i = 0; i < maxTriangles; i++) {
//         triangles[i].position.x = GetRandomValue(0, screenWidth);
//         triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//         triangles[i].base = 30;
//         triangles[i].height = 30;
//         triangles[i].speed = GetRandomValue(2, 5);
//         triangles[i].color = RED;
//         triangles[i].active = true;
//     }

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {

//         ClearBackground(BLACK);
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

//         // Place square above player when space bar is pressed
//         if (IsKeyPressed(KEY_SPACE)) {
//             for (int i = 0; i < MAX_SQUARES; i++) {
//                 if (!squaresActive[i]) {
//                     squares[i].x = ballx - squareSize / 2;
//                     squares[i].y = bally - playerSize - squareSize;
//                     squares[i].width = squareSize;
//                     squares[i].height = squareSize;
//                     squaresActive[i] = true;
//                     break;
//                 }
//             }
//         }

//         // Apply physics to falling triangles
//         for (int i = 0; i < maxTriangles; i++) {
//             if (triangles[i].active) {
//                 triangles[i].position.y += triangles[i].speed;
//                 if (triangles[i].position.y > screenHeight) {
//                     triangles[i].position.y = GetRandomValue(-screenHeight, 0);
//                     triangles[i].position.x = GetRandomValue(0, screenWidth);
//                 }
//             }
//         }

//         // Check for collision between the falling triangles and the squares
//         for (int i = 0; i < maxTriangles; i++) {
//             for (int j = 0; j < MAX_SQUARES; j++) {
//                 if (triangles[i].active && squaresActive[j] && CheckCollisionRecs((Rectangle){ triangles[i].position.x, triangles[i].position.y, triangles[i].base, triangles[i].height }, squares[j])) {
//                     triangles[i].active = false;
//                     sqhp -= 1;
//                 }
//             }
//         }


//         BeginDrawing();
//             // Draw walls
//             DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
//             DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
//             DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
//             DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
//             DrawCircle(ballx, bally, playerSize, BLUE); // Player circle

//             // Draw falling triangles
//             for (int i = 0; i < maxTriangles; i++) {
//                 if (triangles[i].active) {
//                     DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, triangles[i].color);
//                 }
//             }

//             // Draw squares if active
//             for (int i = 0; i < MAX_SQUARES; i++) {
//                 if (squaresActive[i]) {
//                     DrawRectangleRec(squares[i], WHITE);
//                 }
//             }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// } 




#include "raylib.h"
#include "raymath.h"

#define MAX_SQUARES 100
#define MAX_BALLS 10

int main(void)
{
    int sqhp = 5;
    const int screenWidth = 1000; 
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "FALL BALL LVL:2");
    int playerSize = 50; // Initial size of the player
    int radii1 = 20;
    int score = 0;
    int ballx = 500;
    int bally = 900;
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
    int squareSize = 70; // Size of the square to be placed above the player
    bool squaresActive[MAX_SQUARES] = { false }; // Whether each square is active or not
    Rectangle squares[MAX_SQUARES] = { 0 }; // Initialize the squares' positions and sizes

    // Falling Triangle structure
    typedef struct FallingTriangle {
        Vector2 position;
        float base;
        float height;
        float speed;
        Color color;
        bool active;
    } FallingTriangle;

    // Falling Ball structure
    typedef struct FallingBall {
        Vector2 position;
        float radius;
        float speed;
        Color color;
        bool active;
    } FallingBall;

    // Falling triangles setup
    int maxTriangles = 50;
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

    // Falling balls setup
    int maxBalls = 10;
    FallingBall balls[MAX_BALLS];

    for (int i = 0; i < maxBalls; i++) {
        balls[i].position.x = GetRandomValue(0, screenWidth);
        balls[i].position.y = GetRandomValue(-screenHeight, 0);
        balls[i].radius = 10;
        balls[i].speed = GetRandomValue(2, 5);
        balls[i].color = GREEN;
        balls[i].active = true;
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

        // Place square above player when space bar is pressed
        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 0; i < MAX_SQUARES; i++) {
                if (!squaresActive[i]) {
                    squares[i].x = ballx - squareSize / 2;
                    squares[i].y = bally - playerSize - squareSize;
                    squares[i].width = squareSize;
                    squares[i].height = squareSize;
                    squaresActive[i] = true;
                    break;
                }
            }
        }

        // Apply physics to falling triangles
        for (int i = 0; i < maxTriangles; i++) {
            if (triangles[i].active) {
                triangles[i].position.y += triangles[i].speed;
                if (triangles[i].position.y > screenHeight) {
                    triangles[i].position.y = GetRandomValue(-screenHeight, 0);
                    triangles[i].position.x = GetRandomValue(0, screenWidth);
                }
            }
        }

        // Apply physics to falling balls
        for (int i = 0; i < maxBalls; i++) {
            if (balls[i].active) {
                balls[i].position.y += balls[i].speed;
                if (balls[i].position.y > screenHeight) {
                    balls[i].position.y = GetRandomValue(-screenHeight, 0);
                    balls[i].position.x = GetRandomValue(0, screenWidth);
                }
            }
        }

        // Check for collision between the player and squares
        for (int i = 0; i < MAX_SQUARES; i++) {
            if (squaresActive[i] && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, squares[i])) {
                ballx = ballx- 1;
                bally = bally - 1;
            }
        }

        // Check for collision between the player and falling triangles
        for (int i = 0; i < maxTriangles; i++) {
            if (triangles[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ triangles[i].position.x, triangles[i].position.y, triangles[i].base, triangles[i].height })) {
                // Handle collision between player and triangle
                // For now, let's just reset the player position
                score -= 1;
                playerSize -= 10;
            }
        }

        // Check for collision between the player and falling balls
        for (int i = 0; i < maxBalls; i++) {
            if (balls[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ balls[i].position.x - balls[i].radius, balls[i].position.y - balls[i].radius, balls[i].radius * 2, balls[i].radius * 2 })) {
                // Handle collision between player and ball
                // For now, let's just reset the player position
                score += 1;
                playerSize += 1;
            }
        }

        // Check for collision between the falling triangles and the squares
        for (int i = 0; i < maxTriangles; i++) {
            for (int j = 0; j < MAX_SQUARES; j++) {
                if (triangles[i].active && squaresActive[j] && CheckCollisionRecs((Rectangle){ triangles[i].position.x, triangles[i].position.y, triangles[i].base, triangles[i].height }, squares[j])) {
                    triangles[i].active = false;
                    sqhp -= 1;
                }
            }
        }


        BeginDrawing();
            // Draw walls
            DrawRectangle(0, 0, screenWidth, wallThickness, GRAY); // Top wall
            DrawRectangle(0, screenHeight - wallThickness, screenWidth, wallThickness, GRAY); // Bottom wall
            DrawRectangle(0, 0, wallThickness, screenHeight, GRAY); // Left wall
            DrawRectangle(screenWidth - wallThickness, 0, wallThickness, screenHeight, GRAY); // Right wall
            DrawCircle(ballx, bally, playerSize, BLUE); // Player circle

            // Draw falling triangles
            for (int i = 0; i < maxTriangles; i++) {
                if (triangles[i].active) {
                    DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, triangles[i].color);
                }
            }

            // Draw falling balls
            for (int i = 0; i < maxBalls; i++) {
                if (balls[i].active) {
                    DrawCircleV(balls[i].position, balls[i].radius, balls[i].color);
                }
            }

            // Draw squares if active
            for (int i = 0; i < MAX_SQUARES; i++) {
                if (squaresActive[i]) {
                    DrawRectangleRec(squares[i], WHITE);
                }
            }

            // Draw score
            DrawText(TextFormat("Score: %02i", score), 10, 10, 20, GREEN);
            // Draw square HP
            DrawText(TextFormat("Square HP: %02i", sqhp), 10, 40, 20, GREEN);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}


