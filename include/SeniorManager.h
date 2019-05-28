#pragma once

#include"ProjectManager.h"

/* ==================== [–аботник: руководитель направлени€] ==================== */

class SeniorManager : public ProjectManager
{
private:
	int pjcts_amount;

public:
	SeniorManager() : ProjectManager() { this->pjcts_amount = 0; };

	SeniorManager(int id, string name, int pjcts_amount, double deposit, int salary)
	{
		this->id = id;
		this->name = name;
		this->pjcts_amount = pjcts_amount;
		this->salary = salary;
		this->deposit = deposit;

		this->worktime = 0;
		calculatePayment();
	}

	/* ===== [ћетод [переопределение]: рассчитать зар.плату исход€ из участи€ в проекте] ===== */
	int ProjectPaymentMethod(int whole_budget, double deposit) override
	{
		int payment = whole_budget * this->deposit * this->pjcts_amount;
		return payment;
	}

	/* ========== [ћетод [переопределение]: ”становить зар.плату] ========== */
	void calculatePayment() override
	{
		this->payment = (
			ProjectPaymentMethod(1000, this->deposit) +
			HeadingPaymentMethod(this->salary)
			);
	}

	~SeniorManager() {}
};
