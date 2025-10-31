#include "PlantIterator.h"
#include "Rose.h"

PlantIterator::PlantIterator(std::vector<std::vector<Plant*>>& grid)
    : grid(grid), idx(npos) {}

std::size_t PlantIterator::rows() const{
    return grid.size();
}

std::size_t PlantIterator::cols() const{
    return grid.empty() ? 0 : grid[0].size();
}

Plant *PlantIterator::at(std::size_t linear) const
{
    if (rows() == 0 || cols() == 0) return nullptr;
    if (linear >= rows() * cols()) return nullptr;
    std::size_t r = linear / cols();
    std::size_t c = linear % cols();
    return grid[r][c];
}

std::size_t PlantIterator::findNext(std::size_t start) const {
    const std::size_t total = rows() * cols();
    for (std::size_t i = start; i < total; ++i) {
        if (at(i) != nullptr) return i;
    }
    return npos;
}

std::size_t PlantIterator::findPrev(std::size_t start) const {
    // start is assumed > 0; search backward for non-null
    for (std::size_t i = start + 1; i-- > 0; ) {
        if (at(i) != nullptr) return i;
        if (i == 0) break;
    }
    return npos;
}

Plant* PlantIterator::currItem() {
    if (idx == npos) return nullptr;
    return at(idx);
}

void PlantIterator::first() {
    idx = findNext(0);
}

bool PlantIterator::isDone() {
    return idx == npos;
}

void PlantIterator::next() {
    if (idx == npos) return;
    const std::size_t total = rows() * cols();
    std::size_t nextIdx = (idx + 1 < total) ? findNext(idx + 1) : npos;
    idx = nextIdx;
}

void PlantIterator::prev() {
    if (idx == npos) {
        // if done, move to last non-null
        const std::size_t total = rows() * cols();
        if (total == 0) return;
        idx = findPrev(total - 1);
        return;
    }
    if (idx == 0) return;
    idx = findPrev(idx - 1);
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("PlantIterator on empty 3x3 grid: first makes iterator done; currItem is nullptr") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    PlantIterator it(grid);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("PlantIterator::first selects first non-null in row-major order") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    Rose* a = new Rose(); // (0,1)
    Rose* b = new Rose(); // (2,2)
    grid[0][1] = a;
    grid[2][2] = b;

    PlantIterator it(grid);
    it.first();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == a);

    delete a;
    delete b;
}

TEST_CASE("PlantIterator::isDone reflects bounds for single element") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    Rose* a = new Rose();
    grid[1][1] = a;

    PlantIterator it(grid);
    it.first();
    CHECK(it.isDone() == false);
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    delete a;
}

TEST_CASE("PlantIterator::next walks forward row-major and skips nulls") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    Rose* p0 = new Rose(); // (0,0)
    Rose* p1 = new Rose(); // (0,2)
    Rose* p2 = new Rose(); // (1,0)
    Rose* p3 = new Rose(); // (2,1)
    grid[0][0] = p0;
    grid[0][2] = p1;
    grid[1][0] = p2;
    grid[2][1] = p3;

    PlantIterator it(grid);
    it.first();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == p0);
    it.next();
    CHECK(it.currItem() == p1);
    it.next();
    CHECK(it.currItem() == p2);
    it.next();
    CHECK(it.currItem() == p3);
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    // calling next when done should stay done
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    delete p0; delete p1; delete p2; delete p3;
}

TEST_CASE("PlantIterator::prev moves backward correctly; at first stays; from done goes to last") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    Rose* p0 = new Rose(); // (0,0)
    Rose* p1 = new Rose(); // (1,1)
    Rose* p2 = new Rose(); // (2,2)
    grid[0][0] = p0;
    grid[1][1] = p1;
    grid[2][2] = p2;

    PlantIterator it(grid);

    // Start and prev at beginning stays
    it.first();
    REQUIRE(it.currItem() == p0);
    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == p0);

    // Move forward, then back
    it.next(); // p1
    CHECK(it.currItem() == p1);
    it.prev(); // back to p0
    CHECK(it.currItem() == p0);

    // Move to done, then prev should go to last non-null
    it.next(); // p1
    it.next(); // p2
    it.next(); // done
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
    it.prev(); // should go to p2
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == p2);

    delete p0; delete p1; delete p2;
}

TEST_CASE("PlantIterator works with single plant placed anywhere") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    Rose* a = new Rose();
    grid[2][0] = a;

    PlantIterator it(grid);
    it.first();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == a);

    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == a);

    delete a;
}

TEST_CASE("PlantIterator returns correct plant pointer type") {
    std::vector<std::vector<Plant*>> grid(3, std::vector<Plant*>(3, nullptr));
    Rose* rose = new Rose();
    grid[0][0] = rose;

    PlantIterator it(grid);
    it.first();
    REQUIRE(it.isDone() == false);
    Plant* current = it.currItem();
    CHECK(current == rose);

    delete rose;
}

#endif // ENABLE_DOCTESTS
