//Taller "Los Dinosaurios"
#include<iostream>
#include<string.h>
#include<conio.h>
#include<locale.h>
using namespace std;

FILE*apArchivo;
FILE*pTemporal;

struct dtServicio
{
    int   dpii, ciclo;
    char  placa[30], nombre [30],modelo [30];

} rgServicio;

void guardarCliente()
{
    cout<<"Ingrese DPI sin espacios: ";
    cin>>rgServicio.dpii;
    cout<<"Ingrese Nombre: ";
    fflush(stdin);
    gets(rgServicio.nombre);
    cout<<"Ingrese Placa del Vehiculo: ";
    fflush(stdin);
    gets(rgServicio.placa);
    cout<<"Ingrese Modelo del Vehiculo: ";
    fflush(stdin);
    gets(rgServicio.modelo);

    cout<<"\n-- SERVICIOS PARA SU VEHICULO --";
    cout<<"\n1. Cambio de Aceite y Filtro.";
    cout<<"\n2. Ajuste de Frenos.";
    cout<<"\n3. Suspension.";
    cout<<"\n4. Servicio Completo .";
    cout<<"\nSeleccione opcion a realizar: ";
    cin>>rgServicio.ciclo;
    switch(rgServicio.ciclo)
    {
        case 1:
            cout<<"\nUsted eligio *Cambio de Aceite y Filtro*"<<endl;
            break;
        case 2:
            cout<<"\nUsted eligio *Ajuste de Frenos*"<<endl;
            break;
        case 3:
            cout<<"\nUsted eligio *Suspension*"<<endl;
            break;
        case 4:
            cout<<"\nUsted eligio *Servicio Completo*"<<endl;
            cout<<"El Servicio Completo incluye: Cambio de Aceite y Filtro, Ajuste de Frenos y Suspension"<<endl;
            break;
        default:
            cout<<"Lo sentimos el taller no cuenta aún con mas Servicios :("<<endl;

    }

    apArchivo = fopen("C:\\Archivos Taller\\Taller.txt","a+");
    fwrite(&rgServicio, sizeof(rgServicio), 1, apArchivo );
    fclose(apArchivo);

    cout<<"Cliente, Vehiculo y Servicio Guardado Exitosamente!!";
    getch(); //pausa
    cout<<endl;
}

void mostrarServicio()
{
    apArchivo = fopen("C:\\Archivos Taller\\Taller.txt","r+");

    while (fread(&rgServicio, sizeof(rgServicio), 1, apArchivo))
    {
        cout<<"\nDPI: "<<rgServicio.dpii;
        cout<<"\nNombre: "<<rgServicio.nombre;
        cout<<"\nPlaca: "<<rgServicio.placa;
        cout<<"\nModelo: "<<rgServicio.modelo;
        if (rgServicio.ciclo == 1){
            cout<<"\nServicio Realizado: "<<"Cambio de Aceite"<<endl;
        }
        else if (rgServicio.ciclo == 2){
            cout<<"\nServicio Realizado: "<<"Ajuste de Freno"<<endl;
        }
        else if (rgServicio.ciclo == 3){
            cout<<"\nServicio Realizado: "<<"Suspension"<<endl;
        }
        else if (rgServicio.ciclo == 4){
            cout<<"\nServicio Realizado: "<<"Servicio Completo"<<endl;
        }

    }
    fclose(apArchivo);
    getch(); //pausa
}

void editarServicio()
{
    int dpi;
    cout<<"Ingrese DPI sin espacios: ";
    cin>>dpi;

    apArchivo = fopen("C:\\Archivos Taller\\Taller.txt","r+");
    pTemporal = fopen("C:\\Archivos Taller\\Temporal.txt","a+");

    while (fread(&rgServicio, sizeof(rgServicio), 1, apArchivo ))
    {
        if(dpi == rgServicio.dpii)
        {
            cout<<"Ingrese un nuevo Servicio para su Vehiculo: ";
            cout<<"\n-- SERVICIOS PARA SU VEHICULO --";
            cout<<"\n1. Cambio de Aceite y Filtro.";
            cout<<"\n2. Ajuste de Frenos.";
            cout<<"\n3. Suspension.";
            cout<<"\n4. Servicio Completo .";
            cout<<"\nSeleccione opcion a realizar: ";
            cin>>rgServicio.ciclo;
            switch(rgServicio.ciclo)
            {
                case 1:
                    cout<<"\nUsted eligio *Cambio de Aceite y Filtro*"<<endl;
                    break;
                case 2:
                    cout<<"\nUsted eligio *Ajuste de Frenos*"<<endl;
                    break;
                case 3:
                    cout<<"\nUsted eligio *Suspension*"<<endl;
                    break;
                case 4:
                    cout<<"\nUsted eligio *Servicio Completo*"<<endl;
                    cout<<"El Servicio Completo incluye: Cambio de Aceite y Filtro, Ajuste de Frenos y Suspension"<<endl;
                    break;
                default:
                    cout<<"Lo sentimos el taller no cuenta aún con mas Servicios :("<<endl;

            }

            fwrite(&rgServicio, sizeof(rgServicio), 1, pTemporal );
        }
        else
        {
            fwrite(&rgServicio, sizeof(rgServicio), 1, pTemporal );
        }
    }

    fclose(apArchivo);
    fclose(pTemporal);

    remove("C:\\Archivos Taller\\Taller.txt");
    rename("C:\\Archivos Taller\\Temporal.txt", "C:\\Archivos Taller\\Taller.txt");

    cout<<"Servicio Editado!";
    getch();

}

void eliminarServicio()
{
    int dpi;
    cout<<"Ingrese DPI para Eliminar: ";
    cin>>dpi;

    apArchivo = fopen("C:\\Archivos Taller\\Taller.txt","r+");
    pTemporal = fopen("C:\\Archivos Taller\\Temporal.txt","a+");

    while (fread(&rgServicio, sizeof(rgServicio), 1, apArchivo ))
    {
        if(dpi == rgServicio.dpii)
        {
            //no copia el archivo Temporal
        }
        else
        {
            fwrite(&rgServicio, sizeof(rgServicio), 1, pTemporal );
        }
    }

    fclose(apArchivo);
    fclose(pTemporal);

    remove("C:\\Archivos Taller\\Taller.txt");
    rename("C:\\Archivos Taller\\Temporal.txt", "C:\\Archivos Taller\\Taller.txt");

    cout<<"Cliente Eliminado!";
    getch();
}

main (){
    int opc;
    do
    {
        system("cls");
        cout<<"\n                                  -- Taller *LOS DINOSAURIOS*  --";
        cout<<"\n                                       -- CONTROL DE TALLER --";
        cout<<"\n1. Registrar Clientes y Vehiculos.";
        cout<<"\n2. Mostrar Clientes y Vehiculos.";
        cout<<"\n3. Editar Servicio.";
        cout<<"\n4. Eliminar Cliente y Vehiculo.";
        cout<<"\n5. Salir.";
        cout<<"\nIngrese que opcion desea realizar: ";
        cin>>opc;

        switch(opc)
        {
            case 1:
                guardarCliente();
                break;
            case 2:
                mostrarServicio();
                break;
            case 3:
                editarServicio();
                break;
            case 4:
                eliminarServicio();
                break;
            case 5:
                cout<<"Gracias por utilizar este Programa :)";
                break;
            default:
                cout<<"Opcion Invalida";
        }
    } while (opc != 5 );
}