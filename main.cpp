#include <allegro.h>
#include <math.h>

#define WHITE makecol(240,240,240)
#define GREEN makecol(0,220,0)
#define GREEN2 makecol(0,120,0)
#define NUM 1000

BITMAP *buffer;

bool set = true;
int speed = 50;
int scrx = 0;
int scry = 0;

struct particle
{
	int xp[NUM];
	int yp[NUM];

}p[NUM];

void setup()
{	
	if(set == true)
	{
           for(int i = 0; i < NUM; i++)
           {
            p[i].xp[i] = rand() % scrx;
			p[i].yp[i] = rand() % scry;
			}
		set = false;
	}
	for(int n = 1; n < NUM; n++)
    {
		textprintf_ex(buffer, font, p[n].xp[n], p[n].yp[n]    ,  WHITE, 0, "%c", (rand() % 254));
		textprintf_ex(buffer, font, p[n].xp[n], p[n].yp[n] -10,  GREEN, 0, "%c", (rand() % 254));
		textprintf_ex(buffer, font, p[n].xp[n], p[n].yp[n] -20, GREEN2, 0, "%c", (rand() % 254));
		textprintf_ex(buffer, font, p[n].xp[n], p[n].yp[n] -30, GREEN2, 0, "%c", (rand() % 254));
		textprintf_ex(buffer, font, p[n].xp[n], p[n].yp[n] -40, GREEN2, 0, "%c", (rand() % 254));
		textprintf_ex(buffer, font, p[n].xp[n], p[n].yp[n] -50, GREEN2, 0, "%c", (rand() % 254));
		if (n % 2 > 0)
		p[n].yp[n] = (p[n].yp[n]) + 4;

		if (n % 2 == 0)
		p[n].yp[n] = (p[n].yp[n]) + 8;

		if(p[n].yp[n] >= (scry+50))
			p[n].yp[n] = 0;
	}
	rest(speed);
    
}END_OF_FUNCTION(setup);

int main()
{
    int ret;
    
    allegro_init();
    install_keyboard();
    srand(time(NULL));

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

	// choose resolution
	textprintf_ex(screen, font, 150, 130,  WHITE, 0, "Choose Resolution");
	textprintf_ex(screen, font, 150, 140,  WHITE, 0, "1. 800x600");
	textprintf_ex(screen, font, 150, 150,  WHITE, 0, "2. 1024x768");
	textprintf_ex(screen, font, 150, 160,  WHITE, 0, "3. 1280x800");
	textprintf_ex(screen, font, 150, 170,  WHITE, 0, "4. 1360x768");
	textprintf_ex(screen, font, 150, 180,  WHITE, 0, "5. 1440x900");
	textprintf_ex(screen, font, 150, 190,  WHITE, 0, "6. 1680x1050");
	textprintf_ex(screen, font, 150, 200,  WHITE, 0, "7. 1920x1080");
	textprintf_ex(screen, font, 150, 200,  WHITE, 0, "8. 1920x1200");

	readkey();
	if(key[KEY_1_PAD] || key[KEY_1])
	{
		scrx = 800;
		scry = 600;
	}
	else if(key[KEY_2_PAD] || key[KEY_2])
	{
		scrx = 1024;
		scry = 768;
	}
	else if(key[KEY_3_PAD] || key[KEY_3])
	{
		scrx = 1280;
		scry = 800;
	}
	else if(key[KEY_4_PAD] || key[KEY_4])
	{
		scrx = 1360;
		scry = 768;
	}
	else if(key[KEY_5_PAD] || key[KEY_5])
	{
		scrx = 1440;
		scry = 900;
	}
	else if(key[KEY_6_PAD] || key[KEY_6])
	{
		scrx = 1680;
		scry = 1050;
	}
	else if(key[KEY_7_PAD] || key[KEY_7])
	{
		scrx = 1920;
		scry = 1080;
	}
	else if(key[KEY_8_PAD] || key[KEY_8])
	{
		scrx = 1920;
		scry = 1200;
	}
	else
	{
		scrx = 800;
		scry = 600;
	}
	ret = set_gfx_mode(GFX_AUTODETECT, scrx, scry, 0, 0);
    if (ret != 0) {
    allegro_message(allegro_error);
    return 1;
    }

    buffer = create_bitmap(scrx, scry);
	    	
    //wait for keypress
    while(!key[KEY_ESC])
    {
		setup();	
				
		textprintf_ex(buffer, font, 0, 0, WHITE, -1,
        "The Matrix - by guili - %dx%d - Press ESC to quit",
        SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0,0,0,0,scrx,scry);
        clear_bitmap(buffer);
        
    }
    
    //end program
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
