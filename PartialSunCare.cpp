/**
 * @file PartialSunCare.cpp
 * @brief Implementation of the PartialSunCare class.
 */
#include "PartialSunCare.h"

/**
 * @brief Constructor for the PartialSunCare class.
 *
 * Initializes the care strategy and sets its name to "PartialSun".
 */
PartialSunCare::PartialSunCare() { this->strategyName = "PartialSun"; }

/**
 * @brief Applies the care routine for partial sun conditions.
 *
 * This method implements the specific care logic for plants that prefer
 * a mix of sun and shade, which involves printing a descriptive message to the
 * console.
 */
void PartialSunCare::applyCare() {
  std::cout << "apply partial sun and shade care routine";
}

#ifdef ENABLE_DOCTESTS
#include "ShadyCare.h"
#include "SunnyCare.h"
#include "doctest.h"
#include <sstream>

TEST_SUITE("Care Strategies") {
  TEST_CASE("PartialSunCare strategy prints correct message") {
    PartialSunCare psc;
    std::stringstream ss;

    // Redirect cout to a stringstream to capture output
    std::streambuf *old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    psc.applyCare();

    // Restore original cout buffer
    std::cout.rdbuf(old_cout_buf);

    CHECK(ss.str() == "apply partial sun and shade care routine");
  }

  TEST_CASE("SunnyCare strategy prints correct message") {
    SunnyCare sc;
    std::stringstream ss;
    std::streambuf *old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    sc.applyCare();

    std::cout.rdbuf(old_cout_buf);
    CHECK(ss.str() == "Giving the plant full sunlight and regular watering");
  }

  TEST_CASE("ShadyCare strategy prints correct message") {
    ShadyCare shc;
    std::stringstream ss;
    std::streambuf *old_cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    shc.applyCare();
    std::cout.rdbuf(old_cout_buf);
    CHECK(ss.str() == "Giving the plant a few hours of sun daily");
  }
}
#endif
