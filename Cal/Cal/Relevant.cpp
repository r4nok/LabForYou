#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

class repositor
{
protected:
	string *library; // названи€ файлов
	int number_file;
public:

	void relevant();
	void to_change_library();
	float quantity_occurrences(char *abc, int number_file);
	repositor();
	~repositor();

};

class SmartRepositor : public repositor // дл€ работы в командной строке
{
protected:
	char instruction[30]; // команда пользовател€
	char library_pass[50]; // путь дл€ библиотеки
public:

	SmartRepositor() : repositor()
	{
		strcpy_s(instruction, 30, "help");
		strcpy_s(library_pass, 50, "Default library pass");
	}

	void read_instruction();
	void do_instruction();
	
	void help(); // показывает весь возможный список команд
	void change_library_pass(); // измен€ет путь к библиотеке с указанием нового имени файла - библиотеки
	void show_library_pass(); // показывает путь к библиотеке
	void show_lib(); // показывает содержимое библитеки
	void add_file(); // добавл€ет в библиотеку конкретный файл
	void del_file(); // удал€ет из библиотеки конкретный файл 
	void del_all(); // удал€ет все файлы из библиотеки
	void relev_all(); // считает релевантность дл€ всех файлов
	void relev_file(); // считает релевантность дл€ конкретного файла
	void change_file(); // измен€ет сожержимое файла
	void out();

	bool is_right(const char* str);
	void write_in_file();
};

void repositor::to_change_library()
{
	int n, count;
	string *time_mas;
	cout << "add : 1" << endl;
	cout << "delete all and add : 2" << endl;
	cin >> n;
	switch (n)
	{
	case 1:

		time_mas = new string[number_file];
		for (int i = 0; i < number_file; i++)
		{
			time_mas[i] = library[i];
		}

		delete library;

		number_file = number_file + 1;
		library = new string[number_file];
		for (int i = 0; i < number_file; i++)
		{
			library[i] = time_mas[i];
		}

		cout << "Input your file" << endl;
		cin >> library[number_file];
		delete time_mas;
		break;
	case 2:

		cout << "input count" << endl;
		cin >> number_file;
		if (library == NULL)
		{
			library = new string[number_file];
			for (int i = 0; i < number_file; i++)
			{
				cin >> library[i];
			}

		}
		else
		{
			delete library;
			library = new string[number_file];
			for (int i = 0; i < number_file; i++)
			{
				cin >> library[i];
			}
		}



		break;
	default:

		cout << "Eror" << endl;

		break;
	}

}

repositor::repositor() // ////////////// /////////////// конструктор
{
	int couner = 0, couner1 = 0;
	string str;
	ifstream read_library_file;
	read_library_file.open("library.txt");  // сохран€ет в библиотеку файлы

	if (!read_library_file.is_open())
	{

		cout << "Error file" << endl;
	}
	else
	{

		while (!read_library_file.eof())
		{
			str = "";
			getline(read_library_file, str);

			couner++;
		}

		library = new string[couner];
		read_library_file.seekg(0, ios::beg);
		while (!read_library_file.eof())
		{
			str = "";
			getline(read_library_file, str);

			library[couner1] = str;
			couner1++;
		}


	}

	read_library_file.close();
	number_file = couner;
}

repositor::~repositor()
{
	delete[]library;
}

void repositor::relevant()
{
	for (int i = 0; i < number_file; i++)
	{
		//cout << library[i];
	}
	int counter = 0, all_number_slov = 0;

	char *mystring = new char[100000];
	char *time_mass = new char[100000];
	cout << "Input yout text,two words,word" << endl;
	int rez = 0;
	cin.getline(mystring, 100000);
	

	char *arr = new char[100000];
	while (!mystring[counter] == '\0')
	{
		if (mystring[counter] == ' ' || mystring[counter] == '\n')
		{
			all_number_slov++;
		}

		counter++;
	}

	all_number_slov++;

	float *arr_with_chastota = new float[all_number_slov];
	float all_number_slov_with_chastota = 0;
	for (int i = 0; i < all_number_slov; i++)
	{
		arr_with_chastota[i] = 0;
	}


	int counter_for_gaps_for_counter_gaps = 0;
	int check_out = 0, counter1 = 0, counter2 = 0, counter_for_gaps = 0;

	char *string_for_function = new char[1000000];
	int n = 0;//умешитель
	int gap_skip = 1;
	int gap_skip1 = 0;

	char *string_for_file12 = new char[1000000000];

	for (int j = 0; j < this->number_file; j++) //number_file
	{
	
		counter = 0;
		/////////	
		ifstream read_library;			//*// сщитаем количество слов в файле

		read_library.open(library[j]);

		//cout << library[j] << endl;

		if (!read_library.is_open())
		{
			cout << "Error file" << endl;
		}
		else
		{
			char simvol;
			while (read_library.get(simvol))
			{
				string_for_file12[counter] = simvol;
				counter++;
			}
			string_for_file12[counter] = '\0';

		}

		counter = 0;
		while (string_for_file12[counter] != '\0') // сщитаем количество слов в файле
		{
			if (string_for_file12[counter] == ' ' || string_for_file12[counter] == '\n')
			{
				all_number_slov_with_chastota++;
			}

			counter++;
		}

		counter = 0;
		read_library.close();

		while (mystring[counter1] != '\0')
		{
			arr[counter1] = mystring[counter1];
			counter1++;

		}

		arr[counter1] = '\0';


		counter1 = 0;

		for (int k = 0; k < all_number_slov - n; k++)
		{

			while (arr[counter1] != '\0')
			{

				string_for_function[counter1] = arr[counter1];
				counter1++;
				if (arr[counter1] == ' ')
				{
					if (counter_for_gaps_for_counter_gaps == 0)
					{
						counter_for_gaps = counter1;
						counter_for_gaps_for_counter_gaps++;
					}

					gap_skip1++;
				}

				if (gap_skip == gap_skip1)
				{
					break;
				}


			}
			gap_skip1 = 0;

			counter_for_gaps_for_counter_gaps = 0;

			string_for_function[counter1] = '\0';
			counter_for_gaps++;

			while (arr[counter_for_gaps] != '\0')
			{
				time_mass[counter2] = arr[counter_for_gaps];
				counter_for_gaps++;
				counter2++;
			}

			for (int i = 0; i < counter2; i++)
			{
				arr[i] = time_mass[i];
			}

			arr[counter2] = '\0';
			counter1 = 0;
			counter2 = 0;
			counter_for_gaps = 0;



			arr_with_chastota[n] += (quantity_occurrences(string_for_function, j) / all_number_slov_with_chastota);

			counter1 = 0;
			if (k == all_number_slov - n - 1)
			{

				if (n == 2)
				{
					n = 2;
				}

				gap_skip++;
				k = -1;
				n++;


				all_number_slov_with_chastota = all_number_slov_with_chastota - 1;

				while (mystring[counter1] != '\0')
				{
					arr[counter1] = mystring[counter1];
					counter1++;

				}

				counter1 = 0;
				counter2 = 0;

			}
		}
		cout << "======================" << endl;
		cout << "chastota" << endl;
		for (int i = 0; i < all_number_slov; i++)
		{
			cout << arr_with_chastota[i] << endl;
		}
		cout << "======================" << endl;

		for (int i = 0; i < all_number_slov; i++)
		{
			arr_with_chastota[i] = 0;
		}


		counter_for_gaps_for_counter_gaps = 0;
		check_out = 0, counter1 = 0, counter2 = 0, counter_for_gaps = 0;

		n = 0;
		gap_skip = 1;
		gap_skip1 = 0;
		counter = 0;




	}

	delete[]string_for_file12;
	delete[]arr_with_chastota;
	delete[]arr;
	delete[]mystring;

}

float repositor::quantity_occurrences(char *abc,int number_file)
{	

	char *string_for_file = new char[100000000];
	int counter = 0, counter1 = 1;
	int amount_simvol = 0;
	int number_slov = 0;
	int all_number_slov = 0;
	int relevant = 0;
	   
	
	counter = 0;

	while (abc[counter1] != '\0') 
	{
		amount_simvol++;
		counter1++;
	}
	amount_simvol++; 
	counter1 = 0;
	
	ifstream read_library;                  
	read_library.open(library[number_file]);
	if (!read_library.is_open())
	{
		cout << "Error file" << endl;
	}
	else
	{
		char simvol;
		while (read_library.get(simvol))
		{
			
			string_for_file[counter] = simvol;
			counter++;
		}
		string_for_file[counter] = '\0';

	}
	counter = 0;


	
	for (int i = 0; i < 1000; i++)  
	{
		
		if (string_for_file[counter] == abc[0])
		{
			while (string_for_file[counter + counter1] == abc[counter1] && abc[counter1] != '\0')
			{
				counter1++;
				if (counter1 == amount_simvol)
				{
					number_slov++;
				}
			}
		}
		counter++;
		counter1 = 0;
	}
	cout << number_slov << endl;
	read_library.close();
	delete[]string_for_file;
	return number_slov;
}

int main()
{
	SmartRepositor a;
	cout << "Relevance Calculator start!\n";

	for (;;)
	{
		a.read_instruction();
		a.do_instruction();
	}
}

void SmartRepositor::read_instruction()
{
	cout << "\n\n";
	cin.getline(instruction, 20);
}

void SmartRepositor::do_instruction()
{
	help();
	change_library_pass();
	show_library_pass();
	show_lib();
	add_file();
	del_file();
	del_all();
	relev_all();
	//relev_file();
	change_file();
	out();
}

void SmartRepositor::help()
{
	if (is_right("help"))
	{
		cout << "\n******INSTUCTIONS******\n";
		cout << "chn lib pass - change pass to library\n";
		cout << "show lib pass - show pass to library\n";
		cout << "show lib - show files in library\n";
		cout << "add file - add 1 file to library\n";
		cout << "del file - delete 1 file from library\n";
		cout << "del all  - delete all files from library\n";
		cout << "relev all - find relevant for all files in library\n";
		cout << "relev file - find relevant for certain file in library\n";
		cout << "chn file - change file content\n";
		cout << "out - to exit\n";
	}
}

void SmartRepositor::change_library_pass()
{
	if (is_right("chn lib pass"))
	{
		cout << "\n" << "Enter new library pass...";
		cin.getline(library_pass, 100); // указываетс€ путь (полный)

		char library_pass_temp[50];
		for (int i = 0; i < strlen(library_pass) - strlen("library.txt"); i++)
		{
			library_pass_temp[i] = library_pass[i];
		}

		// измен€ем содержимое библиотеки
		int counter = 0, counter1 = 0;
		string str;
		ifstream read_library_file;

		read_library_file.open(library_pass);  // сохран€ет в библиотеку файлы


		if (!read_library_file.is_open())
		{

			cout << "Error file" << endl;
		}
		else
		{

			while (!read_library_file.eof())
			{
				str = "";
				getline(read_library_file, str);
				counter++;
			}

			delete [] library;

			library = new string[counter];

			read_library_file.seekg(0, ios::beg);

			while (!read_library_file.eof())
			{

				str = "";
				getline(read_library_file, str);

				library[counter1] = str;
				counter1++;
			}


		}

		read_library_file.close();
		number_file = counter;
	}
}

void SmartRepositor::show_library_pass()
{
	if (is_right("show lib pass"))
	{
		cout << "\nLibrary pass..." << library_pass << "\n";
	}
}

void SmartRepositor::show_lib()
{
	if (is_right("show lib"))
	{
		cout << "\nLibrary contains:\n";

		if (library == nullptr)
		{
			cout << "nothing\n";
		}
		else
		{
			for (int i = 0; i < number_file; i++)
			{
				cout << library[i] << "\n";
			}
		}
	}
}

void SmartRepositor::add_file()
{
	if (is_right("add file"))
	{
		string *temp = new string[number_file+1];
		for (int i = 0; i < number_file; i++)
		{
			temp[i] = library[i];
		}

		delete [] library;

		number_file = number_file + 1;

		cout << "\nEnter new file name..."; // полный путь к файлу
		cin >> temp[number_file - 1];

		library = new string[number_file];

		for (int i = 0; i < number_file; i++)
		{
			library[i] = temp[i];
		}

		delete [] temp;
	}
}

void SmartRepositor::del_file()
{
	if (is_right("del file"))
	{
		string fn;
		int id;

		cout << "\nEnter file name to delete...";
		cin >> fn;

		for (int i = 0; i < number_file; i++)
		{
			if (library[i] == fn)
			{
				id = i;
				break;
			}
		}

		number_file = number_file - 1;

		string *temp = new string[number_file];

		int k = 0;
		for (int i = 0; i < id; i++)
		{
			temp[k] = library[i];
			k++;
		}
		for (int i = id + 1; i < number_file + 1; i++)
		{
			temp[k] = library[i];
			k++;
		}

		delete [] library;

		library = new string[number_file];
		library = temp;

		for (int i = 0; i < number_file; i++)
		{
			library[i] = temp[i];
		}

		//delete[] temp;
	}
}

void SmartRepositor::del_all()
{
	if (is_right("del all"))
	{
		number_file = 0;
		delete [] library;

		library = nullptr;
	}
}

void SmartRepositor::relev_all()
{
	if (is_right("relev all"))
	{
		relevant();
	}
}

void SmartRepositor::relev_file()
{

}

void SmartRepositor::change_file()
{
	if (is_right("chn file"))
	{
		string temp;
		string fn;
		int id = 0;

		cout << "\nEnter file name to add...";
		cin >> fn;

		cout << "\nEnter what you need to add...";
		cin >> temp;

		for (int i = 0; i < number_file; i++)
		{
			if (library[i] == fn)
			{
				id = i;
				break;
			}
		}

		if (id != 0)
		{
			ofstream out(library[id], ios::app);
			out << temp;
			out.close();

			cout << "\nDone\n";
		}
		else
		{
			cout << "There is no file with such name\n";
		}
	}
}

void SmartRepositor::out()
{
	if (is_right("out"))
	{
		cout << "\nBye";
		exit(1);
	}
}

bool SmartRepositor::is_right(const char* str)
{
	return (strcmp(instruction, str) == 0);
}

void SmartRepositor::write_in_file()
{
	ofstream out(library_pass, ios::trunc);

	for (int i = 0; i < number_file; i++)
	{
		out << library[i] << "\n";
	}

	out.close();
}
