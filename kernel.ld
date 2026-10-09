SECTIONS {
    . = 0x7C00;
    .boot : {
        ./AsemblerObjects/boot.o (.text);
    }
    .kernel : {
        *(.text);
        *(.rodata);
        *(.rodata.*);
        *(.data);
        *(.bss);
    }
     /DISCARD/ : {
            *(.eh_frame)
            *(.note.gnu.property)
            *(.comment)
            *(.note.ABI-tag)
            *(.note.gnu.build-id)
     }
}