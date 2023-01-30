#include "agentmenu.h"

using namespace std;

AgentMenu::AgentMenu(AgentList* l):ListRefer(l){
    splash();
}
void AgentMenu::gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void AgentMenu::frame(){
    for (int i = 0; i < 76; i++) {
        gotoxy(2 + i, 4); cout << "_";
        gotoxy(2 + i, 24); cout << "_";
    }
    for (int i = 0; i < 20; i++)
    {
        gotoxy(4, i + 5); cout << "|";
        gotoxy(77, i + 5); cout << "|";
        gotoxy(2, i + 5); cout << "|";
    }
}
void AgentMenu::enterToContinue(){
    cout<<"Presione enter para continuar ";
    getchar();
}
void AgentMenu::splash(){
    cout<<" _______   __                                                    __        __           "<<endl;
    cout<<"/         /  |                                                  /  |      /  |          "<<endl;
    cout<<"$$$$$$$  |$$/   ______   _______   __     __  ______   _______  $$/   ____$$ |  ______  "<<endl;
    cout<<"$$ |__$$ |/  | /        /         /      /  |/        /         /  | /    $$ | /        "<<endl;
    cout<<"$$    $$< $$ |/$$$$$$  |$$$$$$$  |$$    /$$//$$$$$$  |$$$$$$$  |$$ |/$$$$$$$ |/$$$$$$  |"<<endl;
    cout<<"$$$$$$$  |$$ |$$    $$ |$$ |  $$ | $$  /$$/ $$    $$ |$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |"<<endl;
    cout<<"$$ |__$$ |$$ |$$$$$$$$/ $$ |  $$ |  $$ $$/  $$$$$$$$/ $$ |  $$ |$$ |$$  __$$ |$$  __$$ |"<<endl;
    cout<<"$$    $$/ $$ |$$       |$$ |  $$ |   $$$/   $$       |$$ |  $$ |$$ |$$    $$ |$$    $$/"<<endl;
    cout<<"$$$$$$$/  $$/  $$$$$$$/ $$/   $$/     $/     $$$$$$$/ $$/   $$/ $$/  $$$$$$$/  $$$$$$/ "<<endl;
    cout<<endl<<endl;;
    enterToContinue();
    mainMenu();
}
void AgentMenu::mainMenu(){
   char opc;
    do
    {
        system("cls");
        frame();
        gotoxy(10,6);cout<<".: Menu Pricipal :."<<endl;
        gotoxy(11,7);cout<<"1. Administrar Agentes"<<endl;
        gotoxy(11, 8); cout << "2. Administrar llamadas de un agente" << endl;
        gotoxy(11, 9); cout << "3. Administrar Almacenamiento" << endl;
        gotoxy(11, 10); cout << "4. Salir del sistema" << endl;
        gotoxy(11, 12);cout << "Seleccione una opcion:" << endl;
        gotoxy(11, 13); cin >> opc;
        cin.ignore();
        switch (opc)
        {
        case '1':
            agentMenu();
            break;
        case '2':
            admCalls();
            break;
        case '3':
            admAlmac();
            break;
        case '4':
            gotoxy(11, 17); cout << "Hasta la proxima, que tengas un buen dia.. :)" << endl;
            break;
        default:
            gotoxy(11, 18); cout << "Opcion no valida" << endl;
            gotoxy(11, 19); enterToContinue();
            break;
        }
    } while (opc!='4');
}

void AgentMenu::agentMenu(){
    char opc;
     do
     {
         system("cls");
         frame();
         gotoxy(10,6);cout<<".: Administrar Agentes :."<<endl;
         gotoxy(11,7);cout<<"1. Registrar Agente"<<endl;
         gotoxy(11, 8); cout << "2. Eliminar Agente" << endl;
         gotoxy(11, 9); cout << "3. Eliminar TODOS los agentes" << endl;
         gotoxy(11, 10);cout << "4. Mostrar Agentes" << endl;
         gotoxy(11, 11);cout << "5. Buscar Agente" << endl;
         gotoxy(11, 12);cout << "6. Modificar Agente" << endl;
         gotoxy(11, 13);cout << "7. Ordenar Agentes" << endl;
         gotoxy(11, 14);cout << "8. Salir" << endl;
         gotoxy(11, 16);cout << "Seleccione una opcion:" << endl;
         gotoxy(11, 17); cin >> opc;
         cin.ignore();
         switch (opc)
         {
         case '1':
             pushAgent();
             break;
         case '2':
             popAgent();
             break;
         case '3':
             deleteAll();
             break;
         case '4':
             showAgents();
             break;
         case '5':
             findAgent();
             break;
         case '6':
             modifyAgent();
             break;
         case '7':
             sortAgents();
             break;
         case '8':
             gotoxy(11, 17); cout << "Hasta la proxima, que tengas un buen dia.. :)" << endl;
             break;
         default:
             gotoxy(11, 18); cout << "Opcion no valida" << endl;
             gotoxy(11, 19); enterToContinue();
             break;
         }
     } while (opc!='8');
}

void AgentMenu::admCalls(){
    string myStr;
    Name myName;
    Agent myAgent;
    AgentNode* pos;
    if (ListRefer->isEmpty())
    {
        system("cls");
        frame();
        gotoxy(10, 10);cout << "No hay agentes registrados para modificar" << endl;
        gotoxy(10, 11); enterToContinue();
        return;
    }
    else{
        system("cls");
        cout<<".: Administrar llamadas :."<<endl<<endl;
        cout<<ListRefer->toString(false);
        cout<<"Ingrese el codigo del Agente"<<endl;
        getline(cin, myStr);
        myAgent.setCode(myStr);

        pos=ListRefer->findata(myAgent);
        if(pos!=nullptr){
            new CallMenu(&pos->getDataPtr().getCallList());
        }
        else{
            cout<<"|~-~-~-~-~-~-~-~-~-~-~-|\n"<<endl;
            cout<<"| Agente NO encontrado |"<<endl;
            cout<<"|~-~-~-~-~-~-~-~-~-~-~-|\n"<<endl;
        }
    }
}

void AgentMenu::pushAgent(){
    Agent myAgent;
    AgentNode* pos;
    string myStr="1234";
    Name myName;
    Hour myHour;
    bool band;
    char op;
    do{
        system("cls");
        frame();
        gotoxy(10, 5); cout<<".: Registrar Agente :."<<endl<<endl;
        gotoxy(10, 6); cout<<"Ingrese el codigo del nuevo Agente:"<<endl;
        gotoxy(10, 7);getline(cin, myStr);
        myAgent.setCode(myStr);
        pos=ListRefer->findata(myAgent);
        if(pos!=nullptr){
            gotoxy(8, 8); cout<<"El codigo ingresado ya esta registrado, intentalo de nuevo"<<endl;
            gotoxy(8, 9);enterToContinue();
        }
    }while(pos!=nullptr);

    gotoxy(10, 8); cout<<"Ingrese el nombre y apellido del Agente"<<endl;
    gotoxy(10,9); getline(cin, myStr, ' ');
    myName.setFirst(myStr);
    getline(cin, myStr);
    myName.setLast(myStr);
    myAgent.setNameAgent(myName);

    myAgent.setNameAgent(myName);

    gotoxy(10, 10); cout<<"Ingrese la extension del agente:"<<endl;
    gotoxy(10,11);getline(cin, myStr);

    myAgent.setExtension(stoi(myStr));

    do{
        band = false;
        try {
            gotoxy(10,12);cout << "Ingrese la hora de entrada (HH:MM): " << endl;
            gotoxy(10,13);getline(cin, myStr, ':');
            myHour.setHour(stoi(myStr));
            getline(cin, myStr);
            myHour.setMin(stoi(myStr));
        }  catch (invalid_argument ex) {
            band = true;
            gotoxy(10,14);cout<<"La hora ingresada no es valida intentalo de nuevo:"<<endl;
            gotoxy(10,15);enterToContinue();
            myHour.setHour(00);
            myHour.setMin(00);
            system("cls");
            frame();
        }
    }while(band);
    myAgent.setEntrada(myHour);

    do{
        band = false;
        try {
            gotoxy(10,14);cout << "Ingrese la hora de salida (HH:MM): " << endl;
            gotoxy(10,15);getline(cin, myStr, ':');
            myHour.setHour(stoi(myStr));
            getline(cin, myStr);
            myHour.setMin(stoi(myStr));
        }  catch (invalid_argument ex) {
            band = true;
            gotoxy(10,16);cout<<"La hora ingresada no es valida intentalo de nuevo:"<<endl;
            gotoxy(10,17);enterToContinue();
            myHour.setHour(00);
            myHour.setMin(00);
            system("cls");
            frame();
        }
    }while(band);
    myAgent.setSalida(myHour);

    gotoxy(10,16); cout<<"Ingrese la especialidad del agente:"<<endl;
    gotoxy(10,17);getline(cin, myStr);

    myAgent.setEspecialidad(myStr);

    do{
        band = false;
        try {
            gotoxy(10,18);cout << "Ingrese la horas extras trabajadas por el agente (HH:MM): " << endl;
            gotoxy(10,19);getline(cin, myStr, ':');
            myHour.setHour(stoi(myStr));
            getline(cin, myStr);
            myHour.setMin(stoi(myStr));
        }  catch (invalid_argument ex) {
            band = true;
            gotoxy(10,20);cout<<"La hora ingresada no es valida intentalo de nuevo:"<<endl;
            gotoxy(10,21);enterToContinue();
            myHour.setHour(00);
            myHour.setMin(00);
            system("cls");
            frame();
        }
    }while(band);
    myAgent.setHrsExtra(myHour);
    do{
        system("cls");
        frame();
        gotoxy(10, 6);cout<<"Desea agregar llamadas a la lista del nuevo agente? (S/N)";
        gotoxy(10, 7);cin>>op; cin.ignore();
        op= toupper(op);
    }while(op != 'S' and op != 'N');

    if(op=='S'){
        new CallMenu(&myAgent.getCallList());
        system("cls");
        frame();
    }
    try{
        ListRefer->insertData(ListRefer->getLastPos(),myAgent);
    }
    catch (ListException ex){
        gotoxy(10,10);cout << "Ha ocurrido un problema al registrar un Agente" << endl;
        gotoxy(10,11);cout << "El sistema ha reportado: " << ex.what() << endl;
        gotoxy(10,12);cout << "Si esto ocurre constantemente llame al servicio al cliente" << endl;
        return;
    }
    gotoxy(10,10);cout << "El Agente ha sido registrada" << endl;
    gotoxy(10,11);enterToContinue();

}
void AgentMenu::modifyAgent(){
    Hour myHour;
    bool band;
    string myStr;
    Name myName;
    Agent myAgent;
    AgentNode* pos, *posc;
    char opc;
    system("cls");
    if (ListRefer->isEmpty())
    {
        frame();
        gotoxy(10, 10);cout << "No hay agentes registrados para modificar" << endl;
        gotoxy(10, 11); enterToContinue();
        return;
    }
    else{
        system("cls");
        frame();
        gotoxy(11,7);cout<<" .: Modificar Agente :."<<endl;
        gotoxy(11,8);cout<<"Ingrese el nombre y apellido del Agente"<<endl;
        gotoxy(11,9);getline(cin, myStr, ' ');
        myName.setFirst(myStr);
        getline(cin, myStr);
        myName.setLast(myStr);
        myAgent.setNameAgent(myName);

        pos=ListRefer->findAgent(myAgent);

        if(pos!=nullptr){
            do
            {
                system("cls");
                frame();
                gotoxy(10,6);cout<<".: Selecciona la caracteristica a modificar :."<<endl;
                gotoxy(11,7);cout<<"1. Codigo"<<endl;
                gotoxy(11, 8); cout << "2. Nombre" << endl;
                gotoxy(11, 9); cout << "3. Extension" << endl;
                gotoxy(11, 10);cout << "4. Hora de entrada" << endl;
                gotoxy(11, 11);cout << "5. Hora de salida" << endl;
                gotoxy(11, 12);cout << "6. Especialida" << endl;
                gotoxy(11, 13);cout << "7. Horas Extra" << endl;
                gotoxy(11, 14);cout << "8. Salir" << endl;
                gotoxy(11, 16); cin >> opc; cin.ignore();
                switch (opc)
                {
                case '1':
                    do{
                        system("cls");
                        frame();
                        gotoxy(10, 5); cout<<".: Modificar Codigo :."<<endl<<endl;
                        gotoxy(10, 6); cout<<"Ingrese el nuevo codigo del agente:"<<endl;
                        gotoxy(10, 7);getline(cin, myStr);
                        myAgent.setCode(myStr);
                        posc=ListRefer->findata(myAgent);
                        if(posc!=nullptr){
                            gotoxy(8, 8); cout<<"El codigo ingresado ya esta registrado, intentalo de nuevo"<<endl;
                            gotoxy(8, 9);enterToContinue();
                        }
                    }while(posc!=nullptr);

                    pos->getData()->setCode(myStr);

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();
                    break;
                case '2':
                    system("cls");
                    frame();
                    gotoxy(10, 5); cout<<".: Modificar Nombre :."<<endl<<endl;
                    gotoxy(10, 6); cout<<"Ingrese el nuevo nombre y apellido del Agente"<<endl;
                    gotoxy(10,7); getline(cin, myStr, ' ');
                    myName.setFirst(myStr);
                    getline(cin, myStr);
                    myName.setLast(myStr);

                    pos->getData()->setNameAgent(myName);

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();

                    break;
                case '3':
                    system("cls");
                    frame();
                    gotoxy(10, 5); cout<<".: Modificar Extension :."<<endl<<endl;
                    gotoxy(10, 6); cout<<"Ingrese la nueva extension del agente:"<<endl;
                    gotoxy(10,7);getline(cin, myStr);
                    myAgent.setExtension(stoi(myStr));

                    pos->getData()->setExtension(stoi(myStr));

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();
                    break;
                case '4':
                    system("cls");
                    frame();
                    gotoxy(10, 5); cout<<".: Modificar Hora de entrada :."<<endl<<endl;
                    do{
                        band = false;
                        try {
                            gotoxy(10,6);cout << "Ingrese la nueva hora de entrada (HH:MM): " << endl;
                            gotoxy(10,7);getline(cin, myStr, ':');
                            myHour.setHour(stoi(myStr));
                            getline(cin, myStr);
                            myHour.setMin(stoi(myStr));
                        }  catch (invalid_argument ex) {
                            band = true;
                            gotoxy(10,8);cout<<"La hora ingresada no es valida intentalo de nuevo:"<<endl;
                            gotoxy(10,9);enterToContinue();
                            myHour.setHour(00);
                            myHour.setMin(00);
                            system("cls");
                            frame();
                        }
                    }while(band);

                    pos->getData()->setEntrada(myHour);

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();
                    break;
                case '5':
                    system("cls");
                    frame();
                    gotoxy(10, 5); cout<<".: Modificar Hora de salida :."<<endl<<endl;
                    do{
                        band = false;
                        try {
                            gotoxy(10,6);cout << "Ingrese la nueva hora de salida (HH:MM): " << endl;
                            gotoxy(10,7);getline(cin, myStr, ':');
                            myHour.setHour(stoi(myStr));
                            getline(cin, myStr);
                            myHour.setMin(stoi(myStr));
                        }  catch (invalid_argument ex) {
                            band = true;
                            gotoxy(10,8);cout<<"La hora ingresada no es valida intentalo de nuevo:"<<endl;
                            gotoxy(10,9);enterToContinue();
                            myHour.setHour(00);
                            myHour.setMin(00);
                            system("cls");
                            frame();
                        }
                    }while(band);

                    pos->getData()->setSalida(myHour);

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();

                    break;
                case '6':
                    system("cls");
                    frame();
                    gotoxy(10, 5); cout<<".: Modificar especialidad :."<<endl<<endl;
                    gotoxy(10,6); cout<<"Ingrese la nueva especialidad del agente:"<<endl;
                    gotoxy(10,7);getline(cin, myStr);

                    pos->getData()->setEspecialidad(myStr);

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();

                    break;
                case '7':
                    do{
                        band = false;
                        try {
                            gotoxy(10,5);cout << "Ingrese la horas extras trabajadas por el agente (HH:MM): " << endl;
                            gotoxy(10,6);getline(cin, myStr, ':');
                            myHour.setHour(stoi(myStr));
                            getline(cin, myStr);
                            myHour.setMin(stoi(myStr));
                        }  catch (invalid_argument ex) {
                            band = true;
                            gotoxy(10,7);cout<<"La hora ingresada no es valida intentalo de nuevo:"<<endl;
                            gotoxy(10,8);enterToContinue();
                            myHour.setHour(00);
                            myHour.setMin(00);
                            system("cls");
                            frame();
                        }
                    }while(band);

                    pos->getData()->setHrsExtra(myHour);

                    gotoxy(10,7);cout <<"Agente actualizado correctamente..";
                    gotoxy(10,8);enterToContinue();
                    break;
                case '8':

                    break;
                default:
                    gotoxy(11, 18); cout << "Opcion no valida" << endl;
                    gotoxy(11, 19); enterToContinue();
                    break;
                }
            } while (opc!='8');
        }
        else{
            gotoxy(11,10);cout << "Agente No encontrado" << endl;
        }
        enterToContinue();
    };
}
void AgentMenu::popAgent(){
    string myStr;
    Name myName;
    Agent myAgent;
    AgentNode* pos;
    system("cls");
    if (ListRefer->isEmpty())
    {
        frame();
        gotoxy(10, 10);cout << "No hay agentes registrados para eliminar" << endl;
        gotoxy(10, 11); enterToContinue();
        return;
    }
    else{
        cout<<" .: Eliminar Agente :."<<endl;
        cout << "Code|Nombre\t|Extension\t|Entrada\t|Salida\t|Especialidad\t|HrsExtra" << endl;
        cout<<ListRefer->toString(false)<< endl;
        cout<<"Ingrese el nombre y apellido del Agente"<<endl;

        getline(cin, myStr, ' ');
        myName.setFirst(myStr);
        getline(cin, myStr);
        myName.setLast(myStr);
        myAgent.setNameAgent(myName);

        pos=ListRefer->findAgent(myAgent);

        if(pos!=nullptr){
            ListRefer->deleteData(pos);
            cout << "Agente eliminado correctamente"<< endl;
        }
        else{
            cout << "Agente No encontrado" << endl;
        }
        enterToContinue();
    }
}
void AgentMenu::deleteAll(){
    char op;
    system("cls");
    frame();
    if (ListRefer->isEmpty())
    {
        frame();
        gotoxy(10, 10);cout << "No hay agentes registrados para eliminar" << endl;
        gotoxy(10, 11); enterToContinue();
        return;
    }
    else{
        do{
            system("cls");
            frame();
            gotoxy(8, 10);cout << "Estas seguro que deseas eliminar todo los agentes registrados? (S/N)" << endl;
            gotoxy(10, 11);cin>>op; cin.ignore();
            op= toupper(op);
        }while(op != 'S' and op != 'N');
    }
    if(op=='S'){
        ListRefer->deleteAll();
        gotoxy(10, 12);cout << "Todos los agentes fueron eliminados..." << endl;
        gotoxy(10, 13); enterToContinue();
    }
}
void AgentMenu::showAgents(){
    char opc;
    system("cls");
    if (ListRefer->isEmpty())
    {
        frame();
        gotoxy(10, 10);cout << "No hay Agentes registrados aun para mostrar" << endl;
        gotoxy(10, 11); enterToContinue();
    }
    else {
        do{
            system("cls");
            frame();
            gotoxy(10, 6);cout<<"¿Desea mostrar la lista de llamadas del agente? (S/N)";
            gotoxy(10, 7);cin>>opc; cin.ignore();
            opc= toupper(opc);
        }while(opc!='S' && opc!='N');
        system("cls");
        cout << "\t\t.:Listado de Agentes:." << endl;
        cout << "Code|Nombre\t\t|Exten.\t|Entrada|Salida\t|Especialidad\t|HrsExtra" << endl;
        if(opc=='S'){
            cout <<ListRefer->toString(true);
        }
        else{
            cout <<ListRefer->toString(false);
        }

        enterToContinue();
    }
}
void AgentMenu::findAgent(){
    string myStr;
    Name myName;
    Agent myAgent;
    AgentNode* pos;
    char opc;
    system("cls");
    if (ListRefer->isEmpty())
    {
        frame();
        gotoxy(10, 10);cout << "No hay agentes registrados para buscar" << endl;
        gotoxy(10, 11); enterToContinue();
        return;
    }
    else{
        cout<<" .: Buscar Agente :."<<endl;
        cout<<"Ingrese el nombre y apellido del Agente"<<endl;
        getline(cin, myStr, ' ');
        myName.setFirst(myStr);
        getline(cin, myStr);
        myName.setLast(myStr);
        myAgent.setNameAgent(myName);

        pos=ListRefer->findAgent(myAgent);

        if(pos!=nullptr){
            if(pos->getDataPtr().getCallList().empty()){
                cout<<ListRefer->retrieve(pos).toString(false)<<endl;
                cout<<"|~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-|\n"<<endl;
                cout<<"| El agente no tiene llamadas registradas |"<<endl;
                cout<<"|~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-|\n"<<endl;
            }
            else{
                do{
                    cout<<"Desea mostrar la lista de llamadas del agente? (S/N)"<<endl;
                    cin>>opc; cin.ignore();
                    opc= toupper(opc);
                }while(opc!='S' && opc!='N');

                if(opc=='S'){
                    cout<<ListRefer->retrieve(pos).toString(true)<<endl;
                }
                else{
                    cout<<ListRefer->retrieve(pos).toString(false)<<endl;
                }
            }
        }
        else{
            cout<<"|~-~-~-~-~-~-~-~-~-~-~-|\n"<<endl;
            cout<<"| Agente NO encontrado |"<<endl;
            cout<<"|~-~-~-~-~-~-~-~-~-~-~-|\n"<<endl;
        }
        enterToContinue();
    }
}
void AgentMenu::sortAgents(){
    system("cls");
    frame();
    char opc;
    gotoxy(10,6);cout<<".: Ordenar Agentes :."<<endl;
    gotoxy(11,7);cout<<"1. Ordenar por nombre"<<endl;
    gotoxy(11, 8); cout << "2. Ordenar por especialidad" << endl;
    gotoxy(11, 15); cin >> opc;
    cin.ignore();
    switch (opc)
    {
    case '1':
        ListRefer->sortByName();
        gotoxy(11, 18); cout << "Los agentes han sido ordenados por nombre" << endl;
        gotoxy(11, 19); enterToContinue();
        break;
    case '2':
        ListRefer->sortBySpeciality();
        gotoxy(11, 18); cout << "Los agentes han sido ordenados por especialidad" << endl;
        gotoxy(11, 19); enterToContinue();
        break;
    default:
        gotoxy(11, 18); cout << "Opcion no valida" << endl;
        gotoxy(11, 19); enterToContinue();
        break;
    }
}

void AgentMenu::admAlmac(){
    char opc;
     do
     {
         system("cls");
         frame();
         gotoxy(10,6);cout<<".: Administrar Almacenamiento :."<<endl;
         gotoxy(11,7);cout<<"1. Escribir al disco"<<endl;
         gotoxy(11, 8); cout << "2. Leer de el disco" << endl;
         gotoxy(11, 9);cout << "3. Salir" << endl;
         gotoxy(11, 10); cin >> opc;
         cin.ignore();
         switch (opc)
         {
         case '1':
             writeToDisk();
             break;
         case '2':
             readFromDisk();
             break;
         case '3':
             gotoxy(11, 17); cout << "Hasta la proxima, que tengas un buen dia.. :)" << endl;
             break;
         default:
             gotoxy(11, 18); cout << "Opcion no valida" << endl;
             gotoxy(11, 19); enterToContinue();
             break;
         }
     } while (opc!='3');
}

void AgentMenu::writeToDisk(){
    system("cls");
    frame();
    gotoxy(10,6);cout<<".: Escribir informacion al disco :."<<endl;
    gotoxy(10,7);cout<<"Escribiendo informacion...."<<endl;
    try{
        ListRefer->writeToDisk("Agents.List");
    }
    catch(ListException ex){
        system("cls");
        cout<<"Ocurrio un problema:"<<endl;
        cout<<ex.what()<<endl;
        cout<<endl;
        enterToContinue();

        return;
    }

   gotoxy(10,8);cout << "Escritura hecha correctamente" << endl;
   gotoxy(10,9);enterToContinue();

}

void AgentMenu::readFromDisk(){
    system("cls");
    frame();
    gotoxy(10,6);cout<<".: Leer informacion al disco :."<<endl;
    gotoxy(10,7);cout<<"Leeyendo informacion...."<<endl;
    try{
        ListRefer->readFromDisk("Agents.List");
    }catch(ListException ex){
        system("cls");
        cout<<"Hubo un problema..."<<endl;
        cout<<ex.what()<<endl<<endl;

        enterToContinue();
        return;
    }
    gotoxy(10,8); cout<<"La lectura finalizo exitosamente"<<endl<<endl;
    gotoxy(10,9); enterToContinue();
}
