#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main();
void menuCursos();
void MenuProfesor();
void menuModCurso();


///--------------------------------------------------Cursos-------------------------------------------------------------------
//Lista doble para cursos, los cuales se deben insertar de manera ordenada segun su codigo
struct Curso
{
    string sigla;
    int num;
    string nombre;
    int creditos;
    struct Curso *sig; //puntero siguiente
    struct Curso *ant; //puntero anterior
    struct Grupo *enlaceGru;

}*listaCurso;

/* Funcion para insertar los cursos de forma ordenada segun su sigla que recibe por parámetro la sigla del curso
a ingresar: IC, PI, AE, recibe el numero de identificacion del curso, el nombre del curso y el numero de creditos
*/
void InsertarCurso(string sigla, int num, string nombre,int creditos)
{
    Curso *nuevoC= new Curso();   //nueva estructura de tipo Curso
    nuevoC->sigla=sigla;
    nuevoC->num=num;
    nuevoC->nombre=nombre;
    nuevoC->creditos=creditos;
    nuevoC->sig=NULL;
    Curso *temp;      //puntero temporal para recorrer la lista de cursos
                    // cada vez que se realiza la inserción se renombra el puntero a temporal

    if(listaCurso == NULL)
        listaCurso = nuevoC;
    else{
        struct Curso *temp = listaCurso;
        struct Curso *ant = NULL;
        while((temp != NULL)&&(sigla > temp->sigla)){ //ciclo para realizar la insercion ordenada de cursos
            ant = temp;
            temp = temp->sig;
        }
        if(temp == NULL) // Inserta al final de la lista.
        {
            ant->sig = nuevoC;
            nuevoC->ant = ant;
        }
        else if(ant==NULL) // Inserta al inicio de la lista.
        {
            nuevoC->sig = listaCurso;
            listaCurso->ant = nuevoC;
            listaCurso = nuevoC;
        }
        else{ // Insertar en medio de la lista.
            ant->sig = nuevoC;
            temp->ant = nuevoC;
            nuevoC->sig = temp;
            nuevoC->ant = ant;
        }

    }
    };
/*
Funcion que permite realizar la modificacion de la informacion correspondiente a la sigla de un curso
*/
    void modificarCurso(string vs,string ns, int num)
    {
        Curso *temp= listaCurso;
        Curso *ant=NULL;
        Curso *sig= listaCurso->sig;
        while(temp != NULL)
        {
            if((temp->sigla == vs)&&(temp->num == num))//si los datos ingresados coinciden
            {
                if(sig==NULL)   // si el nodo es igual a nulo
                {
                    temp->sigla=ns;  // se registra la nueva sigla ingresada por el usuario
                    ant->sig=NULL;
                    temp->sig=NULL;
                    temp->ant=NULL;
                    break;
                }
                else
                {               // si no , la sigla se modifica y se actualizan los punteros
                temp->sigla=ns;
                ant->sig=sig;
                sig->ant=ant;
                temp->ant=NULL;
                temp->sig=NULL;
                break;
                }
            }
            else
            {
                if(sig->sig==NULL)
                {
                    ant=temp;
                    temp=sig;
                    sig=NULL;
                }
                else
                {
                ant=temp;
                temp=temp->sig;
                sig=sig->sig;
                }
            }
        }//si no se encuentra ningun dato se invoca al método insertar y se envian los parametros recibidos
        string s= temp->sigla;
        int nu=temp->num;
        string no=temp->nombre;
        int c=temp->creditos;
       InsertarCurso(s,nu,no,c);
        cout<<"modificacion exitosa";
    };
/*
Funcion que permite modificar el numero de identificacion de un curso recibe por parametro, la sigla del curso
el numero registrado y nuevo el numero.
*/
    void modificarCurso(string s, int vnum , int nnum)
    {
        Curso *temp= listaCurso;
        Curso *ant=NULL;
        Curso *sig= listaCurso->sig;
        temp->ant= NULL;
        while(temp != NULL)
        {
            if((temp->sigla == s)&&(temp->num == vnum)) // si el numero registrado coincide con el numero ingresado
            {
                temp->num=nnum;  // se realiza la modificacion
                break;
            }
            else  //si no encuentra, se continua con el recorrido de la lista
            {
                ant=temp;
                temp=temp->sig;
                sig=sig->sig;
                cout<<endl<<"Curso no encontrado";
                menuModCurso();
            }
        }
    };

/*
Funcion que permite modificar el nombre de un curso recibe por parametro, la sigla del curso
el numero y nuevo el nombre.
*/
    void modificarCurso(string s,int num,string nom)
    {
        Curso *temp= listaCurso;
        Curso *ant=NULL;
        Curso *sig= listaCurso->sig;
        temp->ant= NULL;
        while(temp != NULL)
        {
            if((temp->sigla == s)&&(temp->num == num))
            {
                temp->nombre=nom;
                break;
            }
            else
            {
                ant=temp;
                temp=temp->sig;
                sig=sig->sig;
                cout<<endl<<"Curso no encontrado";
                menuModCurso();
            }
        }
    };

    void modificarCurso(int num,string s,int c)
    {
        Curso *temp= listaCurso;
        Curso *ant=NULL;
        Curso *sig= listaCurso->sig;
        temp->ant= NULL;
        while(temp != NULL)
        {
            if((temp->sigla == s)&&(temp->num == num))
            {
                temp->creditos=c;
                break;
            }
            else
            {
                ant=temp;
                temp=temp->sig;
                sig=sig->sig;
                cout<<endl<<"Curso no encontrado";
                menuModCurso();
            }
        }
    };

void ImprimirCursos()
{
    struct Curso *temp= listaCurso;
    while(temp!=NULL)
    {
        cout<<"\n\n";
        cout<<"Sigla: "<<temp->sigla<<endl;
        cout<<"Numero: "<<temp->num<<endl;
        cout<<"Curso: "<<temp->nombre<<endl;
        cout<<"Creditos: "<<temp->creditos<<endl;
        cout<<endl;
        temp=temp->sig;    //para seguir recorriendo la lista

    }

};

void BorrarCurso(string Psigla , int num)
{
    Curso *temp= listaCurso;
    Curso *ant=NULL;
    Curso *sig=listaCurso->sig;
    //Curso *ant=NULL;
    //Curso *sig= NULL;

    while(temp != NULL)
    {
        if((temp->sigla ==Psigla)&&(temp->num==num))
        {
            if(sig==NULL)
            {
                ant->sig=NULL;
                temp->sig=NULL;
                temp->ant=NULL;
                cout<<"Borrado con exito";
                break;
            }
            else{
                ant->sig=sig;
                sig->ant=ant;
                temp->ant=NULL;
                temp->sig=NULL;
                cout<<"Borrado con exito";
                break;
            }
        }
        else{
            if(sig->sig==NULL){
                ant=temp;
                temp=sig;
                sig=NULL;
            }
            else{
            ant=temp;
            temp= sig;
            sig=sig->sig;
            }
        }
    }
    cout<<"El curso no existe"<<endl;
};

struct Curso* buscaCurso(string cSigla, int cNum)
{
 struct Curso *temp= listaCurso;

    while(temp!= NULL)
    {
        if((temp->sigla==cSigla)&&(temp->num==cNum))
        {
                return temp;
        }
        else
        {
          temp = temp->sig;
        }
    }
    return NULL;
};

///----------------------------------------------------Sub lista------------------------------------------------------------------
struct semestre
{
    int numero;
    struct semestre*sig;
    struct CurSeme *enlaceCurSe;
};

///-------------------------------------------------Carreras------------------------------------------------------------
//Lista simple para insertar carreras se inserta al final
struct Carrera
{
    string carrera;
    struct Carrera *sig;
    struct semestre *enlaceSe;
}*listaCarreras;

struct SubCarrera
{
    struct SubCarrera *sig;
    struct SubCarrera *EnlaceCarrera;
};
void InsertarCarrera(string carrera)
{
    struct Carrera *temp = new Carrera();

    temp->carrera = carrera;
    temp->sig = NULL;

    if(listaCarreras == NULL)
    {
        listaCarreras = temp;  //si la lista está vacia se guarda en el nodo la carrera nueva
    }
    else
    {
         struct Carrera *temp1 = listaCarreras;   //se renombra el puntero para trabajar con un temporal
        while(temp1->sig != NULL){
            temp1 = temp1->sig;
        }
        temp1->sig = temp;
    }
}
void ImprimirCarreras()
{
    struct Carrera *aux = listaCarreras;  //se declara un puntero auxiliar para dejar el primer puntero intacto
    while(aux != NULL)
    {
        cout<<"\n\nCarrera: "<<aux->carrera<<endl;

		aux = aux -> sig;
    }

}
 struct Carrera *buscaCarrera(string pCarrera){
     struct Carrera *temp= listaCarreras;

    while(temp != NULL){
        if(temp->carrera == pCarrera)
        {
            return temp;
        }
        else{
            temp= temp->sig;
        }

    }

    return NULL;
}
///-------------------------------------------Semestre---------------------------------------------------------------------------
void insertarSemestre(string caNombre)
{
    struct Carrera *tempCA =buscaCarrera(caNombre);
    struct semestre *nuevoSemestre= new semestre();
    struct semestre *tempSE= tempCA->enlaceSe;
    int conta=1;

    if(tempSE==NULL)
    {

        tempCA->enlaceSe=nuevoSemestre;
    }
    else
    {
        while(tempSE->sig!=NULL)
        {
            tempSE=tempSE->sig;
            conta ++;
        }

        tempSE->sig=nuevoSemestre;
    }
    nuevoSemestre->numero=conta;
}

struct semestre* buscaSemestre(int numSe, struct semestre *primerSE)
{
    struct semestre *temp= primerSE;

    while(temp != NULL){
        if(temp->numero == numSe)
        {
            return temp;
        }
        else{
            temp= temp->sig;
        }

    }

    return NULL;
}

///----------------------------------Aulas-----------------------------------------------------------------------------------------
//lista circular para insertar aulas de forma ordenada por codigo (segun enunciado)
struct Aula
{
    string codigo;  // debe ser string ya que contienen letras y numeros , ejemplo LAB-01, LAB-02 , AU-07
    int numAula;
    struct Aula *sig;


}*primeraAula;

///-----------------------------------Sub lista----------------------------------------------------------------------------------------
struct CurSeme
{
    struct CurSeme *sig;
    struct Curso *EnlaCur;
};

void insertarCurSE(string codigoCu, int numCu, struct semestre *tempSe)
{
    struct Curso *tempCU =buscaCurso(codigoCu, numCu);
    struct CurSeme *nuevoCurSe= new CurSeme();
    if(tempSe->enlaceCurSe==NULL)
    {
        tempSe->enlaceCurSe=nuevoCurSe;
    }
    else{
        struct CurSeme *temp=tempSe->enlaceCurSe;
        while(temp->sig!=NULL)
        {
            temp=temp->sig;
        }
        temp->sig=nuevoCurSe;
    }
}

///------------------------------------Aulas------------------------------------------------------------
void InsertarAula(string codigo, int numAula)
{

    Aula *temp, *nuevAula = new Aula();

    nuevAula->numAula = numAula;
    nuevAula->codigo=codigo;

    if(primeraAula == NULL)
    {
        primeraAula = nuevAula;
        nuevAula->sig = primeraAula;

    }
    else
    {
        temp = primeraAula;
        while(temp->sig != primeraAula) // mientras sea diferente al inicio de la lista
        {
            temp = temp->sig;
        }
        temp->sig = nuevAula;  // se enlaza al primer nodo de la lista
        nuevAula->sig = primeraAula;
    }
}
void ImprimirAulas()
{

    struct Aula *temp = primeraAula->sig;
    if(temp != NULL)
    {

        while(temp != primeraAula) //Se recorren todos los nodos de conforman la lista
        {
            if(temp->sig != temp)
            {
                cout <<"\n\nCodigo de Aula: "<< temp->codigo<<endl;
                cout<<"Numero de aula: "<<temp->numAula<<"\n\n"; //Se imprimen los valores de la lista en pantalla, excepto el ùltimo
            }

            temp = temp->sig; //Se continua con el recorrido de la lista por medio del puntero temporal
        }
        cout <<"Codigo de Aula: "<< temp->codigo<<endl;
                cout<<"Numero de aula: "<<temp->numAula<<endl;
    }
    else
    {
        cout << "Lista vacia...";
    }
}

struct Aula *BuscarAula(string pCodigo, int pAula){
    struct Aula *temp = primeraAula;
    if((temp->codigo==pCodigo)&&(temp->numAula==pAula))
        {
            return temp;
        }
        else{
            temp = temp->sig;
        }
    while(temp!= primeraAula)
    {   if((temp->codigo==pCodigo)&&(temp->numAula==pAula))
        {
            return temp;
        }
        else{
            temp = temp->sig;
        }
    }

    return NULL;

}
///---------------------------------------------------Profesor----------------------------------------------------------------------
struct Profesor
{
    string Nombre;
    int Carne;
    struct Profesor *sig;

    //Profesor(string nom, int car)
    //{
      //  Nombre = nom;
        //Carne = car;
    //}
}*primerProfe;

struct SubProfe
{
    struct SubProfe *sig;
    struct SubProfe *EnlaceProfe;

};

void InsertarProfesor(string Nombre, int Carne)
{

    Profesor *temp,*nuevoProfe= new Profesor();
    nuevoProfe->Nombre=Nombre;
    nuevoProfe->Carne=Carne;
    if(primerProfe == NULL)
    {
        primerProfe = nuevoProfe;
    }
    else
    {
        temp = primerProfe;
        while(temp->sig != NULL)
        {
            temp = temp->sig;
        }
        temp->sig = nuevoProfe;

    }
}
void ModificarProfe(int CarneV, int CarneN)
{
    Profesor *temp=primerProfe;
    while(temp != NULL)
    {
        if(temp->Carne == CarneV)
        {
            temp->Carne== CarneN;
            cout<<"Carne modificado Exitosamente\n\n";
            break;
        }
        temp=temp->sig;
    }
}

void ModificarProfe(int Carne, string Nombre)
{
        Profesor *temp=primerProfe;
    while(temp != NULL)
    {
        if(temp->Carne == Carne)
        {
            temp->Nombre = Nombre;
            cout<<"Nombre modificado Exitosamente\n\n";
            break;
        }
        temp=temp->sig;
    }
}

void BorrarProfesor(int carne)
{
    Profesor *temp=primerProfe;
    if(primerProfe->Carne==carne)
        {
            primerProfe=primerProfe->sig;
        }
    else{
    while(temp != NULL)
    {

        if(temp->sig->Carne == carne)
        {

        break;
        }


        temp=temp->sig;
        }
    temp->sig=temp->sig->sig;
    }

    cout<<"No existe este profesor";
        MenuProfesor();
}

void ImprimirProfes()
{

    struct Profesor *temp= primerProfe;
    while(temp!=NULL)
    {
        cout<<"Profesor: "<<temp->Nombre<<endl;
        cout<<"Carne del Profesor: "<<temp->Carne<<"\n\n"<<endl;
        cout<<endl<<endl;
        temp=temp->sig;

    }
}

struct Profesor *BuscarProfe(string pNombre, int pCarne){
     struct Profesor *temp=primerProfe;
     while(temp != NULL)
     {
         if((temp->Nombre == pNombre)&&(temp->Carne== pCarne)){
            return temp;
         }
         else{
            temp = temp->sig;
         }
     }

     return NULL;
};


///---------------------------------Sub lista-----------------------------------------------------------------------------
struct Grupo
{
    int numeroGru;
    int hora;
    int dia;
    struct Grupo *sig;
    struct Aula *EnlaAu;
    struct Profesor *EnlaPro;
};

void insertarGrupo(string siglaCu, int numCu, string nomPro, int numPro, string siglaAu, int numAu)
{
    struct Curso *tempCU =buscaCurso(siglaCu,numCu);
    struct Grupo *nuevoGrupo=new Grupo();
    nuevoGrupo->EnlaAu=BuscarAula(siglaAu, numAu);
    nuevoGrupo->EnlaPro=BuscarProfe(nomPro, numPro);
    struct Grupo *tempGR= tempCU->enlaceGru;

    int gru=50;

    if(tempGR==NULL)
    {
        tempCU->enlaceGru=nuevoGrupo;
    }
    else
    {
        while(tempGR->sig!=NULL)
        {
            tempGR=tempGR->sig;
            gru ++;
        }
        tempGR->sig=nuevoGrupo;
    }
    nuevoGrupo->numeroGru=gru;
}

struct Grupo *buscaGrupo(int gru, struct Grupo *primerGru)
{
    struct Grupo *temp= primerGru;

    while(temp != NULL){
        if(temp->numeroGru == gru)
        {
            return temp;
        }
        else{
            temp= temp->sig;
        }

    }

    return NULL;
};


///---------------------------------La matriz--------------------------------------------------------------------------
string matriz[16][5];
string dias[]= {"   Horas   ","     Lunes  ","    Martes  ","  Miercoles ","    Jueves  ","    Viernes "};
string horas[]= {"07:00-07:50","07:55-08:45","08:50-09:40","09:45-10:35","10:40-11:30","11:30-12:30","12:30-01:20","01:25-02:15",
"02:20-03:10","03:15-04:05","04:05-04:55","05:00-05:50", "05:55-06:45","06:50-07:40","07:45-08:35","08:40-09:30"};


void imprimirMatriz(){

///     Horas
matriz[0][0]="1";matriz[1][0]="1";matriz[2][0]="1";matriz[3][0]="1";matriz[4][0]="1";matriz[5][0]="1";matriz[6][0]="1";matriz[7][0]="1";matriz[8][0]="1";
matriz[9][0]="1";matriz[10][0]="1";matriz[11][0]="1";matriz[12][0]="1";matriz[13][0]="1";matriz[14][0]="1";matriz[15][0]="1";

int conta=0;
    cout<<"|"<<dias[0]<<"|"<<dias[1]<<"|"<<dias[2]<<"|"<<dias[3]<<"|"<<dias[4]<<"|"<<dias[5]<<"|"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;

    {
    for(int j = 0; j<16; j++)
    {
        for(int i=0; i<5; i++)
        {

            if(matriz[j][i]=="1")
            {
                cout<<"|"<<horas[conta]<<"|";
                conta ++;
            }
            if(matriz[j][i]=="2")
            {
                cout<<" Reservado "<<" |";
            }
            else
            {
                cout<<" Disponible"<<" |";
            }
        }
        cout<<endl;
    }
    }
    }

void imprimirHorario(string sigla, int numCurso, int grupo)
{
    for(int j = 0; j<16; j++)
    {
        for(int i=0; i<5; i++)
        {
            matriz[j][i]="";
        }
    }
    int dia;
    int hora;
    int numLecciones;
    char opcion;
    char opcion2;
    struct Curso * curso = buscaCurso(sigla, numCurso);
    if (curso == NULL){
        cout<<"El curso no existe"<<endl;
    }
    else{
        struct Grupo * tempGrupo = curso->enlaceGru;
        while(tempGrupo != NULL){
            if (tempGrupo->numeroGru == grupo){
                break;
            }
            tempGrupo = tempGrupo->sig;
        }
        if (tempGrupo == NULL)
            cout<<"No se encontro el grupo"<<endl;
        else{
            cout<<endl<<"Digite el numero de lecciones del curso: ";
            cin>>numLecciones;
            //cout<<endl<<"El curso posee restricciones?"<<endl;
            //cout<<"1: Debe darse todas las lecciones juntas.\n2: No se puede dar despues de alumerzo\n 3: ninguna."<<endl;
            //cin>>opcion;
            cout<<"El profesor posee restricciones?"<<endl;
            cout<<"1: Si. \n2: No."<<endl;
            cin>>opcion2;
            if (opcion2 == 1){
                for(int j = 0; j<16; j++)
                    {
                        for(int i=0; i<5; i++)
                    {
                        matriz[j][i]=curso->nombre;
                    }
                }
            }
            while (opcion2 != 1){

                cout<<"0: Lunes\n1: Martes\n2: Miercoles\n3: Jueves\n4: Viernes\n";
                cout<<endl<<"Que dia puede dar clases?: ";
                cin>>dia;
                while((dia!=0) and (dia!=1) and (dia!=2) and (dia!=3) and (dia!=4)){
                    cout<<endl<<"Opcion invalida."<<endl;
                    cout<<"0: Lunes\n1: Martes\n2: Miercoles\n3: Jueves\n4: Viernes\n";
                    cout<<endl<<"Que dia puede dar clases?: ";
                    cin>>dia;
                }
                cout<<"0: "<<horas[0]<<endl<<"1: "<<horas[1]<<endl<<"2: "<<horas[2]<<endl<<"3: "<<horas[3]<<endl;
                cout<<"4: "<<horas[4]<<endl<<"5: "<<horas[5]<<endl<<"6: "<<horas[6]<<endl<<"7: "<<horas[7]<<endl;
                cout<<"8: "<<horas[8]<<endl<<"9: "<<horas[9]<<endl<<"10: "<<horas[10]<<endl<<"11: "<<horas[11]<<endl;
                cout<<"12: "<<horas[12]<<endl<<"13: "<<horas[13]<<endl<<"14: "<<horas[14]<<endl<<"15: "<<horas[15]<<endl;
                cout<<endl<<"A que hora puede dar clases?: ";
                cin>>hora;
                while ((hora != 0) and (hora != 1) and (hora != 2) and (hora != 3) and (hora != 4) and (hora != 5) and (hora != 6) and (hora != 7) and (hora != 8) and (hora != 9) and (hora != 10) and (hora != 11) and (hora != 12) and (hora != 13) and (hora != 14) and (hora != 15)){
                    cout<<endl<<"Opcion invalida"<<endl;
                    cout<<"0: "<<horas[0]<<endl<<"1: "<<horas[1]<<endl<<"2: "<<horas[2]<<endl<<"3: "<<horas[3]<<endl;
                    cout<<"4: "<<horas[4]<<endl<<"5: "<<horas[5]<<endl<<"6: "<<horas[6]<<endl<<"7: "<<horas[7]<<endl;
                    cout<<"8: "<<horas[8]<<endl<<"9: "<<horas[9]<<endl<<"10: "<<horas[10]<<endl<<"11: "<<horas[11]<<endl;
                    cout<<"12: "<<horas[12]<<endl<<"13: "<<horas[13]<<endl<<"14: "<<horas[14]<<endl<<"15: "<<horas[15]<<endl;
                    cout<<endl<<"A que hora puede dar clases?: ";
                    cin>>hora;
                }
                matriz[hora][dia] = curso->nombre;
                cout<<"El profesor puede dar lecciones en otro dia/hora? (1: Si/ 2: No): ";
                cin>>opcion2;
            }
            cout<<"|"<<dias[0]<<"|"<<dias[1]<<"|"<<dias[2]<<"|"<<dias[3]<<"|"<<dias[4]<<"|"<<dias[5]<<"|"<<endl;
            cout<<"------------------------------------------------------------------------------"<<endl;
            int cont = 0;
            for (int j = 0; j<16; j++)
            {
                cout<<horas[j]<<"|";
                for (int i = 0; i<5; i++)
                {
                    if ((matriz[j][i]!="") and (cont<numLecciones)){
                        cout<<curso->nombre<<"|";
                        cont++;
                    }
                    else
                        cout<<"         "<<" |";
                }
                cout<<endl;
            }
        }
    }
}
/**
PROFES:
CURSOS:

**/
///---------------------------------Union----------------------------------------------------------------------------
void InsertarHorario(int Carne, string nomPro, string cSigla, int cNum, string carNombre, string auCodigo, int auNum)
{
    struct Carrera * tempCar = buscaCarrera(carNombre);
    struct Curso *tempCur = buscaCurso(cSigla, cNum);
    struct Profesor *tempPro = BuscarProfe(nomPro, Carne);
    struct Aula *tempAu = BuscarAula(auCodigo, auNum);
}

///---------------------------------Menus de profes------------------------------------------------------------------

void enlazarSemestreCurso(string cSigla, int cNum, string caNom, int sNum){
struct Carrera *tempCa=buscaCarrera(caNom);
struct Curso *tempCu=buscaCurso(cSigla,cNum);
struct semestre *tempSe=tempCa->enlaceSe;
struct CurSeme *tempCurSe=new CurSeme();
struct CurSeme *tempCurSe1;
tempCurSe->EnlaCur=tempCu;

if(tempSe==NULL){
    tempCa->enlaceSe=new semestre();
    tempCa->enlaceSe->enlaceCurSe=tempCurSe;
}
else{
    while((tempSe->sig!=NULL)&&(tempSe->numero!=sNum)){
        tempSe=tempSe->sig;
    }
    if(tempSe->numero==sNum){
        tempCurSe1=tempSe->enlaceCurSe;
        if(tempCurSe1==NULL){
            tempSe->enlaceCurSe=tempCurSe;
        }
        else{
            bool agregar=true;
            while(tempCurSe1->sig!=NULL){
                if((tempCurSe1->EnlaCur->sigla==cSigla)&&(tempCurSe1->EnlaCur->num==cNum)){
                    agregar=false;
                }
            }
            if(agregar){
                tempCurSe1->sig=tempCurSe;
            }
        }
    }
    else{
        tempSe->sig=new semestre();
        tempSe->numero=sNum;
        tempSe->enlaceCurSe=tempCurSe;
    }
}
}

void MenuModProfe()
{
    char opcion;
    cout<<"\n\nQue desea modificar?\n1.Nombre\n2.Carne:\n3.Regresar  ";
    cin>>opcion;
    if(opcion=='1')
    {
        string NuNo;
        int Ca;
        cout<<"\n\nEscriba el carne del profesor que desea reemplazar:  ";
        cin>>Ca;
        cout<<"\n\nEscriba el nuevo nombre del profesor:  ";
        cin>>NuNo;
        ModificarProfe(Ca,NuNo);
    }
    if(opcion=='2')
    {
        int NuCa;
        int ViCa;
        cout<<"\n\nEscriba el carne que desea reemplazar:  ";
        cin>>ViCa;
        cout<<"\n\nEscriba el nuevo carne:  ";
        cin>>NuCa;
        ModificarProfe(ViCa, NuCa);
    }
    if(opcion=='3')
    {
        MenuProfesor();
    }
    else{
        MenuModProfe();
    }
}

void MenuProfesor()
{
    char opcion;
    cout<<"-----------------------\n\n";
    cout<<"Menu de Profesores.\n\n1.Agregar nuevo profesor\n2.Modifcar profesor\n3.Borrar profesor\n4.Ver profesores\n5.Menu Principal.  ";
    cin>>opcion;
    if(opcion=='1')
    {
        cout<<"\n\n";
        string N;
        int C;
        cout<<"\n\nDigite el nombre del nuevo profesor:  ";
        cin>>N;
        cout<<"\n\nDigite el carne del nuevo profesor:  ";
        cin>>C;
        InsertarProfesor(N, C);
        MenuProfesor();
    }
    if(opcion=='2')
    {
        cout<<"\n\n";
        MenuModProfe();
        MenuProfesor();
    }
    if(opcion=='3')
    {
         cout<<"\n\n";
         int car;
         cout<<"Digite el carne del profesor que desea Eliminar:  ";
         cin>>car;
         BorrarProfesor(car);
        MenuProfesor();
    }
    if(opcion=='4')
    {
       cout<<"\n\n";
       ImprimirProfes();
       MenuProfesor();
    }
    if(opcion=='5')
    {
        cout<<"\n\n";
        main();

    }
    else
    {
        cout<<"Digito invalido!\n\n";
        MenuProfesor();
    }
}

///-------------------------------------------------------------Menu de Cursos--------------------------------------------------------

void menuModCurso()
{
    char opcion;
    cout<<"\n\nQue desea modificar?\n1.sigla\n2.numero de codigo\n3.nombre\n4.cantidad de creditos \n5.Menu cursos:  ";
    cin>>opcion;
    if(opcion=='1')
    {
    string vs;
    string ns;
    int num;
    cout<<"Digite la sigla del curso que desea modificar: ";
    cin>> vs;
    cout<<"Digite el numero del curso que desea modificar: ";
    cin>> num;
    cout<<"Digite la nueva sigla para el curso a modificar: ";
    cin>>ns;
    modificarCurso(vs,ns,num);
    }
    if(opcion=='2')
    {
        string s;
        int vnum;
        int nnum;
        cout<<"Digite la sigla del curso que desea modificar: ";
        cin>>s;
        cout<<"Digite el numero del curso que desea modificar: ";
        cin>>vnum;
        cout<<"Digite el nuevo numero del curso a modificar: ";
        cin>>nnum;
        modificarCurso(s,vnum,nnum);
    }
    if(opcion=='3')
    {
        string s;
        int num;
        string nom;
        cout<<"Digite la sigla del curso que desea modificar: ";
        cin>>s;
        cout<<"Digite el numero del curso que desea modificar: ";
        cin>>num;
        cout<<"Digite el nuevo nombre del curso: ";
        cin>>nom;
        modificarCurso(s,num,nom);
    }
    if(opcion=='4')
    {
        string s;
        int num;
        int c;
        cout<<"Digite la sigla del curso que desea modificar: ";
        cin>>s;
        cout<<"Digite el numero del curso que desea modificar: ";
        cin>>num;
        cout<<"Digite la cantidad de creditos del curso: ";
        cin>>c;
        modificarCurso(num,s,c);
    }
    if(opcion =='5')
    {

        menuCursos();
    }
    else{
        menuModCurso();
    }
}

void menuCursos()
{
char opcion;
cout<<"--------------------------------------------------\n\n";
cout<<"Menu de cursos. \n\n1.Agregar nuevo curso\n2.Modificar curso\n3.Borrar curso\n4.Ver cursos\n5.Ir al menu principal";
cin>>opcion;
if(opcion =='1')
{

    cout<<"\n\n";
    string s, nom;
    int num, c;
    cout<<"Escriba la sigla del curso: ";
    cin>> s;
    cout<<"Escriba el codigo del curso: ";
    cin>> num;
    cout<<"Escriba el nombre del curso: ";
    cin>>nom;
    cout<<"Escriba la cantidad de creditos del curso: ";
    cin>>c;
    InsertarCurso(s,num,nom,c);
    menuCursos();
}
if(opcion== '2')
{
    menuModCurso();
    menuCursos();
}
if(opcion=='3'){
    string pSigl;
    int num;
    cout<<"Digite la sigla del curso:";
    cin>>pSigl;
    cout<<"Digite el numero del curso:";
    cin>>num;
    BorrarCurso(pSigl,num);
    menuCursos();
}

if(opcion == '4')
{
    ImprimirCursos();
    menuCursos();
}
if(opcion=='5'){
    main();
}
else{
    cout<<"Digito invalido !";
    menuCursos();
}
}

void menuCarreras()
{
    char opcion;
    cout<<"-----------------------------------------------------------------\n\n";
    cout<<"Menu de carreras. \n\n1.Crear carrera\n2.Ver carreras\n3.Salir: ";
    cin>>opcion;

    if(opcion=='1')
    {
        string nombre;
        cout<<"\nEscriba el nombre de la nueva carrera: ";
        cin>> nombre;
        InsertarCarrera(nombre);
        menuCarreras();
    }
    if(opcion=='2')
    {
        ImprimirCarreras();
        menuCarreras();
    }
    if(opcion=='3')
    {
        main();
    }
    else{
        cout<<"\n\nIncorrecto!\n\n";
        menuCarreras();
    }
}

void menuAulas()
{
    char opcion;
    cout<<"-----------------------------------------------------------------\n\n";
    cout<<"Menu de aulas. \n\n1.Crear aulas\n2.Ver aulas\n3.Salir: ";
    cin>>opcion;
    if(opcion=='1'){
        string codigo;
        int numero;
        cout<<"\n Escriba el codigo de la nueva aula: ";
        cin>>codigo;
        cout<<"\n Escriba el numero de la nueva aula: ";
        cin>>numero;
        InsertarAula(codigo, numero);
        menuAulas;
    }
    if(opcion=='2'){
        ImprimirAulas();
        menuAulas();
    }
    if(opcion=='3')
    {
        main();
    }
    else{
        menuAulas();
    }

}

void menuHorarios()
{
    char opcion;
    cout<<"-----------------------------------------------------------------\n\n";
    cout<<"Menu de horario. \n\n 1.ver horario\n2.Asignar horario a carrera\n3.Imprimir horario de carrera\n4.imprimir horario de curso: ";
    cin>>opcion;

    if(opcion=='1')
    {
        imprimirMatriz();
        menuHorarios();
    }
    if(opcion =='2'){
       /* string p_carrera;
        cout<<"Ingrese el nombre de la carrera: ";
        cin >>p_carrera;
        buscaCarrera(p_carrera);
        if(buscaCarrera(p_carrera)==NULL){
            cout<<"No existe esa carrera.";
            menuHorarios();
        }

        struct semestre tempSE;
        int p_numS;
        cout<<"Ingrese el numero de semestre: ";
        cin >>p_numS;
        buscaSemestre(p_numS, &tempSE);
        if(buscaSemestre(p_numS, &tempSE)==NULL){
        insertarSemestre(p_carrera);
        }
        string nomProfe;
        int carneProf;
        cout<<"Ingrese el nombre del profesor:";
        cin>> nomProfe;
        cout <<"Ingrese el carne del profesor:";
        cin >>carneProf;
        BuscarProfe(nomProfe,carneProf);

        string siglaCur;
        int numCur;
        cout<<"Ingrese la sigla del curso:";
        cin>>siglaCur;
        cout<<"Ingrese el numero del curso";
        cin>>numCur;
        buscaCurso(siglaCur,numCur);

        int p_grupo;
        struct Grupo tempGRU;
        cout<<"Ingrese el numero de grupo";
        cin>>p_grupo;
        buscaGrupo(p_grupo, &tempGRU);

        string p_codigo;
        int p_numAu;
        cout<<"Ingrese el codigo de indentificacion del aula";
        cin>>p_codigo;
        cout<<"Ingrese el numero de aula";
        cin>>p_numAu;
        BuscarAula(p_codigo,p_numAu);

    */
    string nomCar;
    cout<<"Escriba el nombre de la carrera: ";
    cin>>nomCar;
    struct Carrera *tempCarrera=buscaCarrera(nomCar);
    if(tempCarrera==NULL){
        cout<<"Esa carrera no existe. Desea agregarla? (1.Si/2.No) ";
        char opcionCar;
        cin>>opcionCar;
        if(opcionCar=='1'){
            InsertarCarrera(nomCar);
        }
        if(opcionCar=='2'){
            menuHorarios();
        }
    }
    int numSe;
    cout<<"Escriba el numero del semestre: ";
    cin>>numSe;
    string siglaCur;
    int numCur;
    cout<<"Escriba la sigla del curso: ";
    cin>> siglaCur;
    cout<<"Escriba el numero del curso: ";
    cin>>numCur;
    struct Curso *tempCurso=buscaCurso(siglaCur, numCur);
    if(tempCurso==NULL){
        cout<<"El curso no existe.";
        char op;
        cout<<"Desea insertarlo? (1=Si/2=No) ";
        cin>>op;
        if(op=='1'){
            string cNombre;
            cout<<"Escriba el nombre del curso: ";
            cin>>cNombre;
            int cCreditos;
            cout<<"Escriba la cantidad de creditos: ";
            cin>>cCreditos;
            InsertarCurso(siglaCur,numCur,cNombre,cCreditos);
            }
        else{
            menuHorarios();
            }
    }
    string nomP;
    cout<<"Escriba el nombre del profe: ";
    cin>> nomP;
    int carP;
    cout<<"Escriba el carne del profe: ";
    cin>>carP;
    string codAu;
    cout<<"Escriba el codigo del aula: ";
    cin>>codAu;
    int numAu;
    cout<<"Escriba el numero del aula: ";
    cin>> numAu;
    int numGru;
    cout<<"Digite el numero del grupo: ";
    cin>>numGru;
    struct Grupo *temp = new Grupo();
    struct Grupo *tempGrupo = buscaGrupo(numGru,temp);
    if(tempGrupo==NULL){
        enlazarSemestreCurso(siglaCur,numCur,nomCar,numSe);
        insertarGrupo(siglaCur,numCur,nomP,carP,codAu,numAu);
    }
    else{
        cout<<"El grupo ya existe.";
    }

    }

    if(opcion=='3'){
        string nomCa;
        cout<<"Escriba el nombre de la carrera: ";
        cin>>nomCa;
        struct Carrera *tempCarrera=buscaCarrera(nomCa);
        if(tempCarrera==NULL){
            char opc;
            cout<<"Esa carrera no existe. Desea agregarla? (1.Si/2.No) ";
            cin>>opc;
            if(opc=='1'){
                InsertarCarrera(nomCa);
                menuHorarios();
            }
            if(opc=='2'){
                menuHorarios();
            }
        }
        cout<<"|Sigla|Numero|Nombre|Grupo|Creditos|Profesor|\n";
        struct semestre *tempSemestre = tempCarrera->enlaceSe;
        while(tempSemestre!=NULL)
            {
            struct CurSeme *tempCurSeme = tempSemestre->enlaceCurSe;
            while(tempCurSeme!=NULL)
            {
                struct Curso *tempCurso = tempCurSeme->EnlaCur;
               while(tempCurso!=NULL)
               {
                struct Grupo *tempGrupo=tempCurso->enlaceGru;
                while(tempGrupo!=NULL)
                {
                    cout<<"|"<<tempCurso->sigla<<tempCurso->num<<"|"<<tempCurso->nombre<<"|"<<tempGrupo->numeroGru<<"|"<<tempCurso->creditos<<"|"<<tempGrupo->EnlaPro->Nombre<<"|\n";
                    tempGrupo=tempGrupo->sig;
                }
                tempCurso=tempCurso->sig;
               }
               tempCurSeme=tempCurSeme->sig;
            }
        tempSemestre=tempSemestre->sig;
        }
}

if(opcion=='4')
{
    string sigCur;
    int numCur;
    cout<<"Escriba la sigla del curso: ";
    cin>>sigCur;
    cout<<"Escriba el numero del curso: ";
    cin>>numCur;
    struct Curso *tempCurso= buscaCurso(sigCur,numCur);
    if(tempCurso==NULL)
    {
        char opc;
        cout<<"Este curso no existe. Desea agregarla? (1.Si/2.No) ";
        if(opc=='1'){
            int creditos;
            string nombre;
            cout<<"Escriba el nombre del curso: ";
            cin>>nombre;
            cout<<"Escriba la cantidad de creditos: ";
            cin>>creditos;
            InsertarCurso(sigCur,numCur,nombre,creditos);
            menuHorarios();
        }
        if(opc=='2'){
            menuHorarios();
        }
    }
    cout<<"|Sigla|Numero|Nombre|Grupo|Creditos|Profesor|\n";
    while(tempCurso!=NULL){
            struct Grupo *tempGrupo=tempCurso->enlaceGru;
            while(tempGrupo!=NULL){
              cout<<"|   "<<tempCurso->sigla<<tempCurso->num<<"  |"<<tempCurso->nombre<<"|"<<tempGrupo->numeroGru<<"|"<<tempCurso->creditos<<"|"<<tempGrupo->EnlaPro->Nombre<<"|\n";
              tempGrupo=tempGrupo->sig;
            }
        tempCurso=tempCurso->sig;
    }
if(opcion=='5')
{
    string sigla;
    int num;
    int grupo;
    cout<<"Escriba la sigla de curso: ";
    cin>>sigla;
    cout<<"Escriba el numero de curso: ";
    cin>> num;
    cout<<"Escriba el numero de grupo: ";
    cin>> grupo;
    imprimirHorario(sigla, num, grupo );
}
if(opcion== '6')
{
    menuHorarios();
}


}
else{
       cout<< "\n\nIncorrecto!\n\n";
        menuHorarios();
    }
}
int main()
{

    char opcion;
    InsertarCarrera("Computacion");
    InsertarCarrera("Produccion");
    InsertarCurso("IC",1400,"Funda",3);
    InsertarCurso("IC",2101,"POO",4);
    InsertarCurso("IC",3101,"Arqui",4);
    InsertarAula("Miniauditorio",13);
    InsertarAula("LAB",01);
    InsertarAula("Aula",10);
    InsertarProfesor("Huber",123);
    InsertarProfesor("Vera",456);
    InsertarProfesor("Esteban",789);
    InsertarProfesor("Rodolfo",741);
    InsertarProfesor("Jorge",852);
    cout<<"-----------------------------------------------------------------";
    cout<<"\n\nBienvenido que desea realizar?\n1.Carreras\n2.Cursos\n3.Aulas\n4.Profesores\n5.Horario\n6.Salir:  ";
    cin>>opcion;

    if(opcion=='1')
    {
        cout<<endl;
        menuCarreras();
        main();
    }
    if(opcion=='2')
    {
        cout<<endl;

        menuCursos();
        main();
    }
    if(opcion=='3')
    {
        cout<<endl;

        menuAulas();
        main();
    }
    if(opcion =='4')
    {

        cout<<endl;

        MenuProfesor();
        main();
    }
    if(opcion=='5')
    {
        cout<<endl;
        menuHorarios();
        main();

    }
    if(opcion=='6')
    {
    exit (EXIT_FAILURE);
    }
    else{
        main();
    }


return 0;
}
