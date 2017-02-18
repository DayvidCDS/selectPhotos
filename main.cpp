
#include <windows.h>
#include "select.hpp"

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

	fclose(arq);
	//MessageBox(0, "Tudo Ok!  ", "Mensagem", MB_OK|MB_ICONINFORMATION);
	return 0;
}
