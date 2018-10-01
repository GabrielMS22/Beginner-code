#include <allegro.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "inicia.h"



#define height 600
#define width 800


typedef struct tcarta
              {
                  int numero;
                  int valor;
                  struct tcarta *sig;
              }Tcartas;

typedef Tcartas *Tnodo;


void Push(Tnodo *pila, int n);
int Pop(Tnodo *pila);
int buscar(int *vectorr, int na,int contador);


int main ()
   {

       //Inicia Allegro y sus componentes.
       allegro_init();
       install_keyboard();
       install_mouse();
       set_color_depth(32);
       set_gfx_mode( GFX_AUTODETECT_WINDOWED , width , height , 0 , 0 );
       set_window_title("Blackjack");
       install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

       //Si falla al iniciar sonido...
        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
         {
           allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
         }
         set_display_switch_mode(SWITCH_BACKGROUND);
         srand(time(NULL));

         FONT *font=load_font("Font/Blackfont.pcx",NULL,NULL);

       int iniciar=1;
       int x=0,y=0,i,na,x2=0,y2=0,baraja=0,pbaraj=0,bj=1,j,tu=1,bot=1,x3=200,y3=100,n1,n2,n3,n4,n5,n6,n7,n8,x4=230,y4=380,puntaje,puntajec,ganadastu=0,ganadasbot=0;
       Tnodo pila=NULL;
       tcarta c[52];


        //Musica de juego
        MIDI *musica1=load_midi("Sonido/blackjack.mid");

        //Bitmaps de Menu y Buffer
        BITMAP *buffer = create_bitmap(width, height);
        BITMAP *menu = load_bitmap("menu.bmp", NULL);
        BITMAP *jugar = load_bitmap("ImagenesBMP/jugar.bmp", NULL);
        BITMAP *cursor = load_bitmap("ImagenesBMP/cursor.bmp", NULL);
        BITMAP *salir = load_bitmap("ImagenesBMP/salir.bmp", NULL);
        BITMAP *tablero=load_bitmap("ImagenesBMP/tabler.bmp", NULL);
        BITMAP *tablerofinal=load_bitmap("ImagenesBMP/tablerfin.bmp",NULL);
        BITMAP *text= load_bitmap("ImagenesBMP/Blackjacktexto.bmp", NULL);
        BITMAP *pedir=load_bitmap("ImagenesBMP/pedir.bmp", NULL);
        BITMAP *plantarse=load_bitmap("ImagenesBMP/plantarse.bmp", NULL);
        BITMAP *Creditos=load_bitmap("ImagenesBMP/Creditos.bmp", NULL);


       //Bitmaps Carta controlador
       BITMAP *cartas[52];
       //Carta de Trebol
       cartas[0] = load_bitmap("ImagenesBMP/cartas/astrevoles.bmp", NULL);
       cartas[1] = load_bitmap("ImagenesBMP/cartas/2trevoles.bmp", NULL);
       cartas[2] = load_bitmap("ImagenesBMP/cartas/3trevoles.bmp", NULL);
       cartas[3] = load_bitmap("ImagenesBMP/cartas/4trevoles.bmp", NULL);
       cartas[4] = load_bitmap("ImagenesBMP/cartas/5trevoles.bmp", NULL);
       cartas[5] = load_bitmap("ImagenesBMP/cartas/6trevoles.bmp", NULL);
       cartas[6] = load_bitmap("ImagenesBMP/cartas/7trevoles.bmp", NULL);
       cartas[7] = load_bitmap("ImagenesBMP/cartas/8trevoles.bmp", NULL);
       cartas[8] = load_bitmap("ImagenesBMP/cartas/9trevoles.bmp", NULL);
       cartas[9] = load_bitmap("ImagenesBMP/cartas/10trevoles.bmp", NULL);
       cartas[10] = load_bitmap("ImagenesBMP/cartas/jtrevoles.bmp", NULL);
       cartas[11] = load_bitmap("ImagenesBMP/cartas/qtrevoles.bmp", NULL);
       cartas[12] = load_bitmap("ImagenesBMP/cartas/ktrevoles.bmp", NULL);
       //Cartas de Diamante
       cartas[13] = load_bitmap("ImagenesBMP/cartas/asdiamantes.bmp", NULL);
       cartas[14] = load_bitmap("ImagenesBMP/cartas/2diamantes.bmp", NULL);
       cartas[15] = load_bitmap("ImagenesBMP/cartas/3diamantes.bmp", NULL);
       cartas[16] = load_bitmap("ImagenesBMP/cartas/4diamantes.bmp", NULL);
       cartas[17] = load_bitmap("ImagenesBMP/cartas/5diamantes.bmp", NULL);
       cartas[18] = load_bitmap("ImagenesBMP/cartas/6diamantes.bmp", NULL);
       cartas[19] = load_bitmap("ImagenesBMP/cartas/7diamantes.bmp", NULL);
       cartas[20] = load_bitmap("ImagenesBMP/cartas/8diamantes.bmp", NULL);
       cartas[21] = load_bitmap("ImagenesBMP/cartas/9diamantes.bmp", NULL);
       cartas[22] = load_bitmap("ImagenesBMP/cartas/10diamantes.bmp", NULL);
       cartas[23] = load_bitmap("ImagenesBMP/cartas/jdiamantes.bmp", NULL);
       cartas[24] = load_bitmap("ImagenesBMP/cartas/qdiamantes.bmp", NULL);
       cartas[25] = load_bitmap("ImagenesBMP/cartas/kdiamantes.bmp", NULL);
       //Cartas de Espada
       cartas[26] = load_bitmap("ImagenesBMP/cartas/asespadas.bmp", NULL);
       cartas[27] = load_bitmap("ImagenesBMP/cartas/2espadas.bmp", NULL);
       cartas[28] = load_bitmap("ImagenesBMP/cartas/3espadas.bmp", NULL);
       cartas[29] = load_bitmap("ImagenesBMP/cartas/4espadas.bmp", NULL);
       cartas[30] = load_bitmap("ImagenesBMP/cartas/5espadas.bmp", NULL);
       cartas[31] = load_bitmap("ImagenesBMP/cartas/6espadas.bmp", NULL);
       cartas[32] = load_bitmap("ImagenesBMP/cartas/7espadas.bmp", NULL);
       cartas[33] = load_bitmap("ImagenesBMP/cartas/8espadas.bmp", NULL);
       cartas[34] = load_bitmap("ImagenesBMP/cartas/9espadas.bmp", NULL);
       cartas[35] = load_bitmap("ImagenesBMP/cartas/10espadas.bmp", NULL);
       cartas[36] = load_bitmap("ImagenesBMP/cartas/jespadas.bmp", NULL);
       cartas[37] = load_bitmap("ImagenesBMP/cartas/qespadas.bmp", NULL);
       cartas[38] = load_bitmap("ImagenesBMP/cartas/kespadas.bmp", NULL);
       //Cartas de Corazon
       cartas[39] = load_bitmap("ImagenesBMP/cartas/ascorazones.bmp", NULL);
       cartas[40] = load_bitmap("ImagenesBMP/cartas/2corazones.bmp", NULL);
       cartas[41] = load_bitmap("ImagenesBMP/cartas/3corazones.bmp", NULL);
       cartas[42] = load_bitmap("ImagenesBMP/cartas/4corazones.bmp", NULL);
       cartas[43] = load_bitmap("ImagenesBMP/cartas/5corazones.bmp", NULL);
       cartas[44] = load_bitmap("ImagenesBMP/cartas/6corazones.bmp", NULL);
       cartas[45] = load_bitmap("ImagenesBMP/cartas/7corazones.bmp", NULL);
       cartas[46] = load_bitmap("ImagenesBMP/cartas/8corazones.bmp", NULL);
       cartas[47] = load_bitmap("ImagenesBMP/cartas/9corazones.bmp", NULL);
       cartas[48] = load_bitmap("ImagenesBMP/cartas/10corazones.bmp", NULL);
       cartas[49] = load_bitmap("ImagenesBMP/cartas/jcorazones.bmp", NULL);
       cartas[50] = load_bitmap("ImagenesBMP/cartas/qcorazones.bmp", NULL);
       cartas[51] = load_bitmap("ImagenesBMP/cartas/kcorazones.bmp", NULL);
       //Valor de las Cartas



       c[0].valor=1;
       c[1].valor=2;
       c[2].valor=3;
       c[3].valor=4;
       c[4].valor=5;
       c[5].valor=6;
       c[6].valor=7;
       c[7].valor=8;
       c[8].valor=9;
       c[9].valor=10;
       c[10].valor=10;
       c[11].valor=10;
       c[12].valor=10;
       c[13].valor=1;
       c[14].valor=2;
       c[15].valor=3;
       c[16].valor=4;
       c[17].valor=5;
       c[18].valor=6;
       c[19].valor=7;
       c[20].valor=8;
       c[21].valor=9;
       c[22].valor=10;
       c[23].valor=10;
       c[24].valor=10;
       c[25].valor=10;
       c[26].valor=1;
       c[27].valor=2;
       c[28].valor=3;
       c[29].valor=4;
       c[30].valor=5;
       c[31].valor=6;
       c[32].valor=7;
       c[33].valor=8;
       c[34].valor=9;
       c[35].valor=10;
       c[36].valor=10;
       c[37].valor=10;
       c[38].valor=10;
       c[39].valor=1;
       c[40].valor=2;
       c[41].valor=3;
       c[42].valor=4;
       c[43].valor=5;
       c[44].valor=6;
       c[45].valor=7;
       c[46].valor=8;
       c[47].valor=9;
       c[48].valor=10;
       c[49].valor=10;
       c[50].valor=10;
       c[51].valor=10;

        set_volume(200,200);
        play_midi(musica1,20);


        while (iniciar!=0)
            {

                while (iniciar==1)
                     {
                         if (mouse_x > 58 && mouse_x <319 && mouse_y > 360 && mouse_y < 417)
                           {
                               masked_blit(jugar, buffer, 0, 0, 0, 0, width, height);
                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                               blit(buffer, screen, 0, 0, 0, 0, width, height);
                               if (mouse_b & 1)
                                  {
                                         for(i=800;i>=300;i=i-1)
								            {

                                              blit(tablero,buffer,0,0,0,0,width,height);
                                              masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
									          blit(text,buffer,0,0,i,25,400, 600);
                                              blit(buffer,screen,0,0,0,0,800, 600);
								            }

                                            iniciar=2;//Inicia Blackjack

                                  }

                            }

                          else if (mouse_x > 60 && mouse_x < 316 && mouse_y > 457 && mouse_y < 516)
                           {
                               masked_blit(salir, buffer, 0, 0, 0, 0, width, height);
                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                               blit(buffer, screen, 0, 0, 0, 0, width, height);
                               if (mouse_b & 1)
                                  {
                                      masked_blit(Creditos, buffer, 0, 0, 0, 0, width, height);
                                      blit(buffer, screen, 0, 0, 0, 0, width, height);
                                      rest(1000);
                                      textout_ex(screen, font, "Cerrando Blackjack",40,580,457,palette_color[255]);
                                      rest(4000);
                                      iniciar=0;//Forza al ciclo a terminor, sale del juego
                                  }
                           }
                          else
                           {
                               masked_blit(menu, buffer, 0, 0, 0, 0, width, height);
                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                               blit(buffer, screen, 0, 0, 0, 0, width, height);
                           }
                     }
                     //Juego inicio
                     while(iniciar==2)
                     {




                            int bandera;
                             int vectorr[51];
                             int contador=0;
                              for (baraja=0; baraja<52;baraja++)
                             {
                                 contador++;
                                 do
                                 {
                                     na=rand()%51;
                                     bandera=buscar(vectorr,na,contador);
                                 }while(bandera>0);

                                 c[baraja].numero=na;
                             }




                          for (baraja=0; baraja<52; baraja++)
                             {
                                 Push(&pila, c[baraja].numero);
                             }

                              while (bj==1)
                               {
                                   if (tu==1)
                                     {
                                         n1=Pop(&pila);
                                         masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                         textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                         textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                         blit(text,buffer,0,0,i,25,400, 600);
                                         masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                         blit(buffer, screen, 0, 0, 0, 0, width, height);
                                         rest(500);
                                         n2=Pop(&pila);
                                         masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                         blit(text,buffer,0,0,i,25,400, 600);
                                         textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                         textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                         masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                         masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                         blit(buffer, screen, 0, 0, 0, 0, width, height);
                                         rest(500);

                                         tu=2;
                                     }
                                   if (bot==1)
                                     {
                                         n3=Pop(&pila);
                                         masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                         blit(text,buffer,0,0,i,25,400, 600);
                                         textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                         textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                         masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                         masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                         masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                         blit(buffer, screen, 0, 0, 0, 0, width, height);

                                         rest(500);
                                         n4=Pop(&pila);
                                         masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                         blit(text,buffer,0,0,i,25,400, 600);
                                         textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                         textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                         masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                         masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                         masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                         masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                         blit(buffer, screen, 0, 0, 0, 0, width, height);
                                         rest(500);
                                         bot=2;
                                     }
                                  //OPERACIONES DE BLACKJACK
                                  if (bot==2 && tu==2)
                                    {
                                          puntaje = c[n3].valor + c[n4].valor;
                                          puntajec = c[n1].valor + c[n2].valor;

                                          if (c[n3].valor==1 || c[n4].valor==1)
                                             {
                                                 masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                                 blit(text,buffer,0,0,i,25,400, 600);
                                                 textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                                 textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                                 masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                                 masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                                 masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                                 masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                                 masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                                 if (c[n3].valor==1 && c[n4].valor==1)
                                                    {
                                                    puntaje=1;
                                                    puntaje=puntaje+10;
                                                    }
                                               if((c[n3].valor==1) && (c[n4].valor)>=2 && c[n4].valor<=8  )
                                                 {
                                                   puntaje=1;
                                                   puntaje=puntaje+c[n4].valor;
                                                 }

                                               if((c[n3].valor==1) && (c[n4].valor)>=2 && c[n4].valor>9  )
                                                 {
                                                   puntaje=11;
                                                   puntaje=puntaje+c[n4].valor;
                                                 }
                                                 textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                                 blit(buffer, screen, 0, 0, 0, 0, width, height);
                                             }


                                       if (mouse_x > 580 && mouse_x < 683 && mouse_y > 410 && mouse_y < 470)
                                          {

                                               masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                               blit(text,buffer,0,0,i,25,400, 600);
                                               textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                               textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                               masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                               masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                               masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                               masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                               textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                               blit(buffer, screen, 0, 0, 0, 0, width, height);
                                                if(puntaje==21)
                                                   {
                                                     textout_ex(screen, font, "Tu numero es 21, Ganaste, BLACKJACK!",370,300,500,palette_color[255]);
                                                     rest(2500);
                                                     ganadastu++;
                                                      if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);

                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;

                                                    }
                                              //Validacion de Ases
                                              if (mouse_b & 1)
                                                {
                                                    bj=2; //Le da otra carta al jugador.


                                                }


                                           }
                                            else if (mouse_x >577 && mouse_x <752 && mouse_y >483 && mouse_y <525 )
                                                 {

                                               masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                               blit(text,buffer,0,0,i,25,400, 600);
                                               textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                               textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                               masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                               masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                               masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                               masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                               textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                               blit(buffer, screen, 0, 0, 0, 0, width, height);
                                                 if (mouse_b & 1)
                                                    {
                                                    if(puntaje > puntajec)
                                                      {

                                                     textout_ex(screen, font, "Ganaste",370,300,500,palette_color[255]);
                                                     rest(1000);
                                                     ganadastu++;
                                                      if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);

                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;


                                                     }
                                                     if(puntaje==puntajec)
                                                      {

                                                     textout_ex(screen, font, "Empate",370,300,500,palette_color[255]);
                                                     rest(1000);
                                                      if(pila)
                                                        {
                                                          int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;


                                                     }
                                                   else{
                                                    textout_ex(screen, font, "Perdiste",370,300,500,palette_color[255]);
                                                     rest(1000);
                                                     ganadasbot++;
                                                      if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;

                                                   }


                                                  }
                                                }
                                           else
                                            {
                                               masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                               blit(text,buffer,0,0,i,25,400, 600);
                                               textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                               textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                               masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                               masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                               masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                               masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                                 if (c[n3].valor==1 && c[n4].valor==1)
                                                    {
                                                    puntaje=1;
                                                    puntaje=puntaje+10;
                                                    }
                                               if((c[n3].valor==1) && (c[n4].valor)>=2 && c[n4].valor<=8  )
                                                 {
                                                   puntaje=1;
                                                   puntaje=puntaje+c[n4].valor;
                                                 }

                                               if((c[n3].valor==1) && (c[n4].valor)>=2 && c[n4].valor>9  )
                                                 {
                                                   puntaje=11;
                                                   puntaje=puntaje+c[n4].valor;
                                                 }

                                                 textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                                 blit(buffer, screen, 0, 0, 0, 0, width, height);
                                            }



                                      }


                                }
                        while(bj==2)
                            {
                                   if(tu==2)
                                   {
                                      n5=Pop(&pila);
                                     if(c[n5].valor==1)
                                      {
                                       puntaje = puntaje + 11;

                                      }
                                    else
                                      {
                                       puntaje = puntaje + c[n5].valor;
                                      }
                                   masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                   blit(text,buffer,0,0,i,25,400, 600);
                                   textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                   textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                   masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                   masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                   masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                   masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                   masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);

                                   masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                   textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                   blit(buffer, screen, 0, 0, 0, 0, width, height);
                                   tu=3;
                                   rest(500);

                                     if(puntaje>=22)
                                     {
                                         textout_ex(screen, font, "Tu numero es mayor a 21, PIERDES",370,300,500,palette_color[255]);
                                         rest(1500);
                                         ganadasbot++;
                                          if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                               b=Pop(&pila);
                                                            }
                                                        }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;
                                     }
                                     if(puntaje==21)
                                     {
                                         textout_ex(screen, font, "Tu numero es 21, Ganaste, BLACKJACK!",370,300,500,palette_color[255]);
                                         rest(1500);
                                         ganadastu++;
                                          if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;

                                     }

                                   }
                                   if(bot==2)
                                   {
                                     n6=Pop(&pila);
                                    if (c[n6].valor==1)
                                       {
                                       puntajec = puntajec + 11;

                                       }
                                      else
                                        {
                                         puntajec = puntajec + c[n6].valor;
                                        }

                                   masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                   blit(text,buffer,0,0,i,25,400, 600);
                                   textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                   textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                   masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                   masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                   masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                   masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                   masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                   masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);

                                   masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                   textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                   blit(buffer, screen, 0, 0, 0, 0, width, height);
                                   bot=3;
                                     if(puntajec>=22)
                                       {
                                       textout_ex(screen, font, "El numero del BOT es mayor a 21, GANASTE!",250,300,500,palette_color[255]);
                                         rest(2500);
                                         ganadastu++;
                                          if(pila)
                                            {
                                                        int b=0;

                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                            }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;

                                       }
                                      if(puntajec==21)
                                       {
                                         textout_ex(screen, font, "El numero del BOT es 21, PERDISTE!",250,300,500,palette_color[255]);
                                         rest(2500);
                                         ganadasbot++;
                                          if(pila)
                                            {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                            }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;


                                       }
                                   rest(500);


                                   }




                                       if (mouse_x > 580 && mouse_x < 683 && mouse_y > 410 && mouse_y < 470)
                                          {

                                               masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                               blit(text,buffer,0,0,i,25,400, 600);
                                               textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                               textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                                masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                                masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                                masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                                masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                                masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                               masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                               textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                               blit(buffer, screen, 0, 0, 0, 0, width, height);

                                              //Validacion de Ases
                                              if (mouse_b & 1)
                                                {
                                                    //Le da otra carta al jugador.
                                                    bj=3;


                                                }


                                           }
                                          else if (mouse_x >577 && mouse_x <752 && mouse_y >483 && mouse_y <525 )
                                                 {

                                               masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                               blit(text,buffer,0,0,i,25,400, 600);
                                               textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                               textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                                masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                                masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                                masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                                masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                                masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                               masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                               masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                               textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                               blit(buffer, screen, 0, 0, 0, 0, width, height);
                                                 if (mouse_b & 1)
                                                    {
                                                    if(puntaje > puntajec)
                                                      {

                                                     textout_ex(screen, font, "Ganaste",370,300,500,palette_color[255]);
                                                     rest(1000);
                                                     ganadastu++;
                                                      if(pila)
                                                        {
                                                           int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;


                                                     }
                                                     if(puntaje==puntajec)
                                                      {

                                                     textout_ex(screen, font, "Empate",370,300,500,palette_color[255]);
                                                     rest(1000);
                                                      if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;


                                                     }
                                                   else{
                                                    textout_ex(screen, font, "Perdiste",370,300,500,palette_color[255]);
                                                     rest(1000);
                                                     ganadasbot++;
                                                      if(pila)
                                                        {
                                                            int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                                     bj=1;iniciar=1;tu=1;bot=1;
                                                     break;

                                                   }


                                                  }
                                                }

                                           else
                                            {
                                                masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                                blit(text,buffer,0,0,i,25,400, 600);
                                                textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                                textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                                masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                                masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                                masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                                masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                                masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                                masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                                masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                                textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                                blit(buffer, screen, 0, 0, 0, 0, width, height);
                                            }






                            }
                        while(bj==3)
                        {
                            if(tu==3)
                            {
                                      n7=Pop(&pila);
                                      if(c[n7].valor==1)
                                      {
                                       puntaje = puntaje + 11;

                                      }
                                    else
                                      {
                                       puntaje = puntaje + c[n7].valor;
                                      }
                                       masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                       blit(text,buffer,0,0,i,25,400, 600);
                                       textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                       textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                       masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                       masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                       masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                       masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                       masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                       masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                       masked_blit(cartas[n7], buffer, 0, 0, x4+160, y4, 150, 201);

                                   masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                   textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                   blit(buffer, screen, 0, 0, 0, 0, width, height);
                                   tu=4;
                                   rest(500);

                                     if(puntaje>=22)
                                     {
                                         textout_ex(screen, font, "Tu numero es mayor a 21, PIERDES",370,300,500,palette_color[255]);
                                         rest(1500);
                                         ganadasbot++;
                                          if(pila)
                                            {
                                                           int b=0;
                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                            }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;
                                     }
                                     if(puntaje==21)
                                     {
                                         textout_ex(screen, font, "Tu numero es 21, Ganaste, BLACKJACK!",370,300,500,palette_color[255]);
                                         rest(1500);
                                         ganadastu++;
                                          if(pila)
                                            {
                                                            int b=0;

                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                            }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;

                                     }

                                   }
                                   if(bot==3)
                                   {
                                        n8=Pop(&pila);
                                        if (c[n8].valor==1)
                                          {
                                          puntajec = puntajec + 11;

                                          }
                                        else
                                         {
                                            puntajec = puntajec + c[n8].valor;
                                        }

                                    masked_blit(tablero, buffer, 0, 0, 0, 0, width, height);
                                    blit(text,buffer,0,0,i,25,400, 600);
                                    textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                    textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                    masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                    masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                    masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                    masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                    masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                    masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                    masked_blit(cartas[n7], buffer, 0, 0, x4+160, y4, 150, 201);
                                    masked_blit(cartas[n8], buffer, 0, 0, x3+160, y3, 150, 201);

                                   masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                   textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                   blit(buffer, screen, 0, 0, 0, 0, width, height);
                                   bot=4;
                                     if(puntajec>=22)
                                       {
                                       textout_ex(screen, font, "El numero del BOT es mayor a 21, GANASTE!",250,300,500,palette_color[255]);
                                         rest(2500);
                                         ganadastu++;
                                          if(pila)
                                            {
                                                            int b=0;

                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                            }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;

                                       }
                                      if(puntajec==21)
                                       {
                                         textout_ex(screen, font, "El numero del BOT es 21, PERDISTE!",250,300,500,palette_color[255]);
                                         rest(2500);
                                         ganadasbot++;
                                          if(pila)
                                            {
                                                            int b=0;

                                                            while(pila)
                                                            {
                                                               b=Pop(&pila);
                                                            }
                                            }
                                         bj=1;iniciar=1;tu=1;bot=1;
                                         break;


                                       }
                                   rest(500);


                                   }
                                       if (mouse_x > 566 && mouse_x < 764 && mouse_y > 408 && mouse_y < 525)
                                          {

                                                 masked_blit(tablerofinal, buffer, 0, 0, 0, 0, width, height);
                                                 blit(text,buffer,0,0,i,25,400, 600);
                                                 textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                                 textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                                 masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                                 masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                                 masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                                 masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                                 masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                                 masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                                 masked_blit(cartas[n7], buffer, 0, 0, x4+160, y4, 150, 201);
                                                 masked_blit(cartas[n8], buffer, 0, 0, x3+160, y3, 150, 201);
                                                 masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                                 textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                                 blit(buffer, screen, 0, 0, 0, 0, width, height);


                                              if (mouse_b & 1)
                                                {
                                                      if(puntaje>=22)
                                                         {
                                                          textout_ex(screen, font, "Tu numero es mayor a 21, PIERDES",370,300,500,palette_color[255]);
                                                          rest(1500);
                                                          ganadasbot++;
                                                           if(pila)
                                                             {
                                                                 int b=0;

                                                                 while(pila)
                                                                   {
                                                                    b=Pop(&pila);
                                                                   }
                                                            }
                                                          bj=1;iniciar=1;tu=1;bot=1;
                                                          break;
                                                         }
                                                        if(puntaje==21)
                                                        {
                                                        textout_ex(screen, font, "Tu numero es 21, Ganaste, BLACKJACK!",370,300,500,palette_color[255]);
                                                        rest(1500);
                                                        ganadastu++;
                                                         if(pila)
                                                           {
                                                              int b=0;

                                                              while(pila)
                                                               {
                                                                b=Pop(&pila);;
                                                               }
                                                           }
                                                        bj=1;iniciar=1;tu=1;bot=1;


                                                        break;

                                                        }
                                                      if(puntajec>=22)
                                                        {
                                                        textout_ex(screen, font, "El numero del BOT es mayor a 21, GANASTE!",250,300,500,palette_color[255]);
                                                        rest(2500);
                                                        ganadastu++;
                                                         if(pila)
                                                           {
                                                            int b=0;

                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                           }
                                                         bj=1;iniciar=1;tu=1;bot=1;
                                                         break;

                                                       }
                                                      if(puntajec==21)
                                                          {
                                                           textout_ex(screen, font, "El numero del BOT es 21, PERDISTE!",250,300,500,palette_color[255]);
                                                           rest(2500);
                                                           ganadasbot++;
                                                            if(pila)
                                                              {
                                                               int b=0;

                                                                while(pila)
                                                                     {
                                                                       b=Pop(&pila);
                                                                     }
                                                             }
                                                           bj=1;iniciar=1;tu=1;bot=1;
                                                            break;
                                                          }
                                                       if(puntaje>puntajec)
                                                       {
                                                        textout_ex(screen, font, "GANASTE",370,300,500,palette_color[255]);
                                                          rest(1500);
                                                          ganadastu++;
                                                           if(pila)
                                                            {
                                                             int b=0;

                                                              while(pila)
                                                              {
                                                                b=Pop(&pila);
                                                               }
                                                            }
                                                          bj=1;iniciar=1;tu=1;bot=1;
                                                          break;
                                                       }
                                                      if(puntajec>puntaje)
                                                      {
                                                          textout_ex(screen, font, "PERDISTE",370,300,500,palette_color[255]);
                                                          rest(1500);
                                                          ganadasbot++;
                                                           if(pila)
                                                             {
                                                            int b=0;

                                                            while(pila)
                                                               {
                                                                b=Pop(&pila);
                                                               }
                                                             }
                                                          bj=1;iniciar=1;tu=1;bot=1;
                                                          break;

                                                       }
                                                      if(puntaje==puntajec)
                                                      {
                                                         textout_ex(screen, font, "EMPATE",370,300,500,palette_color[255]);
                                                          rest(1500);
                                                           if(pila)
                                                            {
                                                            int b=0;

                                                              while(pila)
                                                                    {
                                                                    b=Pop(&pila);
                                                                    }
                                                            }
                                                          bj=1;iniciar=1;tu=1;bot=1;
                                                          break;
                                                      }
                                                       if(pila)
                                                        {
                                                            int b=0;

                                                            while(pila)
                                                            {
                                                                b=Pop(&pila);
                                                            }
                                                        }
                                                    bj=1;iniciar=1;tu=1;bot=1;


                                                }


                                           }


                                           else
                                            {
                                                masked_blit(tablerofinal, buffer, 0, 0, 0, 0, width, height);
                                                blit(text,buffer,0,0,i,25,400, 600);
                                                textprintf(buffer, font, 50, 50, palette_color[7], "%Veces ganadas: %d ", ganadastu);
                                                textprintf(buffer, font, 50, 70, palette_color[7], "%Veces perdidas: %d ", ganadasbot);
                                                masked_blit(cartas[n1], buffer, 0, 0, x3, y3, 150, 201);
                                                masked_blit(cartas[n2], buffer, 0, 0, x3+75, y3, 150, 201);
                                                masked_blit(cartas[n3], buffer, 0, 0, x4, y4, 150, 201);
                                                masked_blit(cartas[n4], buffer, 0, 0, x4+75, y4, 150, 201);
                                                masked_blit(cartas[n5], buffer, 0, 0, x4+120, y4, 150, 201);
                                                masked_blit(cartas[n6], buffer, 0, 0, x3+120, y3, 150, 201);
                                                masked_blit(cartas[n7], buffer, 0, 0, x4+160, y4, 150, 201);
                                                masked_blit(cartas[n8], buffer, 0, 0, x3+160, y3, 150, 201);
                                                masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 20, 25);
                                                textprintf(buffer, font, 600, 360, palette_color[11], "%Puntos: %d ", puntaje);
                                                blit(buffer, screen, 0, 0, 0, 0, width, height);
                                            }


                        }



                     }





            }
            //Fin del juego


        //Destruccion de Bitmaps
       destroy_midi(musica1);
       destroy_bitmap(buffer);
       destroy_bitmap(menu);
       destroy_bitmap(jugar);
       destroy_bitmap(cursor);
       destroy_bitmap(salir);
       destroy_bitmap(tablero);
       destroy_bitmap(tablerofinal);
       destroy_bitmap(text);
       destroy_bitmap(pedir);
       destroy_bitmap(plantarse);
       destroy_bitmap(Creditos);
       stop_midi();
       allegro_exit();
   }
   END_OF_MAIN();

void Push(Tnodo *pila, int n)
   {
    Tnodo nuevo;
    nuevo = (Tnodo)malloc(sizeof(Tcartas));
    (nuevo->numero)=n;
    (nuevo->sig)=*pila;
    (*pila)=nuevo;
   }

int Pop(Tnodo *pila)
   {
    int n;
    Tnodo eliminar;
    eliminar=(*pila);
    n=(eliminar->numero);
    (*pila)=(eliminar->sig);
    free(eliminar);
    return n;
   }

int buscar(int *vectorr, int na, int contador)
{
    int i;
    for(i=0;i<contador;i++)
    {
        if(vectorr[i]==na)
         {
            return i;
         }
    }
    return -1;
}
