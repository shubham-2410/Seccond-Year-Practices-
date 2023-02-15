#include<iostream>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

int main(){
    cout<<"Enter the number of vertices of Polygon : ";
    int v ;
    cin>>v;

    int a[v+1][2];
    for(int i=0 ;i<n;i++){
        cout<<"Enter the coordinates of "<<i+1<<" vertex of polygon (x,y) : ";
        cin>>a[i][0]<<a[i][1];
    }
    a[v][0]=a[0][0];
    a[v][1]=a[0][1];

    int gd=DETECT , gm;
    initgraph(&gd , &gm , NULL);

    setcolor(YELLOW);
    for(int i=0 ;i<v ;i++){
        line(a[i][0], a[i][1], a[i+1][0] , a[i+1][1]);
    }

    float slp[v];
    for(int i=0 ;i<v ;i++){
        float dx ,dy;
        dy=(a[i+1][1]-a[i][1]);
        dx=(a[i+1][0]- a[i][0]);
        if(dx==0) slp[i]=0;
        else if (dy==0) slp[i]=1;
        else slp[i]=(float)dx/dy;
    }

    int xi[20];
    for(int y=0 ;y<=480 ;y++){
        int k=0;
        // Intersecting points
        for(int i=0 ;i<v ;i++){
            if((a[i][1]<=y && a[i+1][1]>y) || (a[i][1]>y && a[i+1][1]<=y)){
                xi[k]=(int)(a[i][0]+slp[i]*(y-a[i][1]))
                k++;
            }
        }

        // sorting()
        for(int i=0 ;i<v-1 ;i++){
            for(int j=0 ;j<v-1 ;j++){
                int temp=xi[j];
                xi[j]=xi[j+1];
                x[j+1]=temp;
            }
        }

        setcolor(YELLOW);
        for(int i=0 ;i<k ;i=i+2){
            line(xi[i],y,xi[i+1]+1,y);
            delay(500);
        }
    }
    closegraph();
    return 0;
}