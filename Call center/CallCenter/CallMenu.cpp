 #include "CallMenu.h"
CallMenu::CallMenu(CallList* l): ListRefer(l){
	mainMenu();
}
void CallMenu::gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void CallMenu::frame(){
    for (int i = 0; i < 72; i++) {
        gotoxy(2 + i, 4); cout << "_";
        gotoxy(2 + i, 20); cout << "_";
    }
    for (int i = 0; i < 16; i++)
    {
        gotoxy(4, i + 5); cout << "|";
        gotoxy(73, i + 5); cout << "|";
        gotoxy(2, i + 5); cout << "|";
    }
}
void CallMenu::enterToContinue(){
   cout<<"Presione enter para continuar ";
   getch();
}
void CallMenu::mainMenu() {
    int opc;
	do
	{
		system("cls");
        frame();
		gotoxy(10,6);cout<<".: CALL CENTER Menu de Llamadas :."<<endl;
		gotoxy(11,7);cout<<"1. Registrar una llamada."<<endl;
		gotoxy(11, 8); cout << "2. Modificar Duracion de la llamada" << endl;
		gotoxy(11, 9); cout << "3. Eliminar llamada" << endl;
		gotoxy(11, 10);cout << "4. Eliminar todas las llamadas" << endl;
		gotoxy(11, 11); cout << "5. Mostrar llamadas registradas" << endl;
		gotoxy(11, 12); cout << "6. Buscar una llamada" << endl;
		gotoxy(11, 13); cout << "7. Salir" << endl;
		gotoxy(11, 14); cin >> opc;
		switch (opc)
		{
		case 1:
			pushCall();
			break;
		case 2:
			modifyCall();
			break;
		case 3:
			popCall();
			break;
		case 4:
			deleteAll();
			break;
		case 5:
			showCalls();
			break;
		case 6:
			findCall();
			break;
        case 7:
            gotoxy(11, 16); enterToContinue();
            break;
        default:
            gotoxy(11, 15); cout << "Opcion no valida" << endl;
            gotoxy(11, 16); enterToContinue();
            break;
		}
	} while (opc!=7);
	
}
void CallMenu::pushCall(){
	string myStr;
	Call myCall;
	Hour myHour;
    Name myName;
    int id;
    bool band;
    system("cls");
    frame();
    gotoxy(10, 6); cout<<"Registrar llamada"<<endl<<endl;
    do
    {
        srand(time(nullptr));
        id = 1 + rand() % (1000);
        if ((ListRefer->findCode(id)) == false)
        {
            break;
        }
    } while (id != 0);
    gotoxy(10, 7); cout<<"El Id de la nueva llamada es:"<<id<<endl;
    myCall.setId(id);
    cin.ignore();
    gotoxy(10, 8); cout<<"Ingrese el nombre y apellido del cliente:"<<endl;
    gotoxy(10,9); getline(cin, myStr, ' ');
    myName.setFirst(myStr);
    getline(cin, myStr);
    myName.setLast(myStr);
    myCall.setClient(myName);
    do{
        band = false;
        try {
            gotoxy(10,10);cout << "Ingrese la duracion de la llamada (HH:MM): " << endl;
            gotoxy(10,11);getline(cin, myStr, ':');
            myHour.setHour(stoi(myStr));
            getline(cin, myStr);
            myHour.setMin(stoi(myStr));
        }  catch (invalid_argument ex) {
            band = true;
            gotoxy(10,12);cout<<"La duracion ingresada no es valida intentalo de nuevo:"<<endl;
            gotoxy(10,13);enterToContinue();
            myHour.setHour(00);
            myHour.setMin(00);
            system("cls");
            frame();
        }
    }while(band);
    myCall.setDuration(myHour);
    do{
        try {
            gotoxy(10,12);cout << "Ingrese la hora en la que se hizo la llamada (HH:MM): " << endl;
            gotoxy(10,13);getline(cin, myStr, ':');
            myHour.setHour(stoi(myStr));
            getline(cin, myStr);
            myHour.setMin(stoi(myStr));
        }  catch (invalid_argument ex) {
            band = true;
            gotoxy(10,12);cout<<"La Hora ingresada no es valida intentalo de nuevo:"<<endl;
            gotoxy(10,13);enterToContinue();
            myHour.setHour(00);
            myHour.setMin(00);
            system("cls");
            frame();
        }
    }while(band);
    myCall.setHour(myHour);
    try
    {
        ListRefer->pushcallordered(myCall);
    }
    catch (ListException ex)
    {
        gotoxy(10,16);cout << "Ha ocurrido un problema al registrar una llamada" << endl;
        gotoxy(10,17);cout << "El sistema ha reportado: " << ex.what() << endl;
        gotoxy(10,18);cout << "Si esto ocurre constantemente llame al servicio al cliente" << endl;
        return;
    }
	gotoxy(10,16);cout << "La llamada ha sido registrada" << endl;
    gotoxy(10,17);enterToContinue();

}
void CallMenu::modifyCall() {
	int id;
	Call myCall;
	CallNode* pos;
	Hour myHour;
	string myStr;
	system("cls");
    frame();
	gotoxy(10, 7);cout << ".:Modificar llamada:." << endl;
	gotoxy(10, 8);cout << "Ingrese el Id de la llamada a modificar:" << endl;
	gotoxy(10, 9);cin >> id;
	myCall.setId(id);
	if (ListRefer->findCode(id)){
		pos = ListRefer->findCall(myCall);
		gotoxy(10, 10);cout << "Ingrese la duracion de la llamada (HH:MM): " << endl;
		gotoxy(10, 11);getline(cin, myStr, ':');
		myHour.setHour(stoi(myStr));
		getline(cin, myStr);
		myHour.setMin(stoi(myStr));
		pos->getData().setDuration(myHour);
        gotoxy(10, 14);cout<< "Llamada actualizada" << endl;
        gotoxy(10, 15);cout << pos->getData().toString();
        gotoxy(10, 16);enterToContinue();
	}
	else {
		gotoxy(10, 10);cout << "El id ingresado no pertenece a ninguna llamada" << endl;
        gotoxy(10,11);enterToContinue();
	}
	
}
void CallMenu::popCall() {
	int id;
	Call myCall;
	CallNode* pos;
	system("cls");
	if (ListRefer->empty()) {
        frame();
		gotoxy(10, 10);cout << "No hay llamadas registradas aun" << endl;
        gotoxy(10,11);enterToContinue();
	}
	else{
		cout << "\t \t .:Eliminar llamada:." << endl;
		cout << "Listado de llamadas:" << endl<<endl;
        cout << "Id |Cliente |Hora  |Duration" << endl;
		cout << ListRefer->toString();
		cout << "Ingrese el Id de la llamada a eliminar:" << endl;
		cin >> id;
		myCall.setId(id);
		pos = ListRefer->findCall(myCall);
		ListRefer->popCall(pos);
        cout<<endl<<endl;
        cout<<"Llamada eliminada correctamente"<<endl;
        enterToContinue();
	}
	
}
void CallMenu::deleteAll() {
	system("cls");
	if (ListRefer->empty())
	{
        frame();
		gotoxy(10, 10);cout << "No hay llamadas registradas aun para eliminar" << endl;
		gotoxy(10, 11);system("pause");
	}
	else{
        frame();
		gotoxy(10, 10);cout<<"Todas las llamadas han sido eliminadas."<<endl;
		ListRefer->popAllCalls();
        gotoxy(10, 11);enterToContinue();
	}
}
void CallMenu::showCalls() {
	system("cls");
	if (ListRefer->empty())
	{
        frame();
		gotoxy(10, 10);cout << "No hay llamadas registradas aun para eliminar" << endl;
        gotoxy(10, 11);enterToContinue();
	}
	else {
        cout << "\t\t.: Lista de llamadas:." << endl;
        cout << "Id |Cliente     |Hora de llamada  |Duracion       |" << endl;
        cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" <<endl;
		cout << ListRefer->toString();
        enterToContinue();
	}
}
void CallMenu::findCall() {
	int id;
	Call myCall;
	system("cls");
	if (ListRefer->empty())
	{
        frame();
		gotoxy(10, 10);cout << "No hay llamadas registradas aun para buscar" << endl;
        gotoxy(10, 11);enterToContinue();
	}
	else{
		cout << ".:Buscar llamada:." << endl;
		cout << "Para buscar una llamada en especifico ingresa el Id de tu llamada:" << endl;
		cin >> id;
		if (ListRefer->findCode(id)){
			myCall.setId(id);
			cout<<ListRefer->findACall(myCall).toString();
            enterToContinue();
		}
		else{
			cout<<"El id no coincide con ninguna llamada"<<endl;
            enterToContinue();
		}
		
	}
}
