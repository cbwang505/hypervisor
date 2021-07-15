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

#include "../../../../src/x64/intrinsic_cpuid_impl.hpp"

#include <bsl/convert.hpp>
#include <bsl/ut.hpp>

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

    bsl::ut_scenario{"intrinsic_cpuid_impl"} = []() noexcept {
        bsl::ut_given{} = []() noexcept {
            constexpr auto data{0x1234567800000000_u64};
            constexpr auto mask{0xFFFFFFFF00000000_u64};
            auto mut_rax{data};
            auto mut_rbx{data};
            auto mut_rcx{data};
            auto mut_rdx{data};
            bsl::ut_when{} = [&]() noexcept {
                example::intrinsic_cpuid_impl(
                    nullptr, mut_rax.data(), mut_rbx.data(), mut_rcx.data(), mut_rdx.data());
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check((mut_rax & mask) == data);
                    bsl::ut_check((mut_rbx & mask) == data);
                    bsl::ut_check((mut_rcx & mask) == data);
                    bsl::ut_check((mut_rdx & mask) == data);
                };
            };
        };
    };

    return bsl::ut_success();
}
