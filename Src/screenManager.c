#pragma once
#include "raylib.h"

typedef enum Gamescreen
{
    LOGO = 0,
    TITLE,
    GAMEPLAY,
    ENDING
}Gamescreen;

void ScreenManager(void)
{
    const int screenW = 800;
    const int screenH = 450;

    InitWindow(screenW,screenH,"Screen Manager");
    Gamescreen currentScreen = LOGO;
    int frameCounter = 0;
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case LOGO:
            // show logo
            frameCounter++;
            if(frameCounter > 120) currentScreen = TITLE;
            break;
        case TITLE:
            // show Title
            if(IsKeyPressed(KEY_ENTER)) currentScreen = GAMEPLAY;
            break;
        case GAMEPLAY:
            // show Gameplay
            if(IsKeyPressed(KEY_ENTER)) currentScreen = ENDING;
            break;
        case ENDING:
            // show ending 
            if(IsKeyPressed(KEY_ENTER)) currentScreen = TITLE;
            break;
        default:
            break;
        }

    BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentScreen)
        {
        case LOGO:
        {  
            DrawText("LOGO SCREEN",screenW/2,screenH/2,48,BLUE);
            DrawText("Wait for 2 seconds",screenW/2,screenH/2+10,20,DARKBLUE);
            break;
        }
        case TITLE:
        {
            DrawRectangle(0,0,screenW,screenH,DARKBLUE);
            DrawText("TITLE SCREEN",screenW/2,screenH/2,108,WHITE);
            DrawText("Press Enter to play",screenW/2,screenH/2+10,20,DARKGRAY);
            break;
        }
        case GAMEPLAY:
        {
            DrawRectangle(0,0,screenW,screenH,DARKGRAY);
            DrawText("Gameplay SCREEN",screenW/2,screenH/2,108,GREEN);
            DrawText("Press Enter to play",screenW/2,screenH/2+10,20,DARKGREEN);
            break;
        }
        case ENDING:
        {
            DrawRectangle(0,0,screenW,screenH,RAYWHITE);
            DrawText("ENDING SCREEN",screenW/2,screenH/2,108,BLACK);
            DrawText("Press Enter to play",screenW/2,screenH/2+10,20,DARKGRAY);
            break;
        }
        default:
            break;
        }
    EndDrawing();
    }
    CloseWindow();
}