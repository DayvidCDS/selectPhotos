
#include "select.hpp"

imagem::imagem(string tipo_camera, string numero_imagem) {
	set_tipo_camera(tipo_camera);
	set_numero_imagem(numero_imagem);
}
void imagem::set_tipo_camera(string T_CAM) {
	this->tipo_camera = T_CAM;
}

void imagem::set_numero_imagem(string T_IMG) {
	this->numero_imagem = T_IMG;
}

string imagem::get_tipo_camera() {
	return this->tipo_camera;
}

string imagem::get_numero_imagem() {
	return this->numero_imagem;
}
/* REVISAR TODA ESSA PARTE COMENTADA!
void readArq(vector <imagem> &idFile, FILE *arq) {
	
	int number_pull_arq;
	
	while (!feof(arq)) {
		fscanf(arq, "%i\n", &number_pull_arq);
		idFile.push_back(number_pull_arq);	
	}
	
}

void saveFiles(vector <imagem> &idFile, char *nomeSaida) {
	
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
*/
