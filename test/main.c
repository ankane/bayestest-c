#include <assert.h>
#include <math.h>

#include <bayestest.h>

void assert_approx(double act, double exp) {
    assert(fabs(act - exp) < 0.0000000001);
}

void test_binary_no_variants(void) {
    int participants[1] = {0};
    int conversions[1] = {0};
    double probabilities[1] = {99};
    int status = bayestest_binary(0, participants, conversions, probabilities);
    assert(status == 0);
    assert(probabilities[0] == 99);
}

void test_binary_one_variant(void) {
    int participants[1] = {2};
    int conversions[1] = {1};
    double probabilities[1];
    int status = bayestest_binary(1, participants, conversions, probabilities);
    assert(status == 0);
    assert(probabilities[0] == 1);
}

void test_binary_two_variants(void) {
    int participants[2] = {200, 400};
    int conversions[2] = {100, 250};
    double probabilities[2];
    int status = bayestest_binary(2, participants, conversions, probabilities);
    assert(status == 0);
    assert_approx(probabilities[0], 0.001756431311879969);
    assert_approx(probabilities[1], 0.99824356868812);
}

void test_binary_three_variants(void) {
    int participants[3] = {61, 54, 72};
    int conversions[3] = {15, 13, 19};
    double probabilities[3];
    int status = bayestest_binary(3, participants, conversions, probabilities);
    assert(status == 0);
    assert_approx(probabilities[0], 0.29632930651329037);
    assert_approx(probabilities[1], 0.277257277195332);
    assert_approx(probabilities[2], 0.42641341629137763);
}

void test_binary_four_variants(void) {
    int participants[4] = {55, 30, 10, 50};
    int conversions[4] = {50, 30, 10, 45};
    double probabilities[4];
    int status = bayestest_binary(4, participants, conversions, probabilities);
    assert(status == 0);
    assert_approx(probabilities[0], 0.02692341639320739);
    assert_approx(probabilities[1], 0.7040521621641954);
    assert_approx(probabilities[2], 0.249824960767943);
    assert_approx(probabilities[3], 0.019199460674668434);
}

void test_binary_five_variants(void) {
    int participants[5] = {55, 30, 10, 50, 20};
    int conversions[5] = {50, 30, 10, 45, 15};
    double probabilities[5];
    int status = bayestest_binary(5, participants, conversions, probabilities);
    assert(status == -1);
}

void test_binary_negative_participants(void) {
    int participants[1] = {-1};
    int conversions[1] = {1};
    double probabilities[1];
    int status = bayestest_binary(1, participants, conversions, probabilities);
    assert(status == -1);
}

void test_binary_high_participants(void) {
    int participants[1] = {INT_MAX};
    int conversions[1] = {1};
    double probabilities[1];
    int status = bayestest_binary(1, participants, conversions, probabilities);
    assert(status == -1);
}

void test_binary_negative_conversions(void) {
    int participants[1] = {1};
    int conversions[1] = {-1};
    double probabilities[1];
    int status = bayestest_binary(1, participants, conversions, probabilities);
    assert(status == -1);
}

void test_binary_high_conversions(void) {
    int participants[1] = {1};
    int conversions[1] = {INT_MAX};
    double probabilities[1];
    int status = bayestest_binary(1, participants, conversions, probabilities);
    assert(status == -1);
}

void test_binary_more_conversions(void) {
    int participants[1] = {1};
    int conversions[1] = {2};
    double probabilities[1];
    int status = bayestest_binary(1, participants, conversions, probabilities);
    assert(status == -1);
}

int main(void) {
    test_binary_no_variants();
    test_binary_one_variant();
    test_binary_two_variants();
    test_binary_three_variants();
    test_binary_four_variants();
    test_binary_five_variants();
    test_binary_negative_participants();
    test_binary_high_participants();
    test_binary_negative_conversions();
    test_binary_high_conversions();
    test_binary_more_conversions();
}
