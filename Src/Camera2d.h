#pragma once

#include "raylib.h"
#include "raymath.h"

#define BUILDINGS 100
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void RunCamera2D(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "plataform");

    // posx,posy,w,h
    Rectangle player = {400,280,40,40};
    Rectangle buildings[BUILDINGS] = {0};
    Color colorBuildings[BUILDINGS] = {0};
    int spacing = 0;

    for(int i = 0; i < BUILDINGS; ++i)
    {
        buildings[i].height = (float)GetRandomValue(100,800);
        buildings[i].width = (float)GetRandomValue(50,200);
        buildings[i].x = -6000.f + spacing;
        buildings[i].y = screenHeight - 130.f - buildings[i].height;
        spacing += (int)buildings[i].width;

        colorBuildings[i] = (Color){
                (unsigned char)GetRandomValue(200,240),
                (unsigned char)GetRandomValue(200,240),
                (unsigned char)GetRandomValue(200,250),
                255};
    }
    // Camera
    Camera2D cam = {0};
    cam.target = (Vector2){player.x + 20.f, player.y + 20.f};
    cam.offset = (Vector2){screenWidth/2.0f,screenHeight/2.0f};
    cam.rotation= 0.0f;
    cam.zoom = 1.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if(IsKeyDown(KEY_RIGHT)) player.x += 2;
        if(IsKeyDown(KEY_LEFT)) player.x -=2;

        cam.target = (Vector2){player.x +20,player.y +20};

        // cam rotation control
        if(IsKeyDown(KEY_A)) cam.rotation--;
        else if (IsKeyDown(KEY_D)) cam.rotation++;

        // limit cam rot to 80 grad(-40,40)
        if(cam.rotation > 40) cam.rotation = 40;
        else if (cam.rotation < -40) cam.rotation = -40;

        // cam zoom
        cam.zoom = expf(logf(cam.zoom)+((float)GetMouseWheelMove()*0.1f));
        // reset cam 
        if(IsKeyPressed(KEY_R))
        {
            cam.zoom = 1.0f;
            cam.rotation = 0.0f;
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            BeginMode2D(cam);
            DrawRectangle(-6000,320,13000,8000,DARKGRAY);
            for(int i = 0; i < BUILDINGS; ++i)
            {
                DrawRectangleRec(buildings[i], colorBuildings[i]);
            }
            DrawRectangleRec(player,RED);
            DrawLine((int)cam.target.x,-screenHeight*10,
                            (int)cam.target.x,screenHeight*10,GREEN);
            DrawLine(-screenWidth*10,(int)cam.target.y,
                            screenWidth*10,(int)cam.target.y,GREEN);
            EndMode2D();

            DrawRectangle(0,0,screenWidth,5,RED);
            DrawRectangle(0,5,5,screenHeight - 10,RED);
            DrawRectangle(screenWidth -5,5,5,screenHeight -10,RED);
            DrawRectangle(0,screenHeight-5,screenWidth,5,RED);

            DrawRectangle(10,10,250,113,Fade(SKYBLUE,0.5f));
            DrawRectangleLines(10,10,250,113,BLUE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}
