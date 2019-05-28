#pragma once

#include "Programmer.h"
#include "Heading.h"

/* ==================== [Работник: ведущий программист] ==================== */

class TeamLeader : public Programmer, public Heading
{
protected:
	int salary; // оплата труда
public:
	TeamLeader() : Programmer() { this->salary = 0; };

	TeamLeader(int id, string name, int worktime, int base, string project, int budget, double deposit, int salary)
	{
		this->id = id;				// идентификационный номер
		this->name = name;			// ФИО
		this->base = base;			// ставка
		this->project = project;	// проект
		this->salary = salary;		// оплата труда
		this->worktime = worktime;	// отработанное время
		this->budget = budget;		// бюджет
		this->deposit = deposit;	// вклад

		calculatePayment();			// рассчитаем оплату труда
	}
	/* ========== [Метод: рассчитать зар.плату исходя из руководства (кол-во подчиненных)] ========== */
	int HeadingPaymentMethod(int salary) override
	{
		int pay = salary * 100;
		return pay;
	}

	/* ========== [Метод [переопределение]: Установить зар.плату] ========== */
	void calculatePayment()
	{
		this->payment = (
			WorkTimePaymentMethod(this->worktime, this->base) +
			ProjectPaymentMethod(budget, deposit) +
			HeadingPaymentMethod(salary)
			); // высчитаем по методам оплаты: исходя из отработанного времени + исходя из участия в проекте + исходя из руководства
	}

	~TeamLeader() {}
};