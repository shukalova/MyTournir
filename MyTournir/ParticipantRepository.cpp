#include "Participant.cpp"
#include <vector>
#include<fstream>


using namespace std;

class ParticipantRepository {
private:
	vector<Participant*> list;
	ofstream file_writer;
	ifstream file_reader;
public:
	ParticipantRepository() {
	}

	void Add(Participant* item) {
		list.push_back(item);
	}

	void Edit(Participant* item) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->Id == item->Id) {
				list[i]->Name = item->Name;
				list[i]->gender = item ->gender;
				list[i]->Age = item->Age;
			}
		}
	}

	void Delete(int id) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->Id == id) {
				list.erase(list.begin() + i);
				break;
			}
		}
	}

	void SaveAll(const char* fileName) {
		file_writer.open(fileName, ios::out);
		for (int i = 0; i < list.size(); i++) {
			file_writer << list[i]->Name.Value << endl;
			file_writer << list[i]->Id << endl;
			file_writer << list[i]->Age << endl;
			file_writer << list[i]->gender << endl;
		}
		file_writer.close();
	}

	void LoadAll(const char* fileName) {
		char* bufferName = new char[50];
		int bufferGender;
		list.clear();
		file_reader.open(fileName, ios::in);
		Participant* p;
		while (!file_reader.eof()) {
			p = new Participant;
			  
			file_reader >> bufferName;
			const char* c = bufferName;
			p->Name.Value = c;
			//new char[7] {"loaded"};
				//p->Name.Value;
			// bufferName; //p -> Name.Value;
			//p->Name.Value = bufferName;//= //new char[strlen(bufferName)];
			//strcpy_s(p -> Name.Value, bufferName);
			file_reader >> p->Id;
			file_reader >> p->Age;
			file_reader >> bufferGender;
			p->gender = (Gender)bufferGender;
			list.push_back(p);
		}
		file_reader.close();
	}

	vector<Participant*> GetAll() {
		return list;
	}
};