#pragma once

/* ==================== [���������: WorkTime] ==================== */
// * ������ ������ ������ �� ������������� ������� (���� ���������� �� ������)

class WorkTime
{
public:
	WorkTime() {}

	/* ========== [�����: ���������� ���.����� �� ������������� �������] ========== */
	virtual int WorkTimePaymentMethod(int worktime, int base) = 0;

	~WorkTime() {}
};