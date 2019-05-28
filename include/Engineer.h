#pragma once

#include "Employee.h"
#include "WorkTime.h"
#include "Project.h"

/* ==================== [Работник: инженер] ==================== */
// * имеет ставку и оплату за час + бонусы от выполняемого проекта

class Engineer : public Employee, public WorkTime, public Project
{
protected:
	/* ==================== [Переменные] ==================== */
	int base;		// базовая ставка
	double deposit;	// вклад
	string project;	// проект
	int budget;		// бюджет

public:
	Engineer() : Employee() {}; // конструктор по умолчанию (наследуем у класса Employee)

								/* ========== [Метод: рассчитать зар.плату по отработанному времени] ========== */
	int WorkTimePaymentMethod(int work_time, int base) override
	{
		int payment = work_time * base;
		return payment;
	}

	/* ===== [Метод: рассчитать зар.плату с учетом бонуса от выполняемого проекта] ===== */
	int ProjectPaymentMethod(int budget, double deposit) override
	{
		int bonus = budget * deposit;
		return bonus;
	}

	/* ========== [Метод: установить базовую ставку ] ========== */
	void setBase(int base)
	{
		this->base = base;
	}

	/* ========== [Метод: получить базовую ставку ] ========== */
	int getBase() const
	{
		return base;
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

	~Engineer() {}
};

