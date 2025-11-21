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
int main()
{
    queue<filas> emergencia;
    queue<filas> urgencia;
    queue<filas> poucoUrgente;
    queue<filas> naoUrgente;
    char opcao = ' ';
    string senha;
    filas aux;
    int picoLotacao = 0, esperaMaxima = 0,
	totalEsperando = 0, totalGeral = 0,
	totalEmer = 0, totalUrg = 0, totalPoucoU = 0, totalnaoU = 0;
    cout << "\nDigite:\n C- Chegou paciente, A- Atendimento, D- Informações das filas, Q- Encerrar" << endl; 
    cout << "Exemplos: " << endl;
    cout << " C senha V 10 50     A 10 55         D                        Q\n" << endl;
while(opcao != 'Q')
    {
    cin >> opcao;
    switch (opcao)
    {
	case 'C':
	    cin >> senha; 

	    cin >> aux.prior >> aux.horaChegada >> aux.minutosChegada;
	    switch (aux.prior) 
	    {
			case 'V':
				emergencia.push(aux);
				cout << "Paciente adicionado\n" << endl;
				totalEsperando++; // contagem para pico de pacientes na espera
				break;
			case 'A':
				urgencia.push(aux);
				cout << "Paciente adicionado\n" << endl;
				totalEsperando++;
				break;
			case 'D':
				poucoUrgente.push(aux);
				cout << "Paciente adicionado\n" << endl;
				totalEsperando++;
				break;
			case 'B':
				naoUrgente.push(aux);
				cout << "Paciente adicionado\n" << endl;
				totalEsperando++;
				break;
			}
	    break;

	case 'A':
	    cin >> aux.horaChegada >> aux.minutosChegada;
	    if (totalEsperando == 0)
	    {
		cout << aux.horaChegada << " " << aux.minutosChegada
		<< " Sem pacientes aguardando atendimento" << endl;
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
		totalEsperando--;
		
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
		totalEsperando--;
		
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
		totalEsperando--;
	    
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
		totalEsperando--;
	    }
	    break;

	case 'D':
		cout << "V: " << emergencia.size() << " A: " << urgencia.size() << " D: " << poucoUrgente.size() << " B=" << naoUrgente.size();
		cout << " | Atendidos: " << totalGeral << endl;
		break;

	case 'Q':
		cout << "Total atendidos: " << totalGeral << endl;
		cout << "Atendidos por prioridade: " << "V: " << totalEmer;
		cout << " A=" << totalUrg;
		cout << " D=" << totalPoucoU;
		cout << " B=" << totalnaoU << endl;
		cout << "Pico de lotação: " << picoLotacao << endl;
		cout << "Espera máxima: " << esperaMaxima << " min" << endl;
		break;
	    
    }// switch case
	
    if (totalEsperando > picoLotacao) picoLotacao = totalEsperando;
    } // while
    return 0;
}
