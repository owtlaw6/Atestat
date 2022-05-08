#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_mixer.h>
#include <ctime>
#include <queue>
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture *texture_orange,    *texture_null;
SDL_Texture *texture_green,     *texture_red;
SDL_Texture *texture_bluelight, *texture_bluedark;
SDL_Texture *texture_purple,    *texture_gray;
SDL_Texture *texture_pink,      *texture_black;
SDL_Texture *texture_greenlight;

SDL_Surface *surface_orange,    *surface_null;
SDL_Surface *surface_green,     *surface_red;
SDL_Surface *surface_bluelight, *surface_bluedark;
SDL_Surface *surface_purple,    *surface_gray;
SDL_Surface *surface_pink,      *surface_black;
SDL_Surface *surface_greenlight;

SDL_Rect pmp1, pmp2;
SDL_Rect orange, green, red, bluelight, bluedark, purple, gray, pink, black, greenlight, blank;

short int a, b;
bool game = 1;
int m[8][12], score = -1;

void InitEverything();
void play();
void everything();
void render();

void render_orange();     void render_green();
void render_red();        void render_bluelight();
void render_bluedark();   void render_purple();
void render_gray();       void render_pink();
void render_black();      void render_greenlight();

void render_orange_x(SDL_Rect &x);      void render_green_x(SDL_Rect &x);
void render_red_x(SDL_Rect &x);         void render_bluelight_x(SDL_Rect &x);
void render_bluedark_x(SDL_Rect &x);    void render_purple_x(SDL_Rect &x);
void render_gray_x(SDL_Rect &x);        void render_pink_x(SDL_Rect &x);
void render_black_x(SDL_Rect &x);       void render_greenlight_x(SDL_Rect &x);
void render_null_x(SDL_Rect &x);        void render_null();

short int functie2(short int loc);
short int functie1(short int loc);
void verificareelimin();
void Lee_dreapta(short int dovleacd, short int lstartd, short int cstartd, short int col1d);
bool Lee_stanga(short int dovleac, short int lstart, short int cstart, short int col2);

void InitEverything(){
    window = SDL_CreateWindow( "Server", 100, 100, 834, 524, 0 );
	renderer = SDL_CreateRenderer( window, -1, 0 );
	SDL_RenderSetLogicalSize( renderer, 834, 524 );
	everything();
	srand((int)time(0));
	for(short int i = 0; i <= 7; ++i){
        a = rand() % 11;
        b = rand() % 11;
        if (!a || !b) {
            if (!a) a = 1;
            else b = 1;
        }
        m[i][5] = a; m[i][6] = b;
    }
}

void everything(){
    IMG_Init(IMG_INIT_PNG);
    surface_orange = IMG_Load("poze/orange.png");
    surface_null = IMG_Load("poze/null.png");
    surface_green = IMG_Load("poze/green.png");
    surface_red = IMG_Load("poze/red.png");
    surface_bluelight = IMG_Load("poze/bluelight.png");
    surface_bluedark = IMG_Load("poze/bluedark.png");
    surface_purple = IMG_Load("poze/purple.png");
    surface_gray = IMG_Load("poze/gray.png");
    surface_pink = IMG_Load("poze/pink.png");
    surface_black = IMG_Load("poze/black.png");
    surface_greenlight = IMG_Load("poze/greenlight.png");

    texture_orange = SDL_CreateTextureFromSurface(renderer, surface_orange);
    texture_null = SDL_CreateTextureFromSurface(renderer, surface_null);
    texture_green = SDL_CreateTextureFromSurface(renderer, surface_green);
    texture_red = SDL_CreateTextureFromSurface(renderer, surface_red);
    texture_bluelight = SDL_CreateTextureFromSurface(renderer, surface_bluelight);
    texture_bluedark = SDL_CreateTextureFromSurface(renderer, surface_bluedark);
    texture_purple = SDL_CreateTextureFromSurface(renderer, surface_purple);
    texture_gray = SDL_CreateTextureFromSurface(renderer, surface_gray);
    texture_pink= SDL_CreateTextureFromSurface(renderer, surface_pink);
    texture_black = SDL_CreateTextureFromSurface(renderer, surface_black);
    texture_greenlight = SDL_CreateTextureFromSurface(renderer, surface_greenlight);
}

void render_orange(){
    SDL_RenderCopy(renderer, texture_orange, NULL, &orange);
    SDL_RenderPresent(renderer);
}
void render_null(){
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderFillRect( renderer, &blank );
	SDL_RenderPresent( renderer );
}
void render_green(){
    SDL_RenderCopy(renderer, texture_green, NULL, &green);
    SDL_RenderPresent(renderer);
}
void render_red(){
    SDL_RenderCopy(renderer, texture_red, NULL, &red);
    SDL_RenderPresent(renderer);
}
void render_bluelight(){
    SDL_RenderCopy(renderer, texture_bluelight, NULL, &bluelight);
    SDL_RenderPresent(renderer);
}
void render_bluedark(){
    SDL_RenderCopy(renderer, texture_bluedark, NULL, &bluedark);
    SDL_RenderPresent(renderer);
}
void render_purple(){
    SDL_RenderCopy(renderer, texture_purple, NULL, &purple);
    SDL_RenderPresent(renderer);
}
void render_gray(){
    SDL_RenderCopy(renderer, texture_gray, NULL, &gray);
    SDL_RenderPresent(renderer);
}
void render_pink(){
    SDL_RenderCopy(renderer, texture_pink, NULL, &pink);
    SDL_RenderPresent(renderer);
}
void render_black(){
    SDL_RenderCopy(renderer, texture_black, NULL, &black);
    SDL_RenderPresent(renderer);
}
void render_greenlight(){
    SDL_RenderCopy(renderer, texture_greenlight, NULL, &greenlight);
    SDL_RenderPresent(renderer);
}

void render_orange_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_orange, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_null_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_null, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_green_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_green, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_red_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_red, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_bluelight_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_bluelight, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_bluedark_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_bluedark, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_purple_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_purple, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_gray_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_gray, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_pink_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_pink, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_black_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_black, NULL, &x);
    SDL_RenderPresent(renderer);
}
void render_greenlight_x(SDL_Rect &x){
    SDL_RenderCopy(renderer, texture_greenlight, NULL, &x);
    SDL_RenderPresent(renderer);
}

void render(){
    bool loop = true;
    while(loop){ SDL_Event event;
        while ( SDL_PollEvent( &event ) )
            if ( event.type == SDL_QUIT ) {
                loop = false;
                break; }
            for (short int i = 0; i < 8; ++i )
                for (short int j = 0; j < 12; ++j ){ short int cst = m[i][j];
                    switch (cst){ case 0: blank.y = 63 * i + 10; blank.x = 67 * j + 15; render_null(); break;
                        case 1: orange.y = 63 * i + 10;      orange.x = 67 * j + 15; render_orange(); break;
                        case 2: green.y = 63 * i + 10;       green.x = 67 * j + 15; render_green(); break;
                        case 3: red.y = 63 * i + 10;         red.x = 67 * j + 15; render_red(); break;
                        case 4: bluelight.y = 63 * i + 10;   bluelight.x = 67 * j + 15; render_bluelight(); break;
                        case 5: bluedark.y = 63 * i + 10;    bluedark.x = 67 * j + 15; render_bluedark(); break;
                        case 6: purple.y = 63 * i + 10;      purple.x = 67 * j + 15; render_purple(); break;
                        case 7: gray.y = 63 * i + 10;        gray.x = 67 * j + 15; render_gray(); break;
                        case 8: pink.y = 63 * i + 10;        pink.x = 67 * j + 15; render_pink(); break;
                        case 9: black.y = 63 * i + 10;       black.x = 67 * j + 15; render_black(); break;
                        case 10: greenlight.y = 63 * i + 10; greenlight.x = 67 * j + 15; render_greenlight(); break;
                        default: break;
                }
            } loop = false;
        SDL_Delay( 16 );
    }
}

short int functie2(short int loc){
    short int poz = -1;
    for (short int i = 6; i < 12 && poz == -1; i++)
        if (!m[loc][i]) poz = i;
    if (poz == 0 || poz == 11) game = false;
    return poz;
}
short int functie1(short int loc){
    short int poz = -1;
    for (short int i = 5; i >= 0 && poz == -1; --i)
        if (!m[loc][i]) poz = i;
    if (poz == 0 || poz == 11) game = false;
    return poz;
}

bool Lee_stanga(short int dovleac, short int lstart, short int cstart, short int col2){
    short int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, cnt = 1;
    bool lee[8][12] = {0}, ok = 1;
    queue < pair <short int, short int> > q;
	lee[lstart][cstart] = 1;
	q.push(make_pair(lstart, cstart));
	while(!q.empty()){
        pair <short, short> p = q.front(); q.pop();
		short int x = p.first, y = p.second;
		for(short int i = 0; i < 4; i++){
			short int xn = x + dx[i], yn = y + dy[i];
			if(!lee[xn][yn] && m[xn][yn] == dovleac){
				lee[xn][yn] = 1; cnt++;
				q.push(make_pair(xn, yn));
			}
		}
	}
	if (cnt >= 3){ score += cnt;
        for (short int i = 0; i < 8; ++i)
            for (short int j = 11; j >= 0; --j){
                if (lee[i][j]){
                    short int nrpoz = 1, indice = j;
                    while(lee[i][--j]) nrpoz++;
                    short int stop = nrpoz;
                    if (!m[i][indice - nrpoz - 1])
                        while (stop){
                            m[i][indice] = m[i][indice - nrpoz];
                            m[i][indice - nrpoz] = 0; indice--; stop--;
                        }
                    else while (m[i][indice - nrpoz]){
                        m[i][indice] = m[i][indice - nrpoz];
                        m[i][indice - nrpoz] = 0; indice--;
                    }
                }
            }
    }
    for (short int i = 0; i < 8; ++i){
        if (m[i][5] == 0 && m[i][6] == 0 && m[i][4] == 0 && m[i][3] == 0 && m[i][7] == 0 && m[i][8] == 0){
            srand((int)time(0)); int aa, bb; aa = rand() % 11; bb = rand() % 11;
            if (!aa || !bb) {if (!aa) aa = 1; else bb = 1;}
            m[i][5] = aa; m[i][6] = bb;
        }
        if (m[i][5] == 0 && m[i][6] == 0){
            short int poz = 5; ok = 0;
            while (m[i][poz + 2]) m[i][poz] = m[i][poz + 2], poz++;
            m[i][poz++] = 0; m[i][poz] = 0;
            for (short int x = 0; x < 8; ++x)
                for (short int j = 0; j < 12; ++j)
                    if (m[x][j]) Lee_stanga(m[x][j], x, j, col2);
        }
        if (m[i][5] == 0 && m[i][7]){
            short int poz = 5; ok = 0;
            while (m[i][poz + 1]) m[i][poz] = m[i][poz + 1], poz++;
            m[i][poz++] = 0;
            for (short int x = 0; x < 8; ++x)
                for (short int j = 0; j < 12; ++j)
                    if (m[x][j]) Lee_stanga(m[x][j], x, j, col2);
        }
    }
    return ok;
}
void Lee_dreapta(short int dovleacd, short int lstartd, short int cstartd, short int col1d){
    short int dxd[] = {-1, 0, 1, 0}, dyd[] = {0, -1, 0, 1}, cntd = 1;
    bool leed[8][12] = {0};
    queue < pair <short int, short int> > qd;
	leed[lstartd][cstartd] = 1;
	qd.push(make_pair(lstartd, cstartd));
	while(!qd.empty()){
        pair <short, short> pd = qd.front(); qd.pop();
		short int xd = pd.first, yd = pd.second;
		for(short int id = 0; id < 4; id++){
			short int xnd = xd + dxd[id], ynd = yd + dyd[id];
			if(!leed[xnd][ynd] && m[xnd][ynd] == dovleacd){
				leed[xnd][ynd] = 1; cntd++;
				qd.push(make_pair(xnd, ynd));
			}
		}
	}
	if (cntd >= 3){ score += cntd;
        for (short int id = 0; id < 8; ++id)
            for (short int jd = 0; jd < 12; ++jd){
                if (leed[id][jd]){
                    short int nrpozd = 1, indiced = jd;
                    while(leed[id][++jd]) nrpozd++;
                    short int stopd = nrpozd;
                    if (!m[id][indiced + nrpozd + 1])
                        while (stopd){
                            m[id][indiced] = m[id][indiced + nrpozd];
                            m[id][indiced + nrpozd] = 0; indiced++; stopd--;
                        }
                    else while (m[id][indiced + nrpozd]){
                        m[id][indiced] = m[id][indiced + nrpozd];
                        m[id][indiced + nrpozd] = 0; indiced++;
                    }
                }
            }
    }
    for (short int id = 0; id < 8; ++id){
        if (m[id][5] == 0 && m[id][6] == 0 && m[id][4] == 0 && m[id][3] == 0 && m[id][7] == 0 && m[id][8] == 0){
            srand((int)time(0)); int aa, bb; aa = rand() % 11; bb = rand() % 11;
            if (!aa || !bb) {if (!aa) aa = 1; else bb = 1;}
            m[id][5] = aa; m[id][6] = bb;
        }
        else if (m[id][5] == 0 && m[id][6] == 0){
            short int pozd = 6;
            while (m[id][pozd - 2]) m[id][pozd] = m[id][pozd - 2], pozd--;
            m[id][pozd--] = 0; m[id][pozd] = 0;
            for (short int xd = 0; xd < 8; ++xd)
                for (short int jd = 0; jd < 12; ++jd)
                    if (m[xd][jd]) Lee_dreapta(m[xd][jd], xd, jd, col1d);
        }
        if (m[id][6] == 0 && m[id][4]){
            short int pozd = 6;
            while (m[id][pozd - 1]) m[id][pozd] = m[id][pozd - 1], pozd--;
            m[id][pozd--] = 0;
            for (short int xd = 0; xd < 8; ++xd)
                for (short int jd = 0; jd < 12; ++jd)
                    if (m[xd][jd]) Lee_dreapta(m[xd][jd], xd, jd, col1d);
        }
    }
}
void verificareelimin(short int linie, short int col1, short int col2){
    bool ok = Lee_stanga(a, linie, col1, col2);
    if (ok) Lee_dreapta(b, linie, col2, col1);
}

void play(){
    bool loop = true;
    while(loop && game){
        cout << '\n' << "\t" << "SCORE = " << score << '\n';
        score++;
        srand((int)time(0));
        a = rand() % 11;
        b = rand() % 11;
        if (!a || !b) {
            if (!a) a = 1;
            else b = 1;}
        if (a > 10) a = 1;
        if (b > 10) b = 1;
        m[0][0] = a; m[0][11] = b;
        short int c1 = 0, c11 = 0, c2 = 0, c22 = 11;
        pmp1.y = 10; pmp1.x = 15;
        pmp2.y = 10; pmp2.x = 752;
        switch (a){ case 1: render_orange_x(pmp1); break;
                    case 2: render_green_x(pmp1); break;
                    case 3: render_red_x(pmp1); break;
                    case 4: render_bluelight_x(pmp1); break;
                    case 5: render_bluedark_x(pmp1); break;
                    case 6: render_purple_x(pmp1); break;
                    case 7: render_gray_x(pmp1); break;
                    case 8: render_pink_x(pmp1); break;
                    case 9: render_black_x(pmp1); break;
                    case 10: render_greenlight_x(pmp1); break;
                    default: break; }
        switch (b){ case 1: render_orange_x(pmp2); break;
                    case 2: render_green_x(pmp2); break;
                    case 3: render_red_x(pmp2); break;
                    case 4: render_bluelight_x(pmp2); break;
                    case 5: render_bluedark_x(pmp2); break;
                    case 6: render_purple_x(pmp2); break;
                    case 7: render_gray_x(pmp2); break;
                    case 8: render_pink_x(pmp2); break;
                    case 9: render_black_x(pmp2); break;
                    case 10: render_greenlight_x(pmp2); break;
                    default: break; }
        bool ok = true;
        SDL_Event event;
        while (ok){
            SDL_WaitEvent(&event);
            if ( event.type == SDL_QUIT ) { loop = ok = false; break; }
            else if ( event.type == SDL_KEYDOWN ){
                    switch ( event.key.keysym.sym ){
                        case SDLK_DOWN: { m[c1][c11] = 0; m[c2][c22] = 0;
                                        if (c1 + 1 < 8) m[++c1][c11] = a, m[++c2][c22] = b;
                                        else c1 = c2 = 0, m[c1][c11] = a, m[c2][c22] = b;
                                        render(); break;}
                        case SDLK_UP: { m[c1][c11] = 0; m[c2][c22] = 0;
                                        if (c1 - 1 >= 0) m[--c1][c11] = a, m[--c2][c22] = b;
                                        else c1 = c2 = 7, m[c1][c11] = a, m[c2][c22] = b;
                                        render(); break;}
                        case SDLK_RIGHT: { m[c1][c11] = 0; m[c2][c22] = 0; ok = false;
                                        c11 = functie1(c1); c22 = functie2(c2);
                                        m[c1][c11] = a; m[c2][c22] = b; render();
                                        verificareelimin(c1, c11, c22); render(); break; }
                        default: break;
                    }
                }
        }
        SDL_Delay( 16 );
    }
}

int main( int argc, char* args[] ){
	InitEverything();
    orange.w = 67;     orange.h = 63;
    green.w = 67;      green.h = 63;
    red.w = 67;        red.h = 63;
    bluedark.w = 67;   bluedark.h = 63;
    bluelight.w = 67;  bluelight.h = 63;
    purple.w = 67;     purple.h = 63;
    gray.w = 67;       gray.h = 63;
    pink.w = 67;       pink.h = 63;
    black.w = 67;      black.h = 63;
    greenlight.w = 67; greenlight.h = 63;
    blank.w = 67;      blank.h = 63;
    pmp1.w = 67;       pmp1.h = 63;
    pmp2.w = 67;       pmp2.h = 63;

	render();
	play();

	cout << '\n' << "\t" << "GAME OVER" << '\n';
    cout << '\n' << "\t" << "SCORE = " << score << '\n';

	SDL_RenderClear( renderer );
    return 0;
}

