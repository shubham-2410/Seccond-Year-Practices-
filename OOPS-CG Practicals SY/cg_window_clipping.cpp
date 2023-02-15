#include <iostream>
#include <graphics.h>
using namespace std;

int xmin, xmax, ymax, ymin;

void window(int a[4][2])
{
    cout << "Enter the (xmin , xmax , ymin , ymax ) of the window : ";
    cin >> xmin >> xmax >> ymin >> ymax;
    cout << "Input Taken Successsfully \n";
    a[0][0] = xmin;
    a[0][1] = ymax;
    a[1][0] = xmax;
    a[1][1] = ymax;
    a[2][0] = xmax;
    a[2][1] = ymin;
    a[3][0] = xmin;
    a[3][1] = ymin;
}
void display(int a[4][2])
{
    cout << "Coordinates of window are\n";
    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << a[i][j] << ' ' << a[i][j + 1] << endl;
    }
}

int getcode(float x, float y)
{
    int left = 1, right = 2, top = 8, bottom = 4;
    int code = 0;

    if (x < xmin)
        code = code | left;
    else if (x > xmax)
        code = code | right;

    if (y < ymin)
        code = code | bottom;
    else if (y > ymax)
        code = code | top;

    return code;
}

void clipping(float x1, float y1, float x2, float y2, int a[4][2])
{

    for (int i = 0; i < 4; i++)
    {
        line(a[i][0], a[i][1], a[(i + 1) % 4][0], a[(i + 1) % 4][1]);
    }
    line(x1, y1, x2, y2);
    delay(4000);
    cleardevice();
    int code1 = getcode(x1, y1);
    int code2 = getcode(x2, y2);

    float m = (y2 - y1) / (x2 - x1);
    while (true)
    {
        if (code1 == 0 && code2 == 0)
        {
            cout << "Line is completely inside the window \n";
            break;
        }
        else if ((code1 & code2) != 0)
        {
            cout << "Line is completely outside the window\n";
            break;
        }
        else{
            float x, y;
            int code;

            if (code1 != 0)
                code = code1;
            else
                code = code2;

            if (code & 8)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (code & 4)
            {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (code & 2)
            {
                y = y1 + (xmax - x1) * m;
                x = xmax;
            }
            else if (code & 1)
            {
                y = y1 + (xmin - x1) * m;
                x = xmin;
            }

            if (code == code1)
            {
                x1 = x;
                y1 = y;
                code1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = getcode(x2, y2);
            }
        }
        
        cout<<x1<<y1<<" "<<x2<<y2<<endl;
        for (int i=0 ;i<4 ;i++){
            line(a[i][0] ,a[i][1] , a[(i+1)%4][0] , a[(i+1)%4][1]);
        }
        line(x1, y1, x2, y2);
        delay(4000);
        return;
    }
}

int main()
{
    int arr[4][2];
    window(arr);
    display(arr);

    float x1, y1, x2, y2;
    cout << "Enter the coordinates of line (x1,y1,x2,y2) : ";
    cin >> x1 >> y1 >> x2 >> y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    clipping(x1, y1, x2, y2, arr);
    closegraph();
    return 0;
}