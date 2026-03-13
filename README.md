# BayesTest C

Bayesian A/B testing calculations for C

Based on [this post](https://www.evanmiller.org/bayesian-ab-testing.html) by Evan Miller

Also available in [C++](https://github.com/ankane/bayestest-cpp) and [Rust](https://github.com/ankane/bayestest-rust)

[![Build Status](https://github.com/ankane/bayestest-c/actions/workflows/build.yml/badge.svg)](https://github.com/ankane/bayestest-c/actions)

## Installation

Add [the header](https://raw.githubusercontent.com/ankane/bayestest-c/v0.1.0/include/bayestest.h) to your project.

## Getting Started

Include the header

```c
#include "bayestest.h"
```

- [Binary outcomes](#binary-outcomes), like conversion rate
- [Count data](#count-data), like number of sales per salesperson

## Binary Outcomes

```c
int participants[2] = {100, 200};
int conversions[2] = {50, 95};
double probabilities[2];
int status = bayestest_binary(2, participants, conversions, probabilities);
```

Status is `0` on success

Supports up to 4 variants

## Count Data

[unreleased]

```c
int events[2] = {100, 200};
int exposure[2] = {50, 95};
double probabilities[2];
int status = bayestest_count(2, events, exposure, probabilities);
```

Status is `0` on success

Supports up to 3 variants

## History

View the [changelog](https://github.com/ankane/bayestest-c/blob/master/CHANGELOG.md)

## Contributing

Everyone is encouraged to help improve this project. Here are a few ways you can help:

- [Report bugs](https://github.com/ankane/bayestest-c/issues)
- Fix bugs and [submit pull requests](https://github.com/ankane/bayestest-c/pulls)
- Write, clarify, or fix documentation
- Suggest or add new features

To get started with development:

```sh
git clone https://github.com/ankane/bayestest-c.git
cd bayestest-c
cmake -S . -B build
cmake --build build
build/test
```
