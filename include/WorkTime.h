#pragma once

/* ==================== [»нтерфейс: WorkTime] ==================== */
// * расчет оплаты исход€ из отработанного времени (часы умножаютс€ на ставку)

class WorkTime
{
public:
	WorkTime() {}

	/* ========== [ћетод: рассчитать зар.плату по отработанному времени] ========== */
	virtual int WorkTimePaymentMethod(int worktime, int base) = 0;

	~WorkTime() {}
};