int c1[16]={3,7,11,13,2,6,10,12,1,5,9,A5,0,4,8,A4};
int c2[16]={3,7,11,13,12,A5,A4,8,4,0,1,2,6,10,9,5};
int layer[4]={A0,A1,A2,A3};
void setup()
{
for(int i=0;i<16;i++)
 {
 pinMode(c1[i],OUTPUT);
 }
for(int i=0;i<4;i++)
 {
 pinMode(layer[i],OUTPUT);
 }
}
void loop()
{
 delay(3000);
 off();
 spiral();
 Rowlitdowntotop();
 spiral();
 Rowlittoptodown();
 spiral();
 Randomflicker();
 columnslituplefttoright();
 columnslituprighttoleft();
 spiralandoffoutin();
 Randomflicker();
 RandomRain();
 RandomRise();
 flickercolumns();
 spiralandoffinout();
 onoff();
}
void off() //switch off all leds
{
 for(int i=0;i<4;i++)
 {
 digitalWrite(layer[i],0);
 }
 for(int i=0;i<16;i++)
 {
 digitalWrite(c1[i],1);
 }
}
void layeron() //supply power to all anodes only
{
 for(int i=0;i<4;i++)
 {
 digitalWrite(layer[i],1);
 }
}
void spiral()
{
 off();
 layeron();
 for(int j=0;j<2;j++) //repeat pattern 3 times
 {
 for(int i=0;i<16;i++) //now switch on leds by grounding cathodes
 {
 digitalWrite(c2[i],0);
 delay(50);
 }
 delay(50);
 for(int i=15;i>=0;i--) //leds turned off in reverse manner
 {
 digitalWrite(c2[i],1);
 delay(25);
 }
 delay(200);
 }
}
void Rowlitdowntotop()
{
 off();
 for(int i=0;i<16;i++)
 {
 digitalWrite(c2[i],0); //ground cathodes
 }
 for(int j=0;j<5;j++) //repeat pattern for 5 times
 {
 for(int i=0;i<4;i++) // switch on leds by supplying power to anode layers
 {
 digitalWrite(layer[i],1);
 delay(100);
 digitalWrite(layer[i],0); //switch off previous layer
 delay(50);
 }
 }
}
void Rowlittoptodown()
{
 off();
 for(int i=0;i<16;i++)
 {
 digitalWrite(c2[i],0); //ground cathodes
 }
 for(int j=0;j<5;j++) //pattern repeats for 5 times
 {
 for(int i=3;i>=0;i--)
 {
 digitalWrite(layer[i],1); //switch on one layer
 delay(100);
 digitalWrite(layer[i],0); //switch off that layer
 delay(50);
 }
 }
}
void columnslituplefttoright()
{
 off();
 layeron();
 for(int i=0;i<5;i++) //pattern repeats for 5 times
 {
 for(int j=0;j<4;j++) //one vertical layer lights up
 {
 digitalWrite(c1[j],0);
 digitalWrite(c1[j+4],0);
 digitalWrite(c1[j+8],0);
 digitalWrite(c1[j+12],0);
 delay(100);

 digitalWrite(c1[j],1); //vertical layer goes off
 digitalWrite(c1[j+4],1);
 digitalWrite(c1[j+8],1);
 digitalWrite(c1[j+12],1);
 }
 delay(100);
 }
}
void columnslituprighttoleft()
{
 off();
 layeron();
 for(int i=0;i<5;i++) //pattern repeats for 5 times
 {
 for(int j=3;j>=0;j--) //one vertical layer lights up
 {
 digitalWrite(c1[j],0);
 digitalWrite(c1[j+4],0);
 digitalWrite(c1[j+8],0);
 digitalWrite(c1[j+12],0);
 delay(100);
 digitalWrite(c1[j],1); //vertical layer goes off
 digitalWrite(c1[j+4],1);
 digitalWrite(c1[j+8],1);
 digitalWrite(c1[j+12],1);
 }
 delay(100);
 }
}
void Randomflicker()
{
 off();
 int col,row;
 for(int i=0;i<30;i++)
 {
 col=random(0,16); //obtain the random column that gets grounded
 row=random(0,4); //obtain the random layer that gets power
 digitalWrite(layer[row],1); //power the anode
 digitalWrite(c1[col],0); //light up the led stored as per c1 array

 digitalWrite(c1[col],1); //switch off the led stored as per c1 array
 digitalWrite(c2[col],0); //light up the led stored as per c2 array


 digitalWrite(c2[col],1); //light up the led stored as per c1 array
 digitalWrite(layer[row],0); //anode grounded
 }
}
void RandomRain()
{
 off();
 int col;
 for(int j=0;j<15;j++)
 {
 col=random(0,16); //random index of column that gets grounded

 if(c1[col]==c2[col]) //prevents the same led being chosen from both arrays
 continue;
 
 digitalWrite(c1[col],0); //light up two leds
 digitalWrite(c2[col],0);
 for(int i=3;i>=0;i--)
 {
 digitalWrite(layer[i],1); //layers are supplied power and then grounded
 delay(75);
 digitalWrite(layer[i],0);
 delay(75);
 }
 digitalWrite(c1[col],1); //switch of the random leds
 digitalWrite(c2[col],1);
 }
}


void RandomRise()
{
 off();
 int col;
 for(int j=0;j<15;j++)
 {
 col=random(0,16);

 if(c1[col]==c2[col])
 continue;

 digitalWrite(c1[col],0);
 digitalWrite(c2[col],0);
 for(int i=0;i<=3;i++)
 {
 digitalWrite(layer[i],1);
 delay(75);
 digitalWrite(layer[i],0);
 delay(75);
 }
 digitalWrite(c1[col],1);
 digitalWrite(c2[col],1);

 }
}

void flickercolumns()
{
 off();
 int col;
 layeron();
 for(int i=0;i<40;i++)
 {
 col=random(16);
 digitalWrite(c1[col],0);
 delay(25);
 digitalWrite(c1[col],1);
 delay(25);
 digitalWrite(c2[col],0);
 delay(25);
 digitalWrite(c2[col],1);
 delay(25);
 }
}
void spiralandoffoutin()
{

 off(); //set all led off
 layeron();

 for(int j=0;j<4;j++) //repeat pattern 5 times
 {
 for(int i=0;i<16;i++) //now switch on leds by grounding cathodes
 {
 digitalWrite(c2[i],0);
 delay(75);
 digitalWrite(c2[i],1);
 }
 delay(10);
 }
}
void spiralandoffinout()
{
 off(); //set all led off
 layeron();

 for(int j=0;j<4;j++) //repeat pattern 5 times
 {
 for(int i=15;i>0;i--) //now switch on leds by grounding cathodes
 {
 digitalWrite(c2[i],0);
 delay(75);
 digitalWrite(c2[i],1);
 }
 delay(10);
 }
}
void onoff()
{
 off();
 layeron();
 for(int j=0;j<20;j++)
 {
 for(int i=0;i<16;i++)
 {
 digitalWrite(c2[i],0);
 }
 delay(100);
 off();
 delay(100);
 layeron();

 }
}

 


 
