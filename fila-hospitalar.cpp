#include <iostream>
#include <queue>
using namespace std;
struct filas{
    char prior;
    int horas;
    int minutos;
};
void verificaFilas(const filas fila){
    
}
int main(){
    queue<filas> emergencia;
    queue<filas> urgencia;
    queue<filas> poucoUrgente;
    queue<filas> naoUrgente;
    char opcao;
    string senha;
    filas aux;
    int totalEmer = 0;
    int totalUrg = 0;
    int totalPoucoU = 0;
    int totalnaoU = 0;
    switch (opcao)
    {
    case 'C':
        cin >> senha; 
        cin >> aux.prior >> aux.horas >> aux.minutos;
        if (aux.prior == 'V')
        {
            emergencia.push(aux);
            totalEmer++;
        }
        else if (aux.prior == 'A')
        {
            urgencia.push(aux);
            totalUrg++;
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
        cin >> aux.horas >> aux.minutos;
        if (emergencia.size() == 0 && urgencia.size() == 0 && poucoUrgente.size() == 0 && naoUrgente.size()== 0)
        {
            cout << aux.horas << " " << aux.minutos << " Sem pacientes aguardando atendimento" << endl;
        }
        if (!emergencia.empty())
        {   
            emergencia.pop();
        }
        
    }// switch case
    return 0;
}