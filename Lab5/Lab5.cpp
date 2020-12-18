#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv)
{
	int Iseinantis = 0;
	char* argumentas;

	if (argc < 2) 
	{
		cout << " Nera argumento" << endl;
		return(0);
	}

	argumentas = argv[1];

	__asm {
		push eax
		push ebx
		push ecx

		xor ecx, ecx // Sudedami rezultatai nuo 0
		mov ebx, argumentas // Stringas

		ciklas :
		mov al, byte ptr[ebx] // adresas vienos raides
			inc ebx // padidinamas verte, kad butu galima prieiti prie kito adreso

			cmp al, 0 // Jei 0 (stringo pabaiga) iseina     
			jz pabaiga //Sokti jei lygu ar 0

			imul ecx, 10
			sub eax, 48 // reikia padalintin is 48 ,nes pagal ASCII taip gauname int

			add ecx, eax

			jmp ciklas // gritame i cikla

			pabaiga :
		mov Iseinantis, ecx // rezultata perkeliame i Iseinantis

			pop ecx
			pop ebx
			pop eax

	}
	cout << "The number was processed" << endl;
	cout << "String value: " << argumentas << " Type: " << typeid(argumentas).name() << endl;
	cout << "Integer value: " << Iseinantis << " Type: " << typeid(Iseinantis).name();
}