
#include "load.h"
void showme();
int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;


    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

if( event.type == SDL_KEYDOWN )
            {

               if( event.key.keysym.sym == SDLK_UP )
                {
                    if(move==0){
                    if(hl<=1)
                    {
                        frs++;
                        hl=1;

                    }
                     else
                    hl--;
                    if(frs>3)
                    hl=3;
                    }
                    else{
                        if(ls==1)
                        {
                           lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                           lr=2;
                           hl=1;
                           load_file();
                           lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                        }
                       else if(ls==2)
                        {
                            lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                           lr=2;
                           hl=2;
                           load_file();
                           lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                        }
                        else if(ls==3)
                        {
                            lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                           lr=2;
                           hl=3;
                           load_file();
                           lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                        }
                       else{
                lr=3;
                        load_file();

                }}
                }
                else if(event.key.keysym.sym == SDLK_DOWN)
                {
                    if(move==0){
                    if(frs<=1)
                    {
                        hl++;
                        frs=1;
                    }
                    else
                    frs--;
                    if(hl>3)
                    frs=3;
                    }
                    else
                    {
                        if(ls==1)
                        {
                           lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                           lr=2;
                           hl=3;
                           load_file();
                           lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                        }
                       else if(ls==2)
                        {
                           lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                           lr=2;
                           hl=2;
                           load_file();
                           lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                        }
                        else if(ls==3)
                        {
                           lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                           lr=2;
                           hl=1;
                           load_file();
                           lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                        }
                        else
                        {
                        lr=4;
                        load_file();
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_LEFT)
                {
                    if(move==0){
                  if(ls>=1 && ls<=3)
                  {
                      ls--;
                    if(ls<=0)
                    {
                        vl=3;
                    }
                  }
                  else
                  {
                  vl--;
                  if(vl<=0)
                  ls=3;
                  }
                    }
                    else{
                        lr=1;
                    load_file();
                    }
                }
                else if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    if(move==0){
                  if(vl<=3 && vl>=1)
                  {
                    vl++;
                    if(vl>3)
                    ls=1;


                  }
                  else
                  {
                  ls++;
                  if(ls>3)
                  vl=1;

                  }
                }

                else{
                    lr=2;
                load_file();
                }

            }
             else if(event.key.keysym.sym == SDLK_w)
                {
                    lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                }
                  else if(event.key.keysym.sym == SDLK_s)
                {
                    lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                }
                   else if(event.key.keysym.sym == SDLK_d)
                {
                    lr=2;
                           hl=1;
                           load_file();
                           hl=2;
                           load_file();
                           hl=3;
                           load_file();
                }
                     else if(event.key.keysym.sym == SDLK_a)
                {
                    lr=1;
                           hl=1;
                           load_file();
                           hl=2;
                           load_file();
                           hl=3;
                           load_file();
                }
                     else if(event.key.keysym.sym == SDLK_e)
                {
                     lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                    lr=2;
                           hl=1;
                           load_file();
                           hl=2;
                           load_file();
                           hl=3;
                           load_file();
                            lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                }
                  else if(event.key.keysym.sym == SDLK_q)
                {
                     lr=4;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                    lr=1;
                           hl=1;
                           load_file();
                           hl=2;
                           load_file();
                           hl=3;
                           load_file();
                            lr=3;
                           vl=1;
                           load_file();
                           vl=2;
                           load_file();
                           vl=3;
                           load_file();
                }
             if( event.key.keysym.sym == SDLK_LSHIFT ||event.key.keysym.sym == SDLK_RSHIFT)
                {
                    move=1;
                    lr=0;
                }
            }
if( event.type == SDL_KEYUP )
            {
if( event.key.keysym.sym == SDLK_LSHIFT ||event.key.keysym.sym == SDLK_RSHIFT)
                {
                    move=0;

                }
            }


        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
         if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
apply_surface( 0, 0, bg, screen );
      showme();
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


    }

    //Clean up
    clean_ups();

    return 0;
}
void showme()
{

        apply_surface(80, 500+10-30, bk7, screen );
        apply_surface( 230,500+10-30, bk8, screen );
        apply_surface( 380, 500+10-30, bk9, screen );
        apply_surface( 50, 500+45-35, bk4, screen );
        apply_surface( 200, 500+45-35, bk5, screen );
        apply_surface( 350, 500+45-35, bk6, screen );
        apply_surface( 20, 500+75-35, bk1, screen );
        apply_surface( 170, 500+75-35, bk2, screen );
        apply_surface( 320, 500+75-35, bk3, screen );

        apply_surface( 20, 20+60, l3, screen );
        apply_surface( 50, 20+30, l2, screen );
        apply_surface( 80, 20, l1, screen );
        apply_surface( 20, 170+60, l6, screen );
        apply_surface( 50, 170+30, l5, screen );
        apply_surface( 80, 170, l4, screen );
        apply_surface( 20, 320+60, l9, screen );
        apply_surface( 50, 320+30, l8, screen );
        apply_surface( 80, 320, l7, screen );

        apply_surface( 100+0+25, 10+10, b1, screen );
        apply_surface( 100+150+25, 10+10, b2, screen );
        apply_surface( 100+300+25, 10+10, b3, screen );
        apply_surface( 100+0+25, 160+10, b4, screen );
        apply_surface( 100+150+25, 160+10, b5, screen );
        apply_surface( 100+300+25, 160+10, b6, screen );
        apply_surface( 100+0+25, 310+10, b7, screen );
        apply_surface( 100+150+25, 310+10, b8, screen );
        apply_surface( 100+300+25, 310+10, b9, screen );


        apply_surface(500-50, 70, fr7, screen );
        apply_surface( 500+150-50, 70, fr8, screen );
        apply_surface( 500+300-50, 70, fr9, screen );
        apply_surface( 500+30-50, 40, fr4, screen );
        apply_surface( 500+180-50, 40, fr5, screen );
        apply_surface( 500+330-50, 40, fr6, screen );
        apply_surface( 500+60-50, 10, fr1, screen );
        apply_surface( 500+210-50, 10, fr2, screen );
        apply_surface( 500+360-50, 10, fr3, screen );

        apply_surface( 500+400, 70, r1, screen );
        apply_surface( 500+430, 40, r2, screen );
        apply_surface( 500+510-50, 10, r3, screen );
        apply_surface( 500+450-50, 150+70, r4, screen );
        apply_surface( 500+480-50, 150+40, r5, screen );
        apply_surface( 500+510-50, 150+10, r6, screen );
        apply_surface( 500+450-50, 300+70, r7, screen );
        apply_surface( 500+480-50, 300+40, r8, screen );
        apply_surface( 500+510-50, 300+10, r9, screen );

        apply_surface( 500+0-50, 0+100, f1, screen );
        apply_surface( 500+100, 0+100, f2, screen );
        apply_surface( 500+250, 0+100, f3, screen );
        apply_surface( 500+0-50, 150+100, f4, screen );
        apply_surface( 500+100, 150+100, f5, screen );
        apply_surface( 500+250, 150+100, f6, screen );
        apply_surface( 500+0-50, 300+100, f7, screen );
        apply_surface( 500+100, 300+100, f8, screen );
        apply_surface( 500+250, 300+100, f9, screen );
if(hl==1)
{
    if(vl==1 &&(ls<=0||ls>=4))
    {
        apply_surface( 450,100 , vline, screen );
    }
    else if(vl==2 && (ls<=0||ls>=4))
    {
apply_surface( 600, 100, vline, screen );
    }
    else if(vl==3 && (ls<=0||ls>=4))
    {
apply_surface( 750, 100, vline, screen );
    }
     else if((vl<=0||vl>=4 )&&ls==1)
    {
        apply_surface( 900,70 , lsline, screen );
    }
    else if((vl<=0||vl>=4) && ls==2)
    {
apply_surface( 930, 40, lsline, screen );
    }
    else if((vl<=0||vl>=4) && ls==3)
    {
apply_surface( 960, 10, lsline, screen );
    }
}
else if(hl==2)
{
    if(vl==1 &&(ls==0||ls==4))
    {
        apply_surface( 450,100+150 , vline, screen );
    }
    else if(vl==2 && (ls==0||ls==4))
    {
apply_surface( 600, 100+150, vline, screen );
    }
    else if(vl==3 && (ls==0||ls==4))
    {
apply_surface( 750, 100+150, vline, screen );
    }
     else if((vl==0||vl==4 )&&ls==1)
    {
        apply_surface( 900,70 +150, lsline, screen );
    }
    else if((vl==0||vl==4) && ls==2)
    {
apply_surface( 930, 40+150, lsline, screen );
    }
    else if((vl==0||vl==4) && ls==3)
    {
apply_surface( 960, 10+150, lsline, screen );
    }
}
else if(hl==3)
{
    if(vl==1 &&(ls==0||ls==4))
    {
        apply_surface( 450,100+300 , vline, screen );
    }
    else if(vl==2 && (ls==0||ls==4))
    {
apply_surface( 600, 100+300, vline, screen );
    }
    else if(vl==3 && (ls==0||ls==4))
    {
apply_surface( 750, 100+300, vline, screen );
    }
     else if((vl==0||vl==4 )&&ls==1)
    {
        apply_surface( 900,70 +300, lsline, screen );
    }
    else if((vl==0||vl==4) && ls==2)
    {
apply_surface( 930, 40+300, lsline, screen );
    }
    else if((vl==0||vl==4) && ls==3)
    {
apply_surface( 960, 10+300, lsline, screen );
    }
}

}

