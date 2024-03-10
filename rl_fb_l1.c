#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 1000; 
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "FALL BALL LVL:1");
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
    int maxTriangles = 15;
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
        // Teleport player circle to cursor position when space key is pressed and teleport timer is zero
        //not needed as of now
        // if (IsKeyPressed(KEY_SPACE) && teleportTimer <= 0) {
        //     ballx = GetMouseX();
        //     bally = GetMouseY();
        //     teleportTimer = teleportCooldown * 60; // Reset the teleport timer
        //     playerSize += 3; // Increase player size
        // }

        // Update circle positions
        balleny += coinspeed; 
        //nah this code below me aint that  good at working
        // Check for collision between the player and the circles
        if (CheckCollisionCircles((Vector2){ ballx, bally }, playerSize, (Vector2){ ballenx, balleny }, radii1)) {
            score++;
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
        score ++;
        ballenx = GetRandomValue(playerSize, screenWidth - playerSize);
        playerSize += 1; // Reset the position of the yellow ball
        balleny = 0; // Reset the y position of the yellow ball
        coinspeed += 0.5;
    }
   


        // Check for collision between the player and the triangles
        for (int i = 0; i < maxTriangles; i++) {
            if (triangles[i].active && CheckCollisionCircleRec((Vector2){ ballx, bally }, playerSize, (Rectangle){ triangles[i].position.x, triangles[i].position.y, triangles[i].base, triangles[i].height })) {
                triangles[i].active = false;
                playerSize -= 10; // oof
                score -= 1;
            }
        }

        if (playerSize <= 0 ){
            ClearBackground(RAYWHITE);
            DrawText("YOU DIED",400,450,50,RED);
            DrawText("PRESS ESC AND RUN ME AGAIN",350,400,20,RED);
        }

        if (score <= -1 ){
            ClearBackground(RAYWHITE);
            DrawText("Quick score more or else you will lose",200,450,30,RED);
        }

        if (score <= -2 ){
            ClearBackground(RED);
            DrawText("SCORE MORE OR ELSE YOU WILL DIE",100,450,40,WHITE);
        }
 

        if (score <= -3 ){
            ClearBackground(RAYWHITE);
            CloseWindow();
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
            DrawText("Lvl:1",10,100,50,GREEN);

            // Draw falling triangles
            for (int i = 0; i < maxTriangles; i++) {
                if (triangles[i].active) {
                    (DrawTriangle(triangles[i].position, (Vector2){ triangles[i].position.x - triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, (Vector2){ triangles[i].position.x + triangles[i].base / 2, triangles[i].position.y + triangles[i].height }, triangles[i].color));
                }
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
} 


//code for lv 2
// if (IsKeyDown(KEY_DOWN) && bally + playerSize < screenHeight) bally += playerspeed;
//         if (IsKeyDown(KEY_UP) && bally - playerSize > 0) bally -= playerspeed;
