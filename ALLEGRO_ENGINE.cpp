#include <allegro.h>

// DECLARACOES INICIAIS //
int sair=0; void sair_allegro() {sair=1;}; 
int timer=0; void tempo() {timer++;};
int Ctrl_FPS=60; float delay=0;

// INICIALIZACAO ALLEGRO //
int main()
{
  allegro_init();
  install_timer();
  install_keyboard();
  install_mouse(); 
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
  install_int_ex(tempo, BPS_TO_TIMER(60)); //60fps
  set_window_title("ALLEGRO MINIMAL");
  set_close_button_callback( sair_allegro );
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
  BITMAP *buffer = create_bitmap(640,480);  
  
  // LOOP DE JOGO // 
  while (sair==0)
  {
  delay=timer; 
	if (key[KEY_ESC]) {sair=1;}; 
	clear_to_color(buffer,makecol(100,149,237)); //fundo azul
	
	/* < SEU CODIGO AQUI! > */
  
  textprintf_ex(buffer, font, 5, 5, makecol(255,255,255), -1, "ALLEGRO MINIMAL by Daniel Moura - FPS[%d] [%d]", Ctrl_FPS, timer);
	draw_sprite(screen, buffer, 0, 0);
		
  // FINALIZACOES //
	while(timer==delay){};	
	clear(buffer);
  }; 
  destroy_bitmap(buffer);
  return 0;
};
END_OF_MAIN();

