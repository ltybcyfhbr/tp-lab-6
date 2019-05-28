#pragma once

#include <string>

using namespace std;

/* ==================== [Базовый класс работника] ==================== */
class Employee
{
protected:
	/* ==================== [Переменные] ==================== */
	int id;			// идентификационный номер
	string name;	// фио
	int worktime;	// отработанное время
	int payment;	// заработная плата

public:
	/* ==================== [Методы] ==================== */
	Employee() {}	// конструктор по умолчанию

	Employee(int id, string name, int worktime, int payment) // конструктор с параметрами
	{
		this->id = id;
		this->name = name;
		this->worktime = worktime;
	}

	/* ========== ["Универсальный" метод: Установить зар.плату] ========== */
	virtual void calculatePayment() = 0;

	/* ========== [Метод: Назначить ID] ========== */
	void setID(int id)
	{
		this->id = id;
	}

	/* ========== [Метод: Получить ID работника] ========== */
	int getID() const
	{
		return id;
	}

	/* ========== [Метод: Назначить ФИО] ========== */
	void setFIO(string name)
	{
		this->name = name;
	}

	/* ========== [Метод: Получить ФИО работника] ========== */
	string getFIO() const
	{
		return name;
	}

	/* ========== [Метод: Установить рабочее время работнику] ========== */
	void setWorkTime(int worktime)
	{
		this->worktime = worktime;
	}

	/* ========== [Метод: Получить рабочее время работника] ========== */
	int getWorkTime() const
	{
		return worktime;
	}

	/* ========== [Метод: Получить зар.плату работника за время его работы] ========== */
	int getPaymentTime() const
	{
		return payment;
	}

	~Employee() {}	// деструктор
};
