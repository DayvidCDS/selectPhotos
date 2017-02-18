//reparar a entrada dos arquivos
//reparar o nome do cliente

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>

using namespace std;

void saveFiles(vector <int> &, char *);
void readArq(vector <int> &, FILE *);

int main(int argc, char **argv) {
	
	if (argc != 2) {
		cout << "entre com o nome do arquivo de entrada" << endl;
		return 1;
	}
	
	FILE *arq = fopen(argv[1], "r");
	
	if (arq == NULL) {
		cout << "arquivo nao valido!" << endl;
		return 2;
	}

	vector <int> idFile;
	readArq(idFile, arq);
	saveFiles(idFile, argv[1]);
	fclose(arq);
	MessageBox(0, "Tudo Ok!  ", "Mensagem", MB_OK|MB_ICONINFORMATION);
	return 0;
}

void readArq(vector <int> &idFile, FILE *arq) {
	
	int number_pull_arq;
	
	while (!feof(arq)) {
		fscanf(arq, "%i\n", &number_pull_arq);
		idFile.push_back(number_pull_arq);	
	}
	
}

void saveFiles(vector <int> &idFile, char *nomeSaida) {
	
	struct stat st = {0};
	FILE *arqSaida = NULL;
	FILE *arqEntrada = NULL;
	char buffer[BUFSIZ];
	size_t size;
	char nomePessoa[32];
	int pos = 0;

	//string pasta(nomeSaida);
	//char chars[] = ".txt";
   	//for (unsigned int i = 0; i < strlen(chars); ++i) pasta.erase (std::remove(pasta.begin(), pasta.end(), chars[i]), pasta.end());

   	for (int i = 0; nomeSaida[i] != '\0'; i++) { //gambiarra :3
   		if (nomeSaida[i] == '.') {
   			for (int j = i; j > 0; j--) {
   				if (nomeSaida[j] == '\\') {
   					for (int l = 0; nomeSaida[j+l+1] != '.'; l++) {
   						nomePessoa[l] = nomeSaida[j+l+1];
   					}
   					break;
   				}
   			}
   			break;
   		}
   	}

   	//cout << nomePessoa << endl;

	if (stat(nomePessoa, &st) == -1) {
		if (mkdir(nomePessoa) == 0) {

			for (int i = 0; i < idFile.size(); i++) {
				std::stringstream convert;
				convert << idFile[i];
				string nomeFim = "- copia.jpg";
				string strSaida(nomePessoa);
				strSaida += "/" + convert.str() + nomeFim; 
				string strEntrada = "DSC_" + convert.str() + ".jpg";
				arqSaida = fopen(strSaida.c_str(), "wb");
				arqEntrada = fopen(strEntrada.c_str(), "rb");

				while (size = fread(buffer, 1, BUFSIZ, arqEntrada)) {
					fwrite(buffer, 1, size, arqSaida);
				}
				
				fclose(arqEntrada);	
				fclose(arqSaida);
			}
		}
	}
}
