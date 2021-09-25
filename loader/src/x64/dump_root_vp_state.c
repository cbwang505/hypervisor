/**
 * @copyright
 * Copyright (C) 2020 Assured Information Security, Inc.
 *
 * @copyright
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * @copyright
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * @copyright
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <debug.h>
#include <state_save_t.h>
#include <types.h>

/**
 * <!-- description -->
 *   @brief Outputs the contents of a provided root vp state.
 *
 * <!-- inputs/outputs -->
 *   @param state the root vp state to output
 *   @param cpu the CPU that this root vp state belongs to
 */
void
dump_root_vp_state(struct state_save_t *const state, uint32_t const cpu)
{
    if (((void *)0) == state) {
        bferror("state is NULL");
        return;
    }

    bfdebug_d32("root vp state on cpu", cpu);
    bfdebug_ptr(" - virt", state);

    bfdebug_x64(" - rax", state->rax);
    bfdebug_x64(" - rbx", state->rbx);
    bfdebug_x64(" - rcx", state->rcx);
    bfdebug_x64(" - rdx", state->rdx);
    bfdebug_x64(" - rbp", state->rbp);
    bfdebug_x64(" - rsi", state->rsi);
    bfdebug_x64(" - rdi", state->rdi);
    bfdebug_x64(" - r8", state->r8);
    bfdebug_x64(" - r9", state->r9);
    bfdebug_x64(" - r10", state->r10);
    bfdebug_x64(" - r11", state->r11);
    bfdebug_x64(" - r12", state->r12);
    bfdebug_x64(" - r13", state->r13);
    bfdebug_x64(" - r14", state->r14);
    bfdebug_x64(" - r15", state->r15);
    bfdebug_x64(" - rip", state->rip);
    bfdebug_x64(" - rsp", state->rsp);

    bfdebug_x64(" - rflags", state->rflags);

    bfdebug_ptr(" - gdtr.base", state->gdtr.base);
    bfdebug_x16(" - gdtr.limit", state->gdtr.limit);
    bfdebug_ptr(" - idtr.base", state->idtr.base);
    bfdebug_x16(" - idtr.limit", state->idtr.limit);
    bfdebug_x16(" - es_selector", state->es_selector);
    bfdebug_x16(" - es_attrib", state->es_attrib);
    bfdebug_x32(" - es_limit", state->es_limit);
    bfdebug_x64(" - es_base", state->es_base);
    bfdebug_x16(" - cs_selector", state->cs_selector);
    bfdebug_x16(" - cs_attrib", state->cs_attrib);
    bfdebug_x32(" - cs_limit", state->cs_limit);
    bfdebug_x64(" - cs_base", state->cs_base);
    bfdebug_x16(" - ss_selector", state->ss_selector);
    bfdebug_x16(" - ss_attrib", state->ss_attrib);
    bfdebug_x32(" - ss_limit", state->ss_limit);
    bfdebug_x64(" - ss_base", state->ss_base);
    bfdebug_x16(" - ds_selector", state->ds_selector);
    bfdebug_x16(" - ds_attrib", state->ds_attrib);
    bfdebug_x32(" - ds_limit", state->ds_limit);
    bfdebug_x64(" - ds_base", state->ds_base);
    bfdebug_x16(" - fs_selector", state->fs_selector);
    bfdebug_x16(" - fs_attrib", state->fs_attrib);
    bfdebug_x32(" - fs_limit", state->fs_limit);
    bfdebug_x64(" - fs_base", state->fs_base);
    bfdebug_x16(" - gs_selector", state->gs_selector);
    bfdebug_x16(" - gs_attrib", state->gs_attrib);
    bfdebug_x32(" - gs_limit", state->gs_limit);
    bfdebug_x64(" - gs_base", state->gs_base);
    bfdebug_x16(" - ldtr_selector", state->ldtr_selector);
    bfdebug_x16(" - ldtr_attrib", state->ldtr_attrib);
    bfdebug_x32(" - ldtr_limit", state->ldtr_limit);
    bfdebug_x64(" - ldtr_base", state->ldtr_base);
    bfdebug_x16(" - tr_selector", state->tr_selector);
    bfdebug_x16(" - tr_attrib", state->tr_attrib);
    bfdebug_x32(" - tr_limit", state->tr_limit);
    bfdebug_x64(" - tr_base", state->tr_base);

    bfdebug_x64(" - cr0", state->cr0);
    bfdebug_x64(" - cr2", state->cr2);
    bfdebug_x64(" - cr3", state->cr3);
    bfdebug_x64(" - cr4", state->cr4);
    bfdebug_x64(" - cr8", state->cr8);
    bfdebug_x64(" - xcr0", state->xcr0);

    bfdebug_x64(" - dr0", state->dr0);
    bfdebug_x64(" - dr1", state->dr1);
    bfdebug_x64(" - dr2", state->dr2);
    bfdebug_x64(" - dr3", state->dr3);
    bfdebug_x64(" - dr6", state->dr6);
    bfdebug_x64(" - dr7", state->dr7);

    bfdebug_x64(" - efer", state->msr_efer);
    bfdebug_x64(" - star", state->msr_star);
    bfdebug_x64(" - lstar", state->msr_lstar);
    bfdebug_x64(" - cstar", state->msr_cstar);
    bfdebug_x64(" - fmask", state->msr_fmask);
    bfdebug_x64(" - fs_base", state->msr_fs_base);
    bfdebug_x64(" - gs_base", state->msr_gs_base);
    bfdebug_x64(" - kernel_gs_base", state->msr_kernel_gs_base);
    bfdebug_x64(" - sysenter_cs", state->msr_sysenter_cs);
    bfdebug_x64(" - sysenter_esp", state->msr_sysenter_esp);
    bfdebug_x64(" - sysenter_eip", state->msr_sysenter_eip);
    bfdebug_x64(" - pat", state->msr_pat);
    bfdebug_x64(" - debugctl", state->msr_debugctl);

    bfdebug_ptr(" - hve_page", state->hve_page);

    bfdebug_ptr(" - promote_handler", state->promote_handler);
    bfdebug_ptr(" - esr_default_handler", state->esr_default_handler);
    bfdebug_ptr(" - esr_df_handler", state->esr_df_handler);
    bfdebug_ptr(" - esr_gpf_handler", state->esr_gpf_handler);
    bfdebug_ptr(" - esr_nmi_handler", state->esr_nmi_handler);
    bfdebug_ptr(" - esr_pf_handler", state->esr_pf_handler);

    bfdebug_x64(" - nmi", state->nmi);
}
