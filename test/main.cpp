#include "exception.h"

int main()
{
	try
	{
		throw except::SqlEmptyException("sql empty exception");
	}
	catch (const except::ExceptionBase & e)
	{
		printf("%s\n", e.what());
	}

	try
	{
		throw except::SqlEmptyException("sql empty exception",except::SQL_EMPTY);
	}
	catch (const except::ExceptionBase & e)
	{
		printf("%s with error code: %d\n", e.what(), e.getErrorCode());;
	}

	try
	{
		throw except::SqlEmptyException("sql empty exception", except::SQL_EMPTY, EXCEPTION_SRC, EXCEPTION_LINE);
	}
	catch (const except::ExceptionBase & e)
	{
		printf("%s with error code: %d\n", e.what(), e.getErrorCode());;
	}
	return 0;
}