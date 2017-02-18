
#ifndef SELECT_H
#define SELECT_H

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class imagem { //objeto para deixar a seleção mais simples quando aparecer mais de 1 tipo diferente de arquivo. Ex: canon, nikon, sony...
	private:
		string tipo_camera;
		string numero_imagem;
		void set_tipo_camera(string);
		void set_numero_imagem(string);
	public:
		imagem(string, string);
		string get_tipo_camera();
		string get_numero_imagem();
};

//void saveFiles(vector <imagem> &, char *);
//void readArq(vector <imagem> &, FILE *);

#endif