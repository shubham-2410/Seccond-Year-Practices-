#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int LINE(float a1, float b1, float a2, float b2)
{
    float step, da, db, a, b;
    da = (a2 - a1);
    db = (b2 - b1);

    if (da > db)
        step = da;
    else
        step = db;

    da = (da / step);
    db = (db / step);

    a = a1;
    b = b1;

    int i = 1;
    while (i <= step)
    {
        putpixel(a, b, 5);
        a += da;
        b += db;
        i += 1;
        delay(10);
    }
    return 0;
}
void Display(int x1, int y1, int x, int y)
{

    putpixel(x + x1, y + y1, WHITE);
    putpixel(x + x1, y - y1, WHITE);
    putpixel(x - x1, y + y1, WHITE);
    putpixel(x - x1, y - y1, WHITE);
    putpixel(x + y1, y + x1, WHITE);
    putpixel(x + y1, y - x1, WHITE);
    putpixel(x - y1, y + x1, WHITE);
    putpixel(x - y1, y - x1, WHITE);
}
void Bres_circle(int x, int y, int rad)
{
    int y1 = rad;
    int x1 = 0;
    int s = 3 - 2 * rad;
    while (x1 <= y1)
    {
        if (s < 0)
            s = s + 4 * x1 + 6;
        else
        {
            s = s + 4 * (x1 - y1) + 10;
            y1--;
        }
        x1++;
        Display(x1, y1, x, y);
        delay(10);
    }
}

int main()
{

    int gd = DETECT, gm, i;
    int a, b, r;

    initgraph(&gd, &gm, NULL);

    LINE(100, 100, 200, 100); // Co-ordiantes for parallelogram
    LINE(200, 100, 200, 200);
    LINE(100, 100, 100, 200);
    LINE(100, 200, 200, 200);

    LINE(150, 100, 200, 150); // co-ordinates for trapazium
    LINE(150, 100, 100, 150);
    LINE(100, 150, 150, 200);
    LINE(150, 200, 200, 150);

    Bres_circle(150, 150, 35); // Drawing Circle

    delay(1000);
    closegraph();
    return 0;
}