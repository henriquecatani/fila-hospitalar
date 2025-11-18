#include <iostream>
#include <queue>
using namespace std;
struct filas{
    char prior;
    int horaChegada;
    int minutosChegada;
};
int main(){
    queue<filas> emergencia;
    queue<filas> urgencia;
    queue<filas> poucoUrgente;
    queue<filas> naoUrgente;
    char opcao;
    string senha;
    filas aux;
    int totalEmer, totalGeral, totalUrg, totalPoucoU, totalnaoU = 0;
    switch (opcao)
    {
    case 'C':
        cin >> senha; 
        cin >> aux.prior >> aux.horaChegada >> aux.minutosChegada;
        if (aux.prior == 'V')
        {
            emergencia.push(aux);
            totalEmer++;
        }
        else if (aux.prior == 'A')
        {
            urgencia.push(aux);
            totalUrg++;
            totalGeral++;
        }
        else if (aux.prior == 'D')
        {
            poucoUrgente.push(aux);
            totalPoucoU++;
        }else {
            naoUrgente.push(aux);
            totalnaoU++;
        }
    case 'A':
        cin >> aux.horaChegada >> aux.minutosChegada;
        if (emergencia.size() == 0 && urgencia.size() == 0 && poucoUrgente.size() == 0 && naoUrgente.size()== 0)
        {
            cout << aux.horaChegada << " " << aux.minutosChegada << " Sem pacientes aguardando atendimento" << endl;
        }
        if (!emergencia.empty())
        {   
            emergencia.pop();
        }
        
    }// switch case
    return 0;
}