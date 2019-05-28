#pragma once

#include "Employee.h"
#include "Project.h"

/* ==================== [Работник: менеджер] ==================== */
// * оплату получает из денег проекта, которым руководит.

class Manager : public Employee, public Project
{
protected:
	/* ==================== [Переменные] ==================== */
	double deposit;	// вклад
	int budget;		// бюджет
	string project;	// проект

public:
	Manager() // конструктор по умолчанию
	{
		this->deposit = 0;
		this->budget = 0;
		this->project = "";
	}

	Manager(int id, string name, string proj, int budget, double depos) // конструктор с параметрами
	{
		this->id = id;
		this->name = name;
		this->project = proj;
		this->budget = budget;
		this->deposit = depos;

		this->worktime = 0;
		calculatePayment();	// рассчитаем оплату труда
	}

	/* ========== [Метод [переопределение]: Установить зар.плату] ========== */
	void calculatePayment() override
	{
		this->payment = ProjectPaymentMethod(this->budget, this->deposit); // высчитаем по методу оплаты: исходя из участия в проекте
	}

	/* ===== [Метод [переопределение]: рассчитать зар.плату исходя из участия в проекте] ===== */
	int ProjectPaymentMethod(int budget, double deposit) override
	{
		int payment = budget * deposit;
		return payment;
	}

	/* ========== [Метод: установить вклад ] ========== */
	void setDeposit(double depos)
	{
		this->deposit = depos;
	}

	/* ========== [Метод: получить текущий вклад ] ========== */
	double getDeposit()
	{
		return deposit;
	}

	/* ========== [Метод: задать проект] ========== */
	void setProject(string project_name)
	{
		this->project = project_name;
	}

	/* ========== [Метод: получить проект] ========== */
	string getProject()
	{
		return project;
	}

	~Manager() {}
};


