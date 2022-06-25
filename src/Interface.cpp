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

void Interface::impressao_autocomplete_autocorrect(Autocomplete* dados1, Autocorrect *dados2){
    vector<pair<int, string>> dadosAcomp = dados1->dados_autocomplete_interface();
    vector<pair<int, string>> dadosAcorr = dados2->dados_correct_interface();
    string maior1 = ">>> no match found <<<";
    string str1 = "Autocomplete";
    string str2 = " Autocorrect";
    string msg1 = ">>> no match found <<<";
    for(auto qq : dadosAcomp){
        if(qq.second.size() > maior1.size()){
            maior1 = qq.second;
        }
    }
    cout << setw(str1.size() + (maior1.size() - str1.size())+2) << setfill('-') << "+" << setw(str2.size()+2) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << str1 << setw((maior1.size() - str1.size())+2) << "|" << str2 << endl;
    cout << setw(str1.size() + (maior1.size() - str1.size())+2) << setfill('-') << "+" << setw(str2.size()+2) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    if(dadosAcomp.empty() && dadosAcorr.empty()){
        cout << msg1 << setw((maior1.size() - msg1.size())+2) << "|" << " " << msg1 << endl;
    } else if(dadosAcomp.empty()){
        for(int ii=0;  ii < dadosAcorr.size(); ii++){
            if(ii==0){
                cout << msg1 << setw((maior1.size() - msg1.size())+2) 
                     << "|" << " " << dadosAcorr[0].second << endl;
            } else{
                cout << setw(msg1.size() + (maior1.size() - msg1.size())+2) << "|" << " "
                     << dadosAcorr[ii].second << endl;
            }
        }
    } else if(dadosAcorr.empty()){
        for(int ii=0;  ii < dadosAcomp.size(); ii++){
            if(ii==0){
                cout << dadosAcomp[ii].second 
                     << setw((maior1.size() - dadosAcomp[ii].second.size())+2) << "|" << " " << msg1 << endl;
            } else{
                cout << dadosAcomp[ii].second 
                     << setw((maior1.size() - dadosAcomp[ii].second.size())+2) << "|" << endl;
            }
        }
    } else{
        int count1=0, count2=0;
        while(count1 <= dadosAcomp.size() && count2 <= dadosAcorr.size()){
            if(dadosAcomp.size() == dadosAcorr.size()){
                if(count1 < dadosAcomp.size()){
                    cout << dadosAcomp[count1].second 
                         << setw(maior1.size() - dadosAcomp[count1].second.size()+2) << "|" << " " 
                         << dadosAcorr[count2].second << endl;
                }
                count1++;
                count2++;
            } else if(dadosAcomp.size() > dadosAcorr.size()){
                if(count2 < dadosAcorr.size()){
                    cout << dadosAcomp[count1].second 
                         << setw(maior1.size() - dadosAcomp[count1].second.size()+2) << "|" << " " 
                         << dadosAcorr[count2].second << endl;
                    count2++;
                } else if(count1 < dadosAcomp.size()){
                    cout << dadosAcomp[count1].second 
                         << setw(maior1.size() - dadosAcomp[count1].second.size()+2) << "|" << " " << endl;
                }
                count1++;
            } else if(dadosAcomp.size() < dadosAcorr.size()){
                if(count1 < dadosAcomp.size()){
                    cout << dadosAcomp[count1].second 
                         << setw(maior1.size() - dadosAcomp[count1].second.size()+2) << "|" << " " 
                         << dadosAcorr[count2].second << endl;
                    count1++;
                } else if(count2 < dadosAcorr.size()){
                    cout << setw(msg1.size() + (maior1.size() - msg1.size())+2) << "|" << " " 
                         << dadosAcorr[count2].second << endl;
                }
                count2++;
            }
        }
    }
};

string Interface::leitura_entrada(){
    if(!getline(cin, m_entrada)){
        cout << endl;
        exit(-1);
    }
    for(int ii=0; ii < m_entrada.size(); ii++){
        m_entrada[ii] = toupper(m_entrada[ii]);
    }
    return m_entrada;
};

void Interface::impressao_msg_inicial(){
    cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
};
