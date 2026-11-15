%macro deadcode 0
    push 0x0DEADC0DE
%endmacro

[BITS 32]

global trampoline_00
global trampoline_01
global trampoline_02
global trampoline_03
global trampoline_04
global trampoline_05
global trampoline_06
global trampoline_07
global trampoline_08
global trampoline_09
global trampoline_0A
global trampoline_0B
global trampoline_0C
global trampoline_0D
global trampoline_0E
global trampoline_0F
global trampoline_10
global trampoline_11
global trampoline_12
global trampoline_13
global trampoline_14
global trampoline_15
global trampoline_16
global trampoline_17
global trampoline_18
global trampoline_19
global trampoline_1A
global trampoline_1B
global trampoline_1C
global trampoline_1D
global trampoline_1E
global trampoline_1F
global trampoline_20
global trampoline_21
global trampoline_22
global trampoline_23
global trampoline_24
global trampoline_25
global trampoline_26
global trampoline_27
global trampoline_28
global trampoline_29
global trampoline_2A
global trampoline_2B
global trampoline_2C
global trampoline_2D
global trampoline_2E
global trampoline_2F
global trampoline_30
global trampoline_31
global trampoline_32
global trampoline_33
global trampoline_34
global trampoline_35
global trampoline_36
global trampoline_37
global trampoline_38
global trampoline_39
global trampoline_3A
global trampoline_3B
global trampoline_3C
global trampoline_3D
global trampoline_3E
global trampoline_3F
global trampoline_40
global trampoline_41
global trampoline_42
global trampoline_43
global trampoline_44
global trampoline_45
global trampoline_46
global trampoline_47
global trampoline_48
global trampoline_49
global trampoline_4A
global trampoline_4B
global trampoline_4C
global trampoline_4D
global trampoline_4E
global trampoline_4F
global trampoline_50
global trampoline_51
global trampoline_52
global trampoline_53
global trampoline_54
global trampoline_55
global trampoline_56
global trampoline_57
global trampoline_58
global trampoline_59
global trampoline_5A
global trampoline_5B
global trampoline_5C
global trampoline_5D
global trampoline_5E
global trampoline_5F
global trampoline_60
global trampoline_61
global trampoline_62
global trampoline_63
global trampoline_64
global trampoline_65
global trampoline_66
global trampoline_67
global trampoline_68
global trampoline_69
global trampoline_6A
global trampoline_6B
global trampoline_6C
global trampoline_6D
global trampoline_6E
global trampoline_6F
global trampoline_70
global trampoline_71
global trampoline_72
global trampoline_73
global trampoline_74
global trampoline_75
global trampoline_76
global trampoline_77
global trampoline_78
global trampoline_79
global trampoline_7A
global trampoline_7B
global trampoline_7C
global trampoline_7D
global trampoline_7E
global trampoline_7F
global trampoline_80
global trampoline_81
global trampoline_82
global trampoline_83
global trampoline_84
global trampoline_85
global trampoline_86
global trampoline_87
global trampoline_88
global trampoline_89
global trampoline_8A
global trampoline_8B
global trampoline_8C
global trampoline_8D
global trampoline_8E
global trampoline_8F
global trampoline_90
global trampoline_91
global trampoline_92
global trampoline_93
global trampoline_94
global trampoline_95
global trampoline_96
global trampoline_97
global trampoline_98
global trampoline_99
global trampoline_9A
global trampoline_9B
global trampoline_9C
global trampoline_9D
global trampoline_9E
global trampoline_9F
global trampoline_A0
global trampoline_A1
global trampoline_A2
global trampoline_A3
global trampoline_A4
global trampoline_A5
global trampoline_A6
global trampoline_A7
global trampoline_A8
global trampoline_A9
global trampoline_AA
global trampoline_AB
global trampoline_AC
global trampoline_AD
global trampoline_AE
global trampoline_AF
global trampoline_B0
global trampoline_B1
global trampoline_B2
global trampoline_B3
global trampoline_B4
global trampoline_B5
global trampoline_B6
global trampoline_B7
global trampoline_B8
global trampoline_B9
global trampoline_BA
global trampoline_BB
global trampoline_BC
global trampoline_BD
global trampoline_BE
global trampoline_BF
global trampoline_C0
global trampoline_C1
global trampoline_C2
global trampoline_C3
global trampoline_C4
global trampoline_C5
global trampoline_C6
global trampoline_C7
global trampoline_C8
global trampoline_C9
global trampoline_CA
global trampoline_CB
global trampoline_CC
global trampoline_CD
global trampoline_CE
global trampoline_CF
global trampoline_D0
global trampoline_D1
global trampoline_D2
global trampoline_D3
global trampoline_D4
global trampoline_D5
global trampoline_D6
global trampoline_D7
global trampoline_D8
global trampoline_D9
global trampoline_DA
global trampoline_DB
global trampoline_DC
global trampoline_DD
global trampoline_DE
global trampoline_DF
global trampoline_E0
global trampoline_E1
global trampoline_E2
global trampoline_E3
global trampoline_E4
global trampoline_E5
global trampoline_E6
global trampoline_E7
global trampoline_E8
global trampoline_E9
global trampoline_EA
global trampoline_EB
global trampoline_EC
global trampoline_ED
global trampoline_EE
global trampoline_EF
global trampoline_F0
global trampoline_F1
global trampoline_F2
global trampoline_F3
global trampoline_F4
global trampoline_F5
global trampoline_F6
global trampoline_F7
global trampoline_F8
global trampoline_F9
global trampoline_FA
global trampoline_FB
global trampoline_FC
global trampoline_FD
global trampoline_FE
global trampoline_FF

extern interrupt_handler

collect_context:

    push ds
    push es
    push fs
    push gs
    pusha
    mov ebx, esp
    mov eax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    and esp, -16
    sub esp, 12
    push ebx
    call interrupt_handler
    mov esp, ebx
    popa
    pop gs
    pop fs
    pop es
    pop ds
    add esp, 8
    iretd


trampoline_00:
 deadcode
 push 0x00
 jmp collect_context

trampoline_01:
 deadcode
 push 0x01
 jmp collect_context

trampoline_02:
 deadcode
 push 0x02
 jmp collect_context

trampoline_03:
 deadcode
 push 0x03
 jmp collect_context

trampoline_04:
 deadcode
 push 0x04
 jmp collect_context

trampoline_05:
 deadcode
 push 0x05
 jmp collect_context

 trampoline_06:
 deadcode
 push 0x06
 jmp collect_context

trampoline_07:
 deadcode
 push 0x07
 jmp collect_context

trampoline_08:
 push 0x08
 jmp collect_context

trampoline_09:
 deadcode
 push 0x09
 jmp collect_context

trampoline_0A:
 push 0x0A
 jmp collect_context

trampoline_0B:
 push 0x0B
 jmp collect_context

trampoline_0C:
 push 0x0C
 jmp collect_context

trampoline_0D:
 push 0x0D
 jmp collect_context

trampoline_0E:
 push 0x0E
 jmp collect_context

trampoline_0F:
 deadcode
 push 0x0F
 jmp collect_context

trampoline_10:
 deadcode
 push 0x10
 jmp collect_context

trampoline_11:
 push 0x11
 jmp collect_context

trampoline_12:
 deadcode
 push 0x12
 jmp collect_context

trampoline_13:
 deadcode
 push 0x13
 jmp collect_context

trampoline_14:
 deadcode
 push 0x14
 jmp collect_context

trampoline_15:
 push 0x15
 jmp collect_context

trampoline_16:
 deadcode
 push 0x16
 jmp collect_context

trampoline_17:
 deadcode
 push 0x17
 jmp collect_context

trampoline_18:
 deadcode
 push 0x18
 jmp collect_context

trampoline_19:
 deadcode
 push 0x19
 jmp collect_context

trampoline_1A:
 deadcode
 push 0x1A
 jmp collect_context

trampoline_1B:
 deadcode
 push 0x1B
 jmp collect_context

trampoline_1C:
 deadcode
 push 0x1C
 jmp collect_context

trampoline_1D:
 push 0x1D
 jmp collect_context

trampoline_1E:
 push 0x1E
 jmp collect_context

trampoline_1F:
 deadcode
 push 0x1F
 jmp collect_context

trampoline_20:
deadcode
push 0x20
jmp collect_context

trampoline_21:
deadcode
push 0x21
jmp collect_context

trampoline_22:
deadcode
push 0x22
jmp collect_context

trampoline_23:
deadcode
push 0x23
jmp collect_context

trampoline_24:
deadcode
push 0x24
jmp collect_context

trampoline_25:
deadcode
push 0x25
jmp collect_context

trampoline_26:
deadcode
push 0x26
jmp collect_context

trampoline_27:
deadcode
push 0x27
jmp collect_context

trampoline_28:
deadcode
push 0x28
jmp collect_context

trampoline_29:
deadcode
push 0x29
jmp collect_context

trampoline_2A:
deadcode
push 0x2A
jmp collect_context

trampoline_2B:
deadcode
push 0x2B
jmp collect_context

trampoline_2C:
deadcode
push 0x2C
jmp collect_context

trampoline_2D:
deadcode
push 0x2D
jmp collect_context

trampoline_2E:
deadcode
push 0x2E
jmp collect_context

trampoline_2F:
deadcode
push 0x2F
jmp collect_context

trampoline_30:
deadcode
push 0x30
jmp collect_context

trampoline_31:
deadcode
push 0x31
jmp collect_context

trampoline_32:
deadcode
push 0x32
jmp collect_context

trampoline_33:
deadcode
push 0x33
jmp collect_context

trampoline_34:
deadcode
push 0x34
jmp collect_context

trampoline_35:
deadcode
push 0x35
jmp collect_context

trampoline_36:
deadcode
push 0x36
jmp collect_context

trampoline_37:
deadcode
push 0x37
jmp collect_context

trampoline_38:
deadcode
push 0x38
jmp collect_context

trampoline_39:
deadcode
push 0x39
jmp collect_context

trampoline_3A:
deadcode
push 0x3A
jmp collect_context

trampoline_3B:
deadcode
push 0x3B
jmp collect_context

trampoline_3C:
deadcode
push 0x3C
jmp collect_context

trampoline_3D:
deadcode
push 0x3D
jmp collect_context

trampoline_3E:
deadcode
push 0x3E
jmp collect_context

trampoline_3F:
deadcode
push 0x3F
jmp collect_context

trampoline_40:
deadcode
push 0x40
jmp collect_context

trampoline_41:
deadcode
push 0x41
jmp collect_context

trampoline_42:
deadcode
push 0x42
jmp collect_context

trampoline_43:
deadcode
push 0x43
jmp collect_context

trampoline_44:
deadcode
push 0x44
jmp collect_context

trampoline_45:
deadcode
push 0x45
jmp collect_context

trampoline_46:
deadcode
push 0x46
jmp collect_context

trampoline_47:
deadcode
push 0x47
jmp collect_context

trampoline_48:
deadcode
push 0x48
jmp collect_context

trampoline_49:
deadcode
push 0x49
jmp collect_context

trampoline_4A:
deadcode
push 0x4A
jmp collect_context

trampoline_4B:
deadcode
push 0x4B
jmp collect_context

trampoline_4C:
deadcode
push 0x4C
jmp collect_context

trampoline_4D:
deadcode
push 0x4D
jmp collect_context

trampoline_4E:
deadcode
push 0x4E
jmp collect_context

trampoline_4F:
deadcode
push 0x4F
jmp collect_context

trampoline_50:
deadcode
push 0x50
jmp collect_context

trampoline_51:
deadcode
push 0x51
jmp collect_context

trampoline_52:
deadcode
push 0x52
jmp collect_context

trampoline_53:
deadcode
push 0x53
jmp collect_context

trampoline_54:
deadcode
push 0x54
jmp collect_context

trampoline_55:
deadcode
push 0x55
jmp collect_context

trampoline_56:
deadcode
push 0x56
jmp collect_context

trampoline_57:
deadcode
push 0x57
jmp collect_context

trampoline_58:
deadcode
push 0x58
jmp collect_context

trampoline_59:
deadcode
push 0x59
jmp collect_context

trampoline_5A:
deadcode
push 0x5A
jmp collect_context

trampoline_5B:
deadcode
push 0x5B
jmp collect_context

trampoline_5C:
deadcode
push 0x5C
jmp collect_context

trampoline_5D:
deadcode
push 0x5D
jmp collect_context

trampoline_5E:
deadcode
push 0x5E
jmp collect_context

trampoline_5F:
deadcode
push 0x5F
jmp collect_context

trampoline_60:
deadcode
push 0x60
jmp collect_context

trampoline_61:
deadcode
push 0x61
jmp collect_context

trampoline_62:
deadcode
push 0x62
jmp collect_context

trampoline_63:
deadcode
push 0x63
jmp collect_context

trampoline_64:
deadcode
push 0x64
jmp collect_context

trampoline_65:
deadcode
push 0x65
jmp collect_context

trampoline_66:
deadcode
push 0x66
jmp collect_context

trampoline_67:
deadcode
push 0x67
jmp collect_context

trampoline_68:
deadcode
push 0x68
jmp collect_context

trampoline_69:
deadcode
push 0x69
jmp collect_context

trampoline_6A:
deadcode
push 0x6A
jmp collect_context

trampoline_6B:
deadcode
push 0x6B
jmp collect_context

trampoline_6C:
deadcode
push 0x6C
jmp collect_context

trampoline_6D:
deadcode
push 0x6D
jmp collect_context

trampoline_6E:
deadcode
push 0x6E
jmp collect_context

trampoline_6F:
deadcode
push 0x6F
jmp collect_context

trampoline_70:
deadcode
push 0x70
jmp collect_context

trampoline_71:
deadcode
push 0x71
jmp collect_context

trampoline_72:
deadcode
push 0x72
jmp collect_context

trampoline_73:
deadcode
push 0x73
jmp collect_context

trampoline_74:
deadcode
push 0x74
jmp collect_context

trampoline_75:
deadcode
push 0x75
jmp collect_context

trampoline_76:
deadcode
push 0x76
jmp collect_context

trampoline_77:
deadcode
push 0x77
jmp collect_context

trampoline_78:
deadcode
push 0x78
jmp collect_context

trampoline_79:
deadcode
push 0x79
jmp collect_context

trampoline_7A:
deadcode
push 0x7A
jmp collect_context

trampoline_7B:
deadcode
push 0x7B
jmp collect_context

trampoline_7C:
deadcode
push 0x7C
jmp collect_context

trampoline_7D:
deadcode
push 0x7D
jmp collect_context

trampoline_7E:
deadcode
push 0x7E
jmp collect_context

trampoline_7F:
deadcode
push 0x7F
jmp collect_context

trampoline_80:
deadcode
push 0x80
jmp collect_context

trampoline_81:
deadcode
push 0x81
jmp collect_context

trampoline_82:
deadcode
push 0x82
jmp collect_context

trampoline_83:
deadcode
push 0x83
jmp collect_context

trampoline_84:
deadcode
push 0x84
jmp collect_context

trampoline_85:
deadcode
push 0x85
jmp collect_context

trampoline_86:
deadcode
push 0x86
jmp collect_context

trampoline_87:
deadcode
push 0x87
jmp collect_context

trampoline_88:
deadcode
push 0x88
jmp collect_context

trampoline_89:
deadcode
push 0x89
jmp collect_context

trampoline_8A:
deadcode
push 0x8A
jmp collect_context

trampoline_8B:
deadcode
push 0x8B
jmp collect_context

trampoline_8C:
deadcode
push 0x8C
jmp collect_context

trampoline_8D:
deadcode
push 0x8D
jmp collect_context

trampoline_8E:
deadcode
push 0x8E
jmp collect_context

trampoline_8F:
deadcode
push 0x8F
jmp collect_context

trampoline_90:
deadcode
push 0x90
jmp collect_context

trampoline_91:
deadcode
push 0x91
jmp collect_context

trampoline_92:
deadcode
push 0x92
jmp collect_context

trampoline_93:
deadcode
push 0x93
jmp collect_context

trampoline_94:
deadcode
push 0x94
jmp collect_context

trampoline_95:
deadcode
push 0x95
jmp collect_context

trampoline_96:
deadcode
push 0x96
jmp collect_context

trampoline_97:
deadcode
push 0x97
jmp collect_context

trampoline_98:
deadcode
push 0x98
jmp collect_context

trampoline_99:
deadcode
push 0x99
jmp collect_context

trampoline_9A:
deadcode
push 0x9A
jmp collect_context

trampoline_9B:
deadcode
push 0x9B
jmp collect_context

trampoline_9C:
deadcode
push 0x9C
jmp collect_context

trampoline_9D:
deadcode
push 0x9D
jmp collect_context

trampoline_9E:
deadcode
push 0x9E
jmp collect_context

trampoline_9F:
deadcode
push 0x9F
jmp collect_context

trampoline_A0:
deadcode
push 0xA0
jmp collect_context

trampoline_A1:
deadcode
push 0xA1
jmp collect_context

trampoline_A2:
deadcode
push 0xA2
jmp collect_context

trampoline_A3:
deadcode
push 0xA3
jmp collect_context

trampoline_A4:
deadcode
push 0xA4
jmp collect_context

trampoline_A5:
deadcode
push 0xA5
jmp collect_context

trampoline_A6:
deadcode
push 0xA6
jmp collect_context

trampoline_A7:
deadcode
push 0xA7
jmp collect_context

trampoline_A8:
deadcode
push 0xA8
jmp collect_context

trampoline_A9:
deadcode
push 0xA9
jmp collect_context

trampoline_AA:
deadcode
push 0xAA
jmp collect_context

trampoline_AB:
deadcode
push 0xAB
jmp collect_context

trampoline_AC:
deadcode
push 0xAC
jmp collect_context

trampoline_AD:
deadcode
push 0xAD
jmp collect_context

trampoline_AE:
deadcode
push 0xAE
jmp collect_context

trampoline_AF:
deadcode
push 0xAF
jmp collect_context

trampoline_B0:
deadcode
push 0xB0
jmp collect_context

trampoline_B1:
deadcode
push 0xB1
jmp collect_context

trampoline_B2:
deadcode
push 0xB2
jmp collect_context

trampoline_B3:
deadcode
push 0xB3
jmp collect_context

trampoline_B4:
deadcode
push 0xB4
jmp collect_context

trampoline_B5:
deadcode
push 0xB5
jmp collect_context

trampoline_B6:
deadcode
push 0xB6
jmp collect_context

trampoline_B7:
deadcode
push 0xB7
jmp collect_context

trampoline_B8:
deadcode
push 0xB8
jmp collect_context

trampoline_B9:
deadcode
push 0xB9
jmp collect_context

trampoline_BA:
deadcode
push 0xBA
jmp collect_context

trampoline_BB:
deadcode
push 0xBB
jmp collect_context

trampoline_BC:
deadcode
push 0xBC
jmp collect_context

trampoline_BD:
deadcode
push 0xBD
jmp collect_context

trampoline_BE:
deadcode
push 0xBE
jmp collect_context

trampoline_BF:
deadcode
push 0xBF
jmp collect_context

trampoline_C0:
deadcode
push 0xC0
jmp collect_context

trampoline_C1:
deadcode
push 0xC1
jmp collect_context

trampoline_C2:
deadcode
push 0xC2
jmp collect_context

trampoline_C3:
deadcode
push 0xC3
jmp collect_context

trampoline_C4:
deadcode
push 0xC4
jmp collect_context

trampoline_C5:
deadcode
push 0xC5
jmp collect_context

trampoline_C6:
deadcode
push 0xC6
jmp collect_context

trampoline_C7:
deadcode
push 0xC7
jmp collect_context

trampoline_C8:
deadcode
push 0xC8
jmp collect_context

trampoline_C9:
deadcode
push 0xC9
jmp collect_context

trampoline_CA:
deadcode
push 0xCA
jmp collect_context

trampoline_CB:
deadcode
push 0xCB
jmp collect_context

trampoline_CC:
deadcode
push 0xCC
jmp collect_context

trampoline_CD:
deadcode
push 0xCD
jmp collect_context

trampoline_CE:
deadcode
push 0xCE
jmp collect_context

trampoline_CF:
deadcode
push 0xCF
jmp collect_context

trampoline_D0:
deadcode
push 0xD0
jmp collect_context

trampoline_D1:
deadcode
push 0xD1
jmp collect_context

trampoline_D2:
deadcode
push 0xD2
jmp collect_context

trampoline_D3:
deadcode
push 0xD3
jmp collect_context

trampoline_D4:
deadcode
push 0xD4
jmp collect_context

trampoline_D5:
deadcode
push 0xD5
jmp collect_context

trampoline_D6:
deadcode
push 0xD6
jmp collect_context

trampoline_D7:
deadcode
push 0xD7
jmp collect_context

trampoline_D8:
deadcode
push 0xD8
jmp collect_context

trampoline_D9:
deadcode
push 0xD9
jmp collect_context

trampoline_DA:
deadcode
push 0xDA
jmp collect_context

trampoline_DB:
deadcode
push 0xDB
jmp collect_context

trampoline_DC:
deadcode
push 0xDC
jmp collect_context

trampoline_DD:
deadcode
push 0xDD
jmp collect_context

trampoline_DE:
deadcode
push 0xDE
jmp collect_context

trampoline_DF:
deadcode
push 0xDF
jmp collect_context

trampoline_E0:
deadcode
push 0xE0
jmp collect_context

trampoline_E1:
deadcode
push 0xE1
jmp collect_context

trampoline_E2:
deadcode
push 0xE2
jmp collect_context

trampoline_E3:
deadcode
push 0xE3
jmp collect_context

trampoline_E4:
deadcode
push 0xE4
jmp collect_context

trampoline_E5:
deadcode
push 0xE5
jmp collect_context

trampoline_E6:
deadcode
push 0xE6
jmp collect_context

trampoline_E7:
deadcode
push 0xE7
jmp collect_context

trampoline_E8:
deadcode
push 0xE8
jmp collect_context

trampoline_E9:
deadcode
push 0xE9
jmp collect_context

trampoline_EA:
deadcode
push 0xEA
jmp collect_context

trampoline_EB:
deadcode
push 0xEB
jmp collect_context

trampoline_EC:
deadcode
push 0xEC
jmp collect_context

trampoline_ED:
deadcode
push 0xED
jmp collect_context

trampoline_EE:
deadcode
push 0xEE
jmp collect_context

trampoline_EF:
deadcode
push 0xEF
jmp collect_context

trampoline_F0:
deadcode
push 0xF0
jmp collect_context

trampoline_F1:
deadcode
push 0xF1
jmp collect_context

trampoline_F2:
deadcode
push 0xF2
jmp collect_context

trampoline_F3:
deadcode
push 0xF3
jmp collect_context

trampoline_F4:
deadcode
push 0xF4
jmp collect_context

trampoline_F5:
deadcode
push 0xF5
jmp collect_context

trampoline_F6:
deadcode
push 0xF6
jmp collect_context

trampoline_F7:
deadcode
push 0xF7
jmp collect_context

trampoline_F8:
deadcode
push 0xF8
jmp collect_context

trampoline_F9:
deadcode
push 0xF9
jmp collect_context

trampoline_FA:
deadcode
push 0xFA
jmp collect_context

trampoline_FB:
deadcode
push 0xFB
jmp collect_context

trampoline_FC:
deadcode
push 0xFC
jmp collect_context

trampoline_FD:
deadcode
push 0xFD
jmp collect_context

trampoline_FE:
deadcode
push 0xFE
jmp collect_context

trampoline_FF:
deadcode
push 0xFF
jmp collect_context