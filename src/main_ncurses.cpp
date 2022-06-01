#include <iostream>
#include <ncurses.h>
#include <vector>
#include <thread>
#include <chrono> 

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

using namespace std;


void print_choices(int highlight, vector<string> &choices){
  int x, y, i;

  x = 2;
  y = 2;
  for(i = 0; i < choices.size(); ++i){
    if(highlight == i + 1){ /* Destaca a escolha atual */
      mvprintw(y, x, "> %s", choices[i].c_str());
    }else{
      mvprintw(y, x, "%s", choices[i].c_str());
    }
    ++y;
  }
}

int main(int argc, char *argv[]){
    int highlight = 1;
    int choice = 0;

    std::vector<std::string> choices = {"Uma", "Duas", "Três", "Quatro", "Cinco"};
    string texto_atual;
    int n_choices = choices.size();

    initscr();
    keypad(stdscr, TRUE); //habilita as teclas UP/DOWN/LEFT/RIGHT 
    clear();
    noecho();
    raw(); //permite pegar ENTER e BACKSPACE
    cbreak();       /* Buffer de linha desativado. passa tudo */
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    //menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    //keypad(TRUE);
    mvprintw(0, 0, "Use as setas para subir e descer, pressione Enter para selecionar uma escolha");
    refresh();
    while( true ){
        int c = getch();
        clear();
        mvprintw(0, 0, "Use as setas para subir e descer, pressione Enter para selecionar uma escolha");
        if(c == KEY_UP || c == KEY_DOWN || c == KEY_ENTER || c == '\n' || c == KEY_BACKSPACE || c == 127 || c == '\b'){
            switch(c){
                case KEY_UP:
                    if(highlight == 1){
                        highlight = n_choices;
                    }else{
                        --highlight;
                    }
                    break;
                case KEY_DOWN:
                    if(highlight == n_choices)
                        highlight = 1;
                    else
                        ++highlight;
                    break;
                case KEY_ENTER: //enter do keypad
                case '\n':
                    texto_atual.append(choices[highlight]);
                    break;
                case KEY_BACKSPACE: //backspace varia
                case 127:
                case '\b':
                    texto_atual.pop_back();
                    break;
                default:
                    break;
            }
        }
        print_choices(highlight, choices);
        

        if(std::isalpha(c) || c == ' '){
            //limpa a penultima linha
            texto_atual.append(string(1,(char)c));
            mvprintw(HEIGHT-3, 0, "Texto Atual");
            mvprintw(HEIGHT-2, 0, "%s", texto_atual.c_str());
            mvprintw(HEIGHT-1, 0, "O número do caractere que você digitou é = %3d e corresponde à: '%c'", c, c);
        }
        else if(c == 27){ //esc, não tem constante para ele ;<
            mvprintw(HEIGHT-3, 0, "Texto Atual");
            mvprintw(HEIGHT-2, 0, "%s", texto_atual.c_str());
            mvprintw(HEIGHT-1, 0, "Saindo! bye!");
            refresh();
            break;
        }
        else{
            mvprintw(HEIGHT-3, 0, "Texto Atual");
            mvprintw(HEIGHT-2, 0, "%s", texto_atual.c_str());
            mvprintw(HEIGHT-1, 0, "Digite alguma coisa ou ESC pra sair");
        }
        refresh();
    }


    std::this_thread::sleep_for (std::chrono::seconds(1)); //só pra exibir a ultima mensagem
    endwin();
    return 0;
}

