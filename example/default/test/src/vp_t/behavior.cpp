/// @copyright
/// Copyright (C) 2020 Assured Information Security, Inc.
///
/// @copyright
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// @copyright
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// @copyright
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#include "../../../src/vp_t.hpp"

#include <bsl/ut.hpp>

namespace example
{
    /// <!-- description -->
    ///   @brief Used to execute the actual checks. We put the checks in this
    ///     function so that we can validate the tests both at compile-time
    ///     and at run-time. If a bsl::ut_check fails, the tests will either
    ///     fail fast at run-time, or will produce a compile-time error.
    ///
    /// <!-- inputs/outputs -->
    ///   @return Always returns bsl::exit_success.
    ///
    [[nodiscard]] constexpr auto
    tests() noexcept -> bsl::exit_code
    {
        bsl::ut_scenario{"initialize twice fails"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(!mut_vp.initialize({}, {}, {}, {}, {}));
                    };
                };
            };
        };

        bsl::ut_scenario{"initialize invalid id #1"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_check(!mut_vp.initialize({}, {}, {}, {}, bsl::safe_uint16::failure()));
                };
            };
        };

        bsl::ut_scenario{"initialize invalid id #2"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_check(!mut_vp.initialize({}, {}, {}, {}, syscall::BF_INVALID_ID));
                };
            };
        };

        bsl::ut_scenario{"initialize success"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_check(mut_vp.initialize({}, {}, {}, {}, {}));
                };
            };
        };

        bsl::ut_scenario{"release executes without initialize"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    mut_vp.release({}, {}, {}, {});
                };
            };
        };

        bsl::ut_scenario{"release executes with initialize"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        mut_vp.release({}, {}, {}, {});
                    };
                };
            };
        };

        bsl::ut_scenario{"allocate not initialized"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(!mut_vp.allocate({}, {}, {}, {}, {}, {}));
                };
            };
        };

        bsl::ut_scenario{"allocate already allocated"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_required_step(mut_vp.allocate({}, {}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(!mut_vp.allocate({}, {}, {}, {}, {}, {}));
                    };
                };
            };
        };

        bsl::ut_scenario{"allocate invalid vmid #1"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(
                            !mut_vp.allocate({}, {}, {}, {}, bsl::safe_uint16::failure(), {}));
                    };
                };
            };
        };

        bsl::ut_scenario{"allocate invalid vmid #2"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(!mut_vp.allocate({}, {}, {}, {}, syscall::BF_INVALID_ID, {}));
                    };
                };
            };
        };

        bsl::ut_scenario{"allocate invalid ppid #1"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(
                            !mut_vp.allocate({}, {}, {}, {}, {}, bsl::safe_uint16::failure()));
                    };
                };
            };
        };

        bsl::ut_scenario{"allocate invalid ppid #2"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(!mut_vp.allocate({}, {}, {}, {}, {}, syscall::BF_INVALID_ID));
                    };
                };
            };
        };

        bsl::ut_scenario{"allocate success"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                vp_t mut_vp{};
                bsl::ut_when{} = [&]() noexcept {
                    bsl::ut_required_step(mut_vp.initialize({}, {}, {}, {}, {}));
                    bsl::ut_then{} = [&]() noexcept {
                        bsl::ut_check(mut_vp.allocate({}, {}, {}, {}, {}, {}));
                    };
                };
            };
        };

        return bsl::ut_success();
    }
}

/// <!-- description -->
///   @brief Main function for this unit test. If a call to bsl::ut_check() fails
///     the application will fast fail. If all calls to bsl::ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
[[nodiscard]] auto
main() noexcept -> bsl::exit_code
{
    bsl::enable_color();

    static_assert(example::tests() == bsl::ut_success());
    return example::tests();
}