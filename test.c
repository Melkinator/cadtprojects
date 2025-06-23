#include "raylib.h"

#define MAX_ITEM_NAME 50

typedef struct {
    char name[MAX_ITEM_NAME];
    float price;
    int quantity;
} GroceryItem; 

bool clickGrocery = false;
bool clickView = false;
bool clickFruits = false;
int max_items = 3;
int max_fruits = 2;
int mouseHover=-1;

int main() {
    int height = 900;
    int width = 1200;

    InitWindow(width, height, "Grocery Management System");
    SetTargetFPS(60);

    char *fruitNames[] = {"Apple", "Banana"};
    char *items[] = {"Vegetables", "Fruits", "Meat"};

    Rectangle button[max_items];
    Rectangle fruits[max_fruits];
    Rectangle grocery = {20,10,200,50};
    Rectangle view = {240,10,200,50};

    Vector2 mouse = {0.0f, 0.0f};

    while (!WindowShouldClose()) {
        mouse = GetMousePosition();
        ClearBackground(RAYWHITE);
        for (int i=0;i<max_items;i++) {
            button[i] = (Rectangle){20.0f, (float)(70+64*i), 200.0f, 50.0f};
        }

        for (int i=0;i<max_fruits;i++) {
            fruits[i] = (Rectangle){240.0f, (float)(70+64*i), 200.0f, 50.0f};
        }

        for (int i=0;i<max_items;i++) {
            if (CheckCollisionPointRec(mouse, button[i])) {
                mouseHover = i;
            }
        }

        BeginDrawing();
        DrawRectangleRec(grocery, GRAY);
        DrawText("Grocery", grocery.x+15, grocery.y+15, 25, WHITE);

        DrawRectangleRec(view, GRAY);
        DrawText("View", view.x+15, view.y+15, 25, WHITE);
        
        // Clicking different buttons
        if (CheckCollisionPointRec(mouse, grocery)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            clickGrocery = true;
            clickView = false;
        }

        // Clicking different buttons
        if (CheckCollisionPointRec(mouse, view)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            clickGrocery = false;
            clickView = true;
        }

        for (int i=0;i<max_fruits;i++) {
            if (CheckCollisionPointRec(mouse, button[1])&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                clickFruits = true;
            }
        }
        
        // Make new buttons to click on if true
        if (clickGrocery) {
            for (int i=0;i<max_items;i++) {
                DrawRectangleRec(button[i], (mouseHover == i) ? SKYBLUE : GRAY);
                DrawText(items[i], button[i].x+15, button[i].y+15, 25, WHITE);
            }
            if (CheckCollisionPointRec(mouse, grocery)&&IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                clickGrocery = false; // Doesn't appear anymore if you right click
            }
        }
        if (clickFruits) {
            for (int i=0;i<max_fruits;i++) {
                DrawRectangleRec(fruits[i], (mouseHover == i) ? SKYBLUE : GRAY);
                DrawText(fruitNames[i], fruits[i].x+15, fruits[i].y+15, 25, WHITE);
            }
        }
        EndDrawing();
    }
    CloseWindow();
}
