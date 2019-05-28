#pragma once

#include "Engineer.h"

/* ==================== [Работник: инженер-программист] ==================== */

class Programmer : public Engineer
{
public:
	Programmer() : Engineer() {};

	Programmer(int id, string name, int worktime, int base, string project, int budget, double deposit)
	{
		this->id = id;				// идентификационный номер
		this->name = name;			// ФИО
		this->base = base;			// ставка
		this->project = project;	// проект
		this->worktime = worktime;	// отработанное время
		this->budget = budget;		// бюджет
		this->deposit = deposit;	// вклад

		calculatePayment();	// рассчитаем оплату труда
	}

	/* ========== [Метод [переопределение]: Установить зар.плату] ========== */
	void calculatePayment() override
	{
		this->payment = (
			WorkTimePaymentMethod(this->worktime, this->base) +
			ProjectPaymentMethod(budget, deposit)
			); // высчитаем по методам оплаты: исходя из отработанного времени + исходя из участия в проекте
	}

	~Programmer() {}
};

