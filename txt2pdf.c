/*

GarageCode Genial Creations Hehehe
http://GarageCode.tk

*Function this programm
this program i use to convert file TXT to PDF

*tested with GCC but wheel in others compilers...
 i wheel on Unix/Linux/*BSD this: 
    gcc -Wall -o program program.c -l cairo; ./program

Author: Antonio "Cooler_x0a" 
contact: tony.unix@yahoo.com.br
license: BSD

visit this site: http://BotecoUnix.com.br
Real Geeks BotecoUnix

greetz 
Thanks _mlk_ , m0nad,IAK,Fox,nibbles and Chris Torek. 
K&R for book ansi C

reference and Big greetz 
http://web.torek.net/torek/ 

      .--..--..--..--..--..--.
    .' \  (`._   (_)     _   \
  .'    |  '._)         (_)  |
  \ _.')\      .----..---.   /
  |(_.'  |    /    .-\-.  \  |
  \     0|    |   ( O| O) | o|
   |  _  |  .--.____.'._.-.  |
   \ (_) | o         -` .-`  |
    |    \   |`-._ _ _ _ _\ /
    \    |   |  `. |_||_|   |     Solution!
    | o  |    \_      \     |     -.   .-.
    |.-.  \     `--..-'   O |     `.`-' .'
  _.'  .' |     `-.-'      /-.__   ' .-'
.' `-.` '.|='=.='=.='=.='=|._/_ `-'.'
`-._  `.  |________/\_____|    `-.'
   .'   ).| '=' '='\/ '=' |
   `._.`  '---------------'
           //___\   //___\
             ||       ||
             ||_.-.   ||_.-.
            (_.--__) (_.--__)

*/
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
//definindo vars, ponteiro surface e cr
 float position;
   char str[200];

  FILE *fp;

  cairo_surface_t *surface;
  cairo_t *cr;
//definindo nome do arquivo
  surface = cairo_pdf_surface_create("pdffile.pdf", 504, 648);
//defindo a função create do cairo
  cr = cairo_create(surface);
//definindo cor da fonte,aqui usado padrão RGB(red,green,blue) definimos o "blue" setamos para 255
  cairo_set_source_rgb(cr, 0, 0, 0);
//definindo tipo da fonte
  cairo_select_font_face (cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
//definindo tamanho da fonte
  cairo_set_font_size (cr, 5.0);
//definindo posição inicial da fonte
  position=50.0;
//abrir file ler linha por linha e escrever no PDF
  fp = fopen("text.txt", "r");
    if(!fp) return 1; 
  while(fgets(str,sizeof(str),fp) != NULL) {
      int len = strlen(str)-1;
      if(str[len] == '\n') str[len] = 0;
     printf("\x0a %s", str);
  cairo_move_to(cr, 8.0, position);
  cairo_show_text(cr, str);
//variavel position sempre atribui o tamanho da fonte inicial no caso 20 
//assim temos uma lógica simples fazendo pular a linha
  position+=8;
 }
  fclose(fp);


  cairo_show_page(cr);
//destruindo ponteiros definidos
  cairo_surface_destroy(surface);
  cairo_destroy(cr);

  return 0;
}

