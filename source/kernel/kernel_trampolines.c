#include "kernel_trampolines.h"

#include "utility_asm_fuctions.h"
#include "utility_endless_allocator.h"

extern void trampoline_00(void);
extern void trampoline_01(void);
extern void trampoline_02(void);
extern void trampoline_03(void);
extern void trampoline_04(void);
extern void trampoline_05(void);
extern void trampoline_06(void);
extern void trampoline_07(void);
extern void trampoline_08(void);
extern void trampoline_09(void);
extern void trampoline_0A(void);
extern void trampoline_0B(void);
extern void trampoline_0C(void);
extern void trampoline_0D(void);
extern void trampoline_0E(void);
extern void trampoline_0F(void);
extern void trampoline_10(void);
extern void trampoline_11(void);
extern void trampoline_12(void);
extern void trampoline_13(void);
extern void trampoline_14(void);
extern void trampoline_15(void);
extern void trampoline_16(void);
extern void trampoline_17(void);
extern void trampoline_18(void);
extern void trampoline_19(void);
extern void trampoline_1A(void);
extern void trampoline_1B(void);
extern void trampoline_1C(void);
extern void trampoline_1D(void);
extern void trampoline_1E(void);
extern void trampoline_1F(void);
extern void trampoline_20(void);
extern void trampoline_21(void);
extern void trampoline_22(void);
extern void trampoline_23(void);
extern void trampoline_24(void);
extern void trampoline_25(void);
extern void trampoline_26(void);
extern void trampoline_27(void);
extern void trampoline_28(void);
extern void trampoline_29(void);
extern void trampoline_2A(void);
extern void trampoline_2B(void);
extern void trampoline_2C(void);
extern void trampoline_2D(void);
extern void trampoline_2E(void);
extern void trampoline_2F(void);
extern void trampoline_30(void);
extern void trampoline_31(void);
extern void trampoline_32(void);
extern void trampoline_33(void);
extern void trampoline_34(void);
extern void trampoline_35(void);
extern void trampoline_36(void);
extern void trampoline_37(void);
extern void trampoline_38(void);
extern void trampoline_39(void);
extern void trampoline_3A(void);
extern void trampoline_3B(void);
extern void trampoline_3C(void);
extern void trampoline_3D(void);
extern void trampoline_3E(void);
extern void trampoline_3F(void);
extern void trampoline_40(void);
extern void trampoline_41(void);
extern void trampoline_42(void);
extern void trampoline_43(void);
extern void trampoline_44(void);
extern void trampoline_45(void);
extern void trampoline_46(void);
extern void trampoline_47(void);
extern void trampoline_48(void);
extern void trampoline_49(void);
extern void trampoline_4A(void);
extern void trampoline_4B(void);
extern void trampoline_4C(void);
extern void trampoline_4D(void);
extern void trampoline_4E(void);
extern void trampoline_4F(void);
extern void trampoline_50(void);
extern void trampoline_51(void);
extern void trampoline_52(void);
extern void trampoline_53(void);
extern void trampoline_54(void);
extern void trampoline_55(void);
extern void trampoline_56(void);
extern void trampoline_57(void);
extern void trampoline_58(void);
extern void trampoline_59(void);
extern void trampoline_5A(void);
extern void trampoline_5B(void);
extern void trampoline_5C(void);
extern void trampoline_5D(void);
extern void trampoline_5E(void);
extern void trampoline_5F(void);
extern void trampoline_60(void);
extern void trampoline_61(void);
extern void trampoline_62(void);
extern void trampoline_63(void);
extern void trampoline_64(void);
extern void trampoline_65(void);
extern void trampoline_66(void);
extern void trampoline_67(void);
extern void trampoline_68(void);
extern void trampoline_69(void);
extern void trampoline_6A(void);
extern void trampoline_6B(void);
extern void trampoline_6C(void);
extern void trampoline_6D(void);
extern void trampoline_6E(void);
extern void trampoline_6F(void);
extern void trampoline_70(void);
extern void trampoline_71(void);
extern void trampoline_72(void);
extern void trampoline_73(void);
extern void trampoline_74(void);
extern void trampoline_75(void);
extern void trampoline_76(void);
extern void trampoline_77(void);
extern void trampoline_78(void);
extern void trampoline_79(void);
extern void trampoline_7A(void);
extern void trampoline_7B(void);
extern void trampoline_7C(void);
extern void trampoline_7D(void);
extern void trampoline_7E(void);
extern void trampoline_7F(void);
extern void trampoline_80(void);
extern void trampoline_81(void);
extern void trampoline_82(void);
extern void trampoline_83(void);
extern void trampoline_84(void);
extern void trampoline_85(void);
extern void trampoline_86(void);
extern void trampoline_87(void);
extern void trampoline_88(void);
extern void trampoline_89(void);
extern void trampoline_8A(void);
extern void trampoline_8B(void);
extern void trampoline_8C(void);
extern void trampoline_8D(void);
extern void trampoline_8E(void);
extern void trampoline_8F(void);
extern void trampoline_90(void);
extern void trampoline_91(void);
extern void trampoline_92(void);
extern void trampoline_93(void);
extern void trampoline_94(void);
extern void trampoline_95(void);
extern void trampoline_96(void);
extern void trampoline_97(void);
extern void trampoline_98(void);
extern void trampoline_99(void);
extern void trampoline_9A(void);
extern void trampoline_9B(void);
extern void trampoline_9C(void);
extern void trampoline_9D(void);
extern void trampoline_9E(void);
extern void trampoline_9F(void);
extern void trampoline_A0(void);
extern void trampoline_A1(void);
extern void trampoline_A2(void);
extern void trampoline_A3(void);
extern void trampoline_A4(void);
extern void trampoline_A5(void);
extern void trampoline_A6(void);
extern void trampoline_A7(void);
extern void trampoline_A8(void);
extern void trampoline_A9(void);
extern void trampoline_AA(void);
extern void trampoline_AB(void);
extern void trampoline_AC(void);
extern void trampoline_AD(void);
extern void trampoline_AE(void);
extern void trampoline_AF(void);
extern void trampoline_B0(void);
extern void trampoline_B1(void);
extern void trampoline_B2(void);
extern void trampoline_B3(void);
extern void trampoline_B4(void);
extern void trampoline_B5(void);
extern void trampoline_B6(void);
extern void trampoline_B7(void);
extern void trampoline_B8(void);
extern void trampoline_B9(void);
extern void trampoline_BA(void);
extern void trampoline_BB(void);
extern void trampoline_BC(void);
extern void trampoline_BD(void);
extern void trampoline_BE(void);
extern void trampoline_BF(void);
extern void trampoline_C0(void);
extern void trampoline_C1(void);
extern void trampoline_C2(void);
extern void trampoline_C3(void);
extern void trampoline_C4(void);
extern void trampoline_C5(void);
extern void trampoline_C6(void);
extern void trampoline_C7(void);
extern void trampoline_C8(void);
extern void trampoline_C9(void);
extern void trampoline_CA(void);
extern void trampoline_CB(void);
extern void trampoline_CC(void);
extern void trampoline_CD(void);
extern void trampoline_CE(void);
extern void trampoline_CF(void);
extern void trampoline_D0(void);
extern void trampoline_D1(void);
extern void trampoline_D2(void);
extern void trampoline_D3(void);
extern void trampoline_D4(void);
extern void trampoline_D5(void);
extern void trampoline_D6(void);
extern void trampoline_D7(void);
extern void trampoline_D8(void);
extern void trampoline_D9(void);
extern void trampoline_DA(void);
extern void trampoline_DB(void);
extern void trampoline_DC(void);
extern void trampoline_DD(void);
extern void trampoline_DE(void);
extern void trampoline_DF(void);
extern void trampoline_E0(void);
extern void trampoline_E1(void);
extern void trampoline_E2(void);
extern void trampoline_E3(void);
extern void trampoline_E4(void);
extern void trampoline_E5(void);
extern void trampoline_E6(void);
extern void trampoline_E7(void);
extern void trampoline_E8(void);
extern void trampoline_E9(void);
extern void trampoline_EA(void);
extern void trampoline_EB(void);
extern void trampoline_EC(void);
extern void trampoline_ED(void);
extern void trampoline_EE(void);
extern void trampoline_EF(void);
extern void trampoline_F0(void);
extern void trampoline_F1(void);
extern void trampoline_F2(void);
extern void trampoline_F3(void);
extern void trampoline_F4(void);
extern void trampoline_F5(void);
extern void trampoline_F6(void);
extern void trampoline_F7(void);
extern void trampoline_F8(void);
extern void trampoline_F9(void);
extern void trampoline_FA(void);
extern void trampoline_FB(void);
extern void trampoline_FC(void);
extern void trampoline_FD(void);
extern void trampoline_FE(void);
extern void trampoline_FF(void);

static void* trampolines[] = {trampoline_00, trampoline_01, trampoline_02, trampoline_03, trampoline_04,
                            trampoline_05, trampoline_06, trampoline_07, trampoline_08, trampoline_09,
                            trampoline_0A, trampoline_0B, trampoline_0C, trampoline_0D, trampoline_0E,
                            trampoline_0F, trampoline_10, trampoline_11, trampoline_12, trampoline_13,
                            trampoline_14, trampoline_15, trampoline_16, trampoline_17, trampoline_18,
                            trampoline_19, trampoline_1A, trampoline_1B, trampoline_1C, trampoline_1D,
                            trampoline_1E, trampoline_1F, trampoline_20, trampoline_21, trampoline_22,
                            trampoline_23, trampoline_24, trampoline_25, trampoline_26, trampoline_27,
                            trampoline_28, trampoline_29, trampoline_2A, trampoline_2B, trampoline_2C,
                            trampoline_2D, trampoline_2E, trampoline_2F, trampoline_30, trampoline_31,
                            trampoline_32, trampoline_33, trampoline_34, trampoline_35, trampoline_36,
                            trampoline_37, trampoline_38, trampoline_39, trampoline_3A, trampoline_3B,
                            trampoline_3C, trampoline_3D, trampoline_3E, trampoline_3F, trampoline_40,
                            trampoline_41, trampoline_42, trampoline_43, trampoline_44, trampoline_45,
                            trampoline_46, trampoline_47, trampoline_48, trampoline_49, trampoline_4A,
                            trampoline_4B, trampoline_4C, trampoline_4D, trampoline_4E, trampoline_4F,
                            trampoline_50, trampoline_51, trampoline_52, trampoline_53, trampoline_54,
                            trampoline_55, trampoline_56, trampoline_57, trampoline_58, trampoline_59,
                            trampoline_5A, trampoline_5B, trampoline_5C, trampoline_5D, trampoline_5E,
                            trampoline_5F, trampoline_60, trampoline_61, trampoline_62, trampoline_63,
                            trampoline_64, trampoline_65, trampoline_66, trampoline_67, trampoline_68,
                            trampoline_69, trampoline_6A, trampoline_6B, trampoline_6C, trampoline_6D,
                            trampoline_6E, trampoline_6F, trampoline_70, trampoline_71, trampoline_72,
                            trampoline_73, trampoline_74, trampoline_75, trampoline_76, trampoline_77,
                            trampoline_78, trampoline_79, trampoline_7A, trampoline_7B, trampoline_7C,
                            trampoline_7D, trampoline_7E, trampoline_7F, trampoline_80, trampoline_81,
                            trampoline_82, trampoline_83, trampoline_84, trampoline_85, trampoline_86,
                            trampoline_87, trampoline_88, trampoline_89, trampoline_8A, trampoline_8B,
                            trampoline_8C, trampoline_8D, trampoline_8E, trampoline_8F, trampoline_90,
                            trampoline_91, trampoline_92, trampoline_93, trampoline_94, trampoline_95,
                            trampoline_96, trampoline_97, trampoline_98, trampoline_99, trampoline_9A,
                            trampoline_9B, trampoline_9C, trampoline_9D, trampoline_9E, trampoline_9F,
                            trampoline_A0, trampoline_A1, trampoline_A2, trampoline_A3, trampoline_A4,
                            trampoline_A5, trampoline_A6, trampoline_A7, trampoline_A8, trampoline_A9,
                            trampoline_AA, trampoline_AB, trampoline_AC, trampoline_AD, trampoline_AE,
                            trampoline_AF, trampoline_B0, trampoline_B1, trampoline_B2, trampoline_B3,
                            trampoline_B4, trampoline_B5, trampoline_B6, trampoline_B7, trampoline_B8,
                            trampoline_B9, trampoline_BA, trampoline_BB, trampoline_BC, trampoline_BD,
                            trampoline_BE, trampoline_BF, trampoline_C0, trampoline_C1, trampoline_C2,
                            trampoline_C3, trampoline_C4, trampoline_C5, trampoline_C6, trampoline_C7,
                            trampoline_C8, trampoline_C9, trampoline_CA, trampoline_CB, trampoline_CC,
                            trampoline_CD, trampoline_CE, trampoline_CF, trampoline_D0, trampoline_D1,
                            trampoline_D2, trampoline_D3, trampoline_D4, trampoline_D5, trampoline_D6,
                            trampoline_D7, trampoline_D8, trampoline_D9, trampoline_DA, trampoline_DB,
                            trampoline_DC, trampoline_DD, trampoline_DE, trampoline_DF, trampoline_E0,
                            trampoline_E1, trampoline_E2, trampoline_E3, trampoline_E4, trampoline_E5,
                            trampoline_E6, trampoline_E7, trampoline_E8, trampoline_E9, trampoline_EA,
                            trampoline_EB, trampoline_EC, trampoline_ED, trampoline_EE, trampoline_EF,
                            trampoline_F0, trampoline_F1, trampoline_F2, trampoline_F3, trampoline_F4,
                            trampoline_F5, trampoline_F6, trampoline_F7, trampoline_F8, trampoline_F9,
                            trampoline_FA, trampoline_FB, trampoline_FC, trampoline_FD, trampoline_FE,
                            trampoline_FF};

static gate_descriptor* generate_idt(){
    gate_descriptor* ans = endless_malloc(COUNT_INTERRUPT * sizeof(gate_descriptor), 8);
    for (i32 i = 0; i < COUNT_INTERRUPT; ++i) {
        ans[i] = generate_gate_descriptor(trampolines[i],  interrupt_gate, kernel);
    }
    return ans;
}

static gate_descriptor generate_gate_descriptor(void* trampoline_ptr, enum gate_type type, enum descriptor_privilege_level level) {
    gate_descriptor gate;
    gate.shift_low = (u16)trampoline_ptr;
    gate.selector_segment = get_cs_api();
    gate.reserve1 = 0;
    gate.gate_type = type;
    gate.reserve2 = 0;
    gate.dpl = level;
    gate.reserve3 = 1;
    gate.shift_height = (u16)((i32)trampoline_ptr >> 16);
    return gate;
}

void create_lidt() {
    gate_descriptor* descriptor = generate_idt();
    table_gate_descriptor table;
    table.size = COUNT_INTERRUPT * sizeof(gate_descriptor) - 1;
    table.address = (u32)descriptor;
    lidt_api(&table);
}

