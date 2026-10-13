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
    const int MaxFPS = 60;
    const Vector2 centerScreen = (Vector2){screenW/2,screenH/2};
    InitWindow(screenW,screenH,"Screen Manager");
    Gamescreen currentScreen = LOGO;
    int frameCounter = 0;
    SetTargetFPS(MaxFPS);
    float rotation = 0;
    int waitInMiliseconds = 360;
    while(!WindowShouldClose())
    {
        rotation +=0.2;
        switch (currentScreen)
        {
        case LOGO:
            // show logo
            frameCounter++;
            if(frameCounter > waitInMiliseconds || IsKeyPressed(KEY_ENTER)) currentScreen = TITLE;
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
            DrawEllipse(centerScreen.x+rotation,centerScreen.y,300+sin(rotation),250.f,(Color){200,100,50,75});
            DrawText("LOGO SCREEN",centerScreen.x,centerScreen.y,28,BLUE);
            DrawText(TextFormat("Wait for %d seconds",waitInMiliseconds/60),centerScreen.x,centerScreen.y+40,20,DARKBLUE);
            break;
        }
        case TITLE:
        {
            DrawRectangle(0,0,screenW,screenH,DARKBLUE);
            DrawLineBezier(centerScreen,(Vector2){screenW*sin(rotation),screenH+cos(frameCounter)},5,DARKGRAY);
            DrawLineBezier(centerScreen,(Vector2){screenW*cos(rotation),screenH+sin(frameCounter)},5,DARKGRAY);
            DrawLineBezier(centerScreen,(Vector2){screenW*sin(rotation),screenH+10+cos(frameCounter)},5,WHITE);
            DrawText("TITLE SCREEN",30,centerScreen.y-50,60,WHITE);
            DrawText("Press Enter to play",centerScreen.x,centerScreen.y+40,20,DARKGRAY);
            break;
        }
        case GAMEPLAY:
        {
            DrawRectangle(0,0,screenW,screenH,DARKGRAY);
            DrawText("Gameplay SCREEN",30,centerScreen.y,40,GREEN);
            DrawText("Press Enter to play",centerScreen.x,centerScreen.y+40,20,DARKGREEN);
            break;
        }
        case ENDING:
        {
            DrawRectangle(0,0,screenW,screenH,RAYWHITE);
            DrawText("ENDING SCREEN",centerScreen.x,centerScreen.y,108,BLACK);
            DrawText("Press Enter to play",centerScreen.x,centerScreen.y+10,20,DARKGRAY);
            break;
        }
        default:
            break;
        }
    EndDrawing();
    }
    CloseWindow();
}