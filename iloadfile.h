#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include<conio.h>
#include<stdio.h>
SDL_Event event;
SDL_Surface *bg = NULL;
//The top surfaces

SDL_Surface *lsline = NULL;
SDL_Surface *frline = NULL;

SDL_Surface *f1 = NULL;
SDL_Surface *f2 = NULL;
SDL_Surface *f3 = NULL;
SDL_Surface *f4 = NULL;
SDL_Surface *f5 = NULL;
SDL_Surface *f6 = NULL;
SDL_Surface *f7 = NULL;
SDL_Surface *f8 = NULL;
SDL_Surface *f9 = NULL;
int cf[10];
//bottom surfaces
SDL_Surface *b1 = NULL;
SDL_Surface *b2 = NULL;
SDL_Surface *b3 = NULL;
SDL_Surface *b4 = NULL;
SDL_Surface *b5 = NULL;
SDL_Surface *b6 = NULL;
SDL_Surface *b7 = NULL;
SDL_Surface *b8 = NULL;
SDL_Surface *b9 = NULL;
int cb[10];
//right surfaces
SDL_Surface *r1 = NULL;
SDL_Surface *r2 = NULL;
SDL_Surface *r3 = NULL;
SDL_Surface *r4 = NULL;
SDL_Surface *r5 = NULL;
SDL_Surface *r6 = NULL;
SDL_Surface *r7 = NULL;
SDL_Surface *r8 = NULL;
SDL_Surface *r9 = NULL;
int cr[10];
//left surfaces
SDL_Surface *l1 = NULL;
SDL_Surface *l2 = NULL;
SDL_Surface *l3 = NULL;
SDL_Surface *l4 = NULL;
SDL_Surface *l5 = NULL;
SDL_Surface *l6 = NULL;
SDL_Surface *l7 = NULL;
SDL_Surface *l8 = NULL;
SDL_Surface *l9 = NULL;
int cl[10];
//forward surface
SDL_Surface *fr1 = NULL;
SDL_Surface *fr2 = NULL;
SDL_Surface *fr3 = NULL;
SDL_Surface *fr4 = NULL;
SDL_Surface *fr5 = NULL;
SDL_Surface *fr6 = NULL;
SDL_Surface *fr7 = NULL;
SDL_Surface *fr8 = NULL;
SDL_Surface *fr9 = NULL;
int cfr[10];
//backward surfaces
SDL_Surface *bk1 = NULL;
SDL_Surface *bk2 = NULL;
SDL_Surface *bk3 = NULL;
SDL_Surface *bk4 = NULL;
SDL_Surface *bk5 = NULL;
SDL_Surface *bk6 = NULL;
SDL_Surface *bk7 = NULL;
SDL_Surface *bk8 = NULL;
SDL_Surface *bk9 = NULL;
int cbk[10];
SDL_Surface *screen = NULL;
SDL_Surface *hline = NULL;
SDL_Surface *vline = NULL;

//Screen attributes
const int SCREEN_WIDTH = 1050;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
int select=1;
//The frame rate
const int FRAMES_PER_SECOND = 20;

//The dot dimensions
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;


//The event structure


//The camera



//The timer
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};


bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "RUBY", NULL );

    //If everything initialized fine
    return true;
}

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
int hl=1;
int vl=1,move=0;
int lr=0,frs=0,ls=0;
bool load_files()
{
    //Load the dot image

bg= load_image( "ri//bg.png" );
vline=load_image("ri//vline.png");
frline=load_image("ri//frline.png");
lsline=load_image("ri//lsline.png");
    //Load the background
    cf[1]=1;
   f1 = load_image( "ri//R.png" );
   cf[2]=1;
   f2 = load_image( "ri//R.png" );
   cf[3]=1;
   f3 = load_image( "ri//R.png" );
   cf[4]=1;
   f4 = load_image( "ri//R.png" );
   cf[5]=1;
   f5 = load_image( "ri//R.png" );
   cf[6]=1;
   f6 = load_image( "ri//R.png" );
   cf[7]=1;
    f7 = load_image( "ri//R.png" );
    cf[8]=1;
   f8 = load_image( "ri//R.png" );
   cf[9]=1;
   f9 = load_image( "ri//R.png" );
   //right side color
   cr[1]=2;
   r1 = load_image( "ri//SG.png" );
   cr[2]=2;
   r2 = load_image( "ri//SG.png" );
   cr[3]=2;
   r3 = load_image( "ri//SG.png" );
   cr[4]=2;
   r4 = load_image( "ri//SG.png" );
   cr[5]=2;
   r5 = load_image( "ri//SG.png" );
   cr[6]=2;
   r6 = load_image( "ri//SG.png" );
   cr[7]=2;
    r7 = load_image( "ri//SG.png" );
    cr[8]=2;
   r8 = load_image( "ri//SG.png" );
   cr[9]=2;
r9 = load_image( "ri//SG.png" );
 //left side color
    cl[1]=3;
    l1 = load_image( "ri//SB.png" );
    cl[2]=3;
    l2 = load_image( "ri//SB.png" );
    cl[3]=3;
    l3 = load_image( "ri//SB.png" );
    cl[4]=3;
    l4 = load_image( "ri//SB.png" );
    cl[5]=3;
    l5 = load_image( "ri//SB.png" );
    cl[6]=3;
    l6 = load_image( "ri//SB.png" );
    cl[7]=3;
    l7 = load_image( "ri//SB.png" );
    cl[8]=3;
    l8 = load_image( "ri//SB.png" );
    cl[9]=3;
    l9 = load_image( "ri//SB.png" );
//bottom side color
    cb[1]=4;
    b1 = load_image( "ri//Y.png" );
    cb[2]=4;
    b2 = load_image( "ri//Y.png" );
    cb[3]=4;
    b3 = load_image( "ri//Y.png" );
    cb[4]=4;
    b4 = load_image( "ri//Y.png" );
    cb[5]=4;
    b5 = load_image( "ri//Y.png" );
    cb[6]=4;
    b6 = load_image( "ri//Y.png" );
    cb[7]=4;
    b7 = load_image( "ri//Y.png" );
    cb[8]=4;
    b8 = load_image( "ri//Y.png" );
    cb[9]=4;
    b9 = load_image( "ri//Y.png" );
     //forward side color
    cfr[1]=5;
    fr1 = load_image( "ri//SSV.png" );
    cfr[2]=5;
    fr2 = load_image( "ri//SSV.png" );
    cfr[3]=5;
    fr3 = load_image( "ri//SSV.png" );
    cfr[4]=5;
    fr4 = load_image( "ri//SSV.png" );
    cfr[5]=5;
    fr5 = load_image( "ri//SSV.png" );
    cfr[6]=5;
    fr6 = load_image( "ri//SSV.png" );
    cfr[7]=5;
    fr7 = load_image( "ri//SSV.png" );
    cfr[8]=5;
    fr8 = load_image( "ri//SSV.png" );
    cfr[9]=5;
    fr9 = load_image( "ri//SSV.png" );
     //backward side color
    cbk[1]=6;
    bk1 = load_image( "ri//SSP.png" );
    cbk[2]=6;
    bk2 = load_image( "ri//SSP.png" );
    cbk[3]=6;
    bk3 = load_image( "ri//SSP.png" );
    cbk[4]=6;
    bk4 = load_image( "ri//SSP.png" );
    cbk[5]=6;
    bk5 = load_image( "ri//SSP.png" );
    cbk[6]=6;
    bk6 = load_image( "ri//SSP.png" );
    cbk[7]=6;
    bk7 = load_image( "ri//SSP.png" );
    cbk[8]=6;
    bk8 = load_image( "ri//SSP.png" );
    cbk[9]=6;
    bk9 = load_image( "ri//SSP.png" );
    //forward top side color

    return true;
}
void clean_ups()
{
    //Free the surfaces
    SDL_FreeSurface( bg );
SDL_FreeSurface( f1 );
SDL_FreeSurface( f2 );
SDL_FreeSurface( f3 );
SDL_FreeSurface( f4 );
SDL_FreeSurface( f5 );
SDL_FreeSurface( f6 );
SDL_FreeSurface( f7 );
SDL_FreeSurface( f8 );
SDL_FreeSurface( f9 );
SDL_FreeSurface( b1 );
SDL_FreeSurface( b2 );
SDL_FreeSurface( b3 );
SDL_FreeSurface( b4 );
SDL_FreeSurface( b5 );
SDL_FreeSurface( b6 );
SDL_FreeSurface( b7 );
SDL_FreeSurface( b8 );
SDL_FreeSurface( b9 );
SDL_FreeSurface( r1 );
SDL_FreeSurface( r2 );
SDL_FreeSurface( r3 );
SDL_FreeSurface( r4 );
SDL_FreeSurface( r5 );
SDL_FreeSurface( r6 );
SDL_FreeSurface( r7 );
SDL_FreeSurface( r8 );
SDL_FreeSurface( r9 );

SDL_FreeSurface( l1 );
SDL_FreeSurface( l2 );
SDL_FreeSurface( l3 );
SDL_FreeSurface( l4 );
SDL_FreeSurface( l5 );
SDL_FreeSurface( l6 );
SDL_FreeSurface( l7 );
SDL_FreeSurface( l8 );
SDL_FreeSurface( l9 );

SDL_FreeSurface( fr1 );
SDL_FreeSurface( fr2 );
SDL_FreeSurface( fr3 );
SDL_FreeSurface( fr4 );
SDL_FreeSurface( fr5 );
SDL_FreeSurface( fr6 );
SDL_FreeSurface( fr7 );
SDL_FreeSurface( fr8 );
SDL_FreeSurface( fr9 );

SDL_FreeSurface( bk1 );
SDL_FreeSurface( bk2 );
SDL_FreeSurface( bk3 );
SDL_FreeSurface( bk4 );
SDL_FreeSurface( bk5 );
SDL_FreeSurface( bk6 );
SDL_FreeSurface( bk7 );
SDL_FreeSurface( bk8 );
SDL_FreeSurface( bk9 );
}

