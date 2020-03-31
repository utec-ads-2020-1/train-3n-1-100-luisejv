#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	fstream *arch = new fstream("prueba.txt", ios_base::in);
	if (!(arch->is_open()))
	{
		cout << "Archivo fallo en leer" << endl;
	}
	else
	{
		string linea;
		while (getline(*arch, linea))
		{
			stringstream stream(linea);
			string i, j;
			int num1, num2, mayorCiclo = 0;
			getline(stream, i, ' ');
			getline(stream, j, ' ');
			num1 = stoi(i);
			num2 = stoi(j);
			for (num1; num1 <= num2; num1++)
			{
				int finalNum = num1;
				int contador = 1;
				while (finalNum != 1)
				{
					finalNum = (finalNum % 2 == 0) ? finalNum / 2 : 3 * finalNum + 1;
					contador++;
				}
				mayorCiclo = (mayorCiclo < contador) ? contador : mayorCiclo;
			}
			cout << i << " " << j << " " << mayorCiclo << endl;
		}
	}
}
