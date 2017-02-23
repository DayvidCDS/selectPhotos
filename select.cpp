
#include "select.hpp"

Imagem::Imagem(string tipo_camera, string numero_Imagem) {
	set_tipo_camera(tipo_camera);
	set_numero_imagem(numero_Imagem);
}
void Imagem::set_tipo_camera(string T_CAM) {
	this->tipo_camera = T_CAM;
}

void Imagem::set_numero_imagem(string T_IMG) {
	this->numero_imagem = T_IMG;
}

string Imagem::get_tipo_camera() {
	return this->tipo_camera;
}

string Imagem::get_numero_imagem() {
	return this->numero_imagem;
}

void readArq(vector <Imagem *> &idFile, FILE *arq) {
	
	char number_pull_arq[8];
	char tipo_camera[8];
	int i = 0;

	fscanf(arq, "%s\n", &tipo_camera);
	
	while (!feof(arq)) {
		fscanf(arq, "%s\n", &number_pull_arq);
		idFile.push_back(new Imagem(tipo_camera, number_pull_arq));
	}
	
}

void saveFiles(vector <Imagem *> idFile, char *nomeSaida) {
	
	struct stat st = {0};
	FILE *arqSaida = NULL;
	FILE *arqEntrada = NULL;
	char buffer[BUFSIZ];
	size_t size;
	char nomePessoa[32];
	int pos = 0;

   	for (int i = 0; nomeSaida[i] != '\0'; i++) { //forma de pegar o nome do arquivo sem a extensão pelo caminho que ele está localizado
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

   	cout << nomePessoa << endl;

	if (stat(nomePessoa, &st) == -1) { //verifica se existe a pasta, caso contrário cria e executa a putaria
		if (mkdir(nomePessoa) == 0) {

			for (int i = 0; i < idFile.size(); i++) {

				string tipoCam = idFile[i]->get_tipo_camera();
				string numImg = idFile[i]->get_numero_imagem();
				string nomeFim = "- copia.jpg";
				string strSaida(nomePessoa);
				strSaida += "/" + tipoCam + numImg + nomeFim; 
				string strEntrada = tipoCam + numImg + ".jpg";
				
				arqEntrada = fopen(strEntrada.c_str(), "rb");
				arqSaida = fopen(strSaida.c_str(), "wb");

				while (size = fread(buffer, 1, BUFSIZ, arqEntrada)) { //ler bytes do arquivo de entrada e grava os mesmo no arquivo de saida(cópia :3)
					fwrite(buffer, 1, size, arqSaida);
				}
				
				fclose(arqEntrada);	
				fclose(arqSaida);
			}
		}
	}
}
