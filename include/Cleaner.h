#pragma once

#include "Personal.h"

/* ==================== [–аботник: уборщица] ==================== */

class Cleaner : public Personal
{
public:
	Cleaner(int id, string name, int worktime, int base) // конструктор с параметрами
	{
		this->id = id;				// идентификационный номер
		this->name = name;			// фио
		this->base = base;			// ставка
		this->worktime = worktime;	//отработанное врем€
		calculatePayment();			// рассчитаем оплату труда
	}

	/* ========== [ћетод [переопределение]: ”становить зар.плату] ========== */
	void calculatePayment()
	{
		this->payment = WorkTimePaymentMethod(this->worktime, this->base); // высчитаем по методу оплаты: исход€ из отработанного времени
	}

	/* ========== [ћетод: рассчитать зар.плату по отработанному времени] ========== */
	int WorkTimePaymentMethod(int work_time, int base) override
	{
		int payment = work_time * base;
		return payment;
	}

	~Cleaner() {}
};
