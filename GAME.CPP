#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<process.h>


int mode=10;
int ai_count=0;
char ai[5]={'\0','\0','\0','\0','\0'};
int x=0,y=0;
int count=0;
int hit;

char msg[9][2]={"1","2","3","4","5","6","7","8","-"}; // for game solution.

struct square{  //for each element in to be slided in the game
int x,y;
char no[1][2];
}box[9];


void draw_board(){  // draws the board designed

setcolor(4);
for(y=0;y<=100;y=y+50){
for(x=0;x<=100;x=x+50){
setlinestyle(2,1,1);
rectangle(250+x,110+y,300+x,160+y);
}}
setcolor(14);
for(int y=0;y<=100;y=y+50){
for(int x=0;x<=100;x=x+50){
settextstyle(7,0,2);
char string[2];
string[0]='*';
string[1]='\0';
sprintf(string,"%c",box[count].no[0][0]);
outtextxy(x+270,y+122,string);
count++;
}}
count=0;
}

void display(){  // displays game

setcolor(13);
settextstyle(7,1,2);
outtextxy(25,100,"<---QUESTION--|");
outtextxy(550,100,"<---SOLUTION--|");
setcolor(26);
settextstyle(10,0,2);
outtextxy(10,0,"[ A.I's 8-Puzzle_Problem_Solver @ C]");
setcolor(7);
settextstyle(4,0,2);
outtextxy(200,45,"February 2011");
setcolor(7);
settextstyle(7,0,2);
outtextxy(115,70,"Developed By: Chetan Raikwal");

setcolor(12);
settextstyle(6,0,2);
for(y=0;y<=100;y=y+50){
for(x=0;x<=100;x=x+50){
rectangle(50+x,110+y,100+x,160+y);
}}

/*solution*/
setcolor(26);
for(y=0;y<=100;y=y+50){
for(x=0;x<=100;x=x+50){
rectangle(400+x,110+y,450+x,160+y);
}}
setcolor(12);
for(int y=0;y<=100;y=y+50){
for(int x=0;x<=100;x=x+50){
outtextxy(x+420,y+122,msg[count]);
count++;
}}
count=0;

settextstyle(7,0,2);

/*introduction's rectangle*/
setcolor(12);
setlinestyle(2,1,1);
settextstyle(1,0,1);
rectangle(0,0,635,100);

/*Instructions*/
setcolor(9);
setlinestyle(1,1,1);
rectangle(210,110,390,415);
outtextxy(215,115,"Instructions:");
outtextxy(215,145,"Move Valid_BOXES:");
outtextxy(212,150,"__________________");
outtextxy(280,170,"[up]");
outtextxy(270,220,"[down]");
outtextxy(220,195,"[left]");
outtextxy(286,195,"[-]");
outtextxy(330,195,"[right]");
outtextxy(215,250,"[-] blank box ");
outtextxy(212,223,"__________________");
outtextxy(215,300,"But one at a time");
outtextxy(215,330,"to obtain solution");
outtextxy(215,360,"in least posssible");
outtextxy(215,390,"moves.");

outtextxy(520,445,"MODE: ");
outtextxy(20,400,"Enter q to QUIT !");

settextstyle(2,0,0);

outtextxy(20,440,"USER->AI :Press a ");
outtextxy(20,455,"AI->USER :Press any Key");

settextstyle(1,0,1);

setlinestyle(0,1,1);
circle(40,325,35);/*puzzle number*/
setcolor(12);
outtextxy(36,315,"1");
setcolor(9);
rectangle(500,287,620,330);   /*moves box*/
setcolor(12);
outtextxy(20,365,"Puzzle");
outtextxy(540,335,"Move");
outtextxy(503,355,"[ AI + USER ]");
}
void question(){ // checking for positions and color change if any.
for (int n=0;n<=8;n++){
if(box[0].no[0][0]=='1'){
setcolor(14);
outtextxy(box[0].x,box[0].y,box[0].no[0]);
}
else{
setcolor(26);
outtextxy(box[0].x,box[0].y,box[0].no[0]);
}
if(box[1].no[0][0]=='2'){
setcolor(14);
outtextxy(box[1].x,box[1].y,box[1].no[0]);
}
else{
setcolor(26);
outtextxy(box[1].x,box[1].y,box[1].no[0]);
}
if(box[2].no[0][0]=='3'){
setcolor(14);
outtextxy(box[2].x,box[2].y,box[2].no[0]);
}
else{
setcolor(26);
outtextxy(box[2].x,box[2].y,box[2].no[0]);
}
if(box[3].no[0][0]=='4'){
setcolor(14);
outtextxy(box[3].x,box[3].y,box[3].no[0]);
}
else{
setcolor(26);
outtextxy(box[3].x,box[3].y,box[3].no[0]);
}
if(box[4].no[0][0]=='5'){
setcolor(14);
outtextxy(box[4].x,box[4].y,box[4].no[0]);
}
else{
setcolor(26);
outtextxy(box[4].x,box[4].y,box[4].no[0]);
}
if(box[5].no[0][0]=='6'){
setcolor(14);
outtextxy(box[5].x,box[5].y,box[5].no[0]);
}
else{
setcolor(26);
outtextxy(box[5].x,box[5].y,box[5].no[0]);
}
if(box[6].no[0][0]=='7'){
setcolor(14);
outtextxy(box[6].x,box[6].y,box[6].no[0]);
}
else{
setcolor(26);
outtextxy(box[6].x,box[6].y,box[6].no[0]);
}
if(box[7].no[0][0]=='8'){
setcolor(14);
outtextxy(box[7].x,box[7].y,box[7].no[0]);
}
else{
setcolor(26);
outtextxy(box[7].x,box[7].y,box[7].no[0]);
}
if(box[8].no[0][0]=='-'){
setcolor(14);
outtextxy(box[8].x,box[8].y,box[8].no[0]);
}
else{
setcolor(26);
outtextxy(box[8].x,box[8].y,box[8].no[0]);
}
}
}

char score[7];  //move box string
int  tick=1; // moves counter

void move(){
outtextxy(550,300,score);
score[1]='\0';
score[2]='\0';
score[3]='\0';
score[4]='\0';
score[5]='\0';
score[6]='\0';
setcolor(12); /* to drown the numbers in their own color */
sprintf(score,"%d",tick);
outtextxy(550,300,score);
setcolor(0);
tick++;
}
void swap(char *T,char *S){  //swapping - (blank)  and required number
int temp;
temp=*T;
*T=*S;
*S=temp;
}
void error(){ //showing error
setcolor(12);
outtextxy(470,335,"Invalid");
}

void blank(int T,int S){  //making invisible show-hide
char *msg1,*msg2;
sprintf(msg1, box[T].no[0],0);
sprintf(msg2, box[S].no[0],0);
outtextxy(box[T].x,box[T].y,msg1);
outtextxy(box[S].x,box[S].y,msg2);
}

void question_feed(){  // feeding question in desiner mode

outtextxy(getmaxx()-100,1,"Designer");

int x=0,flag=0;

while(1){

if(x==9){break;}

printf("Box %d:",x+1);
char cha=getche();

if(cha=='1'||cha=='2'||cha=='3'||cha=='4'||cha=='5'||cha=='6'||cha=='7'||cha=='8'||cha=='-')
{

for(int q=0;q<=8;q++){
if(box[q].no[0][0]==cha){printf("--> Duplicate! \n"); flag=1; break;}
flag=0;
}

if(flag==1){continue;}


box[x].no[0][0]=cha;
printf("%c \n",box[x].no[0][0]);
box[x].no[0][1]='\0';
x++;
draw_board();

}
else{printf("---> Invalid Input! \n");continue;}
}

int C=0;
for(int B=0;B<=100;B=B+50){
for(int A=0;A<=100;A=A+50){
box[C].x=A+72;
box[C].y=B+126;
C++;
}}

draw_board();
sleep(1);
clearviewport();

}

int correctness(){  // checking game completness.
setcolor(12);
if(box[0].no[0][0]=='1'
&&box[1].no[0][0]=='2'
&&box[2].no[0][0]=='3'
&&box[3].no[0][0]=='4'
&&box[4].no[0][0]=='5'
&&box[5].no[0][0]=='6'
&&box[6].no[0][0]=='7'
&&box[7].no[0][0]=='8'
&&box[8].no[0][0]=='-'){
setcolor(14);
outtextxy(445,370,"Puzzle_Solved");
outtextxy(460,400,"ThankYou!");
outtextxy(400,438,"Press any Key to Exit.....");
outtextxy(10,438,"Kindly inform if Bugs ! are found.");
return 1;
}
else{return 0;}
}

//...................................


int misplaced(){
int h=0;

for(int i=0;i<=8;i++){

if(box[i].no[0][0]=='1' ){
if(i==0){h=h+0;}
else if(i==1){h=h+1;}
else if(i==2){h=h+2;}
else if(i==3){h=h+1;}
else if(i==4){h=h+2;}
else if(i==5){h=h+3;}
else if(i==6){h=h+2;}
else if(i==7){h=h+3;}
else         {h=h+4;}
}

else if(box[i].no[0][0]=='2' ){
if(i==0){h=h+1;}
else if(i==1){h=h+0;}
else if(i==2){h=h+1;}
else if(i==3){h=h+2;}
else if(i==4){h=h+1;}
else if(i==5){h=h+2;}
else if(i==6){h=h+3;}
else if(i==7){h=h+2;}
else         {h=h+3;}

}
else if(box[i].no[0][0]=='3' ){
if(i==0){h=h+2;}
else if(i==1){h=h+1;}
else if(i==2){h=h+0;}
else if(i==3){h=h+3;}
else if(i==4){h=h+2;}
else if(i==5){h=h+1;}
else if(i==6){h=h+4;}
else if(i==7){h=h+3;}
else         {h=h+2;}

}
else if(box[i].no[0][0]=='4' ){
if(i==0){h=h+1;}
else if(i==1){h=h+2;}
else if(i==2){h=h+3;}
else if(i==3){h=h+0;}
else if(i==4){h=h+1;}
if(i==5){h=h+2;}
else if(i==6){h=h+1;}
else if(i==7){h=h+2;}
else         {h=h+3;}

}

else if(box[i].no[0][0]=='5' ){
if(i==0){h=h+2;}
else if(i==1){h=h+1;}
else if(i==2){h=h+2;}
else if(i==3){h=h+1;}
else if(i==4){h=h+0;}
else if(i==5){h=h+1;}
else if(i==6){h=h+2;}
else if(i==7){h=h+1;}
else         {h=h+2;}

}
else if(box[i].no[0][0]=='6' ){
if(i==0){h=h+3;}
else if(i==1){h=h+2;}
else if(i==2){h=h+1;}
else if(i==3){h=h+2;}
else if(i==4){h=h+1;}
else if(i==5){h=h+0;}
else if(i==6){h=h+3;}
else if(i==7){h=h+2;}
else         {h=h+1;}

}
else if(box[i].no[0][0]=='7' ){
if(i==0){h=h+2;}
else if(i==1){h=h+3;}
else if(i==2){h=h+4;}
else if(i==3){h=h+1;}
else if(i==4){h=h+2;}
else if(i==5){h=h+3;}
else if(i==6){h=h+0;}
else if(i==7){h=h+1;}
else         {h=h+2;}
}
else if(box[i].no[0][0]=='8' ){
if(i==0){h=h+3;}
else if(i==1){h=h+2;}
else if(i==2){h=h+3;}
else if(i==3){h=h+2;}
else if(i==4){h=h+1;}
else if(i==5){h=h+2;}
else if(i==6){h=h+1;}
else if(i==7){h=h+0;}
else         {h=h+1;}
}

else {h=h+0;}

}
return h;
}

//....................................


int heuristic(){    // from box[9][2]
int h=0;
h=misplaced();
return h;
}

 //position of -
int position(){
int T;
for(T=0;T<=8;T++){
if(box[T].no[0][0]=='-'){break;}
}
return T;
}


int small(int a,int b,int c,int d){
if((a-b)<0){return c;}
else if((a-b)>0){return d;}
else{return c;} // both are euqal
}

int smaller(int x,int y,int z,int a,int b,int c){

     int i=small(x,y,a,b);

     if(i==a){
     i=small(x,z,a,c);
     if(i==a){return a;}
     else{return c;}
     }
     else{
     i=small(y,z,b,c);
     if(i==b){return b;}
     else {return c;}
     }

}

int smallest(int a,int b,int c,int d,int x,int y,int z,int w){
int e=small(a,b,x,y);
int f=small(e,c,e,z);
int g=small(f,d,f,w);
return g;
}

int  swap_h(int i,int j){

char a=box[i].no[0][0];
box[i].no[0][0]=box[j].no[0][0];
box[j].no[0][0]=a;

int h=heuristic();

//...undo....

a=box[i].no[0][0];
box[i].no[0][0]=box[j].no[0][0];
box[j].no[0][0]=a;

return h;
}

//action...here>>>>

int action(){

int T=position();// T working fine

int a,b,c,d;

if(T==0){
a=swap_h(0,1); // left
b=swap_h(0,3); // up  //swap_v :yet to implement :call by value

int v=small(a,b,1,3);    //s having either 0 or 1 whichever smaller.

if(v==1){return 75;}
else{return 72;}
}

else if(T==1){
a=swap_h(1,0); // left
b=swap_h(1,2); // right
c=swap_h(1,4); // up

int v=smaller(a,b,c,0,2,4);
if(v==0){return 77;}
else if(v==2){return 75;}
else{return 72;}
}

else if(T==2){
a=swap_h(2,1); // right
b=swap_h(2,5); //up

int v=small(a,b,1,5);
if(v==1){return 77;}
else{return 72;}
}

else if(T==3){
a=swap_h(3,0); // down
b=swap_h(3,4); // left
c=swap_h(3,6); // up

int v=smaller(a,b,c,0,4,6);
if(v==0){return 80;}
else if(v==4){return 75;}
else{return 72;}
}

else if(T==4){
a=swap_h(4,1); // down
b=swap_h(4,7); // up
c=swap_h(4,3); // right
d=swap_h(4,5); // left

int v=smallest(a,b,c,d,1,7,3,5);
if(v==1){return 80;}
else if(v==7){return 72;}
else if(v==3){return 77;}
else{return 75;}
}

else if(T==5){
a=swap_h(5,2); // down
b=swap_h(5,8); // up
c=swap_h(5,4); // right

int v=smaller(a,b,c,2,8,4);

if(v==2){return 80;}
else if(v==8){return 72;}
else{return 77;}
}

else if(T==6){
a=swap_h(6,3); // down
b=swap_h(6,7); // left

int v=small(a,b,3,7);
if(v==3){return 80;}
else{return 75;}

}
else if(T==7){
a=swap_h(7,4); // down
b=swap_h(7,8); // left
c=swap_h(7,6); // right

int v=smaller(a,b,c,4,8,6);

if(v==4){return 80;}
else if(v==8){return 75;}
else{return 77;}
}

else if(T==8){
a=swap_h(8,5); // down
b=swap_h(8,7); // right

int v=small(a,b,5,7);
if(v==5){return 80;}
else{return 77;}
}

else{return 0;}

}
/*to do*/

void to_do(int need){
int T = position();
setcolor(getbkcolor());
int S;

if(T==0){
if(need==80){error();}
else if(need==75){
S=1;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==77){error();}
else{
S=3;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}


else if(T==1){
if(need==72){
S=4;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==77){
S=0;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==80){error();}
else{
S=2;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}


else if(T==2){
if(need==75){error();}
else if(need==77){
S=1;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==80){error();}
else{
S=5;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}



else if(T==3){
if(need==72){
S=6;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==80){
S=0;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==77){
error();}
else{
S=4;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}


else if(T==4){
if(need==72){
S=7;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==80){
S=1;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==75){
S=5;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else{
S=3;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}


else if(T==5){
if(need==72){
S=8;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==80){
S=2;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==75){error();}
else{
S=4;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}


else if(T==6){
if(need==72){
error();
}
else if(need==80){
S=3;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==77){error();}
else{
S=7;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}

else if(T==7){
if(need==72){error();}
else if(need==75){
S=8;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==80){
S=4;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else{
S=6;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}

else{
if(need==75){error();}
else if(need==80){
S=5;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}
else if(need==72){error();}
else{
S=7;
move();
blank(T,S);
swap(&box[T].no[0][0],&box[S].no[0][0]);
}}

question();
} // end to_do



void main(){

void move();
void dispaly();
void question();
void question_feed();
void draw_board();
int position();
void to_do(int);
int  action();
void check();

int swap_h(int , int );

int small(int,int, int,int);
int smaller(int,int,int,int,int,int);
int smallest(int,int,int,int,int,int,int,int);

int heuristic(); /*for finding how close to the goal are we!*/
int misplaced();
int correctness();
void blank(int ,int);
void swap(char *,char *);

int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "c:\tc\bgi");

int choise;

while(1){  //Choise  LOOP

setbkcolor(1);

settextstyle(7,0,2);
setlinestyle(2,1,1);
outtextxy(130,5,"8 Puzzle Problem with AI Support");
outtextxy(50,45,"Enter Choise");
outtextxy(50,75,"1. Play");
outtextxy(50,105,"2. Puzzle Design and Play");
outtextxy(50,135,"3. Exit");

choise=getch();

if(choise==50){ // designer mode choise 2

clearviewport();

setbkcolor(3);

question_feed();

break;
}

else if(choise==51) { clearviewport(); setbkcolor(0); exit(0);}

else if(choise==49){

clearviewport();

box[0].no[0][0]='8';
box[1].no[0][0]='1';
box[2].no[0][0]='4';
box[3].no[0][0]='-';
box[4].no[0][0]='6';
box[5].no[0][0]='2';
box[6].no[0][0]='5';
box[7].no[0][0]='3';
box[8].no[0][0]='7';

for(int P=0;P<=8;P++){
box[P].no[0][1]='\0';
}

int C=0;
for(int B=0;B<=100;B=B+50){
for(int A=0;A<=100;A=A+50){
box[C].x=A+72;
box[C].y=B+126;
C++;
}}
break;
}

else{
outtextxy(150,140,"Invalid Input!");
clearviewport();
continue;
}

} //end choise loop

setbkcolor(0);

setcolor(1);

int midx, midy;
midx = getmaxx() / 2;
midy = getmaxy() / 2;

setfillstyle(SOLID_FILL, 14);

sector(midx, midy,0, 270, 100,100);

setcolor(4);
outtextxy(midx+60,midy+10,"Loading................");

sleep(1);
clearviewport();

display();
/*question feed*/


question();
setcolor(26);

outtextxy(20,418,"=================>Enter Numbers<====================");

int need;

while(1){ // game loop............

int cor=correctness();
if (cor==1){break;}

setcolor(12);

setcolor(0);
outtextxy(470,335,"Invalid");

if(mode==10){  //checking mode user

setcolor(0);
sprintf(ai,"%d",ai_count);
outtextxy(52,75,ai);
outtextxy(15,75,"AI : ");

setcolor(0);
outtextxy(580,445,"  AI");
setcolor(2);
outtextxy(580,445,"USER");

need=getch(); //getting key code in user mode

if(need==0){
need=getch();
if(need==72 ||need==75||need==77||need==80){

to_do(need);
}
}

else if(need==97){
mode=11;

setcolor(0);
outtextxy(580,445,"USER");
setcolor(12);
outtextxy(580,445,"  AI");
continue;
}

else if(need==113){
setcolor(14);
outtextxy(460,400,"ThankYou!");
outtextxy(400,438,"Press any Key to Exit.....");
outtextxy(10,438,"Kindly inform iff Bugs ! are found.");
break;/*for quitting the game*/
}

else{
error();
}

}

else if(mode==11){ //checking mode machine

setcolor(0);
sprintf(ai,"%d",ai_count);
outtextxy(52,75,ai);

int hit=kbhit();
if(hit!=0){ // key is pressed if non zero
setcolor(0);
outtextxy(580,445,"  AI");
setcolor(2);
outtextxy(580,445,"USER");
mode=10;        // to USER
continue;
}


//...........ai here..........

int perform=action();  //perform an ai action

sleep(1);

ai_count++;
sprintf(ai,"%d",ai_count);


setcolor(12);
outtextxy(15,75,"AI : ");
outtextxy(52,75,ai);

to_do(perform);
}

else { printf("%d \n",mode); printf("This should not happen");exit(0);} //if something  goes wrong

/* code for user and ai mode changes on the basis of need(action) */

}

getch();
closegraph();
}