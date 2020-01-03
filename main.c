#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    ////////////////////////////////
    //                            //
    //    ESTE PROGRMAA TRABAJA   //
    //  ARCHIVOS EN FORMATO PGMA  //
    //          EN ASCII          //
    //                            //
    ////////////////////////////////


//  ARCHIVO FUNCIONES -> function.h  //

#include "E:\1º DAW\Programación c\imagenes\functions.h"

//  ARCHIVO FUNCIONES -> function.h  //

int main()
{
    char *nombre;
    char *nombre2[20];
    int opcion, menu, flag=1;

    //      PROPIEDADES STRUCT CONTENT    //


    cont content1;
    cont content2;
    cont content3;

    //      PROPIEDADES STRUCT CONTENT    //

    do
    {

        // LIMPIEZA DE PANTALLA //

        cleanout();

        // LIMPIEZA DE PANTALLA //

        printf("Selecciona la imagen que quieras abrir:\n");
        printf("1.- Lena\n");
        printf("2.- Marcie\n");
        printf("3.- Feep\n");
        printf("4.- p51D\n");
        printf("Para salir, introduzca 0.\n");
        scanf("%d",&opcion);
            switch(opcion)
            {

                case 0:

                    flag=0;
                    nombre="NULL";

                break;

                case 1:

                    nombre="lena.pgm";          // LENA.PGM //


                break;

                case 2:

                    nombre="marcie.pgm";        // MARCIE.PGM //

                break;

                case 3:

                    nombre="feep.ascii.pgm";    // FEEP.ASCII.PGM //

                break;


                case 4:

                    nombre="p51D.pgm";          // P51D.PGM //

                break;

                default:

                    flag=1;
                  //  nombre="NULL";

                break;
            }
            if(opcion!=0 && opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4)
            {

                cleanout();

                printf("\n\n - - - - - - Valor incorrecto. Compruebe la seleccion de imagen - - - - - - \n\n");

                system("pause");

                cleanout();

                exit(-1);

            }

            if(nombre == "NULL")
            {

                printf("Programa finalizado. Vuelva pronto\n");
                break;

            }
            else
            {
                abrir_pgm(&content1,nombre);
                int est = comprobar_pgm(&content1);

                if(est!=0)
                {
                    break;
                }
                else
                {
                    cargar_pgm(&content1);

                    int est1 = reservar(&content1);
                    if(est1!=0)
                    {
                        printf("\n\n - - - - - - Error en la función de lectura. Revisa la función leer - - - - - - \n\n");
                        system("pause");
                        exit(-1);
                    }
                    leer(&content1);



                }
            }

            do
            {
                printf("\n\n");

                printf("    ARCHIVO ABIERTO: %s",nombre);

                printf("\n\n\n");


                printf("         -------   MENU PRINCIPAL  ------- \n\n");
                printf("    | 1.- Leer codigo PGM (NO HACER PARA ARCHIVOS CON ALTA RESOLUCION)\n");                                          // FUNCIÓN:     lectura_pgm
                printf("    | 2.- Obtener filas,columnas o valor gris de %s\n", nombre);                // FUNCIÓN:     getFilas, Columns, Gris
                printf("    | 3.- Crear copia de imagen \n");                                           // FUNCIÓN:     escribe
                printf("    | 4.- Crear nueva imagen PGM P2\n");                                        // FUNCIÓN:     rellenar
                printf("    | 5.- Modificar un punto (X,Y) de %s\n", nombre);                           // FUNCIÓN:     putValor
                printf("    | 6.- Sumar imagen %s con otra imagen\n", nombre);                          // FUNCIÓN:     suma
                printf("    | 7.- Restar imagen %s con otra imagen\n", nombre);                         // FUNCIÓN:     resta
                printf("    | 8.- Rotar imagen %s\n", nombre);                                          // FUNCIÓN:     rotar
                printf("    | 9.- Recortar imagen %s\n", nombre);                                       // FUNCIÓN:     recortar
                printf("    | 10.- Ampliar lienzo (size) de %s\n", nombre);                             // FUNCIÓN:     ampliarLienzo
                printf("    | 11.- Realizar Zoom a %s\n", nombre);                                      // FUNCIÓN:     Zoom
                printf("    | 12.- Histograma (veces de repeticion grises) de %s\n", nombre);           // FUNCIÓN:     Histograma (Normal, CSV, XML)
                printf("    | 13.- Otras opciones \n");
                printf("    | 14.- Crear marco funcion \n");                                            // FUNCIÓN:     | Brillo |   |
                printf("    | 20.- Abrir %s\n", nombre);
                printf("    | 0.- Salir del fichero\n");
                printf("\n      -----------------------------------\n\n\n");
                printf("Opcion:");


                scanf("%d",&menu);


                    switch(menu)
                    {

                        case 0:

                            if(content1.valores == NULL)
                            {
                                printf("\nMemoria ya liberada\n");
                            }
                            else
                            {
                                liberar(&content1);
                            }



                            if(close(&content1)==0)
                            {

                                printf("\n\nFichero cerrado correctamente.\n \n");
                                system("pause");
                            }
                            else
                            {
                                printf("\n\nFichero no se ha cerrado correctamente. Compruebe la función close.\n\n");
                                system("pause");
                                exit(-1);
                            }


                        break;

                        //                  PARTE 1                  //



                        case 1:          // LEER CODIGO PGM

                            lectura_pgm(&content1,nombre);

                        break;

                        //                  PARTE 1                  //



                        //                  PARTE 2                  //


                        int opc1, flag2;

                        case 2:          // OBTENER FILAS Y COLUMNAS DEL FICHERO


                            cleanout();
                            printf("\nQue desea saber\n");
                            printf("1.- Total de filas \n");
                            printf("2.- Total de columnas \n");
                            printf("3.- Valor gris en (X,Y) \n");
                            scanf("%d",&opc1);

                            do
                            {
                                switch(opc1)
                                {
                                    case 1:

                                        getFilas(&content1);
                                        flag2=0;

                                    break;

                                    case 2:

                                        getColumns(&content1);
                                        flag2=0;

                                    break;

                                    case 3:

                                        getGris(&content1);
                                        flag2=0;

                                    break;

                                    default:

                                       flag2=1;

                                }
                            }
                            while(flag2!=0);



                        break;

                        //                  PARTE 2                  //



                        //                  PARTE 3                  //

                        case 3:


                            printf("\nIntroduzca el nombre de la imagen copia a realizar. Para cancelar, escriba 0.\n");
                            scanf("%s", &nombre2);
                            if(strcmp(nombre2,"0") != 0 )
                            {
                                strcat(nombre2,".pgm");
                                printf("%s",nombre2);
                                copiar(&content1,nombre2);
                            }


                        break;

                        //                  PARTE 3                  //



                        //                  PARTE 4                  //

                        case 4:

                            printf("Introduzca el nombre de la nueva imagen a crear. Para cancelar, escriba 0.\n");
                            scanf("%s", &nombre2);
                            if(strcmp(nombre2,"0") != 0 )
                            {
                                strcat(nombre2,".pgm");
                                printf("%s",nombre2);
                                rellenar(&content1,&content2,nombre2);
                            }


                        break;

                        //                  PARTE 4                  //



                        //                  PARTE 5                  //

                        case 5:

                                putValor(&content1,nombre);

                        break;

                        //                  PARTE 5                  //



                        //                  PARTE 6                  //


                        int est1;
                        char *nombre3[20];
                        cont content3;
                        case 6:

                            do
                            {
                                printf("Introduzca la imagen existente que desea sumar con %s (SIN EXTENSION)\n",nombre);
                                scanf("%s", &nombre2);

                                strcat(nombre2,".pgm");
                                if( strcmp(nombre,nombre2) == 0 )
                                {
                                    cleanout();
                                    printf("\n- - - - No puedes abrir dos veces una misma imagen. Pruebe a abrir otra - - - -\n");
                                    est1=1;
                                }
                                else
                                {
                                    if( abrir_pgm(&content2,nombre2) !=0 )
                                    {
                                        cleanout();
                                        printf("\n- - - - No existe la imagen introducida. Compruebe la existencia de imagen - - - -\n");
                                        est1=1;

            }
                                    else
                                    {
                                        if( comprobar_pgm(&content2) !=0 )
                                        {
                                            cleanout();
                                            printf("\n- - - - No se permite la operación con formatos binarios (P5) - - - -\n");
                                            est1=1;
                                        }
                                        else
                                        {

                                            est1=0;

                                        }
                                    }
                                }
                            }
                            while(est1!=0);

                            printf("\n\nIntroduzca el nombre de la imagen resultante. Si introduce un nombre existente, se sobrescribira:\n");

                            scanf("%s", &nombre3);
                            strcat(nombre3,".pgm");


                            suma(&content1,&content2,&content3,nombre3);

                        break;

                        //                  PARTE 6                  //



                        //                  PARTE 7                  //



                        case 7:

                            do
                            {
                                printf("Introduzca la imagen existente que desea restar con %s (SIN EXTENSION)\n",nombre);
                                scanf("%s", &nombre2);

                                strcat(nombre2,".pgm");
                                if( strcmp(nombre,nombre2) == 0 )
                                {
                                    cleanout();
                                    printf("\n- - - - No puedes abrir dos veces una misma imagen. Pruebe a abrir otra - - - -\n");
                                    est1=1;
                                }
                                else
                                {
                                    if( abrir_pgm(&content2,nombre2) !=0 )
                                    {
                                        cleanout();
                                        printf("\n- - - - No existe la imagen introducida. Compruebe la existencia de imagen - - - -\n");
                                        est1=1;
                                    }
                                    else
                                    {
                                        if( comprobar_pgm(&content2) !=0 )
                                        {
                                            cleanout();
                                            printf("\n- - - - No se permite la operación con formatos binarios (P5) - - - -\n");
                                            est1=1;
                                        }
                                        else
                                        {

                                            est1=0;

                                        }
                                    }
                                }
                            }
                            while(est1!=0);

                            printf("\n\nIntroduzca el nombre de la imagen resultante. Si introduce un nombre existente, se sobrescribira:\n");

                            scanf("%s", &nombre3);
                            strcat(nombre3,".pgm");


                            resta(&content1,&content2,&content3, nombre3);

                        break;

                        //                  PARTE 7                  //



                        //                  PARTE 8                  //

                        int rot,opc2;

                        case 8:


                            do
                            {

                                cleanout();
                                printf("Introduzca la opcion con los valores de rotación disponible\n");
                                printf("1.-     90\n");
                                printf("2.-     180\n");
                                printf("3.-     270\n");
                                printf("4.-   - 90\n");
                                printf("5.-   - 180\n");
                                printf("6.-   - 270\n");
                                scanf("%d",&opc2);

                            }
                            while(opc2<1 && opc2>6);

                            switch(opc2)
                            {

                                case 1:

                                        rot = 90;

                                break;

                                case 2:

                                        rot = 180;

                                break;

                                case 3:

                                        rot = 270;

                                break;

                                case 4:

                                        rot = -90;

                                break;

                                case 5:

                                        rot = -180;

                                break;

                                case 6:

                                        rot = -270;

                                break;

                            }

                            rotar(&content1, nombre, rot);

                        break;

                        //                  PARTE 8                  //



                        //                  PARTE 9                  //


                        int p1[2];
                        int p2[2];


                        case 9:

                            do
                            {


                                printf("Introduzca el primer punto de recorte (x1,y1) \n");
                                printf("(X, )\n");
                                scanf("%d",&p1[0]);
                                printf("(%d,Y)\n",p1[0]);
                                scanf("%d",&p1[1]);

                                printf("Introduzca el segundo punto de recorte (x2,y2) \n");
                                printf("(X, )\n");
                                scanf("%d",&p2[0]);
                                printf("\n(%d,Y)\n",p2[0]);
                                scanf("%d",&p2[1]);




                                if( ((p2[0])<(p1[0])) && ((p2[1])<(p1[1])) )
                                {

                                    cleanout();
                                    printf("\nNo se puede realizar el recorte si punto P2 es menor que P1\n");

                                }
                                else
                                {

                                    printf("\nPunto P1->(%d,%d)",p1[0],p1[1]);
                                    printf("\nPunto P2->(%d,%d)\n",p2[0],p2[1]);

                                }


                            }
                            while((p2[0])<(p1[0]));
                            recortar(&content1, &content2, nombre,p1,p2);   // CONTENT 2 PARA LA MODIFICACIÓN DE CONTENT 1 //

                        break;

                        //                  PARTE 9                  //


                        //                  PARTE 10                  //


                        int A;




                        case 10:

                            do
                            {
                                printf("\nIntroduzca el valor de ampliacion del lienzo. Debe ser mayor que 0\n");
                                scanf("%d",&A);
                                if(A<=0)
                                {
                                    cleanout();
                                    printf(" - - - - El valor de ampliación tiene que ser mayor que 0 - - - -");
                                }
                            }
                            while(A<=0);


                            ampliarLienzo(&content1,&content2,nombre,A);    // CONTENT 2 PARA LA MODIFICACIÓN DE CONTENT 1 //

                        break;

                        //                  PARTE 10                  //

                        //                  PARTE 11                  //

                        case 11:


                            zoom(&content1,&content2,nombre);               // CONTENT 2 PARA LA MODIFICACIÓN DE CONTENT 1 //

                        break;

                        //                  PARTE 11                  //

                        //                  PARTE 12                  //

                        int menu2;
                        case 12:

                            cleanout();
                            do
                            {
                                printf("Como desea obtener el histograma\n");
                                printf("\n\n");
                                printf("1.- Por pantalla\n");
                                printf("2.- Exportar a fichero CSV\n");
                                printf("3.- Exportar a fichero XML\n");
                                printf("0.- Atras\n");
                                printf("\n\n");
                                scanf("%d",&menu2);
                            }
                            while(menu2<0 && menu2>3);

                            switch(menu2)
                            {

                                case 0:

                                break;

                                case 1:

                                    histograma(&content1, nombre);

                                break;

                                case 2:

                                    histogramaCSV(&content1, nombre);

                                break;


                                case 3:

                                    histogramaXML(&content1, nombre);

                                break;


                            }



                        break;

                        //                  PARTE 13    || OTRAS OPCIONES                  //

                        int submenu;


                        case 13:


                            do
                            {
                                cleanout();

                                printf("\n");
                                printf("         -------   OTRAS OPCIONES  ------- \n");
                                printf("    | 1.- Ajustar brillo a la imagen PGM %s\n", nombre);                    // FUNCIÓN:     Brillo
                                printf("    | 2.- Obtener imagen simetrica respecto X o Y de %s\n", nombre);        // FUNCIÓN:     flipV y flipH
                                printf("    | 3.- Inverso o negativo de %s\n", nombre);                             // FUNCIÓN:     Invertir
                                printf("    | 4.- Umbral de %s\n", nombre);                                         // FUNCIÓN:     Umbral
                                printf("    | 5.- Umbral binario de %s\n", nombre);                                 // FUNCIÓN:     UmbralBinario
                                printf("    | 6.- Umbral de la Escala de Grises de %s\n", nombre);                  // FUNCIÓN:     UmbralGris
                                printf("    | 7.- Operacion de extension de %s\n", nombre);                         // FUNCIÓN:     extension
                                printf("    | 8.- Operacion de reduccion de %s\n", nombre);
                                printf("    | 9.- Resaltar bordes de %s\n", nombre);                         // FUNCIÓN:     reduccion
                                printf("    | 0.- Atras\n");
                                printf("      -----------------------------------\n\n\n");
                                printf("Opcion:");
                                scanf("%d",&submenu);

                                switch(submenu)
                                {

                                    case 0:



                                    break;

                                    int valorBrillo;

                                    case 1:

                                        do
                                        {
                                            printf("\nIntroduzca el tanto por cierto de brillo a aplicar:\n");
                                            scanf("%d",&valorBrillo);
                                            if(valorBrillo<-100 || valorBrillo>100)
                                            {
                                                cleanout();
                                                printf("\n- - - - Opcion incorrecta. Para un porcentaje, el valor debe ser entre -100 y 100\n - - - -\n");
                                            }
                                        }
                                        while(valorBrillo<-100 || valorBrillo>100);

                                        brillo(&content1,&content2, nombre, valorBrillo);


                                    break;

                                    int opc3;

                                    case 2:

                                        do
                                        {
                                            printf("\nCon que eje desea trabajar:\n");
                                            printf("\n1.- Imagen respecto al eje X\n");
                                            printf("\n2.- Imagen respecto al eje Y\n");
                                            scanf("%d",&opc3);
                                            if(opc3!=1 && opc3!=2)
                                            {
                                                cleanout();
                                                printf("\n- - - - Opcion incorrecta - - - -\n");
                                            }
                                        }
                                        while(opc3!=1 && opc3!=2);

                                        if(opc3==1)
                                        {
                                            flipV(&content1,&content2,nombre);
                                        }
                                        else
                                        {
                                            if(opc3==2)
                                            {
                                                flipH(&content1,&content2, nombre);
                                            }
                                        }

                                    break;

                                    case 3:

                                        invertir(&content1, &content2, nombre);

                                    break;

                                    case 4:

                                        umbral(&content1, &content2, nombre);

                                    break;

                                    case 5:

                                        umbralBinario(&content1, &content2, nombre);

                                    break;

                                    case 6:

                                        umbralGris(&content1, &content2, nombre);

                                    break;

                                    case 7:

                                        extension(&content1,&content2, nombre);

                                    break;

                                    case 8:

                                        reduccion(&content1, &content2, nombre);

                                    break;

                                    case 9:

                                        resaltarBordes(&content1, &content2, &content3,nombre);

                                    break;



                                }
                            }
                            while(submenu!=0);



                        break;

                        //                  PARTE 13    || OTRAS OPCIONES                  //

                        int grosor, gris;

                        case 14:

                            cleanout();
                            do
                            {
                                printf("Introduzca el grosor del marco que desea poner\n");
                                scanf("%d",&grosor);
                            }
                            while(grosor<0);

                            do
                            {
                                printf("\nQue valor gris desea poner para el marco\n");
                                scanf("%d",&gris);
                            }
                            while(gris<0 || gris>content1.grises);

                            crearMarco(&content1,&content2, grosor, gris, nombre);

                        break;

                        case 20:

                            printf("\nSe va a abrir dicho fichero por un programa asociado para su lectura\nCompruebe que programa va a ejecutar dicho fichero\n");
                            system("pause");
                            system("E:");                                            //   CAMBIAR POR LETRA UNIDAD DEL USB O RUTA DEL ARCHIVO IMAGEN   //

                            system("cd 1º DAW\Programación c\imagenes");
                            cleanout();
                            system(nombre);
                            cleanout();

                        break;




                        //                  PARTE 12                  //



                        //                  VALOR DEFECTO                  //

                        default:

                            cleanout();
                            printf("\n\n - - - - - - Opcion incorrecta. Vuelva a intentarlo  - - - - - - \n\n");


                        //                  VALOR DEFECTO                  //

                   }

            }
            while(menu!=0); //  CONTROLADO POR VALOR MENU   //



                        ///////////////////////////////
                        //  BANDERA DEL PROGRAMA     //
                        //  0 -> EXIT                //
                        //  1 -> VOLVER AL PRINCIPIO //
                        ///////////////////////////////



            if(flag!=0)
            {

                cleanout();

                do
                {

                    printf("------------------------------------");
                    printf("\n| 0.- Salir del programa           | \n");
                    printf("\n| 1.- Abrir otro fichero PGM       | \n");
                    printf("------------------------------------\n");
                    printf("\n\n");
                    printf("Opcion: ");
                    scanf("%d",&flag);

                    switch(flag)
                    {

                        case 0:

                            flag=0;

                        break;

                        case 1:

                            flag=1;

                        break;

                        default:

                            cleanout();
                            printf("\n\n");
                            printf(" - - - - Valor incorrecto. Compruebe la pasada e intentalo de nuevo - - - -");
                            printf("\n\n");

                        break;

                    }
                }
                while(flag!=0 && flag!=1);
            }
            else
            {

                break;

            }


    }
    while(flag!=0);


   // cleanout();


    return 0;





}

