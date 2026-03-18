#include <ctime>    //   ████████  ██████  ████████  ████████  ██  ██████  ██
#include <curses.h> //      ██     ██         ██     ██    ██  ██  ██      ██
#include <stdio.h>
#include <stdlib.h> //      ██     ████       ██     ████████  ██  ██████  ██
#include <string.h> //      ██     ██         ██     ██  ██    ██      ██
#include <unistd.h> //      ██     ██████     ██     ██    ██  ██  ██████  ██
typedef int I;I x=431424,y=598356,r=427089,f=247872,g=799248,h,c=348480,p=615696
,t,a[20][10],b[7][4]={{x,y,x,y},{r,p,r,p},{c,c,c,c},{599636,431376,598336,432192
},{411985,610832,415808,595540},{f,g,f,g},{614928,399424,615744,428369}},s=0;I N
(I x,I y){return 3&b[p][x]>>y;}void S(I x,I y,I r,I v){for(I i=0;i<8;i+=2)a[N(r,i*2
)+y][N(r,(i*2)+2)+x]=v;}void F(){for(I c=0;c<20;c++){move(1+c,1);for(auto &z:a[c]){
z&&attron(262176|z<<8);printw("  ");attroff(262176|z<<8);}}move(21,1);printw("S"
"core: %d",s);refresh();}void P(){y=g=0;p=rand()%7;r=h=rand()%4;x=f=rand()%(10-N(r,
16));}void U(){S(f,g,h,0);S(f=x,g=y,h=r,p+1);}void R(){for(I q=y;q<=y+N(r,18);q++){c=1
;for(auto &z:a[q])c*=z;if(!c)continue;for(I c=q-1;c>0;c--)memcpy(&a[c+1][0],&a[c
][0],40);memset(&a[0][0],0,10);s++;}}I C(I x,I y,I r){if(y+N(r,18)>19)return 1;S
(f,g,h,0);c=0;for(I i=0;i<8;i+=2)a[y+N(r,i*2)][x+N(r,(i*2)+2)]&&c++;S(f,g,h,p+1)
;return c;}I T(){if(++t>30){t=0;if(C(x,y+1,r)){if(!y)return 0;R();P();}else y++;
U();}return 1;}void L(){while(T()){usleep(10000);if((c=getch())==97&&x>0&&!C(x-1,y,
r))x--;if(c==100&&x+N(r,16)<9&&!C(x+1,y,r))x++;if(c==115){while(!C(x,y+1,r)){y++
;U();}R();P();}if(c==119){++r%=4;while(x+N(r,16)>9)x--;if(C(x,y,r)){x=f;r=h;}}if
(c==113)return;U();F();}}I main(){srand(time(0));if(!initscr()){fprintf(stderr
,"Failed to initialize ncurses.\n");return 1;}if(LINES<22||COLS<22){endwin();
fprintf(stderr,"Terminal too small: need at least 22x22, got %dx%d.\n",COLS,
LINES);return 1;}if(!has_colors()){endwin();fprintf(stderr,"Terminal does not s"
"upport colors required by this game.\n");return 1;}start_color();for(c=1;c<8;
c++){init_pair(c,c,0);}P();noecho();timeout(0);curs_set(0);box(stdscr,0,0);L();
endwin();return 0;} // Conor Taylor
