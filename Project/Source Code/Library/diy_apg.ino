#include <Pattern.h>

Pattern pattern;

int d[]={0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
int c[]={0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
int b[]={0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
int a[]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
int receivedint;
boolean newData = false;
/*
 pin 22-29 column x a0-a7
 pin 30-37 row y  a8-a15
 pin 38-45 data d0-d15
 pin 48-51 control
 a=msb
 d=lsb
 c1=46
 c2=47
 we=49
 re=48
 */
void setup() {
  Serial.begin(9600);
  Serial.println("choose the following:\n0) Background Zero \n1) Background One \n2) CheckerBoard Pattern \n4) Read");
 //control
 for(int t=46;49>=t;t++)
 {
  pinMode(t,OUTPUT);
  }
//address
 for(int q=22;37>=q;q++)
 {
  pinMode(q,OUTPUT);
  }
}

void loop() {

 recvOneChar();
 delay(1);
 showNewData();
}



void checkerboard()
{
  digitalWrite(49,1);
  for(int y=0; y<=15;y++)
{
  for(int yy=0; yy<=15;yy++)
  { 
  digitalWrite(37,a[y]);
  digitalWrite(36,b[y]);
  digitalWrite(35,c[y]);
  digitalWrite(34,d[y]);
  digitalWrite(33,a[yy]);
  digitalWrite(32,b[yy]);
  digitalWrite(31,c[yy]);
  digitalWrite(30,d[yy]);
                            for(int x=0; x<=15;x++)
                            { 
                              for(int xx=0; xx<=15;xx++)
                              {
 
                              
                                digitalWrite(29,a[x]);
                                digitalWrite(28,b[x]);
                                digitalWrite(27,c[x]);
                                digitalWrite(26,d[x]);
                                digitalWrite(25,a[xx]);
                                digitalWrite(24,b[xx]);
                                digitalWrite(23,c[xx]);
                                digitalWrite(22,d[xx]);
                            if((xx%2 == 0 && yy%2 == 0) || (xx%2 == 1 && yy%2 == 1))
                              {
                                for(int k=38;k<=45;k++)
                                { 
                                  digitalWrite(k,1);
                                  
                                }
                              }
                              else
                              {
                                for(int z=38;z<=45;z++)
                                {
                                  digitalWrite(z,0);
                                  
                                }
                                }
                                control_write();
                                digitalWrite(49,1);
                            }
                          }
}
}


digitalWrite(37,a[0]);
  digitalWrite(36,b[0]);
  digitalWrite(35,c[0]);
  digitalWrite(34,d[0]);
  digitalWrite(33,a[0]);
  digitalWrite(32,b[0]);
  digitalWrite(31,c[0]);
  digitalWrite(30,d[0]);
                                digitalWrite(29,a[0]);
                                digitalWrite(28,b[0]);
                                digitalWrite(27,c[0]);
                                digitalWrite(26,d[0]);
                                digitalWrite(25,a[0]);
                                digitalWrite(24,b[0]);
                                digitalWrite(23,c[0]);
                                digitalWrite(22,d[0]);

}

  
void bg0()
{digitalWrite(49,1);
  for(int y=0; y<=15;y++)
{
  for(int yy=0; yy<=15;yy++)
  { 
  digitalWrite(37,a[y]);
  digitalWrite(36,b[y]);
  digitalWrite(35,c[y]);
  digitalWrite(34,d[y]);
  digitalWrite(33,a[yy]);
  digitalWrite(32,b[yy]);
  digitalWrite(31,c[yy]);
  digitalWrite(30,d[yy]);
                            for(int x=0; x<=15;x++)
                            { 
                              for(int xx=0; xx<=15;xx++)
                              {
 
                              
                                digitalWrite(29,a[x]);
                                digitalWrite(28,b[x]);
                                digitalWrite(27,c[x]);
                                digitalWrite(26,d[x]);
                                digitalWrite(25,a[xx]);
                                digitalWrite(24,b[xx]);
                                digitalWrite(23,c[xx]);
                                digitalWrite(22,d[xx]);
                              
                                for(int m=38;m<=45;m++)
                                {
                                  digitalWrite(m,0);
                                  
                                  
                                }
                                
                                control_write();
                                digitalWrite(49,1);
                            }
                          }
}
}
  
digitalWrite(37,a[0]);
  digitalWrite(36,b[0]);
  digitalWrite(35,c[0]);
  digitalWrite(34,d[0]);
  digitalWrite(33,a[0]);
  digitalWrite(32,b[0]);
  digitalWrite(31,c[0]);
  digitalWrite(30,d[0]);
                                digitalWrite(29,a[0]);
                                digitalWrite(28,b[0]);
                                digitalWrite(27,c[0]);
                                digitalWrite(26,d[0]);
                                digitalWrite(25,a[0]);
                                digitalWrite(24,b[0]);
                                digitalWrite(23,c[0]);
                                digitalWrite(22,d[0]);
                                
  }
  
void bg1()
{ digitalWrite(49,1);
  for(int y=0; y<=15;y++)
{
  for(int yy=0; yy<=15;yy++)
  { 
  digitalWrite(37,a[y]);
  digitalWrite(36,b[y]);
  digitalWrite(35,c[y]);
  digitalWrite(34,d[y]);
  digitalWrite(33,a[yy]);
  digitalWrite(32,b[yy]);
  digitalWrite(31,c[yy]);
  digitalWrite(30,d[yy]);
                            for(int x=0; x<=15;x++)
                            { 
                              for(int xx=0; xx<=15;xx++)
                              {
 
                              
                                digitalWrite(29,a[x]);
                                digitalWrite(28,b[x]);
                                digitalWrite(27,c[x]);
                                digitalWrite(26,d[x]);
                                digitalWrite(25,a[xx]);
                                digitalWrite(24,b[xx]);
                                digitalWrite(23,c[xx]);
                                digitalWrite(22,d[xx]);
                              
                                for(int i=38;i<=45;i++)
                                {
                                  digitalWrite(i,1);
                                  
                                }
                                
                                control_write();
                                digitalWrite(49,1);
                            }
                          }
}
}
digitalWrite(37,a[0]);
  digitalWrite(36,b[0]);
  digitalWrite(35,c[0]);
  digitalWrite(34,d[0]);
  digitalWrite(33,a[0]);
  digitalWrite(32,b[0]);
  digitalWrite(31,c[0]);
  digitalWrite(30,d[0]);
                                digitalWrite(29,a[0]);
                                digitalWrite(28,b[0]);
                                digitalWrite(27,c[0]);
                                digitalWrite(26,d[0]);
                                digitalWrite(25,a[0]);
                                digitalWrite(24,b[0]);
                                digitalWrite(23,c[0]);
                                digitalWrite(22,d[0]);

  }

void control_read()
{ 

  for(int n=38;n<=45;n++)
  {
  //data
  pinMode(n,INPUT);
  }
 
  
 for(int y=0; y<=15;y++)
{
  for(int yy=0; yy<=15;yy++)
  { 
  digitalWrite(37,a[y]);
  digitalWrite(36,b[y]);
  digitalWrite(35,c[y]);
  digitalWrite(34,d[y]);
  digitalWrite(33,a[yy]);
  digitalWrite(32,b[yy]);
  digitalWrite(31,c[yy]);
  digitalWrite(30,d[yy]);
                            for(int x=0; x<=15;x++)
                            { 
                              for(int xx=0; xx<=15;xx++)
                              {
 
                              
                                digitalWrite(29,a[x]);
                                digitalWrite(28,b[x]);
                                digitalWrite(27,c[x]);
                                digitalWrite(26,d[x]);
                                digitalWrite(25,a[xx]);
                                digitalWrite(24,b[xx]);
                                digitalWrite(23,c[xx]);
                                digitalWrite(22,d[xx]);

                                digitalWrite(46,0);
                                digitalWrite(47,1);
                                digitalWrite(48,0);
                                digitalWrite(49,1);
 
                              for(int n=38;n<=45;n++)
                                 {
                                  Serial.print(digitalRead(n));
                                 }
                                 Serial.print("  ");
                            }
                          }

Serial.println("");
}
}

  }

  
void control_write()
{
  for(int m=38;m<=45;m++)
 {
  //data
  pinMode(m,OUTPUT);
 }
 digitalWrite(46,0);
 digitalWrite(47,1);
 digitalWrite(48,1);
 digitalWrite(49,0);
  }

void recvOneChar() {
 if (Serial.available() > 0) {
 receivedint = Serial.read();
 newData = true;
 }
}

void showNewData() {
 if (newData == true) {

switch (receivedint) {
    case '0':    //background 0
      bg0();
      Serial.println("Write Done.");
      Serial.println("\n\n\n");
      break;
    case '1':    // background 1
      bg1();
      Serial.println("Write Done.");
      Serial.println("\n\n\n");
      break;
    case '2':    // checkerboard
      checkerboard();
      Serial.println("Write Done.");
      Serial.println("\n\n\n");
      break;
    case '4':    // read
      control_read();
      Serial.println("Read Done.");
      Serial.println("\n\n\n");
      break;

     case '5':    // Diagonal
      pattern.diagonal(0);
      Serial.println("Write Done.");
      Serial.println("\n\n\n");
      break;

      case '6':         
      pattern.checkerboard();
      //Serial.println("Write Done.");
      Serial.println("\n\n\n");
      break;

      case '7':    // read
      pattern.read();
      Serial.println("Read Done.");
      Serial.println("\n\n\n");
      break;

      case '8':    // read
      pattern.background_one();
      Serial.println("Read Done.");
      Serial.println("\n\n\n");
      break;

      case '9':    // read
      pattern.background_zero();
      Serial.println("Read Done.");
      Serial.println("\n\n\n");
      break;
}
 newData = false;
 }
}
