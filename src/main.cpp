#include <iostream>
#include <fstream>
#include <vector>

/* ==================== [Подключение необходимых классов] ==================== */
#include "Employee.h"

#include "Manager.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "TeamLeader.h"
#include "Tester.h"
#include "ProjectManager.h"
#include "SeniorManager.h"

using namespace std;

int main()
{
	vector <Employee*> workers; // создадим работника

	ifstream FileWorkers("workers.txt"); // загрузим работников из файла

	if (!FileWorkers.is_open()) // если не удалось открыть
	{
		cout << "[OPENING FileWorkers ERROR] FAILED to open" << endl;
		return false;
	}
	else
	{
		enum PROFFESIONS {
			TRAINEE,			// стажер
			MANAGER,			// менеджер
			CLEANER,			// уборщица
			DRIVER,				// водитель
			PROGRAMMER,			// инженер-программист
			TEAM_LEADER,		// ведущий программист
			TESTER,				// инженер по тестированию
			PROJECT_MANAGER,	// проектный менеджер
			SENIOR_MANAGER,		// руководитель направления	
		};

		PROFFESIONS pos_ID = TRAINEE; // ID должности (по умолчанию - стажер)

		int id; // идентификационный номер

		while (FileWorkers >> id)
		{
			string name, surname, second_name, fio, position; // ФИО сотрудника, должность
			FileWorkers >> name >> surname >> second_name >> position; // считаем из файла и запишем в переменные
			fio = name + " " + surname + " " + second_name; // образуем ФИО

															// расставим по соответствующим должностям идентификаторы профессий

			if (position == "Cleaner")				pos_ID = CLEANER;
			else if (position == "Driver")				pos_ID = DRIVER;
			else if (position == "ProjectManager")		pos_ID = PROJECT_MANAGER;
			else if (position == "Tester")				pos_ID = TESTER;
			else if (position == "Manager")				pos_ID = MANAGER;
			else if (position == "TeamLeader")			pos_ID = TEAM_LEADER;
			else if (position == "SeniorManager")		pos_ID = SENIOR_MANAGER;
			else if (position == "Programmer")			pos_ID = PROGRAMMER;


			int worktime = 0, // время работы
				base = 0, // ставка
				budget = 0, // бюджет
				salary = 0,	 // оплата труда
				pjcts_amount = 0;// количество проектов

			double deposit = 0.0;	// вклад
			string project = "";	// будущее название проекта

			switch (pos_ID) // обработаем ситуацию каждой должности
			{
			case CLEANER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				workers.push_back(new Cleaner(id, fio, worktime, base));
				break;
			}
			case DRIVER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				workers.push_back(new Driver(id, fio, worktime, base));
				break;
			}
			case TESTER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				workers.push_back(new Tester(id, fio, worktime, base, project, budget, deposit));
				break;
			}
			case PROGRAMMER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				workers.push_back(new Programmer(id, fio, worktime, base, project, budget, deposit));
				break;
			}
			case TEAM_LEADER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				FileWorkers >> salary;
				workers.push_back(new TeamLeader(id, fio, worktime, base, project, budget, deposit, salary));
				break;
			}
			case MANAGER:
			{
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				workers.push_back(new Manager(id, fio, project, budget, deposit));
				break;
			}
			case PROJECT_MANAGER:
			{
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				FileWorkers >> salary;
				workers.push_back(new ProjectManager(id, fio, project, budget, deposit, salary));
				break;
			}
			case SENIOR_MANAGER:
			{
				FileWorkers >> pjcts_amount;
				FileWorkers >> deposit;
				FileWorkers >> salary;
				workers.push_back(new SeniorManager(id, fio, pjcts_amount, deposit, salary));
				break;
			}
			}
		}

		FileWorkers.close(); // закроем наш файл
							 /* ==================== [Вывод информации о работнике на экран] ==================== */
		for (int i = 0; i < workers.size(); ++i)
		{
			workers[i]->calculatePayment();
			cout <<
				workers[i]->getID() << "\t" <<
				workers[i]->getFIO() << "\t" <<
				workers[i]->getPaymentTime() << "\t" <<
				workers[i]->getWorkTime()
				<< endl;
		}
	}
	system("pause");
	return 0;
}