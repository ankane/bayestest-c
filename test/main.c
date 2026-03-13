#include <assert.h>
#include <limits.h>
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

void test_count_no_variants(void) {
    int events[1] = {0};
    int exposures[1] = {0};
    double probabilities[1] = {99};
    int status = bayestest_count(0, events, exposures, probabilities);
    assert(status == 0);
    assert(probabilities[0] == 99);
}

void test_count_one_variant(void) {
    int events[1] = {0};
    int exposures[1] = {0};
    double probabilities[1];
    int status = bayestest_count(1, events, exposures, probabilities);
    assert(status == 0);
    assert(probabilities[0] == 1);
}

void test_count_two_variants(void) {
    int events[2] = {55, 30};
    int exposures[2] = {50, 30};
    double probabilities[2];
    int status = bayestest_count(2, events, exposures, probabilities);
    assert(status == 0);
    assert_approx(probabilities[0], 0.6710529663661625);
    assert_approx(probabilities[1], 0.3289470336338596);
}

void test_count_three_variants(void) {
    int events[3] = {55, 30, 10};
    int exposures[3] = {50, 30, 10};
    double probabilities[3];
    int status = bayestest_count(3, events, exposures, probabilities);
    assert(status == 0);
    assert_approx(probabilities[0], 0.4633365654508068);
    assert_approx(probabilities[1], 0.2306153779716283);
    assert_approx(probabilities[2], 0.3060480565775272);
}

void test_count_four_variants(void) {
    int events[4] = {55, 30, 10, 20};
    int exposures[4] = {50, 30, 10, 15};
    double probabilities[4];
    int status = bayestest_count(4, events, exposures, probabilities);
    assert(status == -1);
}

void test_count_exposure_relative(void) {
    int events[2] = {55, 30};
    int exposures[2] = {50000, 30000};
    double probabilities[2];
    int status = bayestest_count(2, events, exposures, probabilities);
    assert(status == 0);
    assert_approx(probabilities[0], 0.6710529663661625);
    assert_approx(probabilities[1], 0.3289470336338596);
}

void test_count_negative_events(void) {
    int events[1] = {-1};
    int exposures[1] = {1};
    double probabilities[1];
    int status = bayestest_count(1, events, exposures, probabilities);
    assert(status == -1);
}

void test_count_negative_exposure(void) {
    int events[1] = {1};
    int exposures[1] = {-1};
    double probabilities[1];
    int status = bayestest_count(1, events, exposures, probabilities);
    assert(status == -1);
}

void test_prob_b_beats_a(void) {
    assert_approx(bayestest_prob_b_beats_a(1, 2, 3, 4), 0.6428571428571429);
    assert_approx(bayestest_prob_b_beats_a(55, 50, 30, 30), 0.38386463776317903);
    assert_approx(bayestest_prob_b_beats_a(50, 50, 35, 30), 0.6867997222295887);
}

void test_prob_c_beats_ab(void) {
    assert_approx(bayestest_prob_c_beats_ab(1, 2, 3, 4, 5, 6), 0.4128959276018096);
    assert_approx(bayestest_prob_c_beats_ab(1, 2, 3, 4, 5, 100), 0.0004147782900546515);
    assert_approx(bayestest_prob_c_beats_ab(55, 50, 30, 30, 10, 10), 0.35421204276865736);
    assert_approx(bayestest_prob_c_beats_ab(50, 50, 35, 30, 13, 18), 0.09139305107602524);
}

void test_prob_d_beats_abc(void) {
    assert_approx(bayestest_prob_d_beats_abc(1, 2, 3, 4, 5, 6, 7, 8), 0.2853316096371013);
    assert_approx(bayestest_prob_d_beats_abc(55, 50, 30, 30, 10, 10, 25, 30), 0.08421499131901738);
}

void test_prob_1_beats_2(void) {
    assert_approx(bayestest_prob_1_beats_2(1, 2, 3, 4), 0.29629629629629595);
    assert_approx(bayestest_prob_1_beats_2(55, 50, 30, 30), 0.6710529663661625);
    assert_approx(bayestest_prob_1_beats_2(50, 50, 35, 30), 0.24796547380927997);
}

void test_prob_1_beats_23(void) {
    assert_approx(bayestest_prob_1_beats_23(1, 2, 3, 4, 5, 6), 0.16901765046296247);
    assert_approx(bayestest_prob_1_beats_23(1, 2, 3, 4, 5, 100), 0.2962330601144884);
    assert_approx(bayestest_prob_1_beats_23(55, 50, 30, 30, 10, 10), 0.4633365654508068);
    assert_approx(bayestest_prob_1_beats_23(50, 50, 35, 30, 13, 18), 0.23397153850438435);
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

    test_count_no_variants();
    test_count_one_variant();
    test_count_two_variants();
    test_count_three_variants();
    test_count_four_variants();
    test_count_exposure_relative();
    test_count_negative_events();
    test_count_negative_exposure();

    test_prob_b_beats_a();
    test_prob_c_beats_ab();
    test_prob_d_beats_abc();

    test_prob_1_beats_2();
    test_prob_1_beats_23();

    return 0;
}
