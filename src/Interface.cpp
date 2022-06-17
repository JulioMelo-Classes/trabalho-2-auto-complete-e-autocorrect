#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "Interface.hpp"

using namespace std;

void Interface::impressao_autocomplete(Autocomplete* dados1, Autocorrect *dados2){
    string maior1 = ">>> no match found <<<", maior2 = ">>> no match found <<<";
    string str1 = "Autocomplete";
    string str2 = " Autocorrect ";
    string msg1 = ">>> no match found <<<";
    string msg2 = " >>> no match found <<<";
    for(auto qq : dados1->get_dados_autocomplete()){
        if(qq.second.size() > maior1.size()){
            maior1 = qq.second;
        }
    }
    // cout << str1 << setw((maior1.size() - str1.size())+2) << "|" << str2 << endl;
    if(dados1->get_dados_autocomplete().empty() && dados2->get_dados_correct().empty()){
        cout << msg1 << setw((maior1.size() - msg1.size())+2) << "|" << msg2 << endl;
    } else if(dados1->get_dados_autocomplete().empty()){
        for(int ii=0;  ii < dados2->get_dados_correct().size(); ii++){
            if(ii==0){
                cout << msg1 << setw((maior1.size() - msg1.size())+2) 
                     << "| " << dados2->get_dados_correct()[0].second << endl;
            } else{
                cout << setw(msg1.size() + (maior1.size() - msg1.size())+2) << "| " 
                     << dados2->get_dados_correct()[ii].second << endl;
            }
        }
    } else if(dados2->get_dados_correct().empty()){
        /*int jj=0;
        for(auto pp : dados1->get_dados_autocomplete()){
            if(jj==0){
                cout << "\"" << pp.second  << "\"" << endl;
                cout << "\"" << pp.second << "|" << msg2 << "\"" << endl;
            }
            jj++;
        }*/
        for(int ii=0;  ii < dados1->get_dados_autocomplete().size(); ii++){
            if(ii==0){
                cout << dados1->get_dados_autocomplete()[ii].second 
                     << setw(maior1.size() - dados1->get_dados_autocomplete()[ii].second.size()) << "|" << msg2 << endl;
            } else{
                cout << dados1->get_dados_autocomplete()[ii].second 
                     << setw((maior1.size() - dados1->get_dados_autocomplete()[ii].second.size())+2) << "|" << endl;
            }
        }
    } else{
        int count1=0, count2=0;
        while(count1 != dados1->get_dados_autocomplete().size() && count2 != dados2->get_dados_correct().size()){
            cout << dados1->get_dados_autocomplete()[count1].second 
                 << setw(maior1.size() - dados1->get_dados_autocomplete()[count1].second.size()) << "| " 
                 << dados2->get_dados_correct()[count2].second << endl;
            if(dados1->get_dados_autocomplete().size() == dados2->get_dados_correct().size()){
                count1++;
                count2++;
            } else if(dados1->get_dados_autocomplete().size() > dados2->get_dados_correct().size()){
                if(count2 == dados2->get_dados_correct().size()){
                    count1++;
                } else{
                    count1++;
                    count2++;
                }
            } else if(dados1->get_dados_autocomplete().size() < dados2->get_dados_correct().size()){
                if(count1 == dados1->get_dados_autocomplete().size()){
                    count2++;
                } else{
                    count1++;
                    count2++;
                }
            }
        }
    }
};

void Interface::impressao_autocorrect(Autocorrect* dados){
    cout << "Autocorrect" << endl;
    if(dados->get_dados_correct().empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        for(auto pp : dados->get_dados_correct()){
            cout << pp.second << endl;
        }
    }
};

string Interface::leitura_entrada(){
    getline(cin, m_entrada);
    for(int ii=0; ii < m_entrada.size(); ii++){
        m_entrada[ii] = toupper(m_entrada[ii]);
    }
    return m_entrada;
};

void Interface::impressao_msg_inicial(){
    cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
};
