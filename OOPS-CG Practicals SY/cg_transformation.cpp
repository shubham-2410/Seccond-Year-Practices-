#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

void Input(float arr[][3],int n){
    cout<<"\nEnter the co-ordinates in clockwise order \n";
    for(int i=0 ; i<n ;i++){
        cout<<"Enter the co-ordinates of "  << i+1<<" vertex (x,y) : ";
        for( int j=0;j<=1;j++){
            cin>>arr[i][j];
        }
        arr[i][2]=1;
    }
}
void display(float arr[][3] ,int n){
    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<3 ;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}
int multi(float a1[][3] , float a2[3][3], float arr[][3],int n){
    for(int i=0 ;i <n ;i++){
        for(int j=0 ;j<3 ;j++){
            for(int k=0 ;k<3;k++){
                arr[i][j]=arr[i][j]+(a1[i][k] * a2[k][j]);
            }
        }
    }
}
int main(){
    cout<<"Enter the number of vertices of Polygon : ";
    int m;
    cin>>m;

    float a[m][3];
    Input(a,m);
    display(a,m);

    float  tx,ty , sx , sy ;
    float ang;

    float f[m][3]={0};
    // float b[3][3]={1,0,0,0,1,0,0,0,1};
    float r[3][3];
    float t[3][3];
    float s[3][3];
    cout<<"\n\t1.Translation\n\t2.Scaling\n\t3.Rotation\n";
    int c;
    cout<<"Enter your choice : ";
    cin>>c;
    
    switch(c){
        case 1:
            // int tx , ty;
            cout<<"Enter translation factor\n";
            cout<<"tx : ";
            cin>>tx;
            t[0][0]=1;
            t[0][1]=0;
            t[0][2]=0;
            t[1][0]=0;
            cout<<"ty : ";
            cin>>ty;
            t[1][1]=1;
            t[1][2]=0;
            t[2][0]=tx;
            t[2][1]=ty;
            t[2][2]=1;
            multi(a,t,f,m);
            display(t,m);
            break;
        case 2:
            // int sx , sy;
            cout<<"Enter the Scaling factor\n";
            cout<<"sx : ";
            cin>>sx;
            s[0][0]=sx;
            s[0][1]=0;
            s[0][2]=0;
            s[1][0]=0;
            cout<<"sy : ";
            cin>>sy;
            s[1][1] =sy;
            s[1][2]=0;
            s[2][0]=0;
            s[2][1]=0;
            s[2][2]=1;
            multi(a,s,f,m);
            display(f,m);
            break;
        case 3:
            // int ang;
            cout<<"Enter the Angle of rotation(in rad) : ";
            cin>>ang;
            ang=ang*(3.14/180.0);
            r[0][0]=cos(ang);
            r[0][1]=-sin(ang);
            r[0][2]=0;
            r[1][0]=sin(ang);
            r[1][1]=cos(ang);
            r[1][2]=0;
            r[2][0]=0;
            r[2][1]=0;
            r[2][2]=1;
            multi(a,r,f,m);
            display(f,m);
            break;
        default:
            break;
    }
    int gd=DETECT , gm ;
    initgraph(&gd , &gm ,NULL);
    
    int j=0;
    for(int i=0 ;i<m ;i++){
            line(a[i][j] , a[i][j+1], a[((i+1)%m)][j] , a[((i+1)%m)][j+1] );
    }
    delay(10000);
    cleardevice();
    for(int i=0 ;i<m ;i++){
            line(f[i][j] , f[i][j+1], f[((i+1)%m)][j] , f[((i+1)%m)][j+1] );
    }
    delay(4000);
    getch();
    closegraph();
    return 0;
}