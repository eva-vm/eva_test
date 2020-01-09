# eva_test

Simple test framework used by the Eva project

# Installation

## Using `meson`

Create the file `subprojects/evatest.wrap`:

```ini
[wrap-git]
url = https://github.com/eva-vm/eva_test.git
revision = 1.1
```

In your `meson.build`, get the dependency variable as follows:

```meson
test_dep = subproject('evatest').get_variable('test_dep')
```

## Using `cmake`

Add this repository as a submodule, and include the `evatest` folder into your targets' include directory:

```cmake
target_include_directory(target PRIVATE <path/to/evatest/repo>)
```

## Manually

Add this repository as a submodule, and add a compiler include option pointing to the root of the repo.

# Usage

Include the test file as follows (if you've followed the instructions above):

```c
#include <evatest/test.h>
```

Several macros are available to you.

## `INIT_TEST`

This macro adds the required variables for the tests to be tracked. It should be put before any test is run.

## `TEST(c)`

Tests whether the condition `c` is true, and report the result (see [Options](#options) below for details about the report).

## `END_TEST`

Ends the tests, shows a summary of the tests or the number of tests run (depending on the protocol, see [Options](#options) below).

# Options

You can control the behavior of the testing library through defines.

## `TEST_MAX` (default: 1000)

Maximum number of tests tracked. If you add more tests, they will be run but their errors might not get reported.

This has no effect with `EVATEST_TAP` where errors aren't tracked, just reported as-is.

## `EVATEST_TAP` (default: unset)

Defining this enables the TAP reporter, allowing to work with TAP test harnesses. This allows the sharing of more information about the tests in a standard way.
