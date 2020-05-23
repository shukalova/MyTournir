#include <iostream>
#include "Participant.cpp"
#include "ParticipantRepository.cpp"
#include <fstream>
#include <locale.h>

enum TableSymbols {
	table_pipe = 186,
	table_x = 206, // ╩╠╦═╬
	table_L = 200,
	table_J = 188,
	table_r = 201,
	table_r_ = 187
};

void participantMenu();


int main()
{
	//setlocale(LC_ALL, "");
	participantMenu();
	return 0;
}

Participant* createParticipant(int index) {
	Participant* p = new Participant();
	p -> Id = index;
	//char* temp = new char[9]{ "TestName" };
	p->Name.Value = new char[9]{ "TestName" };
	p -> gender = Male;
	p -> Age = index + 15;

	//cin >> p->Name.Value;
	
	return p;
}

void showParticipants(vector<Participant*> participants) {

	printf("test \xA5 ");
	
	printf("╔═════╦═════════════╦═════════════╦════════", (char)table_r_,"\n");
	cout << (char)table_pipe << " Id  "<< (char)table_pipe <<  "Name" << (char)table_pipe << " Age " << (char)table_pipe << " Gender " << (char)table_pipe << endl;
	cout << "╠═════╬═════════════╬═════════════╬════════╣" << endl;
	for (int i = 0; i < participants.size(); i++) {
		cout << (char)table_pipe << participants[i]->Id << (char)table_pipe << participants[i] -> Name.Value << (char)table_pipe << participants[i] -> Age << (char)table_pipe << participants[i]->gender << endl;
	}
	cout << (char)table_L << "═════╩═════════════╩═════════════╩════════<<"  << endl;

}

void participantMenu() {
	ParticipantRepository pr;
	int pm = -1;
	while (pm != 0) {
		cout << "1.Add participant" << endl;
		cout << "2.Edit participant" << endl;
		cout << "3.Delete participant" << endl;
		cout << "4.Find by name" << endl;
		cout << "5.Show all participants" << endl;
		cout << "6.Save All" << endl;
		cout << "7.Load All" << endl;
		cout << "0.Exit" << endl;
		cin >> pm;
		system("cls");
		switch(pm) {
			case 1: {
				for (int i = 0; i < 5; i++) {
					pr.Add(createParticipant(i));
				}
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				break;
			}
			case 5: {
				showParticipants(pr.GetAll());
				cin.get();
				cin.get();
				system("cls");
				break;
			}
			case 6: {
				pr.SaveAll("test_save111.txt");
				break;
			}
			case 7: {
				pr.LoadAll("test_save111.txt");
				break;
			}

			case 0: {
				break;
			}
			default: break;
		}
	}
}

