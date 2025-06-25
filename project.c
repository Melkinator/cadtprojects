#include "raylib.h"

#define MAX_ITEM_NAME 50

bool clickGrocery = false;
bool clickView = false;
bool clickFruits = false;
bool saveEyes = false;
bool addItem = false;
bool addAmount = false;
bool removeAmount = false;
bool prompt = false;
int max_items = 3;
int max_fruits = 2;
int max_prompts = 3;
int mouseHover1=-1;
int mouseHover2=-1;
int clickProcess=-1;

typedef struct {
    char name[MAX_ITEM_NAME];
    float price;
    int quantity;
} GroceryItem; 

int main() {
    const int height = 900;
    const int width = 1200;

    InitWindow(width, height, "Grocery Management System");
    SetTargetFPS(60);

    char *fruitNames[] = {"Apple", "Banana"};
    char *items[] = {"Vegetables", "Fruits", "Meat"};
    char *prompts[] = {"Add Amount", "Remove Amount", "Delete Item"};

    Rectangle button[max_items];
    Rectangle fruits[max_fruits];
    Rectangle promptButtons[max_prompts];
    Rectangle grocery = {20,10,200,50};
    Rectangle view = {240,10,200,50};

    Vector2 mouse = {0.0f, 0.0f};

    while (!WindowShouldClose()) {
        mouse = GetMousePosition();
        if (IsKeyPressed(KEY_P)) {
            if (saveEyes) {
                saveEyes = 0;
            } else {
                saveEyes = 1;
            }
        }
        if (saveEyes) {
            ClearBackground(BLACK);
        } else {
            ClearBackground(WHITE);
        }
        for (int i=0;i<max_items;i++) {
            button[i] = (Rectangle){20.0f, (float)(80+64*i), 200.0f, 50.0f};
            if (CheckCollisionPointRec(mouse, button[i])) mouseHover1 = i;
        }

        for (int i=0;i<max_fruits;i++) {
            fruits[i] = (Rectangle){240.0f, (float)(80+64*i), 200.0f, 50.0f};
            if (CheckCollisionPointRec(mouse, fruits[i])) mouseHover2=i;
        }

        for (int i=0;i<3;i++) {
            promptButtons[i] = (Rectangle){460.0f, (float)(80+64*i), 210.0f, 50.0f};
        }

        BeginDrawing();
        DrawRectangle(10,5,1180,60, LIGHTGRAY);
        DrawRectangle(10,70,218,820, LIGHTGRAY);
        DrawRectangle(230,70,960,820, LIGHTGRAY);

        DrawText("Press P to enable light/dark mode.", 830, 0, 20, GREEN);

        DrawRectangleRec(grocery, GRAY);
        DrawText("Grocery", grocery.x+15, grocery.y+15, 25, WHITE);

        DrawRectangleRec(view, GRAY);
        DrawText("View", view.x+15, view.y+15, 25, WHITE);
        
        // Clicking different buttons
        if (CheckCollisionPointRec(mouse, grocery)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            clickGrocery = true;
            clickView = false;
        }

        if (CheckCollisionPointRec(mouse, view)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            clickGrocery = false;
            clickView = true;
        }

        if (CheckCollisionPointRec(mouse, button[1])&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            clickFruits = true;
        }
        
        for (int i=0;i<max_fruits;i++) {
            if (CheckCollisionPointRec(mouse, fruits[i])&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                prompt = true;
                clickProcess = i;
            }
        }

        // Make new buttons to click on if true
        if (clickGrocery) {
            for (int i=0;i<max_items;i++) {
                DrawRectangleRec(button[i], (mouseHover1 == i) ? SKYBLUE : GRAY);
                DrawText(items[i], button[i].x+15, button[i].y+15, 25, WHITE);
            }
            if (CheckCollisionPointRec(mouse, grocery)&&IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                clickGrocery = false; // Doesn't appear anymore if you right click
                clickFruits = false;
                prompt = false;
            }
        }
        if (clickFruits) {
            for (int i=0;i<max_fruits;i++) {
                DrawRectangleRec(fruits[i], (mouseHover2 == i) ? RED : GRAY);
                DrawText(fruitNames[i], fruits[i].x+15, fruits[i].y+15, 25, WHITE);
            }
            if (CheckCollisionPointRec(mouse, button[1])&&IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                clickFruits = false;
                prompt = false;
            }
        }
        if (prompt) {
            for (int i=0;i<3;i++) {
                DrawRectangleRec(promptButtons[i], GRAY);
                DrawText(prompts[i], promptButtons[i].x+15, promptButtons[i].y+15, 25, WHITE);
            }
            if (CheckCollisionPointRec(mouse, fruits[clickProcess])&&IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                prompt = false;
            }
        }
        EndDrawing();
    }
    CloseWindow();
}
