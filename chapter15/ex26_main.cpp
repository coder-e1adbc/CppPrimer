#include "ex26.h"

int main()
{
	{
		Quote q1;
		Quote q2 = q1;
		Quote q3 = std::move(q1);
		q3 = q2;
		q3 = std::move(q2);
	}
	{
		Bulk_quote bq1;
		Bulk_quote bq2 = bq1;
		Bulk_quote bq3 = std::move(bq1);
		bq3 = bq2;
		bq3 = std::move(bq2);
	}

	return 0;
}


