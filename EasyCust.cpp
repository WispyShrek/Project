#include "EasyCust.h"

	CHECK(customer.cartToString().find("Rose") != std::string::npos);
	CHECK(ss.str().find("Paying with EFT") != std::string::npos);
}

TEST_CASE("EasyCust: destructor cleans up memory safely")
{
	EasyCust *customer = new EasyCust("Dave", nullptr, 20.0, new EFT(), {new Rose(), new Rose()});
	delete customer; // should not leak or crash
}
