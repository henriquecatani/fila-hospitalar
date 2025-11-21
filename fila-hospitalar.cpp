#include <iostream>
#include <queue>
using namespace std;
struct filas{
    char prior;
    int horaChegada;
    int minutosChegada;
};
int tempoEspera(const filas aux1, const filas aux2){
    int horas1 = aux1.horaChegada * 60;
    int horas2 = aux2.horaChegada * 60;
    int soma1 = horas1 + aux1.minutosChegada;
    int soma2 = horas2 + aux2.minutosChegada;
    int tempoEsperando = soma1 - soma2;
    return tempoEsperando;
}
int main(){
    queue<filas> emergencia;
    queue<filas> urgencia;
    queue<filas> poucoUrgente;
    queue<filas> naoUrgente;
    char opcao = ' ';
    string senha;
    filas aux;
    int esperaMaxima = 0;
    int picoLotacao = 0;
    int totalEmer, totalGeral, totalUrg, totalPoucoU, totalnaoU;
    totalEmer = totalGeral = totalUrg = totalPoucoU = totalnaoU = 0;
    cout << "\nDigite:\n C- Chegou paciente, A- Atendimento, D- Informações das filas, Q- Encerrar" << endl; 
    cout << "Exemplos: " << endl;
    cout << " C senha V 10 50     A 10 55         D                        Q\n" << endl;
while(opcao != 'Q'){
    cin >> opcao;
    switch (opcao)
    {
        case 'C':
            cin >> senha; 
            cin >> aux.prior >> aux.horaChegada >> aux.minutosChegada;
            if (aux.prior == 'V')
            {
                emergencia.push(aux);
                cout << "Paciente adicionado\n" << endl;
            }
            else if (aux.prior == 'A')
            {
                urgencia.push(aux);
                cout << "Paciente adicionado\n" << endl;

            }
            else if (aux.prior == 'D')
            {
                poucoUrgente.push(aux);
                cout << "Paciente adicionado\n" << endl;

            }else {
                naoUrgente.push(aux);
                cout << "Paciente adicionado\n" << endl;

            }
            break;
        case 'A':
            cin >> aux.horaChegada >> aux.minutosChegada;
            if (emergencia.size() == 0 && urgencia.size() == 0 && poucoUrgente.size() == 0 && naoUrgente.size()== 0)
            {
                cout << aux.horaChegada << " " << aux.minutosChegada << " Sem pacientes aguardando atendimento" << endl;
            }
            
            else if (!emergencia.empty())
            {   
                filas aux2 = emergencia.front();
                int espera = tempoEspera(aux,aux2);
                if (espera > esperaMaxima)
                {
                    esperaMaxima = espera;
                }
                cout << "Tempo de espera até ser atendido: " << espera << " min" << endl;
                emergencia.pop();
                totalEmer++;
                totalGeral++;
                
            }
            else if (!urgencia.empty())
            {
                filas aux2 = urgencia.front();
                int espera = tempoEspera(aux,aux2);
                if (espera > esperaMaxima)
                {
                    esperaMaxima = espera;
                }
                cout << "Tempo de espera até ser atendido: " << espera << " min" << endl;   
                urgencia.pop();
                totalUrg++;
                totalGeral++;
                
            }
            else if (!poucoUrgente.empty())
            {
                filas aux2 = poucoUrgente.front();
                int espera = tempoEspera(aux,aux2);
                if (espera > esperaMaxima)
                {
                    esperaMaxima = espera;
                }
                cout << "Tempo de espera até ser atendido: " << espera << " min" << endl;
                poucoUrgente.pop();
                totalPoucoU++;
                totalGeral++;
            
            }
            else if (!naoUrgente.empty())
            {
                filas aux2 = naoUrgente.front();
                int espera = tempoEspera(aux,aux2);
                if (espera > esperaMaxima)
                {
                    esperaMaxima = espera;
                }
                cout << "Tempo de espera até ser atendido: " << espera << " min" << endl;
                naoUrgente.pop();
                totalnaoU++;
                totalGeral++;
            }
            break;
        case 'D':
                cout << "V: " << emergencia.size() << " A: " << urgencia.size() << " D: " << poucoUrgente.size() << " B: " << naoUrgente.size();
                cout << " | Atendidos: " << totalGeral << endl;
                break;
        case 'Q':
                cout << "Total atendidos: " << totalGeral << endl;
                cout << "Atendidos por prioridade: " << "V: " << totalEmer;
                cout << " A: " << totalUrg;
                cout << " D: " << totalPoucoU;
                cout << " B: " << totalnaoU << endl;
                //cout Pico de lotacao;
                cout << "Espera máxima: " << esperaMaxima << " min" << endl;
                break;
            
        }// switch case
    }
    return 0;
}