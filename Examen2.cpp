#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<iostream>

using namespace std;

/***********************************************************************************************///variabes globales
string datos[50][50], votantes[50][50];
int edad[50], votos=0, voto[10]={0}, opc_cand=0;
int p=0, t=0, y=0, k=0;
bool cedula[50]={false};
/***********************************************************************************************/
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
/***********************************************************************************************/
void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void hacer_graficos(int a,int y);
void graficos();

/***********************************************************************************************/
void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/***********************************************************************************************/
void pintarfondo(int fondo, int frente)
{
    int color = (fondo << 4) + frente;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/***********************************************************************************************/
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	for (i=x1; i<=x2;i++)
		{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
		}
	for (i=y1; i<=y2;i++)
		{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
		}
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}
/***********************************************************************************************/
void cuadropintado(int x1, int y1, int x2, int y2, int fondocolor)
{
	int i;
	pintarfondo(fondocolor, 0);
	for (i=x1; i<=x2;i++)
		{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
		}
	for (i=y1; i<=y2;i++)
		{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
		}
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  
}

/***********************************************************************************************/
void Registrar_Candidatos() 
{
	char opc;
	SetConsoleTextAttribute (hConsoleHandle, 15);
	for (t;t<=p;t++)
		{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(10,5,85,28);
		cuadro(33,1,65,3);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(35,02); cout<<"REGISTRO DE CANDIDATOS";
		for (int h=0;h<4;h++)
			{
			gotoxy(12,6); cout<<"INGRESE NOMBRE DEL CANDIDATO: --> ";
			cin >> datos[t][h];
			h++;
			gotoxy(12,8); cout<<"INGRESE APELLIDO DEL CANDIDATO: --> ";
			cin >> datos[t][h];
			h++;
			gotoxy(12,10); cout<<"INGRESE NUMERO DE CEDULA DEL CANDIDATO: --> ";
			cin >> datos[t][h];
			h++;
			gotoxy(12,12); cout<<"INGRESE LAS SIGLAS DEL PARTIDO POLITICO: --> ";
			cin >> datos[t][h];
			gotoxy(12,25);cout<<"DESEA INGRESAR OTRO CANDIDATO: (S/N) ";
    		opc=getch();
    		p++;
    		}	
			if (toupper(opc)=='N')
				{
				t++;
				break;
				}
		}
}

/***********************************************************************************************/
void Mostrar_Candidatos()
{
	int cand=0;
	int	ind=p-1;
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(33,1,64,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(35,02); cout<<"-- CANDIDATOS REGISTRADOS --"<<endl<<endl<<endl;
	if (ind==-1)
		{
		cout<<"**** NO HAY CANDIDATOS REGISTRADOS ****"<<endl<<endl;
		}else if (ind!=-1){
	
	for (int w=0;w<=ind;w++)
		{
		cand++;
		for (int q=0;q<4;q++)
			{
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<"****** CANDIDATO "<<cand<<" *******"<<endl;
			SetConsoleTextAttribute (hConsoleHandle, 15);
			cout<<"NOMBRE DEL CANDIDATO:			"<<datos[w][q]<<endl;
			q++;
			cout<<"APELLIDO DEL CANDIDATO:			"<<datos[w][q]<<endl;
			q++;
			cout<<"NUMERO DE CEDULA DEL CANDIDATO:		"<<datos[w][q]<<endl;
			q++;
			cout<<"PARTIDO POLITICO:			"<<datos[w][q]<<endl<<endl;
			}
	}
}
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cout<<"<Pulse tecla para Abandonar> ";
	getch();
}
/***********************************************************************************************/
void Modificar_Candidato()
{
	system("cls");
	char opc;
	string ced;
	int indi=0;
	cuadro(33,1,65,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(35,02); cout<<"--- MODIFICAR CANDIDATOS ---"<<endl<<endl<<endl;
	cout<<"DIGITE EL NUMERO DE CEDULA DEL CANDIDATO A MODIFICAR: ";
	cin >> ced;
	for (int a=0;a<=p;a++)
		{
		if (datos[a][2]==ced)
			{
			indi=a;
			break;
			}
		}
	if 	(datos[indi][2]==ced)
		{
		cout<<endl<<"NOMBRE DEL CANDIDATO:			"<<datos[indi][0]<<endl;
		cout<<"APELLIDO DEL CANDIDATO:			"<<datos[indi][1]<<endl;
		cout<<"NUMERO DE CEDULA DEL CANDIDATO:		"<<datos[indi][2]<<endl;
		cout<<"PARTIDO POLITICO:			"<<datos[indi][3]<<endl<<endl; 	
		cout<<"DESEA MODIFICARLO: (S/N) "<<endl;
		opc=getch();
		if (toupper(opc)=='S')
			{
			cout<<endl<<"INGRESE NOMBRE DEL CANDIDATO: --> ";
			cin >> datos[indi][0];
			cout<<endl<<"INGRESE APELLIDO DEL CANDIDATO: --> ";
			cin >> datos[indi][1];
			cout<<endl<<"INGRESE NUMERO DE CEDULA DEL CANDIDATO: --> ";
			cin >> datos[indi][2];
			cout<<endl<<"INGRESE LAS SIGLAS DEL PARTIDO POLITICO: --> ";
			cin >> datos[indi][3];
			}
		SetConsoleTextAttribute (hConsoleHandle, 14);	
		cout<<endl<<"***** CANDIDATO MODIFICADO *****";
		}else 
			{
			SetConsoleTextAttribute (hConsoleHandle, 14);	
   			cout<<endl<<"***** EL NUMERO DE CEDULA NO ESTA REGISTRADO *****";
		   	}
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cout<<endl<<"<Pulse tecla para Abandonar> ";
	getch();
}

/***********************************************************************************************/
void Eliminar_Candidato()
{
	system("cls");
	char opc, opc4;
	string ced;
	int indi=0;
	int indi2=indi;
	system("cls");	
	cuadro(33,1,65,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(35,02); cout<<" --- ELIMINAR CANDIDATOS ---"<<endl<<endl<<endl;
	cout<<"DIGITE EL NUMERO DE CEDULA DEL CANDIDATO A ELIMINAR: ";
	cin >> ced;
	cout<<endl;
	for (int a=0;a<=p;a++)
		{
		if (datos[a][2]==ced)
			{
			indi=a;
			break;
			}
   		}	
	cout<<"NOMBRE DEL CANDIDATO:			"<<datos[indi][0]<<endl;
	cout<<"APELLIDO DEL CANDIDATO:			"<<datos[indi][1]<<endl;
	cout<<"NUMERO DE CEDULA DEL CANDIDATO:		"<<datos[indi][2]<<endl;
	cout<<"PARTIDO POLITICO:			"<<datos[indi][3]<<endl<<endl; 	
	cout<<"DESEA ELIMINARLO: (S/N) "<<endl;
	opc=getch();
	if (toupper(opc)=='S')
		{
		SetConsoleTextAttribute (hConsoleHandle, 14);
		cout<<endl<<"***** CANDIDATO BORRADO *****"<<endl;	
		for(indi;indi<=p;indi++)
			{
			for(int x=0;x<4;x++)
				{
				datos[indi][x]=datos[indi2+1][x];
				}
			indi2++; 
			}
		p--;
		t--;
		}else if (toupper(opc)!='S'){
			SetConsoleTextAttribute (hConsoleHandle, 14);
			cout<<endl<<"***** CANDIDATO NO HA SIDO BORRADO *****"<<endl;
		}
	SetConsoleTextAttribute (hConsoleHandle, 10);	
	cout<<"<Pulse tecla para Abandonar> ";
	getch();
}
 
/***********************************************************************************************/
void Submenu_Candidatos()
{
	char opc;
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6);
		cuadro(8,8,72,23);
		cuadro(8,24,72,26);
		cuadro(15,20,27,22); 
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(21,4);cout<<"******* REGISTRO DE CANDIDATOS *******";
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);cout<<"[1]  REGISTRAR CANDIDATOS";
		gotoxy(15,12);cout<<"[2]  MOSTRAR CANDIDATOS";
		gotoxy(15,14);cout<<"[3]  MODIFICAR CANDIDATOS";
		gotoxy(15,16);cout<<"[4]  ELIMINAR CANDIDATOS";
		gotoxy(16,21);cout<<"<[5] SALIR>";
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);cout<<"Su opcion es: ";
		opc=getch();
		switch(opc)
			{
			case '1': Registrar_Candidatos();break;
			case '2': Mostrar_Candidatos(); break;
			case '3': Modificar_Candidato(); break;
			case '4': Eliminar_Candidato(); break;
			}
		}while(opc!='5');
}

/***********************************************************************************************/
void Registrar_Votantes()
{
	char opc;
	SetConsoleTextAttribute (hConsoleHandle, 15);
	for (y;y<=k;y++)
		{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(10,5,85,28);
		cuadro(33,1,65,3);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(35,02); cout<<"REGISTRO DE VOTANTES";
		for (int h=0;h<4;h++)
			{
			gotoxy(12,6); cout<<"INGRESE NOMBRE DEL VOTANTE: --> ";
			cin >> votantes[y][h];
			h++;
			gotoxy(12,8); cout<<"INGRESE APELLIDO DEL VOTANTE: --> ";
			cin >> votantes[y][h];
			h++;
			gotoxy(12,10); cout<<"INGRESE NUMERO DE CEDULA DEL VOTANTE: --> ";
			cin >> votantes[y][h];
			h++;
			gotoxy(12,12); cout<<"INGRESE EDAD DEL VOTANTE: --> ";
			cin >> edad[y];
			gotoxy(12,25);cout<<"DESEA INGRESAR OTRA PERSONA: (S/N) ";
    		opc=getch();
    		k++;
    		}	
		if (toupper(opc)=='N')
			{
			y++;	
			break;
			}
		}	
}

/***********************************************************************************************/
void Mostrar_Votantes()
{
	system("cls");
	int ind=k-1;
	int entero=0;
	string ced;
	int indi=-1;
	cuadro(33,1,65,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(35,02); cout<<"--- CONSULTA DE VOTANTES ---"<<endl<<endl<<endl;
	cout<<"DIGITE EL NUMERO DE CEDULA DE LA PERSONA A CONSULTAR: ";
	cin >> ced;
	for (int a=0;a<=k;a++)
		{
		if (votantes[a][2]==ced)
			{
			indi=a;
			break;
			}
		}
   	if (indi!=-1)
		{
	   	cout<<endl<<"NOMBRE DE LA PERSONA:		"<<votantes[indi][0]<<endl;
		cout<<"APELLIDO DE LA PERSONA:		"<<votantes[indi][1]<<endl;
		cout<<"NUMERO DE CEDULA DE LA PERSONA:	"<<votantes[indi][2]<<endl;
		cout<<"EDAD DE LA PERSONA:		"<<edad[indi]<<endl<<endl; 
		if (edad[indi] >= 18)
			{
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<"** ESTA PERSONA PUEDE EMITIR EL VOTO **"<<endl;
			}else {
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<"** ESTA PERSONA ES MENOR DE EDAD, NO PUEDE VOTAR **"<<endl;
			}
		}else {
		SetConsoleTextAttribute (hConsoleHandle, 14);	
		cout<<endl<<"** LA PERSONA CON EL NUMERO DE CEDULA "<<ced<<" NO ESTA REGISTRADA **"<<endl;
		}
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cout<<endl<<"<Pulse tecla para Abandonar> ";
	getch();
}

/***********************************************************************************************/
void Modificar_Votantes(){
	system("cls");
	char opc;
	string ced;
	int indi=0;
	cuadro(33,1,65,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(35,02); cout<<"---- MODIFICAR VOTANTES ----"<<endl<<endl<<endl;
	cout<<"DIGITE EL NUMERO DE CEDULA DEL VOTANTE A MODIFICAR: ";
	cin >> ced;
	for (int a=0;a<=k;a++)
		{
		if (votantes[a][2]==ced)
			{
			indi=a;
			break;
			}
   		}
	if (votantes[indi][2]==ced)
		{
		cout<<endl<<"NOMBRE DEL VOTANTE:			"<<votantes[indi][0]<<endl;
		cout<<"APELLIDO DEL VOTANTE:			"<<votantes[indi][1]<<endl;
		cout<<"NUMERO DE CEDULA DEL VOTANTE:		"<<votantes[indi][2]<<endl;
		cout<<"EDAD DEL VOTANTE:			"<<edad[indi]<<endl<<endl; 	
		SetConsoleTextAttribute (hConsoleHandle, 14);
		cout<<"DESEA MODIFICARLO: (S/N) ";
		opc=getch();
		SetConsoleTextAttribute (hConsoleHandle, 15);
		if (toupper(opc)=='S')
			{	
			cout<<endl<<endl<<"INGRESE NOMBRE DEL VOTANTE: --> ";
			cin >> votantes[indi][0];
			cout<<endl<<"INGRESE APELLIDO DEL VOTANTE: --> ";
			cin >> votantes[indi][1];
			cout<<endl<<"INGRESE NUMERO DE CEDULA DEL VOTANTE: --> ";
			cin >> votantes[indi][2];
			cout<<endl<<"INGRESE EDAD DEL VOTANTE: --> ";
			cin >> edad[indi];
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<endl<<"*** VOTANTE MODIFICADO ***";
			}else if (toupper(opc)=='N'){
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<endl<<"*** VOTANTE NO MODIFICADO ***";	
			}
		}else
			{
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<endl<<"*** EL NUMERO DE CEDULA NO ESTA REGISTRADO ***";	
			}	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cout<<endl<<"<Pulse tecla para Abandonar> ";
	getch();	
}

/***********************************************************************************************/
void Eliminar_Votantes(){
	system("cls");
	char opc;
	string ced;
	int indi=0;
	cuadro(33,1,65,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(35,02); cout<<"---- ELIMINAR VOTANTES ----"<<endl<<endl<<endl;
	cout<<"DIGITE EL NUMERO DE CEDULA DEL VOTANTE A ELIMINAR: ";
	cin >> ced;
	for (int a=0;a<=k;a++)
		{
		if (votantes[a][2]==ced)
			{
			indi=a;
			break;
			}
   		}
	if (votantes[indi][2]==ced)
		{	   	
		cout<<endl<<"NOMBRE DEL VOTANTE:			"<<votantes[indi][0]<<endl;
		cout<<"APELLIDO DEL VOTANTE:			"<<votantes[indi][1]<<endl;
		cout<<"NUMERO DE CEDULA DEL VOTANTE:		"<<votantes[indi][2]<<endl;
		cout<<"EDAD DEL VOTANTE:			"<<edad[indi]<<endl<<endl; 	
		cout<<endl<<"DESEA ELIMINARLO: (S/N) ";
		opc=getch();
		int indi2=indi;
		if (toupper(opc)=='S')
			{
			for(indi;indi<=k;indi++)
				{
				for(int x=0;x<3;x++)
					{
					votantes[indi][x]=votantes[indi2+1][x];
					}
				edad[indi]=edad[indi2+1];
				indi2++; 
				}
			k--;
			y--;
			SetConsoleTextAttribute (hConsoleHandle, 14);
			cout<<endl<<"***** VOTANTE BORRADO *****"<<endl;
			}else if (toupper(opc)=='N'){
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<endl<<"*** VOTANTE NO BORRADO ***";
			}	
		}else
			{
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			cout<<endl<<"*** EL NUMERO DE CEDULA NO ESTA REGISTRADO ***";	
			}
			
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cout<<endl<<"<Pulse tecla para Abandonar> ";
	getch();	
}

/***********************************************************************************************/
void Submenu_Votantes()
{
	char opc;
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6); 
		cuadro(8,8,72,23);
		cuadro(8,24,72,26); 
		cuadro(15,20,27,22); 
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(21,4);cout<<"******* REGISTRO DE VOTANTES *******";
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);cout<<"[1]  REGISTRAR VOTANTES";
		gotoxy(15,12);cout<<"[2]  CONSULTAR VOTANTES";
		gotoxy(15,14);cout<<"[3]  MODIFICAR VOTANTES";
		gotoxy(15,16);cout<<"[4]  ELIMINAR VOTANTES";
		gotoxy(16,21);cout<<"<[5] SALIR>";
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);cout<<"Su opcion es: ";
		opc=getch();
		switch(opc)
			{
			case '1': Registrar_Votantes();break;
			case '2': Mostrar_Votantes(); break;
			case '3': Modificar_Votantes(); break;
			case '4': Eliminar_Votantes(); break;
			}
		}while(opc!='5');
}

/***********************************************************************************************/
void hacer_graficos(int a,int y)
{
int i;int j=25;
for (i=1; i<=a; i++)
	{
		gotoxy (j,y); printf("%c",178);
		j++;
	}
}
/***********************************************************************************************/
void conteo_votos ()
{
	int opc2=opc_cand-1;	
	for (int s=0;s<p;s++)
		{
		if (opc2==s)
			{
			voto[s]=voto[s]+1;
			}
		}
}
/***********************************************************************************************/
void Emitir_voto()
{
	string ced;	
	int a=10, b=15, c=40, d=17, e=16, f=16, indi=-1;
	int candi=0;
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(10,2,80,4);
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(27,3); cout<<" ********* EMITA SU VOTO **********";
	gotoxy (4,7); cout<<"DIGITE SU NUMERO DE CEDULA: ";
	cin >> ced;
	for (int g=0;g<=k;g++)
		{
		if (votantes[g][2]==ced)
			{
			indi=g;
			break;
			}
		}
   	if ((indi!=-1) && (cedula[indi]==false))
	   	{
	   	cedula[indi]=true;	
	   	gotoxy (4,9);cout<<"NOMBRE DE LA PERSONA:		"<<votantes[indi][0];
	   	gotoxy (4,10);cout<<"APELLIDO DE LA PERSONA:		"<<votantes[indi][1];
		gotoxy (4,11);cout<<"NUMERO DE CEDULA DE LA PERSONA:	"<<votantes[indi][2];
		gotoxy (4,12);cout<<"EDAD DE LA PERSONA:			"<<edad[indi]; 
		if (edad[indi] >= 18)
			{
			SetConsoleTextAttribute (hConsoleHandle, 14);	
			gotoxy (4,13);cout<<endl<<"SELECCIONE EL NUMERO DEL CANDIDATO A VOTAR: ";
			SetConsoleTextAttribute (hConsoleHandle, 15);
			for (int j=0;j<p;j++)
				{
				candi++;		
				cuadro(a,b,c,d);
				SetConsoleTextAttribute (hConsoleHandle, 15);
				gotoxy(e,f);cout << " [ "<<candi<<" ]  "<<datos[j][0]<<" "<<datos[j][1]<<endl<<endl;
				b=b+3; d=d+3; f=f+3;
				}	
			cout<<"Su opcion es: ";
			cin>>opc_cand;
			b=0; d=0;
			b=(opc_cand+4)*3;
			d=b+2;
			cuadropintado(10,b,40,d,2);	
			conteo_votos();
			
			}else {
			SetConsoleTextAttribute (hConsoleHandle, 14);
			gotoxy (4,13);	cout<<endl<<"ESTA PERSONA ES MENOR DE EDAD, NO PUEDE VOTAR"<<endl<<endl;
			}
			
		}else if ((indi>-1)&&(cedula[indi]==true)){
		gotoxy (4,13);cout<<"LA PERSONA CON EL NUMERO DE CEDULA "<<ced<<" YA EMITIO SU VOTO"<<endl<<endl;
		}else {
		gotoxy (4,13);cout<<"LA PERSONA CON EL NUMERO DE CEDULA "<<ced<<" NO ESTA REGISTRADA"<<endl<<endl;
		}
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cout<<endl<<endl<<endl<<"<Pulse tecla para Abandonar> ";
	getch();  
}

int suma()
{	
	int conteo=0, ganador=-1;
	conteo = voto[0];
	for (int s = 0; s<=p; s++) 
 		{  
 		if (conteo < voto[s])   
	 		{
			conteo = voto[s];
			ganador=s;
   			}
		}
 	return(ganador);
}	
/****************************************************************************************************/	
void Resultados() 
{    
	int e=8, f=8;
	int sin_cand=p-1;
	system("cls");
	cuadro (2,1,57,5);
	gotoxy(4,3); cout<<"********** RESULTADO DE LAS VOTACIONES ***********";
	for (int j=0;j<p;j++)
		{
		gotoxy(e,f);cout <<datos[j][0]<<" "<<datos[j][1]<<"   "<<voto[j]<<endl;
		SetConsoleTextAttribute (hConsoleHandle, 10);
		hacer_graficos(voto[j],f);	
		f=f+3;
		}
	/*if(sin_cand!=-1){*/
	
	cout<<endl<<endl<<"EL GANADOR DE LAS ELECCIONES ES: "<<endl<<endl;
	cout <<"   "<<datos[suma()][0]<<" "<<datos[suma()][1];
	

	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(4,20);	cout<<"<Pulse tecla para Abandonar> ";
	getch();
}

/***********************************************************************************************/
void menu()
{
	char opc,conti; 
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6);
		cuadro(8,8,72,23);
		cuadro(8,24,72,26);
		cuadro(15,20,27,22); 
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(21,4);cout<<"******* SISTEMA DE VOTACIONES TSE *******";
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);cout<<"[1]  CANDIDATOS";
		gotoxy(15,12);cout<<"[2]  VOTANTES";
		gotoxy(15,14);cout<<"[3]  EMITIR VOTO";
		gotoxy(15,16);cout<<"[4]  RESULTADOS";
		gotoxy(16,21);cout<<"<[5] SALIR>";
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);cout<<"Su opcion es: ";
		opc=getch();
		switch(opc)
			{
			case '1': Submenu_Candidatos();break;
			case '2': Submenu_Votantes(); break;
			case '3': Emitir_voto(); break;
			case '4': Resultados(); break;
			case '5': 
				system("cls");
				gotoxy(20,10);cout<<"Estas seguro Que Deseas Salir del Sistema";
				SetConsoleTextAttribute (hConsoleHandle, 2);
				gotoxy(20,15);cout<<"Desea Continuar S/N";
				conti=getch();
				if (conti=='N' || conti=='n')
				menu();
				else if (conti=='S' || conti=='s')
				break; 
			}
		}while(opc!='5');
}

/********************************************************************************************/
int main(int argc, char** argv) {
	menu();
	return 0;
}
