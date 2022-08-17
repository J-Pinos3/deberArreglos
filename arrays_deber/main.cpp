#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <ctime>
#include <random>

using namespace std;

const int MAX = 50;
int Menu();

int menu_Calificaciones();
void Agregar_calificaciones(array<int, MAX>& arr, int& total );
bool Buscar_calificaciones(const array<int, MAX>& arr, const int total, int& indice);
void Eliminar_calificaciones(array<int, MAX>& arr, int& total );
void Insertar_calificacion(array<int, MAX>& arr, int& total);
void Ordenar_calificaciones(array<int, MAX>& arr, const int total);
void Mostrar_calificaciones(const array<int, MAX>& arr, const int total);

void Palindromo();
void Invertir_Array(array<int, 20>& arr, int cifras );

void Elim_duplicados();

void Suma_Dados(array <int, 7>& dado1, array <int, 7>& dado2);

int main()
{

   int opcion = 1;

    while(opcion != 0){
        opcion = Menu();
        system("cls");

        switch(opcion){

            case 1:{
                   int opcion_notas = 1;
                   int total = 0;
                   array <int, MAX> arreglo_notas = {};

                    while(opcion_notas != 0){
                            opcion_notas = menu_Calificaciones();
                            system("cls");

                            switch(opcion_notas){

                                case 1:{
                                    cout <<"\t\tAGREGAR CALIFICACIONES"<<endl<<endl;
                                    Agregar_calificaciones(arreglo_notas, total);
                                    cout <<endl<<endl;
                                    Mostrar_calificaciones(arreglo_notas, total);
                                }
                                break;

                                case 2:{
                                    cout <<"\t\tBUSCAR CALIFICACIONES"<<endl<<endl;
                                    int indice = 0;
                                    if ( Buscar_calificaciones(arreglo_notas, total, indice) ){
                                            cout <<"Elemento encontrado en la posici"<<char(162)<<"n: "<<indice+1<<endl<<endl;
                                    }else{
                                        cout <<"No se pudo encontrar el elemento"<<endl<<endl;
                                    }
                                    Mostrar_calificaciones(arreglo_notas, total);
                                }
                                break;

                                case 3:{
                                    cout <<"\t\tELIMINAR CALIFICACIONES"<<endl<<endl;
                                    Mostrar_calificaciones(arreglo_notas, total);
                                    cout <<endl<<endl;
                                    Eliminar_calificaciones(arreglo_notas, total);
                                }
                                break;

                                case 4:{
                                    cout <<"\t\tINSERTAR CALIFICACIONES"<<endl<<endl;

                                    Mostrar_calificaciones(arreglo_notas, total);
                                    cout <<endl<<endl;
                                    Insertar_calificacion(arreglo_notas, total);

                                }
                                break;

                                case 5:{
                                    cout <<"\t\tORDENAR CALIFICACIONES"<<endl<<endl;
                                    Ordenar_calificaciones(arreglo_notas, total);
                                    cout <<endl<<endl;
                                    Mostrar_calificaciones(arreglo_notas, total);
                                }
                                break;


                                case 0:{
                                    cout <<"\t\tVuelva Pronto"<<endl<<endl;

                                }
                                break;

                                default:{
                                    cout <<"ALGO HA SALIDO MUY MAL :("<<endl<<endl;
                                }
                                break;



                            }//fin del switch interno


                            system("pause");
                            system("cls");

                    }//fin del while interno CALIFICACIONES

            }
            break;


            case 2:{
                    Palindromo();

            }
            break;


            case 3:{
                    Elim_duplicados();
            }
            break;


            case 4:{
                    array <int, 7> dado1 = {};
                    array <int, 7> dado2 = {};
                    Suma_Dados(dado1, dado2);
            }
            break;

            case 0:{
                cout <<"\tGracias por su preferencia"<<endl<<endl;
            }
            break;


            default:{
                cout <<"ALGO HA SALIDO MUY MAL :("<<endl<<endl;
            }
            break;


        }//fin del switch principal

        system("pause");
        system("cls");

    }//FIN DEL WHILE PRINCIPAL


    return 0;
}


int Menu(){
    int opcion;
    cout <<"\tMEN"<<char(233)<<endl;
    cout <<"1) Ejercicio 1"<<endl;//calificaciones
    cout <<"2) Ejercicio 2"<<endl;//palíndromo
    cout <<"3) Ejercicio 3"<<endl;//duplicados
    cout <<"4) Ejercicio 4"<<endl;//dados
    cout <<"0) SALIR"<<endl;

    cout <<"Opci"<<char(162)<<"n"<<endl;
    cin >> opcion;

    while(opcion < 0 || opcion > 4){
        cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
        cout <<"Opci"<<char(162)<<"n"<<endl;
        cin >> opcion;
        cout <<endl;
    }


    return opcion;
}//FIN DE LA FUNCION MENU



int menu_Calificaciones(){

    int opcion_1;
    cout <<"\tMEN"<<char(233)<<endl;
    cout <<"1) Agregar calificaciones"<<endl;
    cout <<"2) Buscar calificaci"<<char(162)<<"n"<<endl;
    cout <<"3) Eliminar calificaci"<<char(162)<<"n"<<endl;
    cout <<"4) Insertar calificaci"<<char(162)<<"n"<<endl;
    cout <<"5) Ordenar calificaciones"<<endl;
    cout <<"0) SALIR"<<endl;

    cout <<"Opci"<<char(162)<<"n"<<endl;
    cin >> opcion_1;

    while(opcion_1 < 0 || opcion_1 > 5){
        cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
        cout <<"Opci"<<char(162)<<"n"<<endl;
        cin >> opcion_1;
        cout <<endl;
    }


    return opcion_1;


}//fin de la funcion menu_Calificaciones

void Agregar_calificaciones(array<int, MAX>& arr, int& total ){
     int nota = 0;
     int i = total;//ingresa calificaciones al final si i = 0, siempre se ingresan las notas desde 0
     cout <<"Ingrese las notas de los estudiantes entre 0 y 10, incluidos, (-1 para terminar)"<<endl<<endl;
     cin >> nota;
     while(nota < -1 || nota > 10){
         cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
         cout <<"Ingrese las notas de los estudiantes entre 0 y 10, incluidos, (-1 para terminar)"<<endl<<endl;
         cin >> nota;
     }

     while(nota != -1){

         arr.at(i) = nota;
         i++;
         total++;//cada vez que se ingresa un alumno el total aumenta
         cout <<"Ingrese las notas de los estudiantes entre 0 y 10, incluidos, (-1 para terminar)"<<endl<<endl;
         cin >> nota;
         while(nota < -1 || nota > 10){
             cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
             cout <<"Ingrese las notas de los estudiantes entre 0 y 10, incluidos, (-1 para terminar)"<<endl<<endl;
             cin >> nota;
         }
     }
    //cout <<"Se ingresaron: "<<i<<" elementos"<<endl;
}//FIN DE LA FUNCIÓN AGREGAR CALIFICACIONES

bool Buscar_calificaciones(const array<int, MAX>& arr, const int total, int& indice){
    bool encontradoPE= false;
    int valor_a_buscar = 0;
    cout <<"Ingrese el valor a buscar: ";
    cin >> valor_a_buscar;
    for(int i = 0; i < total && encontradoPE == false; i++){
        if( valor_a_buscar == arr.at(i) ){
            encontradoPE = true;
            indice = i;
        }
    }

    return encontradoPE;
}//FIN DE LA FUNCIÓN BUSCAR CALIFICACIONES

void Eliminar_calificaciones(array<int, MAX>& arr, int& total ){
    int pos = 0;
    cout <<"Ingrese la posici"<<char(162)<<"n de la nota que desea eliminar: ";
    cin >> pos;

    while(pos < 1 || pos > total){
        cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
        cout <<"Ingrese la posici"<<char(162)<<"n de la nota que desea eliminar: ";
        cin >> pos;
    }

    pos = pos-1;
    for(int i = pos; i < total-1; i++){
        arr.at(i) = arr.at(i+1);
    }

    total--;
}//FIN DE LA FUNCIÓN ELIMINAR CALIFICACIONES

void Insertar_calificacion(array<int, MAX>& arr, int& total){
    int pos = 0;
    int nuevo = 0;
    if(total < MAX){
        cout <<"Ingrese la posici"<<char(162)<<"n de la nota insertar: ";
        cin >>pos;
        while(pos < 1 || pos > total){
            cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
            cout <<"Ingrese la posici"<<char(162)<<"n de la nota que desea eliminar: ";
            cin >> pos;
        }

        cout <<"Ingrese la nota del estudiante entre 0 y 10, incluidos: ";
        cin >> nuevo;   
        while(nuevo < 0 || nuevo > 10){
            cout <<"Error \nInt"<<char(130)<<"ntelo de nuevo"<<endl;
            cout <<"Ingrese la nota del estudiante entre 0 y 10, incluidos: "<<endl<<endl;
            cin >> nuevo;

        }

        pos = pos-1;
        for(int i= total; i > pos; i-- ){
            arr.at(i) = arr.at(i-1);
        }
        arr.at(pos) = nuevo;
        total++;
    }

}//FIN DE LA FUNCION INSERTAR CALIFICACION

void Ordenar_calificaciones(array<int, MAX>& arr, const int total){
    //ORDENAMIENTO POR SELECCIÓON
    int aux = 0, min = 0;
    for(int i = 0; i < total; i++){

        min = i;

        for(int j = i+1; j < total; j++){
            if( arr.at(j) < arr.at(min) ){
                min = j;
            }
        }
        aux = arr.at(i);
        arr.at(i) = arr.at(min);
        arr.at(min) = aux;
    }

}//FIN DE LA FUNCIÓN ORDENAR CALIFICACIONES

void Mostrar_calificaciones(const array<int, MAX>& arr, const int total){

    cout <<endl<<endl<<"Resumen de notas"<<endl<<endl;
    for(int i = 0; i < total; i++){
        cout <<"Nota "<<i+1<<": "<<arr.at(i)<<endl;

    }


}//FIN DE LA FUNCIÓN MOSTRAR CALIFICACIONES



void Palindromo(){
    array<int, 20> arr_orig = {};
    array<int, 20> arr_invert = {};

    int cifras = 0;
    int digitos;
    cout <<"Ingrese el n"<<char(163)<<"mero de d"<<char(161)<<"gitos a almacenar: ";
    cin >> digitos;
    while(digitos < 0){
        cout <<"Ingrese el n"<<char(163)<<"mero de d"<<char(161)<<"gitos a almacenar: ";
        cin >> digitos;
    }
    cout <<"\nIngrese los d"<<char(161)<<"gitos del n"<<char(163)<<"mero para determinar si es pal"<<char(161)<<"ndromo "<<endl<<endl;
    //LA LECTURA CONSTANTE DE DATOS ME DA EL ERROR
    int i = 0, numero = 0;
    while( i < digitos ){

        cout <<"["<<i+1<<"]: ";
        cin >> arr_orig.at(i);
        arr_invert.at(i) = arr_orig.at(i);
        numero = numero*10 + arr_orig.at(i);
        cifras++;
        i++;
        //cout <<"Ingrese los dígitos del número para determinar si es palíndromo, (ingrese una letra para terminar) "<<endl<<endl;
    }

    cin.sync();

    cout <<endl;
    Invertir_Array(arr_invert, cifras); //se procede a invertir el otro array que tiene los mismos elementos que el original

    bool sonPalindromos = false;
    int contador = 0;

    while(contador < cifras){
        if( arr_orig.at(contador) == arr_invert.at(contador) ){
            sonPalindromos = true;
        }else{
            sonPalindromos = false;
            break;
        }

        contador++;
    }


    if(sonPalindromos){
        cout <<"El n"<<char(163)<<"mero: "<<numero <<" es pal"<<char(161)<<"ndromo"<<endl;
    }else{
        cout <<"EL n"<<char(163)<<"mero ingresado no es pal"<<char(161)<<"ndromo"<<endl<<endl;
    }
}//FIN DE LA FUNCION PALÍNDROMO

void Invertir_Array(array<int, 20>& arr, int cifras ){
    int aux = 0, j = cifras;

    for(int i = 0; i < cifras; i++){
        j--; //j empieza con la ultima posicion del array
        if(j > i){
            aux = arr.at(i);
            arr.at(i) = arr.at(j);
            arr.at(j) = aux;
        }
    }


}//fin de la funcion invertir_Array



void Elim_duplicados(){
    array<int, 20> arr1 = {};
    array<int, 20> arr_aux = {};
    bool seRepite = false;
    int contador = 0;
    cout <<"Ingrese los valores del arreglo"<<endl;
    for(int i = 0; i < 20; i++){
        cin >> arr1.at(i);

        while(arr1.at(i) < 10||arr1.at(i) > 100){
            cout <<"Int"<<char(130)<<"ntelo de nuevo"<<endl;
            cin >> arr1.at(i);
            cout <<endl;
        }


        seRepite = false;
        for(int j = 0; j < 20 && seRepite == false ; j++){
            if( arr1.at(i) == arr1.at(j) && (i != j ) ){
                cout <<"Ingrese otro valor: ";
                cin >> arr1.at(i);

                while(arr1.at(i) < 10||arr1.at(i) > 100){
                    cout <<"Int"<<char(130)<<"ntelo de nuevo"<<endl;
                    cin >> arr1.at(i);
                    cout <<endl;
                }
                seRepite = true;
            }

        }


        if(seRepite == false){
            arr_aux.at(contador) = arr1.at(i);//este array solo almacena los valores únicos
            contador++;
        }


    //cout <<"contador    "<<contador<<endl;
    }//fin del for exterior
    cout <<"los "<<char(163)<<"nicos valores ingresados son"<<endl;
    for(int i = 0; i< contador; i++){
        cout <<"-"<<arr_aux.at(i)<<endl;
    }

}//FIN DE LA FUNCION ELIM_DUPLICADOS



void Suma_Dados(array <int, 7>& dado1, array <int, 7>& dado2){

    default_random_engine motor_generacion( static_cast<unsigned int>( time(0) ) );
    uniform_int_distribution<unsigned int > entero_Aleatorio(1,6);

    for(int i = 1; i <= 36000; i++ ){
        dado1.at( entero_Aleatorio(motor_generacion) ) = dado1.at( entero_Aleatorio(motor_generacion) ) + 1;
        dado2.at( entero_Aleatorio(motor_generacion) ) = dado2.at( entero_Aleatorio(motor_generacion) ) + 1;
    }


    cout <<" CARA \t\t FRECUENCIA"<<endl;
    for(int i = 1; i <= 6; i++){
        cout <<" "<<i<<" \t\t "<<dado1.at(i) + dado2.at(i) <<endl;
    }

}//FIN DE LA FUNCIÓN SUMA DADOS



