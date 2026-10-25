SECTIONS {
    . = 0x7C00;
    _kernel_start = .;
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
    _kernel_end = .;
     /DISCARD/ : {
            *(.eh_frame)
            *(.note.gnu.property)
            *(.comment)
            *(.note.ABI-tag)
            *(.note.gnu.build-id)
     }
}