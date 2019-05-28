#pragma once

#include "Personal.h"

/* ==================== [–аботник: водитель] ==================== */

class Driver : public Personal
{
public:
	Driver(int id, string name, int worktime, int base) // конструктор с параметрами
	{
		this->id = id;				// идентификационный номер
		this->name = name;			// ‘»ќ
		this->base = base;			// базова€ ставка
		this->worktime = worktime;	// отработанное врем€
		calculatePayment();	// рассчитаем оплату труда
	}

	/* ========== [ћетод [переопределение]: ”становить зар.плату] ========== */
	void calculatePayment() override
	{
		this->payment = WorkTimePaymentMethod(this->worktime, this->base); // высчитаем по методу оплаты: исход€ из отработанного времени
	}

	/* ========== [ћетод: рассчитать зар.плату по отработанному времени] ========== */
	int WorkTimePaymentMethod(int worktime, int base) override
	{
		this->payment = worktime * base;
		return payment;
	}



	~Driver() {}
};

