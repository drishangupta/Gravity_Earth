#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <math.h>
#include <vector>
double G = 6.67430*(pow(10,-11));
double gravity = 0.2725;
Color background = {65,74,76,255};

class Planet{
    
    public:
    std::vector<float> velocity = {0.0f,0.0f};
    double mass;
    double radius;
    Vector2 pos;
    
    Planet(double m, float vx, float vy, double r, Vector2 p )
    {
        mass=m;
        velocity[0]=vx;
        velocity[1]=vy;
        radius=r;
        pos=p;

    }

    void Draw()
    {
        DrawCircle(pos.x,pos.y,radius,BLUE);
    }
    void Update()
    {   
        velocity[1] += gravity;
        pos.x += velocity[0];
        pos.y += velocity[1];

        const int screenWidth = GetScreenWidth();
        const int screenHeight = GetScreenHeight();

        if (pos.x + radius >= screenWidth) {
            pos.x = screenWidth - radius;
            velocity[0] *= -0.95;
        }
        if (pos.x - radius <= 0) {
            pos.x = radius;
            velocity[0] *= -0.95;
        }
        
        // Y-axis bounce
        if (pos.y + radius >= screenHeight) {
            pos.y = screenHeight - radius;
            velocity[1] *= -0.95;
        }
        if (pos.y - radius <= 0) {
            pos.y = radius;
            velocity[1] *= -0.95;
        }
        
    }
    
};

int main() 
{
  InitWindow(800.0f,800.0f,"Gravity Simulation");
  SetTargetFPS(60);
  Planet planet(600.0, 100,-10,80,{250,250}); 
  Planet planet2(600.0, 0,0,50,{400,400}); 
  while(!WindowShouldClose())
  {
    planet.Update();
    planet2.Update();
    BeginDrawing();

    ClearBackground(background);
    planet.Draw();
    planet2.Draw();
    EndDrawing();


  }
}